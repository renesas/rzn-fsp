/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * File Name    : board_leds.c
 * Description  : This module has information about the LEDs on this board.
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BOARD_RZN2L_RSK_LEDS
 *
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#if defined(BOARD_RZN2L_RSK)

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/** Array of LED IOPORT pins. */
static const uint32_t g_bsp_prv_leds[][2] =
{
    {(uint32_t) BSP_IO_PORT_18_PIN_2, (uint32_t) BSP_IO_REGION_SAFE}, ///< RLED0
    {(uint32_t) BSP_IO_PORT_22_PIN_3, (uint32_t) BSP_IO_REGION_SAFE}, ///< RLED1
    {(uint32_t) BSP_IO_PORT_04_PIN_1, (uint32_t) BSP_IO_REGION_SAFE}, ///< RLED2
    {(uint32_t) BSP_IO_PORT_17_PIN_3, (uint32_t) BSP_IO_REGION_SAFE}  ///< RLED3
};

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/** Structure with LED information for this board. */

const bsp_leds_t g_bsp_leds =
{
    .led_count = (uint16_t) (sizeof(g_bsp_prv_leds) / sizeof(g_bsp_prv_leds[0])),
    .p_leds    = g_bsp_prv_leds
};

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

#endif

/** @} (end addtogroup BOARD_RZN2L_RSK_LEDS) */
