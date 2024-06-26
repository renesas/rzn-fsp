/***********************************************************************************************************************
 * Copyright [2020-2024] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
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

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_poeg.h"
#include "r_poeg_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "POEG" in ASCII, used to determine if channel is open. */
#define POEG_OPEN                (0x504F4547ULL)

#define POEG_PRV_STATUS_FLAGS    (R_POEG0_POEG0GA_DERR1ST_Msk | R_POEG0_POEG0GA_DERR0ST_Msk | R_POEG0_POEG0GA_ST_Msk | \
                                  R_POEG0_POEG0GA_SSF_Msk | R_POEG0_POEG0GA_OSTPF_Msk | R_POEG0_POEG0GA_IOCF_Msk |     \
                                  R_POEG0_POEG0GA_PIDF_Msk)

#define POEG_PRV_FLAG_CLEAR      (R_POEG0_POEG0GA_DERR1ST_Msk | R_POEG0_POEG0GA_DERR0ST_Msk | R_POEG0_POEG0GA_SSF_Msk | \
                                  R_POEG0_POEG0GA_OSTPF_Msk | R_POEG0_POEG0GA_IOCF_Msk | R_POEG0_POEG0GA_PIDF_Msk)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * ISR prototypes
 **********************************************************************************************************************/
void poeg_event_isr(void);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* POEG implementation of POEG interface  */
const poeg_api_t g_poeg_on_poeg =
{
    .open          = R_POEG_Open,
    .reset         = R_POEG_Reset,
    .outputDisable = R_POEG_OutputDisable,
    .statusGet     = R_POEG_StatusGet,
    .callbackSet   = R_POEG_CallbackSet,
    .close         = R_POEG_Close,
};

/*******************************************************************************************************************//**
 * @addtogroup POEG
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initializes the POEG module and applies configurations. Implements @ref poeg_api_t::open.
 *
 * @note The @ref poeg_cfg_t::trigger setting can only be configured once after reset. Reopening with a different trigger
 * configuration is not possible.
 *
 * @retval FSP_SUCCESS                    Initialization was successful.
 * @retval FSP_ERR_ASSERTION              A required input pointer is NULL.
 * @retval FSP_ERR_ALREADY_OPEN           Module is already open.
 * @retval FSP_ERR_IRQ_BSP_DISABLED       poeg_cfg_t::p_callback is not NULL, but ISR is not enabled.  ISR must be
 *                                        enabled to use callback.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT The channel requested in the p_cfg parameter is not available on this device.
 * @retval FSP_ERR_IP_UNIT_NOT_PRESENT    The Unit requested in the p_cfg parameter is not available on this device.
 **********************************************************************************************************************/
fsp_err_t R_POEG_Open (poeg_ctrl_t * const p_ctrl, poeg_cfg_t const * const p_cfg)
{
    poeg_instance_ctrl_t * p_instance_ctrl = (poeg_instance_ctrl_t *) p_ctrl;
#if POEG_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(POEG_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
    FSP_ERROR_RETURN(((1U << p_cfg->channel) & BSP_FEATURE_POEG_CHANNEL_MASK), FSP_ERR_IP_CHANNEL_NOT_PRESENT);
    FSP_ERROR_RETURN((p_cfg->unit <= BSP_FEATURE_POEG_MAX_UNIT), FSP_ERR_IP_UNIT_NOT_PRESENT);
    if (p_cfg->p_callback)
    {
        FSP_ERROR_RETURN(p_cfg->irq >= 0, FSP_ERR_IRQ_BSP_DISABLED);
    }

    if (p_cfg->irq >= 0)
    {
        FSP_ASSERT(NULL != p_cfg->p_callback);
    }
#endif

    if (BSP_FEATURE_POEG_LLPP_UNIT == p_cfg->unit)
    {
        /* LLPP Peripheral */
        p_instance_ctrl->p_reg =
            (R_POEG0_Type *) ((uint32_t) R_POEG0 + (p_cfg->channel * BSP_FEATURE_POEG_GROUP_OFSSET_ADDRESS));
    }
    else if (BSP_FEATURE_POEG_NONSAFETY_UNIT == p_cfg->unit)
    {
        /* Non-Safety Peripheral */
        p_instance_ctrl->p_reg =
            (R_POEG0_Type *) ((uint32_t) R_POEG1 + (p_cfg->channel * BSP_FEATURE_POEG_GROUP_OFSSET_ADDRESS));
    }
    else
    {
        /* Safety Peripheral */
        p_instance_ctrl->p_reg =
            (R_POEG0_Type *) ((uint32_t) R_POEG2 + (p_cfg->channel * BSP_FEATURE_POEG_GROUP_OFSSET_ADDRESS));
    }

    p_instance_ctrl->p_cfg               = p_cfg;
    *(uint32_t *) p_instance_ctrl->p_reg = ((uint32_t) p_cfg->trigger << R_POEG0_POEG0GA_PIDE_Pos) |
                                           ((uint32_t) p_cfg->polarity << R_POEG0_POEG0GA_INV_Pos) |
                                           ((uint32_t) p_cfg->noise_filter << R_POEG0_POEG0GA_NFEN_Pos);

    /* Set callback and context pointers, if configured */
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    /* Make sure the module is marked open before enabling the interrupt since the interrupt could fire immediately. */
    p_instance_ctrl->open = POEG_OPEN;

    /* Configure interrupt. */
    if (p_cfg->irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_cfg->irq, p_cfg->ipl, p_instance_ctrl);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disables GPT output pins. Implements @ref poeg_api_t::outputDisable.
 *
 * @retval FSP_SUCCESS                 GPT output pins successfully disabled.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_POEG_OutputDisable (poeg_ctrl_t * const p_ctrl)
{
    poeg_instance_ctrl_t * p_instance_ctrl = (poeg_instance_ctrl_t *) p_ctrl;
#if POEG_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(POEG_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Disable GPT output pins. */
    *(uint32_t *) p_instance_ctrl->p_reg |= (1U << R_POEG0_POEG0GA_SSF_Pos);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Resets status flags. Implements @ref poeg_api_t::reset.
 *
 * @note Status flags are only reset if the original POEG trigger is resolved. Check the status using
 * @ref R_POEG_StatusGet after calling this function to verify the status is cleared.
 *
 * @retval FSP_SUCCESS                 Function attempted to clear status flags.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_POEG_Reset (poeg_ctrl_t * const p_ctrl)
{
    poeg_instance_ctrl_t * p_instance_ctrl = (poeg_instance_ctrl_t *) p_ctrl;
#if POEG_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(POEG_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Reset POEG status flags. */
    *(uint32_t *) p_instance_ctrl->p_reg &= ~POEG_PRV_STATUS_FLAGS;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Get current POEG status and store it in provided pointer p_status. Implements @ref poeg_api_t::statusGet.
 *
 * @retval FSP_SUCCESS                 Current POEG state stored successfully.
 * @retval FSP_ERR_ASSERTION           p_ctrl or p_status was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_POEG_StatusGet (poeg_ctrl_t * const p_ctrl, poeg_status_t * const p_status)
{
    poeg_instance_ctrl_t * p_instance_ctrl = (poeg_instance_ctrl_t *) p_ctrl;
#if POEG_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(POEG_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Get POEG state. */
    p_status->state = (poeg_state_t) (*(uint32_t *) p_instance_ctrl->p_reg & POEG_PRV_STATUS_FLAGS);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref poeg_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_POEG_CallbackSet (poeg_ctrl_t * const          p_ctrl,
                              void (                     * p_callback)(poeg_callback_args_t *),
                              void const * const           p_context,
                              poeg_callback_args_t * const p_callback_memory)
{
    poeg_instance_ctrl_t * p_instance_ctrl = (poeg_instance_ctrl_t *) p_ctrl;

#if POEG_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(POEG_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
    p_instance_ctrl->p_callback        = p_callback;
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disables POEG interrupt. Implements @ref poeg_api_t::close.
 *
 * @note This function does not disable the POEG.
 *
 * @retval FSP_SUCCESS                 Successful close.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_POEG_Close (poeg_ctrl_t * const p_ctrl)
{
    poeg_instance_ctrl_t * p_instance_ctrl = (poeg_instance_ctrl_t *) p_ctrl;

#if POEG_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(POEG_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Disable interrupts. */
    if (p_instance_ctrl->p_cfg->irq >= 0)
    {
        R_BSP_IrqDisable(p_instance_ctrl->p_cfg->irq);
        R_FSP_IsrContextSet(p_instance_ctrl->p_cfg->irq, NULL);
    }

    /* Clear open flag. */
    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/** @} (end addtogroup POEG) */

/*******************************************************************************************************************//**
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Notifies user of POEG event.
 **********************************************************************************************************************/
void poeg_event_isr (void)
{
    POEG_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    poeg_callback_args_t args;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    volatile poeg_instance_ctrl_t * p_instance_ctrl = (poeg_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
     * stored in non-secure memory so they can be accessed by a non-secure callback function. */
    poeg_callback_args_t * p_args = p_instance_ctrl->p_callback_memory;
    if (NULL == p_args)
    {
        /* Store on stack */
        p_args = &args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        args = *p_args;
    }

    p_args->p_context = p_instance_ctrl->p_context;

    /* If the project is not Trustzone Secure, then it will never need to change security state in order to call the callback. */
    p_instance_ctrl->p_callback(p_args);

    if (NULL != p_instance_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_instance_ctrl->p_callback_memory = args;
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    POEG_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}
