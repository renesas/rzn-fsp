/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "bsp_cfg.h"

#include <r_usb_basic.h>
#include <r_usb_basic_api.h>
#include <string.h>

#include "src/driver/inc/r_usb_typedef.h"
#include "src/driver/inc/r_usb_extern.h"
#include "src/hw/inc/r_usb_bitdefine.h"
#include "src/hw/inc/r_usb_reg_access.h"
#if  USB_IP_EHCI_OHCI == 1
 #include "r_usb_hhci_local.h"
#endif

#if defined(USB_CFG_HCDC_USE)
 #include "r_usb_hcdc_api.h"
#endif                                 /* defined(USB_CFG_HCDC_USE) */

#if defined(USB_CFG_HHID_USE)
 #include "r_usb_hhid_api.h"
#endif                                 /* defined(USB_CFG_HHID_USE) */

#if defined(USB_CFG_HMSC_USE)
 #include "r_usb_hmsc_api.h"
 #include "../r_usb_hmsc/src/inc/r_usb_hmsc_driver.h"
#endif                                 /* defined(USB_CFG_HMSC_USE) */

#if defined(USB_CFG_PHID_USE)
 #include "r_usb_phid_api.h"
#endif                                 /* defined(USB_CFG_PHID_USE) */

#if defined(USB_CFG_PCDC_USE)
 #include "r_usb_pcdc_api.h"
 #include "r_usb_pcdc_cfg.h"
#endif                                 /* defined(USB_CFG_PCDC_USE) */

#if defined(USB_CFG_PMSC_USE)
 #include "../r_usb_pmsc/src/inc/r_usb_pmsc_driver.h"
#endif                                 /* defined(USB_CFG_PMSC_USE) */

#if (BSP_CFG_RTOS == 2)
 #include "src/driver/inc/r_usb_cstd_rtos.h"
#endif

/******************************************************************************
 * Macro definitions
 ******************************************************************************/
#define USB_VALUE_100    (100)
#define USB_VALUE_7FH    (0x7F)
#define USB_VALUE_FFH    (0xFF)
#define USB_VALUE_32     (32U)

/******************************************************************************
 * Exported global variables (to be accessed by other files)
 ******************************************************************************/
#if (BSP_CFG_RTOS == 0)
usb_event_t g_usb_cstd_event;
uint16_t    g_usb_change_device_state[USB_NUM_USBIP];
#else                                  /*(BSP_CFG_RTOS == 0)*/
usb_instance_ctrl_t g_usb_cstd_event[USB_EVENT_MAX];
usb_callback_t    * g_usb_apl_callback[USB_NUM_USBIP];

#endif                                 /*(BSP_CFG_RTOS == 0)*/

#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
usb_utr_t g_usb_hdata[USB_NUM_USBIP][USB_MAXPIPE_NUM + 1] USB_BUFFER_PLACE_IN_SECTION;
#endif                                 /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */

#if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
usb_utr_t g_usb_pdata[USB_MAXPIPE_NUM + 1] USB_BUFFER_PLACE_IN_SECTION;

#endif                                 /* (USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI */

volatile uint16_t g_usb_usbmode[USB_NUM_USBIP];
volatile uint16_t g_usb_open_class[USB_NUM_USBIP];

#if defined(USB_CFG_PMSC_USE)
uint8_t g_usb_pmsc_usbip = USB_VALUE_FFH;
#endif                                 /* defined(USB_CFG_PMSC_USE) */

/******************************************************************************
 * Private global variables and functions
 ******************************************************************************/
static uint8_t is_init[USB_NUM_USBIP] =
{
    USB_NO,
#if USB_NUM_USBIP == 2
    USB_NO,
#endif
};

#if (BSP_CFG_RTOS == 2)
 #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
static uint8_t gs_usb_suspend_ing[USB_NUM_USBIP] =
{
    USB_NO,
  #if USB_NUM_USBIP == 2
    USB_NO,
  #endif
};
 #endif                                /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */

uint8_t g_usb_resume_ing[USB_NUM_USBIP] =
{
    USB_NO,
 #if USB_NUM_USBIP == 2
    USB_NO,
 #endif
};
#endif                                 /*(BSP_CFG_RTOS == 2)*/

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/** Version data structure used by error logger macro. */
#if BSP_CFG_ERROR_LOG != 0
const char g_module_name[] = "r_usb";
#endif

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

const usb_api_t g_usb_on_usb =
{
    .open                 = R_USB_Open,
    .close                = R_USB_Close,
    .read                 = R_USB_Read,
    .write                = R_USB_Write,
    .stop                 = R_USB_Stop,
    .suspend              = R_USB_Suspend,
    .resume               = R_USB_Resume,
    .vbusSet              = R_USB_VbusSet,
    .infoGet              = R_USB_InfoGet,
    .pipeRead             = R_USB_PipeRead,
    .pipeWrite            = R_USB_PipeWrite,
    .pipeStop             = R_USB_PipeStop,
    .usedPipesGet         = R_USB_UsedPipesGet,
    .pipeInfoGet          = R_USB_PipeInfoGet,
    .eventGet             = R_USB_EventGet,
    .callback             = R_USB_Callback,
    .pullUp               = R_USB_PullUp,
    .hostControlTransfer  = R_USB_HostControlTransfer,
    .periControlDataGet   = R_USB_PeriControlDataGet,
    .periControlDataSet   = R_USB_PeriControlDataSet,
    .periControlStatusSet = R_USB_PeriControlStatusSet,
    .remoteWakeup         = R_USB_RemoteWakeup,
    .moduleNumberGet      = R_USB_ModuleNumberGet,
    .classTypeGet         = R_USB_ClassTypeGet,
    .deviceAddressGet     = R_USB_DeviceAddressGet,
    .pipeNumberGet        = R_USB_PipeNumberGet,
    .deviceStateGet       = R_USB_DeviceStateGet,
    .dataSizeGet          = R_USB_DataSizeGet,
    .setupGet             = R_USB_SetupGet,
};

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup USB USB
 * @{
 **********************************************************************************************************************/

/**************************************************************************//**
 * @brief Obtains completed USB related events. (OS-less Only)
 *
 * In USB host mode, the device address value of the USB device that completed
 * an event is specified in the usb_ctrl_t structure member (address) specified
 * by the event's argument.
 * In USB peripheral mode, USB_NULL is specified in member (address).
 * If this function is called in the RTOS execution environment, a failure is returned.
 *
 * @retval FSP_SUCCESS        Event Get Success.
 * @retval FSP_ERR_USB_FAILED If called in the RTOS environment, an error is returned.
 *
 * @note Do not use the same variable as the first argument of R_USB_Open for the first argument.
 * @note Do not call this API in the interrupt function.
 ******************************************************************************/
fsp_err_t R_USB_EventGet (usb_ctrl_t * const p_ctrl, usb_status_t * event)
{
    fsp_err_t result;
#if (BSP_CFG_RTOS == 0)
    result   = FSP_SUCCESS;
    (*event) = USB_STATUS_NONE;
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

    usb_cstd_usb_task();
    if (g_usb_cstd_event.write_pointer != g_usb_cstd_event.read_pointer)
    {
        *p_instance_ctrl = g_usb_cstd_event.ctrl[g_usb_cstd_event.read_pointer];
        (*event)         = g_usb_cstd_event.code[g_usb_cstd_event.read_pointer];
        g_usb_cstd_event.read_pointer++;
        if (g_usb_cstd_event.read_pointer >= USB_EVENT_MAX)
        {
            g_usb_cstd_event.read_pointer = 0;
        }
    }

#else                                  /* (BSP_CFG_RTOS == 0) */
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(*event);
    result = FSP_ERR_USB_FAILED;
#endif /* (BSP_CFG_RTOS == 0) */
    return result;
}                                      /* End of function R_USB_EventGet() */

/**************************************************************************//**
 * @brief Register a callback function to be called upon completion of a
 * USB related event. (RTOS only)
 *
 * This function registers a callback function to be called when a USB-related event has completed.
 * If this function is called in the OS-less execution environment, a failure is returned.
 *
 * @retval FSP_SUCCESS        Successfully completed.
 * @retval FSP_ERR_USB_FAILED If this function is called in the OS-less execution environment, a failure is returned.
 * @retval FSP_ERR_ASSERTION  Parameter is NULL error.
 * @note Do not call this API in the interrupt function.
 ******************************************************************************/
fsp_err_t R_USB_Callback (usb_callback_t * p_callback)
{
    fsp_err_t err;
#if (BSP_CFG_RTOS == 2)
 #if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_callback)
 #endif                                /* USB_CFG_PARAM_CHECKING_ENABLE */
    g_usb_apl_callback[0] = p_callback;
    err = FSP_SUCCESS;
#else /* (BSP_CFG_RTOS == 2) */
    FSP_PARAMETER_NOT_USED(*p_callback);
    err = FSP_ERR_USB_FAILED;
#endif                                 /* (BSP_CFG_RTOS == 2) */
    return err;
} /* End of function R_USB_Callback() */

/**************************************************************************//**
 * @brief Applies power to the USB module specified in the argument (p_ctrl).
 *
 * @retval FSP_SUCCESS           Success in open.
 * @retval FSP_ERR_USB_BUSY      Specified USB module now in use.
 * @retval FSP_ERR_ASSERTION     Parameter is NULL error.
 * @retval FSP_ERR_USB_FAILED    The function could not be completed successfully.
 * @retval FSP_ERR_USB_PARAMETER Parameter error.
 * @note Do not call this API in the following function.
 * @note (1). Interrupt function.
 * @note (2). Callback function ( for RTOS ).
 ******************************************************************************/
fsp_err_t R_USB_Open (usb_ctrl_t * const p_ctrl, usb_cfg_t const * const p_cfg)
{
    fsp_err_t err = FSP_SUCCESS;
#if (BSP_CFG_RTOS == 2)
    usb_rtos_err_t os_err;
#endif
#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
    usb_utr_t utr;
#endif                                 /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;
    usb_utr_t             hse_utr;
    memset((void *) &hse_utr, 0, sizeof(usb_utr_t));

#if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl)
    FSP_ASSERT(p_cfg)
#endif                                 /* USB_CFG_PARAM_CHECKING_ENABLE */

    p_instance_ctrl->module_number = p_cfg->module_number;
    p_instance_ctrl->type          = (usb_class_t) (p_cfg->type & USB_VALUE_7FH);
    p_instance_ctrl->p_context     = (void *) p_cfg->p_context;
#if (BSP_CFG_RTOS == 2)
    g_usb_apl_callback[p_instance_ctrl->module_number] = p_cfg->p_usb_apl_callback;
#endif

#if USB_CFG_PARAM_CHECKING_ENABLE

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_IP0 != p_instance_ctrl->module_number) && (USB_IP1 != p_instance_ctrl->module_number)),
                     FSP_ERR_USB_PARAMETER)

    FSP_ERROR_RETURN(!(((USB_SPEED_HS != p_cfg->usb_speed) && (USB_SPEED_FS != p_cfg->usb_speed)) &&
                       (USB_SPEED_LS != p_cfg->usb_speed) &&
                       (USB_MODE_HOST != p_cfg->usb_mode)),
                     FSP_ERR_USB_PARAMETER)
    switch ((usb_class_internal_t) p_instance_ctrl->type)
    {
        case USB_CLASS_INTERNAL_PCDC:
        case USB_CLASS_INTERNAL_PHID:
        case USB_CLASS_INTERNAL_PVND:
        case USB_CLASS_INTERNAL_PMSC:
        {
            FSP_ERROR_RETURN(USB_MODE_PERI == p_cfg->usb_mode, FSP_ERR_USB_PARAMETER)

            FSP_ERROR_RETURN(!((USB_SPEED_LS == p_cfg->usb_speed) || (USB_NULL == p_cfg->p_usb_reg)),
                             FSP_ERR_USB_PARAMETER)
            break;
        }

        /* Host */
        case USB_CLASS_INTERNAL_HCDC:
        case USB_CLASS_INTERNAL_HHID:
        case USB_CLASS_INTERNAL_HVND:
        case USB_CLASS_INTERNAL_HMSC:
        {
            FSP_ERROR_RETURN(USB_MODE_HOST == p_cfg->usb_mode, FSP_ERR_USB_PARAMETER)
            FSP_ERROR_RETURN(USB_SPEED_HS == p_cfg->usb_speed, FSP_ERR_USB_PARAMETER)
            break;
        }

        default:
        {
            return FSP_ERR_USB_PARAMETER;
            break;
        }
    }
#endif                                 /* USB_CFG_PARAM_CHECKING_ENABLE */
    if (USB_YES == is_init[p_instance_ctrl->module_number])
    {
        return FSP_ERR_USB_BUSY;
    }

#if (BSP_CFG_RTOS == 2)
    os_err = usb_rtos_configuration();
    if (UsbRtos_Success != os_err)
    {
        return FSP_ERR_USB_FAILED;
    }
#endif

#if USB_NUM_USBIP == 2
    if ((USB_NO == is_init[USB_IP0]) && (USB_NO == is_init[USB_IP1]))
    {
#endif                                 /* USB_NUM_USBIP == 2 */

    memset((void *) &g_usb_cstd_event, 0, sizeof(g_usb_cstd_event));

#if USB_NUM_USBIP == 2
}
#endif                                 /* USB_NUM_USBIP == 2 */

    is_init[p_instance_ctrl->module_number] = USB_YES;

    g_usb_open_class[p_instance_ctrl->module_number] = 0;

#if (BSP_CFG_RTOS == 0)
    g_usb_change_device_state[p_instance_ctrl->module_number] = 0;
#endif                                 /* (BSP_CFG_RTOS == 0) */

#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
    g_usb_hstd_use_pipe[p_instance_ctrl->module_number] = 0;
    memset((void *) &g_usb_hdata[p_instance_ctrl->module_number], 0, sizeof(usb_utr_t));
#endif                                 /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */

#if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
    memset((void *) &g_usb_pdata, 0, ((USB_MAXPIPE_NUM + 1) * sizeof(usb_utr_t)));
#endif                                 /* (USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_REPI */

    if (USB_MODE_HOST == p_cfg->usb_mode)
    {
#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
        g_usb_usbmode[p_instance_ctrl->module_number] = USB_MODE_HOST;

        utr.ip  = p_instance_ctrl->module_number;
        utr.ipp = usb_hstd_get_usb_ip_adr((uint16_t) p_instance_ctrl->module_number); /* Get the USB IP base address. */

        err = usb_module_start(utr.ip);
        if (FSP_SUCCESS == err)
        {
            /* USB driver initialization */
            R_USB_HstdMgrOpen(&utr);      /* USB0 MGR Open */
 #if defined(USB_CFG_HCDC_USE) || defined(USB_CFG_HHID_USE) || defined(USB_CFG_HMSC_USE) || defined(USB_CFG_HVND_USE)
            usb_class_driver_start(&utr); /* Init host class driver task. */
            usb_host_registration(&utr);  /* Class Registration */
 #endif  /* defined(USB_CFG_HCDC_USE)||defined(USB_CFG_HHID_USE)||defined(USB_CFG_HMSC_USE)||defined(USB_CFG_HVND_USE) */

            /* Setting MCU(USB interrupt init) register */
            usb_cpu_usbint_init(utr.ip, p_cfg);
            FSP_PARAMETER_NOT_USED(hse_utr);
        }
#endif                                 /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */
    }
    else
    {
#if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
        g_usb_usbmode[p_instance_ctrl->module_number] = USB_MODE_PERI;

 #if defined(USB_CFG_PMSC_USE)
        g_usb_pmsc_usbip = p_instance_ctrl->module_number;
        err              = r_usb_pmsc_media_initialize(p_cfg->p_context); /* Register the media device driver. */
        if (FSP_SUCCESS != err)
        {
            return err;
        }
 #endif                                /* defined(USB_CFG_PMSC_USE) */
        /* USB module start setting */
        err = usb_module_start(p_instance_ctrl->module_number);
        if (FSP_SUCCESS == err)
        {
            /* USB driver initialization */
            usb_pdriver_init(p_instance_ctrl, p_cfg);
            if (NULL == g_usb_pstd_driver.p_configtbl)
            {
                return FSP_ERR_USB_PARAMETER;
            }

            /* Setting MCU(USB interrupt init) register */
            usb_cpu_usbint_init(p_instance_ctrl->module_number, p_cfg);

            if (USB_SPEED_HS == p_cfg->usb_speed)
            {
                hse_utr.ip = p_instance_ctrl->module_number;
                hw_usb_set_hse(&hse_utr);
            }
            else
            {
                (void) hse_utr;
            }

            /* Setting USB relation register  */
            hw_usb_pmodule_init(p_instance_ctrl->module_number);

            if (USB_ATTACH == usb_pstd_chk_vbsts(p_instance_ctrl->module_number))
            {
                hw_usb_set_cnen(p_instance_ctrl->module_number);
                usb_cpu_delay_xms((uint16_t) 10);
                hw_usb_pset_dprpu(p_instance_ctrl->module_number);
            }
        }
#endif                                 /* (USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_REPI */
    }

    if (FSP_SUCCESS == err)
    {
        if (USB_MODE_HOST == p_cfg->usb_mode)
        {
            g_usb_open_class[p_instance_ctrl->module_number] |= (uint16_t) (1 << p_instance_ctrl->type); /* Set USB Open device class */
            if (USB_CLASS_INTERNAL_HCDC == (usb_class_internal_t) p_instance_ctrl->type)
            {
                g_usb_open_class[p_instance_ctrl->module_number] |= (1 << USB_CLASS_INTERNAL_HCDCC);     /* Set USB Open device class */
            }
        }
        else
        {
#if defined(USB_CFG_PCDC_USE)
            g_usb_open_class[p_instance_ctrl->module_number] |= (uint16_t) (1 << USB_CLASS_INTERNAL_PCDC);
            g_usb_open_class[p_instance_ctrl->module_number] |= (uint16_t) (1 << USB_CLASS_INTERNAL_PCDCC);
#endif                                 /* defined(USB_CFG_PCDC_USE) */

#if defined(USB_CFG_PHID_USE)
            g_usb_open_class[p_instance_ctrl->module_number] |= (uint16_t) (1 << USB_CLASS_INTERNAL_PHID);
#endif                                 /* defined(USB_CFG_PHID_USE) */

#if defined(USB_CFG_PMSC_USE)
            g_usb_open_class[p_instance_ctrl->module_number] |= (uint16_t) (1 << USB_CLASS_INTERNAL_PMSC);
#endif                                 /* defined(USB_CFG_PMSC_USE) */

#if defined(USB_CFG_PVND_USE)
            g_usb_open_class[p_instance_ctrl->module_number] |= (uint16_t) (1 << USB_CLASS_INTERNAL_PVND);
#endif                                 /* defined(USB_CFG_PVND_USE) */
        }
    }

    return err;
}

/**************************************************************************//**
 * @brief Terminates power to the USB module specified in argument (p_ctrl).
 * USB0 module stops when USB_IP0 is specified to the member (module),
 * USB1 module stops when USB_IP1 is specified to the member (module).
 *
 * @retval FSP_SUCCESS           Success.
 * @retval FSP_ERR_USB_FAILED    The function could not be completed successfully.
 * @retval FSP_ERR_USB_NOT_OPEN  USB module is not open.
 * @retval FSP_ERR_ASSERTION     Parameter is NULL error.
 * @retval FSP_ERR_USB_PARAMETER Parameter error.
 * @note Do not call this API in the following function.
 * @note (1). Interrupt function.
 * @note (2). Callback function ( for RTOS ).
 ******************************************************************************/
fsp_err_t R_USB_Close (usb_ctrl_t * const p_ctrl)
{
    fsp_err_t ret_code;

    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
    usb_info_t          info;
    uint8_t             ip;
    uint8_t             dev_addr;
    usb_instance_ctrl_t ctrl;
    usb_utr_t           utr;
    uint8_t             class_code = USB_IFCLS_CDC;

    info.class_type = 0;
    info.speed      = 0;
#endif                                 /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */

#if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(USB_NULL != p_ctrl)

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_IP0 != p_instance_ctrl->module_number) && (USB_IP1 != p_instance_ctrl->module_number)),
                     FSP_ERR_USB_PARAMETER)

    if (USB_MODE_HOST == g_usb_usbmode[p_instance_ctrl->module_number])
    {
 #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
        switch ((usb_class_internal_t) p_instance_ctrl->type)
        {
            case USB_CLASS_INTERNAL_HCDC:
            {
                class_code = (uint8_t) USB_IFCLS_CDC;
                break;
            }

            case USB_CLASS_INTERNAL_HHID:
            {
                class_code = (uint8_t) USB_IFCLS_HID;
                break;
            }

            case USB_CLASS_INTERNAL_HMSC:
            {
                class_code = (uint8_t) USB_IFCLS_MAS;
                break;
            }

            case USB_CLASS_INTERNAL_HVND:
            {
                class_code = (uint8_t) USB_IFCLS_VEN;
                break;
            }

            default:
            {
                return FSP_ERR_ASSERTION;
                break;
            }
        }
 #endif                                /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */
    }
#endif                                 /* USB_CFG_PARAM_CHECKING_ENABLE */
#if  USB_IP_EHCI_OHCI == 1
    usb_hstd_ehci_deinit();
    usb_hstd_ohci_deinit();
 #ifdef VECTOR_NUMBER_USB_HI
    R_BSP_IrqDisable((IRQn_Type) VECTOR_NUMBER_USB_HI); /* USBI disable */
 #endif
#endif /* USB_IP_EHCI_OHCI == 1 */
    ret_code = usb_module_stop(p_instance_ctrl->module_number);
    if (FSP_SUCCESS == ret_code)
    {
        is_init[p_instance_ctrl->module_number] = USB_NO;

        if (USB_MODE_HOST == g_usb_usbmode[p_instance_ctrl->module_number])
        {
#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
            utr.ip  = p_instance_ctrl->module_number;
            utr.ipp = usb_hstd_get_usb_ip_adr(utr.ip);

            usb_hstd_driver_release(&utr, class_code);

            /* WAIT_LOOP */
            for (ip = 0; ip < USB_NUM_USBIP; ip++)
            {
                for (dev_addr = 1; dev_addr < (USB_MAXDEVADDR + 1); dev_addr++)
                {
                    ctrl.module_number  = ip;
                    ctrl.device_address = dev_addr;
                    ctrl.type           = p_instance_ctrl->type;
                    R_USB_InfoGet(&ctrl, &info, ctrl.device_address);
                    if ((USB_NULL != info.speed) && (ctrl.type == info.class_type))
                    {
                        usb_hstd_clr_pipe_table(ip, dev_addr);
                    }
                }
            }
#endif                                 /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */
        }
        else
        {
#if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
            usb_pstd_driver_release(); /* Clear the information registered in the structure usb_pcdreg_t. */
            usb_pstd_clr_pipe_table(p_instance_ctrl->module_number);
#endif  /* (USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI */
        }

        g_usb_open_class[p_instance_ctrl->module_number] = 0;

#if defined(USB_CFG_PMSC_USE)
        ret_code = r_usb_pmsc_media_close();
#endif                                 /* defined(USB_CFG_PMSC_USE) */
#if (BSP_CFG_RTOS == 2)
        usb_rtos_delete();
#endif
    }
    else
    {
        ret_code = FSP_ERR_USB_NOT_OPEN;
    }

#if defined(USB_CFG_PMSC_USE)
    g_usb_pmsc_usbip = USB_VALUE_FFH;
#endif                                 /* defined(USB_CFG_PMSC_USE) */

    return ret_code;
}

/**************************************************************************//**
 * @brief Bulk/interrupt data transfer and control data transfer
 *
 * 1. Bulk/interrupt data transfer
 *
 *   Requests USB data read (bulk/interrupt transfer).
 *   The read data is stored in the area specified by argument (p_buf).
 *   After data read is completed, confirm the operation by checking the return value
 *   (USB_STATUS_READ_COMPLETE) of the R_USB_GetEvent function. The received data size is set in member
 *   (size) of the usb_ctrl_t structure. To figure out the size of the data when a read is complete,
 *   check the return value (USB_STATUS_READ_COMPLETE) of the R_USB_GetEvent function, and then
 *   refer to the member (size) of the usb_crtl_t structure.
 *
 * 2. Control data transfer
 *
 *   The R_USB_Read function is used to receive data in the data stage and the
 *   R_USB_Write function is used to send data to the USB host.
 *
 * @retval FSP_SUCCESS           Successfully completed (Data read request completed).
 * @retval FSP_ERR_USB_FAILED    The function could not be completed successfully.
 * @retval FSP_ERR_USB_BUSY      Data receive request already in process for
 *                               USB device with same device address.
 * @retval FSP_ERR_ASSERTION     Parameter is NULL error.
 * @retval FSP_ERR_USB_PARAMETER Parameter error.
 * @note The address specified in the argument p_buf must be 4-byte aligned.
 * @note Do not call this API in the following function.
 * @note (1). Interrupt function.
 * @note (2). Callback function ( for RTOS ).
 ******************************************************************************/
fsp_err_t R_USB_Read (usb_ctrl_t * const p_ctrl, uint8_t * p_buf, uint32_t size, uint8_t destination)
{
    usb_info_t info;
    usb_er_t   err;
    fsp_err_t  result = FSP_ERR_USB_FAILED;

    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

#if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(USB_NULL != p_ctrl)

    if (USB_MODE_PERI == g_usb_usbmode[p_instance_ctrl->module_number])
    {
 #if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
        FSP_ERROR_RETURN(((USB_CLASS_PCDC <= destination) && (destination < USB_CLASS_END)), FSP_ERR_USB_PARAMETER)
 #endif                                /* #if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI) */
    }
    else
    {
 #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
        FSP_ASSERT(destination)
        FSP_ERROR_RETURN(USB_ADDRESS5 >= destination, FSP_ERR_USB_PARAMETER)
 #endif                                /* #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST) */
    }
#endif                                 /* USB_CFG_PARAM_CHECKING_ENABLE */

    if (USB_MODE_PERI == g_usb_usbmode[p_instance_ctrl->module_number])
    {
#if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
        p_instance_ctrl->type = (usb_class_t) (destination & USB_VALUE_7FH);
#endif                                 /* #if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI) */
    }
    else
    {
#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
        p_instance_ctrl->device_address = destination;
#endif                                 /* #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST) */
    }

#if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(!(((USB_NULL == p_buf)) || (USB_NULL == size)))
    FSP_ERROR_RETURN((((uint32_t) p_buf & 0x03) == 0), FSP_ERR_USB_PARAMETER)

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_IP0 != p_instance_ctrl->module_number) && (USB_IP1 != p_instance_ctrl->module_number)),
                     FSP_ERR_USB_PARAMETER)

    FSP_ERROR_RETURN(!((USB_CLASS_INTERNAL_PCDCC == (usb_class_internal_t) p_instance_ctrl->type) ||
                       (USB_CLASS_INTERNAL_PVND == (usb_class_internal_t) p_instance_ctrl->type) ||
                       (USB_CLASS_INTERNAL_HVND == (usb_class_internal_t) p_instance_ctrl->type) ||
                       (USB_CLASS_INTERNAL_HMSC == (usb_class_internal_t) p_instance_ctrl->type) ||
                       (USB_CLASS_INTERNAL_PMSC == (usb_class_internal_t) p_instance_ctrl->type)),
                     FSP_ERR_USB_PARAMETER)

    FSP_ERROR_RETURN(USB_NULL != (g_usb_open_class[p_instance_ctrl->module_number] &
                                  (1 << p_instance_ctrl->type)),
                     FSP_ERR_USB_PARAMETER) /* Check USB Open device class */
#endif  /* USB_CFG_PARAM_CHECKING_ENABLE */

    (void) R_USB_InfoGet(p_instance_ctrl, &info, p_instance_ctrl->device_address);
    if (USB_STATUS_CONFIGURED == info.device_status)
    {
        err = usb_data_read(p_instance_ctrl, p_buf, size);

        if (USB_OK == err)
        {
            result = FSP_SUCCESS;
        }
        else if (USB_QOVR == err)
        {
            result = FSP_ERR_USB_BUSY;
        }
        else
        {
            /* Noting */
        }
    }

    return result;
}

/**************************************************************************//**
 * @brief Bulk/Interrupt data transfer and control data transfer
 *
 * 1. Bulk/Interrupt data transfer
 *
 *   Requests USB data write (bulk/interrupt transfer).
 *   Stores write data in area specified by argument (p_buf).
 *   Set the device class type in usb_ctrl_t structure member (type).
 *   Confirm after data write is completed by checking the return value (USB_STATUS_WRITE_COMPLETE)
 *   of the R_USB_GetEvent function.
 *   To request the transmission of a NULL packet, assign USB_NULL(0) to the third argument (size).
 *
 * 2. Control data transfer
 *
 *   The R_USB_Read function is used to receive data in the data stage and
 *   the R_USB_Write function is used to send data to the USB host.
 *
 * @retval FSP_SUCCESS           Successfully completed. (Data write request completed)
 * @retval FSP_ERR_USB_FAILED    The function could not be completed successfully.
 * @retval FSP_ERR_USB_BUSY      Data write request already in process for
 *                               USB device with same device address.
 * @retval FSP_ERR_ASSERTION     Parameter is NULL error.
 * @retval FSP_ERR_USB_PARAMETER Parameter error.
 * @note The address specified in the argument p_buf must be 4-byte aligned.
 * @note Do not call this API in the following function.
 * @note (1). Interrupt function.
 * @note (2). Callback function ( for RTOS ).
 ******************************************************************************/
fsp_err_t R_USB_Write (usb_ctrl_t * const p_ctrl, uint8_t const * const p_buf, uint32_t size, uint8_t destination)
{
    usb_info_t info;
    usb_er_t   err;
    fsp_err_t  result = FSP_ERR_USB_FAILED;

    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

#if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(USB_NULL != p_ctrl)

    if (USB_MODE_PERI == g_usb_usbmode[p_instance_ctrl->module_number])
    {
 #if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
        FSP_ERROR_RETURN(((USB_CLASS_PCDC <= destination) && (destination < USB_CLASS_END)), FSP_ERR_USB_PARAMETER)
 #endif                                /* #if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI) */
    }
    else
    {
 #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
        FSP_ASSERT(destination)
        FSP_ERROR_RETURN(USB_ADDRESS5 >= destination, FSP_ERR_USB_PARAMETER)
 #endif                                /* #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST) */
    }
#endif                                 /* USB_CFG_PARAM_CHECKING_ENABLE */

    if (USB_MODE_PERI == g_usb_usbmode[p_instance_ctrl->module_number])
    {
#if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
        p_instance_ctrl->type = (usb_class_t) (destination & USB_VALUE_7FH);
#endif                                 /* USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI */
    }
    else
    {
#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
        p_instance_ctrl->device_address = destination;
#endif                                 /* USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */
    }

#if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(!((USB_NULL == p_buf) && (0 != size)))
    FSP_ERROR_RETURN((((uint32_t) p_buf & 0x03) == 0), FSP_ERR_USB_PARAMETER)

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_IP0 != p_instance_ctrl->module_number) && (USB_IP1 != p_instance_ctrl->module_number)),
                     FSP_ERR_USB_PARAMETER)

    FSP_ERROR_RETURN(!((USB_CLASS_INTERNAL_HCDCC == (usb_class_internal_t) p_instance_ctrl->type) ||
                       (USB_CLASS_INTERNAL_PVND == (usb_class_internal_t) p_instance_ctrl->type) ||
                       (USB_CLASS_INTERNAL_HVND == (usb_class_internal_t) p_instance_ctrl->type) ||
                       (USB_CLASS_INTERNAL_HMSC == (usb_class_internal_t) p_instance_ctrl->type) ||
                       (USB_CLASS_INTERNAL_PMSC == (usb_class_internal_t) p_instance_ctrl->type)),
                     FSP_ERR_USB_PARAMETER)

    FSP_ERROR_RETURN(USB_NULL != (g_usb_open_class[p_instance_ctrl->module_number] &
                                  (1 << p_instance_ctrl->type)),
                     FSP_ERR_USB_PARAMETER) /* Check USB Open device class */
#endif  /* USB_CFG_PARAM_CHECKING_ENABLE */

    (void) R_USB_InfoGet(p_instance_ctrl, &info, p_instance_ctrl->device_address);
    if (USB_STATUS_CONFIGURED == info.device_status)
    {
        err = usb_data_write(p_instance_ctrl, p_buf, size);

        if (USB_OK == err)
        {
            result = FSP_SUCCESS;
        }
        else if (USB_QOVR == err)
        {
            result = FSP_ERR_USB_BUSY;
        }
        else
        {
            /* Noting */
        }
    }

    return result;
}

/**************************************************************************//**
 * @brief Requests a data read/write transfer be terminated
 * when a data read/write transfer is being performed.
 *
 * To stop a data read, set USB_TRANSFER_READ as the argument (type); to stop a data write,
 * specify USB_WRITE as the argument (type).
 *
 * @retval FSP_SUCCESS           Successfully completed. (stop completed)
 * @retval FSP_ERR_USB_FAILED    The function could not be completed successfully.
 * @retval FSP_ERR_ASSERTION     Parameter is NULL error.
 * @retval FSP_ERR_USB_BUSY      Stop processing is called multiple times.
 * @retval FSP_ERR_USB_PARAMETER Parameter error.
 * @note Do not call this API in the following function.
 * @note (1). Interrupt function.
 * @note (2). Callback function ( for RTOS ).
 ******************************************************************************/
fsp_err_t R_USB_Stop (usb_ctrl_t * const p_ctrl, usb_transfer_t direction, uint8_t destination)
{
    usb_info_t info;
    usb_er_t   err;
    fsp_err_t  result = FSP_ERR_USB_FAILED;
    info.device_status = 0;

    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

#if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(USB_NULL != p_ctrl)

    if (USB_MODE_PERI == g_usb_usbmode[p_instance_ctrl->module_number])
    {
 #if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
        FSP_ERROR_RETURN(USB_CLASS_END > destination, FSP_ERR_USB_PARAMETER)
 #endif                                /* #if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI) */
    }
    else
    {
 #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
        FSP_ASSERT(destination)
        FSP_ERROR_RETURN(USB_ADDRESS5 >= destination, FSP_ERR_USB_PARAMETER)
 #endif                                /* #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST) */
    }
#endif                                 /* USB_CFG_PARAM_CHECKING_ENABLE */

    if (USB_MODE_PERI == g_usb_usbmode[p_instance_ctrl->module_number])
    {
#if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
        p_instance_ctrl->type = (usb_class_t) (destination & USB_VALUE_7FH);
#endif                                 /* USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI */
    }
    else
    {
#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
        p_instance_ctrl->device_address = destination;
#endif                                 /* USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */
    }

#if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(!((USB_TRANSFER_WRITE != direction) && (USB_TRANSFER_READ != direction)), FSP_ERR_USB_PARAMETER)

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_IP0 != p_instance_ctrl->module_number) && (USB_IP1 != p_instance_ctrl->module_number)),
                     FSP_ERR_USB_PARAMETER)

    FSP_ERROR_RETURN(!((USB_CLASS_INTERNAL_PVND == (usb_class_internal_t) p_instance_ctrl->type) ||
                       (USB_CLASS_INTERNAL_HVND == (usb_class_internal_t) p_instance_ctrl->type) ||
                       (USB_CLASS_INTERNAL_HMSC == (usb_class_internal_t) p_instance_ctrl->type) ||
                       (USB_CLASS_INTERNAL_PMSC == (usb_class_internal_t) p_instance_ctrl->type)),
                     FSP_ERR_USB_PARAMETER)

    FSP_ERROR_RETURN(!(((USB_CLASS_INTERNAL_HCDCC == (usb_class_internal_t) p_instance_ctrl->type) &&
                        (USB_TRANSFER_WRITE == direction)) ||
                       ((USB_CLASS_INTERNAL_PCDCC == (usb_class_internal_t) p_instance_ctrl->type) &&
                        (USB_TRANSFER_READ == direction))),
                     FSP_ERR_USB_PARAMETER)
#endif                                 /* USB_CFG_PARAM_CHECKING_ENABLE */

    (void) R_USB_InfoGet(p_instance_ctrl, &info, p_instance_ctrl->device_address);
    FSP_ERROR_RETURN(USB_STATUS_CONFIGURED == info.device_status, FSP_ERR_USB_FAILED)

    err = usb_data_stop(p_instance_ctrl, direction);

    if (USB_OK == err)
    {
        result = FSP_SUCCESS;
    }
    else if (USB_QOVR == err)
    {
        result = FSP_ERR_USB_BUSY;
    }
    else
    {
        /* Nothing */
    }

    return result;
}

/**************************************************************************//**
 * @brief Sends a SUSPEND signal from the USB module assigned to the member
 * (module) of the usb_crtl_t structure.
 *
 * After the suspend request is completed, confirm the operation with the return value
 * (USB_STATUS_SUSPEND) of the R_USB_EventGet function.
 *
 * @retval FSP_SUCCESS           Successfully completed.
 * @retval FSP_ERR_USB_FAILED    The function could not be completed successfully.
 * @retval FSP_ERR_USB_BUSY      During a suspend request to the specified USB module,
 *                               or when the USB module is already in the suspended state.
 * @retval FSP_ERR_ASSERTION     Parameter is NULL error.
 * @retval FSP_ERR_USB_PARAMETER Parameter error.
 * @note Do not call this API in the following function.
 * @note (1). Interrupt function.
 * @note (2). Callback function ( for RTOS ).
 ******************************************************************************/
fsp_err_t R_USB_Suspend (usb_ctrl_t * const p_ctrl)
{
#if USB_CFG_MODE == USB_CFG_PERI
    FSP_PARAMETER_NOT_USED(p_ctrl);

    return FSP_ERR_USB_FAILED;         /* Support Host only. */
#else /* USB_CFG_MODE == USB_CFG_PERI */
    fsp_err_t ret_code = FSP_SUCCESS;

    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

    FSP_PARAMETER_NOT_USED(*p_instance_ctrl);
 #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
    usb_utr_t  utr;
    usb_info_t info;
    usb_er_t   err;
 #endif                                /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */

    FSP_ERROR_RETURN(USB_MODE_PERI != g_usb_usbmode[p_instance_ctrl->module_number], FSP_ERR_USB_FAILED)

 #if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(USB_NULL != p_ctrl)

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_IP0 != p_instance_ctrl->module_number) && (USB_IP1 != p_instance_ctrl->module_number)),
                     FSP_ERR_USB_PARAMETER)
 #endif                                /* USB_CFG_PARAM_CHECKING_ENABLE */

 #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
    p_instance_ctrl->device_address = USB_DEVICEADDR;

    ret_code = R_USB_InfoGet(p_instance_ctrl, &info, p_instance_ctrl->device_address);
    FSP_ERROR_RETURN(USB_STATUS_CONFIGURED == info.device_status, FSP_ERR_USB_FAILED)

    utr.ip  = p_instance_ctrl->module_number;
    utr.ipp = usb_hstd_get_usb_ip_adr(utr.ip);
  #if (BSP_CFG_RTOS == 0)
    if (USB_NULL != (g_usb_change_device_state[p_instance_ctrl->module_number] & (1 << USB_STATUS_SUSPEND)))
    {
        return FSP_ERR_USB_BUSY;
    }

    err = usb_hstd_change_device_state(&utr,
                                       (usb_cb_t) &usb_hstd_suspend_complete,
                                       USB_DO_GLOBAL_SUSPEND,
                                       USB_DEVICEADDR);

    if (USB_OK == err)
    {
        g_usb_change_device_state[p_instance_ctrl->module_number] |= (1 << USB_STATUS_SUSPEND);
    }
    else
    {
        ret_code = FSP_ERR_USB_FAILED;
    }

  #else                                /* (BSP_CFG_RTOS == 0) */
    if (USB_YES == gs_usb_suspend_ing[p_instance_ctrl->module_number])
    {
        ret_code = FSP_ERR_USB_BUSY;
    }
    else
    {
        gs_usb_suspend_ing[p_instance_ctrl->module_number] = USB_YES;
    }

    err = usb_hstd_change_device_state(&utr,
                                       (usb_cb_t) &usb_hstd_suspend_complete,
                                       USB_DO_GLOBAL_SUSPEND,
                                       USB_DEVICEADDR);

    if (USB_OK != err)
    {
        ret_code = FSP_ERR_USB_FAILED;
    }
    gs_usb_suspend_ing[p_instance_ctrl->module_number] = USB_NO;
  #endif                               /* (BSP_CFG_RTOS == 0) */
 #endif                                /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */

    return ret_code;
#endif                                 /* USB_CFG_MODE == USB_CFG_PERI */
}

/**************************************************************************//**
 * @brief Sends a RESUME signal from the USB module assigned to the
 * member (module) of the usb_ctrl_tstructure.
 *
 * After the resume request is completed, confirm the operation with the return
 * value (USB_STATUS_RESUME) of the R_USB_EventGet function
 *
 * @retval FSP_SUCCESS              Successfully completed.
 * @retval FSP_ERR_USB_FAILED       The function could not be completed successfully.
 * @retval FSP_ERR_USB_BUSY         Resume already requested for same device address.
 *                                  (USB host mode only)
 * @retval FSP_ERR_USB_NOT_SUSPEND  USB device is not in the SUSPEND state.
 * @retval FSP_ERR_ASSERTION        Parameter is NULL error.
 * @retval FSP_ERR_USB_PARAMETER    Parameter error.
 * @note Do not call this API in the following function.
 * @note (1). Interrupt function.
 * @note (2). Callback function ( for RTOS ).
 ******************************************************************************/
fsp_err_t R_USB_Resume (usb_ctrl_t * const p_ctrl)
{
#if USB_CFG_MODE == USB_CFG_PERI
    FSP_PARAMETER_NOT_USED(p_ctrl);

    return FSP_ERR_USB_FAILED;         /* Support Host only. */
#else /* USB_CFG_MODE == USB_CFG_PERI */
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

    usb_utr_t utr;
    usb_er_t  err;

    fsp_err_t  ret_code = FSP_ERR_USB_FAILED;
    usb_info_t info;
    info.device_status = 0;

 #if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(USB_NULL != p_ctrl)

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_IP0 != p_instance_ctrl->module_number) && (USB_IP1 != p_instance_ctrl->module_number)),
                     FSP_ERR_USB_PARAMETER)
    FSP_ERROR_RETURN(USB_MODE_PERI != g_usb_usbmode[p_instance_ctrl->module_number], FSP_ERR_USB_PARAMETER)
 #endif                                /* USB_CFG_PARAM_CHECKING_ENABLE */

    ret_code = R_USB_InfoGet(p_instance_ctrl, &info, p_instance_ctrl->device_address);
    FSP_ERROR_RETURN(USB_STATUS_SUSPEND == info.device_status, FSP_ERR_USB_NOT_SUSPEND)

 #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
    utr.ip  = p_instance_ctrl->module_number;
    utr.ipp = usb_hstd_get_usb_ip_adr(utr.ip);

  #if (BSP_CFG_RTOS == 0)
    if (USB_NULL != (g_usb_change_device_state[p_instance_ctrl->module_number] & (1 << USB_STATUS_RESUME)))
    {
        return FSP_ERR_USB_BUSY;
    }

    err = usb_hstd_change_device_state(&utr,
                                       (usb_cb_t) &usb_hstd_resume_complete,
                                       USB_DO_GLOBAL_RESUME,
                                       p_instance_ctrl->device_address);
    if (USB_OK == err)
    {
        g_usb_change_device_state[p_instance_ctrl->module_number] |= (1 << USB_STATUS_RESUME);
    }
    else
    {
        ret_code = FSP_ERR_USB_FAILED;
    }

  #else                                /* (BSP_CFG_RTOS == 0) */
    if (USB_YES == g_usb_resume_ing[p_instance_ctrl->module_number])
    {
        ret_code = FSP_ERR_USB_BUSY;
    }
    else
    {
        g_usb_resume_ing[p_instance_ctrl->module_number] = USB_YES;
    }

    if (FSP_ERR_USB_BUSY == ret_code)
    {
        return ret_code;
    }

    err = usb_hstd_change_device_state(&utr,
                                       (usb_cb_t) &usb_hstd_resume_complete,
                                       USB_DO_GLOBAL_RESUME,
                                       p_instance_ctrl->device_address);
    if (USB_OK != err)
    {
        ret_code = FSP_ERR_USB_FAILED;
    }
    g_usb_resume_ing[p_instance_ctrl->module_number] = USB_NO;
  #endif                               /* (BSP_CFG_RTOS == 0) */
 #endif                                /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */
    return ret_code;
#endif                                 /* USB_CFG_MODE == USB_CFG_PERI */
}

/**************************************************************************//**
 * @brief Specifies starting or stopping the VBUS supply.
 *
 * @retval FSP_SUCCESS              Successful completion. (VBUS supply start/stop completed)
 * @retval FSP_ERR_USB_FAILED       The function could not be completed successfully.
 * @retval FSP_ERR_ASSERTION        Parameter is NULL error.
 * @retval FSP_ERR_USB_PARAMETER    Parameter error.
 * @note Do not call this API in the following function.
 * @note (1). Interrupt function.
 * @note (2). Callback function ( for RTOS ).
 ******************************************************************************/
fsp_err_t R_USB_VbusSet (usb_ctrl_t * const p_ctrl, uint16_t state)
{
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

#if (USB_CFG_MODE == USB_CFG_PERI)
    FSP_PARAMETER_NOT_USED(state);
    FSP_PARAMETER_NOT_USED(*p_instance_ctrl);

    return FSP_ERR_USB_FAILED;
#else
    usb_utr_t utr;

    FSP_ERROR_RETURN(USB_MODE_PERI != g_usb_usbmode[p_instance_ctrl->module_number], FSP_ERR_USB_FAILED)

 #if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(USB_NULL != p_ctrl)

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_IP0 != p_instance_ctrl->module_number) && (USB_IP1 != p_instance_ctrl->module_number)),
                     FSP_ERR_USB_PARAMETER)
    FSP_ERROR_RETURN(!((USB_ON != state) && (USB_OFF != state)), FSP_ERR_USB_PARAMETER)
 #endif                                /* USB_CFG_PARAM_CHECKING_ENABLE */

    utr.ip  = p_instance_ctrl->module_number;
    utr.ipp = usb_hstd_get_usb_ip_adr(utr.ip);
    FSP_PARAMETER_NOT_USED(state);

    return FSP_SUCCESS;
#endif                                 /* (USB_CFG_MODE == USB_CFG_PERI) */
}

/**************************************************************************//**
 * @brief Obtains completed USB-related events.
 *
 * @retval FSP_SUCCESS              Successful completion. (VBUS supply start/stop completed)
 * @retval FSP_ERR_ASSERTION        Parameter is NULL error.
 * @retval FSP_ERR_USB_FAILED       The function could not be completed successfully.
 * @retval FSP_ERR_USB_PARAMETER    Parameter error.
 ******************************************************************************/
fsp_err_t R_USB_InfoGet (usb_ctrl_t * const p_ctrl, usb_info_t * p_info, uint8_t destination)
{
    fsp_err_t             ret_code        = FSP_SUCCESS;
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;
    usb_utr_t             utr;

#if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
    uint32_t status;
    FSP_PARAMETER_NOT_USED(destination);
#endif                                 /* ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI) */

#if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl)
    FSP_ASSERT(p_info)

    if (USB_MODE_HOST == g_usb_usbmode[p_instance_ctrl->module_number])
    {
 #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
        FSP_ASSERT(destination)
        FSP_ERROR_RETURN(USB_ADDRESS5 >= destination, FSP_ERR_USB_PARAMETER)
 #endif                                /* #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST) */
    }

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_IP0 != p_instance_ctrl->module_number) && (USB_IP1 != p_instance_ctrl->module_number)),
                     FSP_ERR_USB_PARAMETER)
#else                                  /* USB_CFG_PARAM_CHECKING_ENABLE */
    FSP_PARAMETER_NOT_USED(*p_instance_ctrl);
#endif                                 /* USB_CFG_PARAM_CHECKING_ENABLE */

    if (USB_MODE_HOST == g_usb_usbmode[p_instance_ctrl->module_number])
    {
#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
        p_instance_ctrl->device_address = destination;
#endif                                         /* #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST) */
    }

    p_info->device_status = USB_STATUS_DETACH; /* Initialized for warning measures. */

    FSP_ERROR_RETURN(0 != g_usb_open_class[p_instance_ctrl->module_number], FSP_ERR_USB_FAILED)

    utr.ip = p_instance_ctrl->module_number;

    if (USB_MODE_HOST == g_usb_usbmode[p_instance_ctrl->module_number])
    {
#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
        utr.ipp = usb_hstd_get_usb_ip_adr(utr.ip);

        /* Set USB Device class */
        switch (g_usb_hstd_device_info[utr.ip][p_instance_ctrl->device_address][3])
        {
            case USB_IFCLS_CDC:
            {
                p_info->class_type = (uint8_t) USB_CLASS_PCDC;
                break;
            }

            case USB_IFCLS_HID:
            {
                p_info->class_type = (uint8_t) USB_CLASS_PHID;
                break;
            }

            case USB_IFCLS_MAS:
            {
                p_info->class_type = (uint8_t) USB_CLASS_PMSC;
                break;
            }

            case USB_IFCLS_VEN:
            {
                p_info->class_type = (uint8_t) USB_CLASS_PVND;
                break;
            }

            default:
            {
                p_info->class_type = USB_NULL;
                break;
            }
        }

        /* Set USB connect speed */
        switch (g_usb_hstd_device_info[utr.ip][p_instance_ctrl->device_address][4])
        {
            case USB_NOCONNECT:
            {
                p_info->speed = USB_NULL;
                break;
            }

            case USB_HSCONNECT:
            {
                p_info->speed = USB_SPEED_HS;
                break;
            }

            case USB_FSCONNECT:
            {
                p_info->speed = USB_SPEED_FS;
                break;
            }

            case USB_LSCONNECT:
            {
                p_info->speed = USB_SPEED_LS;
                break;
            }

            default:
            {
                p_info->speed = USB_NULL;
                break;
            }
        }

        /* Set USB device state */
        switch (g_usb_hstd_device_info[utr.ip][p_instance_ctrl->device_address][1])
        {
            case USB_POWERED:          /* Power state  */
            {
                p_info->device_status = USB_STATUS_POWERED;
                break;
            }

            case USB_DEFAULT:          /* Default state  */
            {
                p_info->device_status = USB_STATUS_DEFAULT;
                break;
            }

            case USB_ADDRESS:          /* Address state  */
            {
                p_info->device_status = USB_STATUS_ADDRESS;
                break;
            }

            case USB_CONFIGURED:       /* Configured state  */
            {
                p_info->device_status = USB_STATUS_CONFIGURED;
                break;
            }

            case USB_SUSPENDED:        /* Suspend state */
            {
                p_info->device_status = USB_STATUS_SUSPEND;
                break;
            }

            case USB_DETACHED:         /* Disconnect(VBUSon) state */
            {
                p_info->device_status = USB_STATUS_DETACH;
                break;
            }

            default:                   /* Error */
            {
                p_info->device_status = USB_NULL;
                break;
            }
        }

        /* Set USB Peri BC port state */
 #if USB_CFG_BC == USB_CFG_ENABLE
        if (USB_DEVICEADDR == p_instance_ctrl->device_address) /* Check Root port address */
        {
            if (USB_BC_STATE_CDP == g_usb_hstd_bc[utr.ip].state)
            {
                p_info->bcport = USB_BCPORT_CDP;
            }
            else
            {
                p_info->bcport = USB_BCPORT_SDP; /* USB_SDP/USB_CDP/USB_DCP */
            }
        }
        else
        {
            p_info->bcport = USB_BCPORT_SDP; /* USB_SDP/USB_CDP/USB_DCP */
        }

 #else  /* #if USB_CFG_BC == USB_CFG_ENABLE */
        p_info->bcport = USB_BCPORT_SDP;     /* USB_SDP/USB_CDP/USB_DCP */
 #endif /* #if USB_CFG_BC == USB_CFG_ENABLE */
#endif  /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */
    }
    else
    {
#if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
        p_info->class_type = USB_NULL; /* Device class */
        switch (usb_cstd_port_speed(&utr))
        {
            case USB_NOCONNECT:
            {
                p_info->speed = USB_NULL;
                break;
            }

            case USB_HSCONNECT:
            {
                p_info->speed = USB_SPEED_HS;
                break;
            }

            case USB_FSCONNECT:
            {
                p_info->speed = USB_SPEED_FS;
                break;
            }

            case USB_LSCONNECT:
            {
                p_info->speed = USB_SPEED_LS;
                break;
            }

            default:
            {
                p_info->speed = USB_NULL;
                break;
            }
        }

        status = hw_usb_read_intsts(p_instance_ctrl->module_number);
        switch ((uint16_t) (status & USB_DVSQ))
        {
            case USB_DS_POWR:          /* Power state  */
            {
                p_info->device_status = USB_STATUS_DETACH;
                break;
            }

            case USB_DS_DFLT:          /* Default state  */
            {
                p_info->device_status = USB_STATUS_DEFAULT;
                break;
            }

            case USB_DS_ADDS:          /* Address state  */
            {
                p_info->device_status = USB_STATUS_ADDRESS;
                break;
            }

            case USB_DS_CNFG:          /* Configured state  */
            {
                p_info->device_status = USB_STATUS_CONFIGURED;
                break;
            }

            case USB_DS_SPD_POWR:      /* Power suspend state */
            case USB_DS_SPD_DFLT:      /* Default suspend state */
            case USB_DS_SPD_ADDR:      /* Address suspend state */
            case USB_DS_SPD_CNFG:      /* Configured Suspend state */
            {
                p_info->device_status = USB_STATUS_SUSPEND;
                break;
            }

            default:                   /* Error */
            {
                break;                 /* p_info->device_status = USB_STS_ERROR; */
            }
        }

 #if USB_CFG_BC == USB_CFG_ENABLE
        p_info->bcport = (uint8_t) g_usb_bc_detect; /* USB_SDP/USB_CDP/USB_DCP */
 #else  /* USB_CFG_BC == USB_CFG_ENABLE */
        p_info->bcport = USB_BCPORT_SDP;            /* USB_SDP */
 #endif /* USB_CFG_BC == USB_CFG_ENABLE */
        ret_code = FSP_SUCCESS;
#endif  /* (USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI */
    }

    return ret_code;
}

/**************************************************************************//**
 * @brief Requests a data read (bulk/interrupt transfer) via the pipe specified in the argument.
 *
 * The read data is stored in the area specified in the argument (p_buf).
 * After the data read is completed, confirm the operation with the R_USB_GetEvent function
 * return value(USB_STATUS_READ_COMPLETE).
 * To figure out the size of the data when a read is complete, check the return
 * value (USB_STATUS_READ_COMPLETE) of the R_USB_GetEvent function, and then
 * refer to the member (size) of the usb_crtl_t structure.
 *
 * @retval FSP_SUCCESS              Successfully completed.
 * @retval FSP_ERR_USB_BUSY         Specified pipe now handling data receive/send request.
 * @retval FSP_ERR_USB_FAILED       The function could not be completed successfully.
 * @retval FSP_ERR_ASSERTION        Parameter is NULL error.
 * @retval FSP_ERR_USB_PARAMETER    Parameter error.
 * @note The address specified in the argument p_buf must be 4-byte aligned.
 * @note Do not call this API in the following function.
 * @note (1). Interrupt function.
 * @note (2). Callback function ( for RTOS ).
 ******************************************************************************/
fsp_err_t R_USB_PipeRead (usb_ctrl_t * const p_ctrl, uint8_t * p_buf, uint32_t size, uint8_t pipe_number)
{
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;
    uint8_t               pipe;

#if !defined(USB_CFG_HVND_USE) && !defined(USB_CFG_PVND_USE)
    FSP_PARAMETER_NOT_USED(*p_instance_ctrl);
    FSP_PARAMETER_NOT_USED(*p_buf);
    FSP_PARAMETER_NOT_USED(size);
    FSP_PARAMETER_NOT_USED(pipe_number);
    FSP_PARAMETER_NOT_USED(pipe);

    return FSP_ERR_USB_FAILED;
#else                                  /* !defined(USB_CFG_HVND_USE) && !defined(USB_CFG_PVND_USE) */
    fsp_err_t   ret_code = FSP_ERR_USB_FAILED;
    usb_utr_t * p_tran_data;
 #if (BSP_CFG_RTOS == 2)
    usb_utr_t tran_data;
 #endif                                /* (BSP_CFG_RTOS == 2) */

    usb_er_t   err;
    usb_info_t info;

 #if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl)
 #endif                                /* USB_CFG_PARAM_CHECKING_ENABLE */

 #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
    pipe = (uint8_t) R_USB_HstdGetPipeID(p_instance_ctrl->device_address, pipe_number);
    p_instance_ctrl->pipe = pipe;
 #else
    p_instance_ctrl->pipe = pipe_number;
 #endif

 #if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN((((USB_PIPE0 != p_instance_ctrl->pipe)) || (USB_MAXPIPE_NUM < p_instance_ctrl->pipe)),
                     FSP_ERR_USB_PARAMETER)

    FSP_ASSERT(!((USB_NULL == p_buf) || (USB_NULL == size)))
    FSP_ERROR_RETURN((((uint32_t) p_buf & 0x03) == 0), FSP_ERR_USB_PARAMETER)

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_IP0 != p_instance_ctrl->module_number) && (USB_IP1 != p_instance_ctrl->module_number) &&
                       (USB_MODE_HOST == g_usb_usbmode[p_instance_ctrl->module_number])),
                     FSP_ERR_USB_PARAMETER)

    FSP_ERROR_RETURN(USB_NULL != (g_usb_open_class[p_instance_ctrl->module_number] &
                                  (1 << p_instance_ctrl->type)),
                     FSP_ERR_USB_PARAMETER) /* Check USB Open device class */
 #endif /* USB_CFG_PARAM_CHECKING_ENABLE */

    ret_code = R_USB_InfoGet(p_instance_ctrl, &info, p_instance_ctrl->device_address);
    if (USB_STATUS_CONFIGURED == info.device_status)
    {
        /* PIPE Transfer set */
        if (USB_MODE_HOST == g_usb_usbmode[p_instance_ctrl->module_number])
        {
 #if defined(USB_CFG_HVND_USE)
  #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
            p_tran_data = (usb_utr_t *) &g_usb_hdata[p_instance_ctrl->module_number][p_instance_ctrl->pipe];

            p_tran_data->ip           = p_instance_ctrl->module_number;
            p_tran_data->ipp          = usb_hstd_get_usb_ip_adr(p_tran_data->ip);
            p_tran_data->keyword      = p_instance_ctrl->pipe;  /* Pipe No */
            p_tran_data->p_tranadr    = p_buf;                  /* Data address */
            p_tran_data->tranlen      = size;                   /* Data Size */
            p_tran_data->p_setup      = 0;
            p_tran_data->complete     = usb_hvnd_read_complete; /* Callback function */
            p_tran_data->segment      = USB_TRAN_END;
            p_tran_data->read_req_len = size;                   /* Data Size */

            err = usb_hstd_transfer_start(p_tran_data);         /* USB Transfer Start */
            if (USB_OK == err)
            {
                ret_code = FSP_SUCCESS;
            }
            else if (USB_QOVR == err)
            {
                ret_code = FSP_ERR_USB_BUSY;
            }
            else
            {
            }
  #endif                               /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */
 #endif                                /* #if defined(USB_CFG_HVND_USE) */
        }
        else
        {
 #if defined(USB_CFG_PVND_USE)
  #if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
   #if (BSP_CFG_RTOS == 2)
            p_tran_data = (usb_utr_t *) &tran_data;
   #else                                                                    /* (BSP_CFG_RTOS == 2) */
            p_tran_data = (usb_utr_t *) &g_usb_pdata[p_instance_ctrl->pipe];
   #endif /* (BSP_CFG_RTOS == 2) */

            p_tran_data->ip           = p_instance_ctrl->module_number;     /* USB Module Number */
            p_tran_data->keyword      = p_instance_ctrl->pipe;              /* Pipe No */
            p_tran_data->p_tranadr    = p_buf;                              /* Data address */
            p_tran_data->tranlen      = size;                               /* Data Size */
            p_tran_data->complete     = (usb_cb_t) &usb_pvnd_read_complete; /* Callback function */
            p_tran_data->read_req_len = size;                               /* Data Size */
            err = usb_pstd_transfer_start(p_tran_data);                     /* USB Transfer Start */
            if (USB_OK == err)
            {
                ret_code = FSP_SUCCESS;
            }
            else if (USB_QOVR == err)
            {
                ret_code = FSP_ERR_USB_BUSY;
            }
            else
            {
            }
  #endif                               /* (USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI */
 #endif                                /* defined(USB_CFG_PVND_USE) */
        }
    }
    return ret_code;
#endif  /* !defined(USB_CFG_HVND_USE) && !defined(USB_CFG_PVND_USE) */
}

/**************************************************************************//**
 * @brief Requests a data write (bulk/interrupt transfer).
 *
 * The write data is stored in the area specified in the argument (p_buf).
 * After data write is completed, confirm the operation with the return value
 * (USB_STATUS_WRITE_COMPLETE) of the EventGet function.
 * To request the transmission of a NULL packet, assign USB_NULL (0) to the third argument (size).
 *
 * @retval FSP_SUCCESS              Successfully completed.
 * @retval FSP_ERR_USB_BUSY         Specified pipe now handling data receive/send request.
 * @retval FSP_ERR_USB_FAILED       The function could not be completed successfully.
 * @retval FSP_ERR_ASSERTION        Parameter is NULL error.
 * @retval FSP_ERR_USB_PARAMETER    Parameter error.
 * @note The address specified in the argument p_buf must be 4-byte aligned.
 * @note Do not call this API in the following function.
 * @note (1). Interrupt function.
 * @note (2). Callback function ( for RTOS ).
 ******************************************************************************/
fsp_err_t R_USB_PipeWrite (usb_ctrl_t * const p_ctrl, uint8_t * p_buf, uint32_t size, uint8_t pipe_number)
{
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;
    uint8_t               pipe;

#if !defined(USB_CFG_HVND_USE) && !defined(USB_CFG_PVND_USE)
    FSP_PARAMETER_NOT_USED(*p_instance_ctrl);
    FSP_PARAMETER_NOT_USED(*p_buf);
    FSP_PARAMETER_NOT_USED(size);
    FSP_PARAMETER_NOT_USED(pipe_number);
    FSP_PARAMETER_NOT_USED(pipe);

    return FSP_ERR_USB_FAILED;
#else
    usb_er_t    err;
    fsp_err_t   ret_code;
    usb_info_t  info;
    usb_utr_t * p_tran_data;
 #if (BSP_CFG_RTOS == 2)
    usb_utr_t tran_data;
 #endif                                /* (BSP_CFG_RTOS == 2) */

 #if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl)
    FSP_ERROR_RETURN((((uint32_t) p_buf & 0x03) == 0), FSP_ERR_USB_PARAMETER)
 #endif                                /* USB_CFG_PARAM_CHECKING_ENABLE */

 #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
    pipe = (uint8_t) R_USB_HstdGetPipeID(p_instance_ctrl->device_address, pipe_number);
    p_instance_ctrl->pipe = pipe;
 #else
    p_instance_ctrl->pipe = pipe_number;
 #endif

 #if USB_CFG_PARAM_CHECKING_ENABLE

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_IP0 != p_instance_ctrl->module_number) && (USB_IP1 != p_instance_ctrl->module_number)),
                     FSP_ERR_USB_PARAMETER)

    FSP_ERROR_RETURN((((USB_NULL != p_buf) || (USB_PIPE0 != p_instance_ctrl->pipe)) ||
                      (USB_MAXPIPE_NUM > p_instance_ctrl->pipe)),
                     FSP_ERR_USB_PARAMETER)

    if (USB_MODE_PERI == g_usb_usbmode[p_instance_ctrl->module_number])
    {
  #if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
        FSP_ASSERT((USB_NULL != p_buf) && (USB_NULL == size))
  #endif                                    /* (USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI */
    }
    FSP_ERROR_RETURN(USB_NULL == (g_usb_open_class[p_instance_ctrl->module_number] & (1 << p_instance_ctrl->type)),
                     FSP_ERR_USB_PARAMETER) /* Check USB Open device class */
 #endif                                     /* USB_CFG_PARAM_CHECKING_ENABLE */

    ret_code = R_USB_InfoGet(p_instance_ctrl, &info, p_instance_ctrl->device_address);
    if (USB_STATUS_CONFIGURED == info.device_status)
    {
        /* PIPE Transfer set */
        if (USB_MODE_HOST == g_usb_usbmode[p_instance_ctrl->module_number])
        {
 #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
  #if defined(USB_CFG_HVND_USE)
            p_tran_data = (usb_utr_t *) &g_usb_hdata[p_instance_ctrl->module_number][p_instance_ctrl->pipe];

            p_tran_data->ip        = p_instance_ctrl->module_number;
            p_tran_data->ipp       = usb_hstd_get_usb_ip_adr((uint8_t) p_instance_ctrl->module_number);
            p_tran_data->keyword   = p_instance_ctrl->pipe;   /* Pipe No */
            p_tran_data->p_tranadr = p_buf;                   /* Data address */
            p_tran_data->tranlen   = size;                    /* Data Size */
            p_tran_data->complete  = usb_hvnd_write_complete; /* Callback function */
            p_tran_data->segment   = USB_TRAN_END;
            err = usb_hstd_transfer_start(p_tran_data);
            if (USB_OK == err)
            {
                ret_code = FSP_SUCCESS;
            }
            else if (USB_QOVR == err)
            {
                ret_code = FSP_ERR_USB_BUSY;
            }
            else
            {
            }
  #endif                               /* defined(USB_CFG_HVND_USE) */
 #endif                                /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */
        }
        else
        {
 #if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
  #if defined(USB_CFG_PVND_USE)
   #if (BSP_CFG_RTOS == 2)
            p_tran_data = (usb_utr_t *) &tran_data;
   #else                                                             /* (BSP_CFG_RTOS == 2) */
            p_tran_data = (usb_utr_t *) &g_usb_pdata[p_instance_ctrl->pipe];
   #endif /* (BSP_CFG_RTOS == 2) */

            p_tran_data->ip        = p_instance_ctrl->module_number; /* USB Module Number */
            p_tran_data->keyword   = p_instance_ctrl->pipe;          /* Pipe No */
            p_tran_data->p_tranadr = p_buf;                          /* Data address */
            p_tran_data->tranlen   = size;                           /* Data Size */
            p_tran_data->complete  = usb_pvnd_write_complete;        /* Callback function */
            err = usb_pstd_transfer_start(p_tran_data);

            if (USB_OK == err)
            {
                ret_code = FSP_SUCCESS;
            }
            else if (USB_QOVR == err)
            {
                ret_code = FSP_ERR_USB_BUSY;
            }
            else
            {
            }
  #endif                               /* defined(USB_CFG_PVND_USE) */
 #endif                                /* (USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI */
        }
    }
    return ret_code;
#endif /* #if !defined(USB_CFG_HVND_USE) && !defined(USB_CFG_PVND_USE) */
}

/**************************************************************************//**
 * @brief Terminates a data read/write operation.
 *
 * @retval FSP_SUCCESS              Successfully completed. (Stop request completed)
 * @retval FSP_ERR_USB_FAILED       The function could not be completed successfully.
 * @retval FSP_ERR_ASSERTION        Parameter is NULL error.
 * @retval FSP_ERR_USB_PARAMETER    Parameter error.
 * @note Do not call this API in the following function.
 * @note (1). Interrupt function.
 * @note (2). Callback function ( for RTOS ).
 ******************************************************************************/
fsp_err_t R_USB_PipeStop (usb_ctrl_t * const p_ctrl, uint8_t pipe_number)
{
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

#if !defined(USB_CFG_HVND_USE) && !defined(USB_CFG_PVND_USE)
    FSP_PARAMETER_NOT_USED(*p_instance_ctrl);
    FSP_PARAMETER_NOT_USED(pipe_number);

    return FSP_ERR_USB_FAILED;
#else
    usb_er_t   err      = FSP_ERR_USB_FAILED;
    fsp_err_t  ret_code = FSP_ERR_USB_FAILED;
    usb_info_t info;
    usb_utr_t  utr;
    utr.ip = p_instance_ctrl->module_number;

 #if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl)
 #endif                                /* USB_CFG_PARAM_CHECKING_ENABLE */

 #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
    if (USB_MODE_HOST == g_usb_usbmode[p_instance_ctrl->module_number])
    {
        utr.ipp = usb_hstd_get_usb_ip_adr(utr.ip);
    }
 #endif                                /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */
    p_instance_ctrl->pipe = pipe_number;

 #if USB_CFG_PARAM_CHECKING_ENABLE

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_IP0 != p_instance_ctrl->module_number) && (USB_IP1 != p_instance_ctrl->module_number)),
                     FSP_ERR_USB_PARAMETER)

    FSP_ERROR_RETURN(USB_PIPE0 != p_instance_ctrl->pipe, FSP_ERR_USB_PARAMETER)

    FSP_ERROR_RETURN(USB_MAXPIPE_NUM > p_instance_ctrl->pipe, FSP_ERR_USB_PARAMETER)

    FSP_ERROR_RETURN(USB_NULL != (g_usb_open_class[p_instance_ctrl->module_number] & (1 << p_instance_ctrl->type)),
                     FSP_ERR_USB_PARAMETER) /* Check USB Open device class */
 #endif /* USB_CFG_PARAM_CHECKING_ENABLE */

    err = R_USB_InfoGet(p_instance_ctrl, &info, p_instance_ctrl->device_address);
    FSP_ERROR_RETURN(USB_STATUS_CONFIGURED == info.device_status, FSP_ERR_USB_FAILED)

    if (USB_MODE_HOST == g_usb_usbmode[p_instance_ctrl->module_number])
    {
 #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
        err = usb_hstd_transfer_end(&utr, p_instance_ctrl->pipe, (uint16_t) USB_DATA_STOP);
 #endif                                /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */
    }
    else
    {
 #if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
        err = usb_pstd_transfer_end(&utr, p_instance_ctrl->pipe);
 #endif                                /* (USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI */
    }

    if (USB_OK == err)
    {
        ret_code = FSP_SUCCESS;
    }
    return ret_code;
#endif                                 /* !defined(USB_CFG_HVND_USE) && !defined(USB_CFG_PVND_USE) */
}

/**************************************************************************//**
 * @brief Gets the selected pipe number (number of the pipe that has completed initalization) via bit map information.
 *
 * The bit map information is stored in the area specified in argument (p_pipe).
 * Based on the information (module member and address member) assigned to the usb_ctrl_t structure,
 * obtains the PIPE information of that USB device.
 *
 * @retval FSP_SUCCESS              Successfully completed.
 * @retval FSP_ERR_USB_FAILED       The function could not be completed successfully.
 * @retval FSP_ERR_ASSERTION        Parameter is NULL error.
 * @retval FSP_ERR_USB_PARAMETER    Parameter error.
 ******************************************************************************/
fsp_err_t R_USB_UsedPipesGet (usb_ctrl_t * const p_ctrl, uint16_t * p_pipe, uint8_t destination)
{
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

    usb_info_t info;
    uint32_t   pipe_no;

    info.device_status = 0;

    FSP_PARAMETER_NOT_USED(*p_instance_ctrl);
#if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
    FSP_PARAMETER_NOT_USED(destination);
#endif                                 /* ( (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST ) */

#if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(!((USB_NULL == p_instance_ctrl) || (USB_NULL == p_pipe)))

    if (USB_MODE_HOST == g_usb_usbmode[p_instance_ctrl->module_number])
    {
 #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
        FSP_ASSERT(destination)
        FSP_ERROR_RETURN(USB_ADDRESS5 >= destination, FSP_ERR_USB_PARAMETER)
 #endif                                /* #if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST) */
    }

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_IP0 != p_instance_ctrl->module_number) && (USB_IP1 != p_instance_ctrl->module_number)),
                     FSP_ERR_USB_PARAMETER)

 #if defined(BSP_BOARD_GROUP_RA2A1)
    FSP_ERROR_RETURN(USB_IP1 != p_instance_ctrl->module_number, FSP_ERR_USB_PARAMETER)
 #endif                                /* defined(BSP_BOARD_GROUP_RA2A1)  */
#endif                                 /* USB_CFG_PARAM_CHECKING_ENABLE */

    if (USB_MODE_HOST == g_usb_usbmode[p_instance_ctrl->module_number])
    {
#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
        p_instance_ctrl->device_address = destination;
#endif                                 /* ( (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST ) */
    }

    R_USB_InfoGet(p_instance_ctrl, &info, p_instance_ctrl->device_address);
    FSP_ERROR_RETURN(USB_STATUS_CONFIGURED == info.device_status, FSP_ERR_USB_FAILED)

    /* Get PIPE Number from Endpoint address */
    * p_pipe = ((uint16_t) 1 << USB_PIPE0);
    if (USB_MODE_HOST == g_usb_usbmode[p_instance_ctrl->module_number])
    {
#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
        for (pipe_no = USB_MIN_PIPE_NO; pipe_no < (USB_MAX_PIPE_NO + 1); pipe_no++)
        {
            if (USB_TRUE == g_usb_pipe_table[p_instance_ctrl->module_number][pipe_no].use_flag)
            {
                if ((((uint16_t) p_instance_ctrl->device_address) << USB_DEVADDRBIT) ==
                    (uint16_t) (g_usb_pipe_table[p_instance_ctrl->module_number][pipe_no].pipe_maxp & USB_DEVSEL))
                {
                    (*p_pipe) = (uint16_t) ((*p_pipe) | (uint16_t) 1 << pipe_no);
                }
            }
        }
#endif                                 /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */
    }
    else
    {
#if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
        for (pipe_no = USB_MIN_PIPE_NO; pipe_no < (USB_MAX_PIPE_NO + 1); pipe_no++)
        {
            if (USB_TRUE == g_usb_pipe_table[p_instance_ctrl->module_number][pipe_no].use_flag)
            {
                (*p_pipe) = (uint16_t) ((*p_pipe) | (uint16_t) (1 << pipe_no));
            }
        }
#endif                                 /* (USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI */
    }

    return FSP_SUCCESS;
}

/**************************************************************************//**
 * @brief Gets the following pipe information regarding the pipe specified in the
 * argument (p_ctrl) member (pipe): endpoint number, transfer type,
 * transfer direction and maximum packet size.
 *
 * The obtained pipe information is stored in the area specified in the argument (p_info).
 *
 * @retval FSP_SUCCESS              Successfully completed.
 * @retval FSP_ERR_USB_FAILED       The function could not be completed successfully.
 * @retval FSP_ERR_ASSERTION        Parameter is NULL error.
 * @retval FSP_ERR_USB_PARAMETER    Parameter error.
 ******************************************************************************/
fsp_err_t R_USB_PipeInfoGet (usb_ctrl_t * const p_ctrl, usb_pipe_t * p_info, uint8_t pipe_number)
{
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

    usb_info_t info;
    info.device_status = 0;
    uint32_t  pipe_type = 0;
    fsp_err_t result    = FSP_ERR_ASSERTION;
    usb_utr_t utr;

    uint16_t i = 0;

#if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl)
    FSP_ASSERT(p_info)
    FSP_ASSERT(pipe_number)
#endif                                 /* USB_CFG_PARAM_CHECKING_ENABLE */

    p_instance_ctrl->pipe = pipe_number;

#if USB_CFG_PARAM_CHECKING_ENABLE

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_IP0 != p_instance_ctrl->module_number) && (USB_IP1 != p_instance_ctrl->module_number)),
                     FSP_ERR_USB_PARAMETER)

    FSP_ERROR_RETURN(!(USB_MAXPIPE_NUM < p_instance_ctrl->pipe), FSP_ERR_USB_PARAMETER)
#endif                                 /* USB_CFG_PARAM_CHECKING_ENABLE */

    utr.ip = p_instance_ctrl->module_number;
    if (USB_MODE_HOST == g_usb_usbmode[p_instance_ctrl->module_number])
    {
#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
        utr.ipp = usb_hstd_get_usb_ip_adr(utr.ip);
#endif                                 /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */
    }

    R_USB_InfoGet(p_instance_ctrl, &info, p_instance_ctrl->device_address);
    FSP_ERROR_RETURN(USB_STATUS_CONFIGURED == info.device_status, FSP_ERR_USB_FAILED)

    if (USB_MODE_HOST == g_usb_usbmode[p_instance_ctrl->module_number])
    {
#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
        for (i = 0; i < USB_VALUE_32; i++)
        {
            if (p_instance_ctrl->pipe != g_usb_hstd_pipe[i].epnum)
            {
                pipe_type = 0;
            }
            else
            {
                p_info->endpoint = g_usb_hstd_pipe[i].direction;
                pipe_type        = g_usb_hstd_pipe[i].type;
                break;
            }
        }

        switch (pipe_type)
        {
            case USB_EP_ISO:
            {
                p_info->transfer_type = USB_TRANSFER_TYPE_ISO; /* Set Isochronous */
                break;
            }

            case USB_EP_BULK:
            {
                p_info->transfer_type = USB_TRANSFER_TYPE_BULK; /* Set Bulk */
                break;
            }

            case USB_EP_INT:
            {
                p_info->transfer_type = USB_TRANSFER_TYPE_INT; /* Set Interrupt */
                break;
            }

            default:
            {
                result = FSP_ERR_USB_FAILED;
                break;
            }
        }

        if (FSP_ERR_USB_FAILED != result)
        {
            p_info->maxpacketsize = usb_cstd_get_maxpacket_size(&utr, p_instance_ctrl->pipe); /* Set Max packet size */
            result                = FSP_SUCCESS;
        }
#endif  /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */
    }
    else
    {
#if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)

        /* Get PIPE Number from Endpoint address */
        p_info->endpoint =
            (uint8_t) (g_usb_pipe_table[p_instance_ctrl->module_number][p_instance_ctrl->pipe].pipe_cfg &
                       USB_EPNUMFIELD);                                                                        /* Set EP num. */
        if (USB_DIR_P_IN ==
            (g_usb_pipe_table[p_instance_ctrl->module_number][p_instance_ctrl->pipe].pipe_cfg & USB_DIRFIELD)) /* Check dir */
        {
            p_info->endpoint |= USB_EP_DIR_IN;                                                                 /* Set DIR IN */
        }

        pipe_type = usb_cstd_get_pipe_type(&utr, p_instance_ctrl->pipe);

        switch (pipe_type)
        {
            case USB_TYPFIELD_ISO:
            {
                p_info->transfer_type = USB_TRANSFER_TYPE_ISO; /* Set Isochronous */
                break;
            }

            case USB_TYPFIELD_BULK:
            {
                p_info->transfer_type = USB_TRANSFER_TYPE_BULK; /* Set Bulk */
                break;
            }

            case USB_TYPFIELD_INT:
            {
                p_info->transfer_type = USB_TRANSFER_TYPE_INT; /* Set Interrupt */
                break;
            }

            default:
            {
                result = FSP_ERR_USB_FAILED;
                break;
            }
        }

        if (FSP_ERR_USB_FAILED != result)
        {
            p_info->maxpacketsize = usb_cstd_get_maxpacket_size(&utr, p_instance_ctrl->pipe); /* Set Max packet size */
            result                = FSP_SUCCESS;
        }
        FSP_PARAMETER_NOT_USED(i);
#endif  /* (USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI */
    }

    return result;
}

/**************************************************************************//**
 * @brief This API enables or disables pull-up of D+/D- line.
 *
 * @retval FSP_SUCCESS              Successful completion. (Pull-up enable/disable setting completed)
 * @retval FSP_ERR_USB_FAILED       The function could not be completed successfully.
 * @retval FSP_ERR_ASSERTION        Parameter is NULL error.
 * @retval FSP_ERR_USB_PARAMETER    Parameter error.
 * @note Do not call this API in the following function.
 * @note (1). Interrupt function.
 * @note (2). Callback function ( for RTOS ).
 ******************************************************************************/
fsp_err_t R_USB_PullUp (usb_ctrl_t * const p_ctrl, uint8_t state)
{
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

#if (USB_CFG_MODE == USB_CFG_HOST)
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
    FSP_PARAMETER_NOT_USED(state);

    return FSP_ERR_USB_FAILED;
#else                                  /* USB_CFG_MODE == USB_CFG_HOST */
 #if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl)

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_ON != state) && (USB_OFF != state)), FSP_ERR_USB_PARAMETER)
 #endif                                                                                                     /* #if USB_CFG_PARAM_CHECKING_ENABLE */

    FSP_ERROR_RETURN(!(USB_MODE_HOST == g_usb_usbmode[p_instance_ctrl->module_number]), FSP_ERR_USB_FAILED) /* Support Peri only. */

    hw_usb_pcontrol_dprpu(p_instance_ctrl->module_number, state);

    return FSP_SUCCESS;
#endif                                 /* USB_CFG_MODE == USB_CFG_HOST */
} /* End of function R_USB_PullUp */

/**************************************************************************//**
 * @brief Performs settings and transmission processing when transmitting a setup packet.
 *
 * @retval FSP_SUCCESS              Successful completion.
 * @retval FSP_ERR_USB_FAILED       The function could not be completed successfully.
 * @retval FSP_ERR_ASSERTION        Parameter is NULL error.
 * @retval FSP_ERR_USB_PARAMETER    Parameter error.
 * @retval FSP_ERR_USB_BUSY         Specified pipe now handling data receive/send request.
 * @note The address specified in the argument p_buf must be 4-byte aligned.
 * @note Do not call this API in the following function.
 * @note (1). Interrupt function.
 * @note (2). Callback function ( for RTOS ).
 ******************************************************************************/
fsp_err_t R_USB_HostControlTransfer (usb_ctrl_t * const p_ctrl,
                                     usb_setup_t      * p_setup,
                                     uint8_t          * p_buf,
                                     uint8_t            device_address)
{
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

    usb_er_t  err    = USB_ERROR;
    fsp_err_t result = FSP_ERR_USB_FAILED;

#if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl)
    FSP_ASSERT(p_setup)
    FSP_ASSERT(!((USB_NULL == p_buf) && (0 != p_setup->request_length)))
    FSP_ASSERT(device_address)
    FSP_ERROR_RETURN((((uint32_t) p_buf & 0x03) == 0), FSP_ERR_USB_PARAMETER)

    FSP_ERROR_RETURN(USB_MAXDEVADDR >= device_address, FSP_ERR_USB_PARAMETER)
#endif                                 /* USB_CFG_PARAM_CHECKING_ENABLE */

    p_instance_ctrl->device_address       = device_address;
    p_instance_ctrl->setup.request_type   = p_setup->request_type;
    p_instance_ctrl->setup.request_value  = p_setup->request_value;
    p_instance_ctrl->setup.request_index  = p_setup->request_index;
    p_instance_ctrl->setup.request_length = p_setup->request_length;

    if ((p_instance_ctrl->setup.request_type & USB_HOST_TO_DEV) == USB_HOST_TO_DEV)
    {
        err = usb_ctrl_read(p_instance_ctrl, p_buf, p_instance_ctrl->setup.request_length);  /* Request Control transfer */
    }
    else
    {
        err = usb_ctrl_write(p_instance_ctrl, p_buf, p_instance_ctrl->setup.request_length); /* Request Control transfer */
    }

    if (err == USB_QOVR)
    {
        result = FSP_ERR_USB_BUSY;
    }
    else if (err == USB_ERROR)
    {
        result = FSP_ERR_USB_FAILED;
    }
    else
    {
        result = FSP_SUCCESS;
    }

    return result;
}

/**************************************************************************//**
 * @brief Receives data sent by control transfer.
 *
 * @retval FSP_SUCCESS              Successful completion.
 * @retval FSP_ERR_USB_FAILED       The function could not be completed successfully.
 * @retval FSP_ERR_ASSERTION        Parameter is NULL error.
 * @retval FSP_ERR_USB_BUSY         Specified pipe now handling data receive/send request.
 * @retval FSP_ERR_USB_PARAMETER    Parameter error.
 * @note The address specified in the argument p_buf must be 4-byte aligned.
 * @note Do not call this API in the following function.
 * @note (1). Interrupt function.
 * @note (2). Callback function ( for RTOS ).
 ******************************************************************************/
fsp_err_t R_USB_PeriControlDataGet (usb_ctrl_t * const p_ctrl, uint8_t * p_buf, uint32_t size)
{
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

    usb_er_t  err    = USB_ERROR;
    fsp_err_t result = FSP_ERR_USB_FAILED;

#if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl)
    FSP_ASSERT(p_buf)
    FSP_ERROR_RETURN((((uint32_t) p_buf & 0x03) == 0), FSP_ERR_USB_PARAMETER)
#endif                                                 /* USB_CFG_PARAM_CHECKING_ENABLE */

    err = usb_ctrl_read(p_instance_ctrl, p_buf, size); /* Request Control transfer */
    if (err == USB_QOVR)
    {
        result = FSP_ERR_USB_BUSY;
    }
    else if (err == USB_ERROR)
    {
        result = FSP_ERR_USB_FAILED;
    }
    else
    {
        result = FSP_SUCCESS;
    }

    return result;
}

/**************************************************************************//**
 * @brief Performs transfer processing for control transfer.
 *
 * @retval FSP_SUCCESS              Successful completion.
 * @retval FSP_ERR_USB_FAILED       The function could not be completed successfully.
 * @retval FSP_ERR_ASSERTION        Parameter is NULL error.
 * @retval FSP_ERR_USB_BUSY         Specified pipe now handling data receive/send request.
 * @retval FSP_ERR_USB_PARAMETER    Parameter error.
 * @note The address specified in the argument p_buf must be 4-byte aligned.
 * @note Do not call this API in the following function.
 * @note (1). Interrupt function.
 * @note (2). Callback function ( for RTOS ).
 ******************************************************************************/
fsp_err_t R_USB_PeriControlDataSet (usb_ctrl_t * const p_ctrl, uint8_t * p_buf, uint32_t size)
{
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

    usb_er_t  err    = USB_ERROR;
    fsp_err_t result = FSP_ERR_USB_FAILED;

#if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl)
    FSP_ASSERT(p_buf)
    FSP_ERROR_RETURN((((uint32_t) p_buf & 0x03) == 0), FSP_ERR_USB_PARAMETER)
#endif                                                  /* USB_CFG_PARAM_CHECKING_ENABLE */

    err = usb_ctrl_write(p_instance_ctrl, p_buf, size); /* Request Control transfer */
    if (err == USB_QOVR)
    {
        result = FSP_ERR_USB_BUSY;
    }
    else if (err == USB_ERROR)
    {
        result = FSP_ERR_USB_FAILED;
    }
    else
    {
        result = FSP_SUCCESS;
    }

    return result;
}

/**************************************************************************//**
 * @brief Set the response to the setup packet.
 *
 * @retval FSP_SUCCESS              Successful completion.
 * @retval FSP_ERR_USB_FAILED       The function could not be completed successfully.
 * @retval FSP_ERR_ASSERTION        Parameter is NULL error.
 * @note Do not call this API in the following function.
 * @note (1). Interrupt function.
 * @note (2). Callback function ( for RTOS ).
 ******************************************************************************/
fsp_err_t R_USB_PeriControlStatusSet (usb_ctrl_t * const p_ctrl, usb_setup_status_t status)
{
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

#if (USB_CFG_MODE == USB_CFG_HOST)
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
    FSP_PARAMETER_NOT_USED(status);

    return FSP_ERR_USB_FAILED;
#else                                  /* USB_CFG_MODE == USB_CFG_HOST */
 #if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl)
 #endif /* USB_CFG_PARAM_CHECKING_ENABLE */

    p_instance_ctrl->status = (uint16_t) status;

    hw_usb_pcontrol_dcpctr_pid(p_instance_ctrl->module_number, (uint16_t) status);

    return FSP_SUCCESS;
#endif                                 /* #if (USB_CFG_MODE == USB_CFG_HOST) */
}

/**************************************************************************//**
 * @brief Sends a remote wake-up signal to the connected Host.
 *
 * @retval FSP_SUCCESS              Successful completion.
 * @retval FSP_ERR_USB_FAILED       The function could not be completed successfully.
 * @retval FSP_ERR_ASSERTION        Parameter is NULL error.
 * @retval FSP_ERR_USB_NOT_SUSPEND  Device is not suspended.
 * @retval FSP_ERR_USB_BUSY         The device is in resume operation.
 * @note Do not call this API in the following function.
 * @note (1). Interrupt function.
 * @note (2). Callback function ( for RTOS ).
 ******************************************************************************/
fsp_err_t R_USB_RemoteWakeup (usb_ctrl_t * const p_ctrl)
{
    fsp_err_t ret_code = FSP_ERR_USB_FAILED;
#if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;
    usb_utr_t             utr;
    uint16_t              ret_val;

 #if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl)
 #endif                                /* USB_CFG_PARAM_CHECKING_ENABLE */

    utr.ip = p_instance_ctrl->module_number;

 #if (BSP_CFG_RTOS == 0)
    ret_val = usb_cstd_remote_wakeup(&utr);
    switch (ret_val)
    {
        case USB_OK:
        {
            ret_code = FSP_SUCCESS;
            break;
        }

        case USB_QOVR:
        {
            ret_code = FSP_ERR_USB_NOT_SUSPEND;
            break;
        }

        case USB_ERROR:
        default:
        {
            ret_code = FSP_ERR_USB_FAILED;
            break;
        }
    }

 #else                                 /* (BSP_CFG_RTOS == 0) */
    if (USB_YES == g_usb_resume_ing[p_instance_ctrl->module_number])
    {
        ret_code = FSP_ERR_USB_BUSY;
    }
    else
    {
        g_usb_resume_ing[p_instance_ctrl->module_number] = USB_YES;
    }

    if (FSP_ERR_USB_BUSY == ret_code)
    {
        return ret_code;
    }

    ret_val = usb_cstd_remote_wakeup(&utr);
    switch (ret_val)
    {
        case USB_OK:
        {
            ret_code = FSP_SUCCESS;
            break;
        }

        case USB_QOVR:
        {
            ret_code = FSP_ERR_USB_NOT_SUSPEND;
            break;
        }

        case USB_ERROR:
        default:
        {
            ret_code = FSP_ERR_USB_FAILED;
            break;
        }
    }
    g_usb_resume_ing[p_instance_ctrl->module_number] = USB_NO;
 #endif                                /* BSP_CFG_RTOS == 0 */
#else /*((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)*/
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif /*((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)*/

    return ret_code;
}

/**************************************************************************//**
 * @brief This API gets the module number.
 *
 * @retval FSP_SUCCESS              Successful completion.
 ******************************************************************************/
fsp_err_t R_USB_ModuleNumberGet (usb_ctrl_t * const p_ctrl, uint8_t * module_number)
{
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

    *module_number = p_instance_ctrl->module_number;

    return FSP_SUCCESS;
}

/**************************************************************************//**
 * @brief This API gets the class type.
 *
 * @retval FSP_SUCCESS              Successful completion.
 ******************************************************************************/
fsp_err_t R_USB_ClassTypeGet (usb_ctrl_t * const p_ctrl, usb_class_t * class_type)
{
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

    *class_type = p_instance_ctrl->type;

    return FSP_SUCCESS;
}

/**************************************************************************//**
 * @brief This API gets the device address.
 *
 * @retval FSP_SUCCESS              Successful completion.
 ******************************************************************************/
fsp_err_t R_USB_DeviceAddressGet (usb_ctrl_t * const p_ctrl, uint8_t * device_address)
{
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

    *device_address = p_instance_ctrl->device_address;

    return FSP_SUCCESS;
}

/**************************************************************************//**
 * @brief This API gets the pipe number.
 *
 * @retval FSP_SUCCESS              Successful completion.
 ******************************************************************************/
fsp_err_t R_USB_PipeNumberGet (usb_ctrl_t * const p_ctrl, uint8_t * pipe_number)
{
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

    *pipe_number = p_instance_ctrl->pipe;

    return FSP_SUCCESS;
}

/**************************************************************************//**
 * @brief This API gets the state of the device.
 *
 * @retval FSP_SUCCESS              Successful completion.
 ******************************************************************************/
fsp_err_t R_USB_DeviceStateGet (usb_ctrl_t * const p_ctrl, uint16_t * state)
{
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

    *state = p_instance_ctrl->status;

    return FSP_SUCCESS;
}

/**************************************************************************//**
 * @brief This API gets the data size.
 *
 * @retval FSP_SUCCESS              Successful completion.
 ******************************************************************************/
fsp_err_t R_USB_DataSizeGet (usb_ctrl_t * const p_ctrl, uint32_t * data_size)
{
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

    *data_size = p_instance_ctrl->data_size;

    return FSP_SUCCESS;
}

/**************************************************************************//**
 * @brief This API gets the setup type.
 *
 * @retval FSP_SUCCESS              Successful completion.
 ******************************************************************************/
fsp_err_t R_USB_SetupGet (usb_ctrl_t * const p_ctrl, usb_setup_t * setup)
{
    usb_instance_ctrl_t * p_instance_ctrl = (usb_instance_ctrl_t *) p_ctrl;

    *setup = p_instance_ctrl->setup;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup USB)
 **********************************************************************************************************************/
