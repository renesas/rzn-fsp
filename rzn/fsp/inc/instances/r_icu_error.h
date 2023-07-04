/***********************************************************************************************************************
 * Copyright [2020-2023] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics Corporation and/or its affiliates and may only
 * be used with products of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.
 * Renesas products are sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for
 * the selection and use of Renesas products and Renesas assumes no liability.  No license, express or implied, to any
 * intellectual property right is granted by Renesas.  This software is protected under all applicable laws, including
 * copyright laws. Renesas reserves the right to change or discontinue this software and/or this documentation.
 * THE SOFTWARE AND DOCUMENTATION IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND
 * TO THE FULLEST EXTENT PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY,
 * INCLUDING WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE
 * SOFTWARE OR DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.
 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR
 * DOCUMENTATION (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER,
 * INCLUDING, WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY
 * LOST PROFITS, OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/

#ifndef R_ICU_ERROR_H
#define R_ICU_ERROR_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_error_api.h"
#include "r_icu_error_cfg.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define ERROR_TABLE_MAX_ENTRIES    (128)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef void (* error_table_t)(uint32_t id);

/** ICU_ERROR Error event source */
typedef enum e_icu_error_event_source
{
    ICU_ERROR_EVENT_SOURCE_CPU0,
    ICU_ERROR_EVENT_SOURCE_PERIPHERAL_0,
    ICU_ERROR_EVENT_SOURCE_PERIPHERAL_1,
} icu_error_event_source_t;

/** ICU_ERROR CPU0 Error Code */
typedef enum e_icu_error_cpu0_error
{
    ICU_ERROR_CPU0_ERROR_EVENT0  = (1UL << 0),
    ICU_ERROR_CPU0_ERROR_EVENT1  = (1UL << 1),
    ICU_ERROR_CPU0_ERROR_EVENT2  = (1UL << 2),
    ICU_ERROR_CPU0_ERROR_EVENT3  = (1UL << 3),
    ICU_ERROR_CPU0_ERROR_EVENT4  = (1UL << 4),
    ICU_ERROR_CPU0_ERROR_EVENT5  = (1UL << 5),
    ICU_ERROR_CPU0_ERROR_EVENT6  = (1UL << 6),
    ICU_ERROR_CPU0_ERROR_EVENT7  = (1UL << 7),
    ICU_ERROR_CPU0_ERROR_EVENT8  = (1UL << 8),
    ICU_ERROR_CPU0_ERROR_EVENT9  = (1UL << 9),
    ICU_ERROR_CPU0_ERROR_EVENT10 = (1UL << 10),
    ICU_ERROR_CPU0_ERROR_EVENT11 = (1UL << 11),
    ICU_ERROR_CPU0_ERROR_EVENT12 = (1UL << 12),
    ICU_ERROR_CPU0_ERROR_EVENT13 = (1UL << 13),
    ICU_ERROR_CPU0_ERROR_EVENT14 = (1UL << 14),
    ICU_ERROR_CPU0_ERROR_EVENT15 = (1UL << 15),
    ICU_ERROR_CPU0_ERROR_EVENT16 = (1UL << 16),
    ICU_ERROR_CPU0_ERROR_EVENT17 = (1UL << 17),
    ICU_ERROR_CPU0_ERROR_EVENT18 = (1UL << 18),
    ICU_ERROR_CPU0_ERROR_EVENT19 = (1UL << 19),
    ICU_ERROR_CPU0_ERROR_EVENT20 = (1UL << 20),
    ICU_ERROR_CPU0_ERROR_EVENT21 = (1UL << 21),
    ICU_ERROR_CPU0_ERROR_EVENT22 = (1UL << 22),
    ICU_ERROR_CPU0_ERROR_EVENT23 = (1UL << 23),
    ICU_ERROR_CPU0_ERROR_EVENT24 = (1UL << 24),
    ICU_ERROR_CPU0_ERROR_EVENT25 = (1UL << 25)
} icu_error_cpu0_error_t;

/** ICU_ERROR Peripheral 0 Error Code */
typedef enum e_icu_error_peripheral_error_0
{
    ICU_ERROR_PERIPHERAL_ERROR_0_CLMA_INT      = (1UL << 0),  // Main OSC stop detection
    ICU_ERROR_PERIPHERAL_ERROR_0_CLMA0_INT     = (1UL << 1),  // CLMA0 error detection
    ICU_ERROR_PERIPHERAL_ERROR_0_CLMA1_INT     = (1UL << 2),  // CLMA1 error detection
    ICU_ERROR_PERIPHERAL_ERROR_0_CLMA2_INT     = (1UL << 3),  // CLMA2 error detection
    ICU_ERROR_PERIPHERAL_ERROR_0_BSC_WTO       = (1UL << 4),  // External wait timeout detection interrupt
    ICU_ERROR_PERIPHERAL_ERROR_0_DMAC0_ERR     = (1UL << 5),  // DMAC0 transfer error
    ICU_ERROR_PERIPHERAL_ERROR_0_DMAC1_ERR     = (1UL << 6),  // DMAC1 transfer error
    ICU_ERROR_PERIPHERAL_ERROR_0_WDT_NMIUNDF0  = (1UL << 7),  // Down-counter underflow/refresh error for CPU0
    ICU_ERROR_PERIPHERAL_ERROR_0_USB_FDMAERR   = (1UL << 9),  // USB (Function) DMA error
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_LTCSE  = (1UL << 10), // DSMIF0 lower threshold current sum error
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_UTCSE  = (1UL << 11), // DSMIF0 upper threshold current sum error
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_LTODE0 = (1UL << 12), // DSMIF0 lower threshold overcurrent detection 0
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_LTODE1 = (1UL << 13), // DSMIF0 lower threshold overcurrent detection 1
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_LTODE2 = (1UL << 14), // DSMIF0 lower threshold overcurrent detection 2
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_UTODE0 = (1UL << 15), // DSMIF0 upper threshold overcurrent detection 0
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_UTODE1 = (1UL << 16), // DSMIF0 upper threshold overcurrent detection 1
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_UTODE2 = (1UL << 17), // DSMIF0 upper threshold overcurrent detection 2
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_SCDE0  = (1UL << 18), // DSMIF0 Short-circuit detection 0
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_SCDE1  = (1UL << 19), // DSMIF0 Short-circuit detection 1
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_SCDE2  = (1UL << 20), // DSMIF0 Short-circuit detection 2
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_LTCSE  = (1UL << 21), // DSMIF1 lower threshold current sum error
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_UTCSE  = (1UL << 22), // DSMIF1 upper threshold current sum error
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_LTODE0 = (1UL << 23), // DSMIF1 lower threshold overcurrent detection 0
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_LTODE1 = (1UL << 24), // DSMIF1 lower threshold overcurrent detection 1
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_LTODE2 = (1UL << 25), // DSMIF1 lower threshold overcurrent detection 2
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_UTODE0 = (1UL << 26), // DSMIF1 upper threshold overcurrent detection 0
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_UTODE1 = (1UL << 27), // DSMIF1 upper threshold overcurrent detection 1
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_UTODE2 = (1UL << 28), // DSMIF1 upper threshold overcurrent detection 2
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_SCDE0  = (1UL << 29), // DSMIF1 Short-circuit detection 0
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_SCDE1  = (1UL << 30), // DSMIF1 Short-circuit detection 1
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_SCDE2  = (1UL << 31), // DSMIF1 Short-circuit detection 2
} icu_error_peripheral_error_0_t;

/** ICU_ERROR Peripheral 1 Error Code */
typedef enum e_icu_error_peripheral_error_1
{
    ICU_ERROR_PERIPHERAL_ERROR_1_DOC_DOPCI  = (1UL << 0),  // DOC interrupt
    ICU_ERROR_PERIPHERAL_ERROR_1_SRAM0_IE1  = (1UL << 1),  // System SRAM0 ECC 1 bit error
    ICU_ERROR_PERIPHERAL_ERROR_1_SRAM0_IE2  = (1UL << 2),  // System SRAM0 ECC 2 bits error
    ICU_ERROR_PERIPHERAL_ERROR_1_SRAM0_OVF  = (1UL << 3),  // System SRAM0 ECC error address capture overflow
    ICU_ERROR_PERIPHERAL_ERROR_1_SRAM1_IE1  = (1UL << 4),  // System SRAM1 ECC 1 bit error
    ICU_ERROR_PERIPHERAL_ERROR_1_SRAM1_IE2  = (1UL << 5),  // System SRAM1 ECC 2 bits error
    ICU_ERROR_PERIPHERAL_ERROR_1_SRAM1_OVF  = (1UL << 6),  // System SRAM1 ECC error address capture overflow
    ICU_ERROR_PERIPHERAL_ERROR_1_SRAM2_IE1  = (1UL << 7),  // System SRAM2 ECC 1 bit error
    ICU_ERROR_PERIPHERAL_ERROR_1_SRAM2_IE2  = (1UL << 8),  // System SRAM2 ECC 2 bits error
    ICU_ERROR_PERIPHERAL_ERROR_1_SRAM2_OVF  = (1UL << 9),  // System SRAM2 ECC error address capture overflow
    ICU_ERROR_PERIPHERAL_ERROR_1_BUSERR     = (1UL << 13), // Bus error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_SHOST  = (1UL << 15), // Master MPU for Serial Host I/F error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_PHOST  = (1UL << 16), // Master MPU for Parallel Host I/F error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DMACR0 = (1UL << 17), // Master MPU Read channel for DMAC0 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DMACW0 = (1UL << 18), // Master MPU Write channel for DMAC0 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DMACR1 = (1UL << 19), // Master MPU Read channel for DMAC1 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DMACW1 = (1UL << 20), // Master MPU Write channel for DMAC1 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_GMACR  = (1UL << 21), // Master MPU Read channel for GMAC error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_GMACW  = (1UL << 22), // Master MPU Write channel for GMAC error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_USBH   = (1UL << 23), // Master MPU for USB Host error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_USBF   = (1UL << 24), // Master MPU for USB Function error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DBGR   = (1UL << 27), // Master MPU Read channel for Debug error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DBGW   = (1UL << 28), // Master MPU Write channel for Debug error
} icu_error_peripheral_error_1_t;

/** ERROR instance control block. Do not initialize. Initialization occurs when the @ref error_api_t::open function is called. */
typedef struct st_icu_error_instance_ctrl
{
    error_cfg_t const * p_cfg;         // Pointer to the configuration structure
    uint32_t            open;          ///< Used by driver to check if the control structure is valid

    /* Pointer to callback and optional working memory */
    void (* p_callback)(error_callback_args_t *);
    error_callback_args_t * p_callback_memory;
    void const            * p_context; ///< User defined context passed into callback function
} icu_error_instance_ctrl_t;

/** ERROR event configuration extension. */
typedef struct st_icu_error_extended_cfg
{
    uint8_t   cpu0_err0_ipl;                     ///< Cortex-R52 CPU0 error 0 interrupt priority
    IRQn_Type cpu0_err0_irq;                     ///< Cortex-R52 CPU0 error 0 interrupt IRQ number
    uint8_t   cpu0_err1_ipl;                     ///< Cortex-R52 CPU0 error 1 interrupt priority
    IRQn_Type cpu0_err1_irq;                     ///< Cortex-R52 CPU0 error 1 interrupt IRQ number
    uint8_t   peri_err0_ipl;                     ///< Peripheral error 0 interrupt priority
    IRQn_Type peri_err0_irq;                     ///< Peripheral error 0 interrupt IRQ number
    uint8_t   peri_err1_ipl;                     ///< Peripheral error 1 interrupt priority
    IRQn_Type peri_err1_irq;                     ///< Peripheral error 1 interrupt IRQ number
    uint32_t  cpu0_err_reset_mask;               ///< Cortex-R52 CPU0 error reset mask
    uint32_t  cpu0_err0_event_mask;              ///< Cortex-R52 CPU0 error 0 event mask
    uint32_t  cpu0_err1_event_mask;              ///< Cortex-R52 CPU0 error 1 event mask
    uint32_t  peri_err_event_0_reset_mask;       ///< Peripheral error event 0 reset mask
    uint32_t  peri_err0_event_0_mask;            ///< Peripheral error 0 event 0 mask
    uint32_t  peri_err1_event_0_mask;            ///< Peripheral error 1 event 0 mask
    uint32_t  peri_err_event_1_reset_mask;       ///< Peripheral error event 1 reset mask
    uint32_t  peri_err0_event_1_mask;            ///< Peripheral error 0 event 1 mask
    uint32_t  peri_err1_event_1_mask;            ///< Peripheral error 1 event 1 mask

    const error_table_t * p_error_handler_table; ///< Peripheral error handler table
} icu_error_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const error_api_t g_error_on_icu_error;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_ICU_ERROR_Open(error_ctrl_t * const p_api_ctrl, error_cfg_t const * const p_cfg);
fsp_err_t R_ICU_ERROR_Close(error_ctrl_t * const p_api_ctrl);
fsp_err_t R_ICU_ERROR_StatusGet(error_ctrl_t * const p_api_ctrl, uint32_t source, uint32_t * p_status);
fsp_err_t R_ICU_ERROR_StatusClear(error_ctrl_t * const p_api_ctrl, uint32_t source, uint32_t event);
fsp_err_t R_ICU_ERROR_CallbackSet(error_ctrl_t * const          p_api_ctrl,
                                  void (                      * p_callback)(error_callback_args_t *),
                                  void const * const            p_context,
                                  error_callback_args_t * const p_callback_memory);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
