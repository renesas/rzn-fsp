/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * File Name    : board_leds.h
 * Description  : This module has information about the LEDs on this board.
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @ingroup BOARD_RZN2H_EVB
 * @defgroup BOARD_RZN2H_EVB_LEDS Board LEDs
 * @brief LED information for this board.
 *
 * This is code specific to the RZN2H_EVB board. It includes info on the number of LEDs and which pins are they
 * are on.
 *
 * @{
 **********************************************************************************************************************/

#ifndef BOARD_LEDS_H
#define BOARD_LEDS_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Information on how many LEDs and what pins they are on. */
typedef struct st_bsp_leds
{
    uint16_t led_count;                ///< The number of LEDs on this board
    uint32_t const (*p_leds)[2];       ///< Pointer to an array of IOPORT pins for controlling LEDs
} bsp_leds_t;

/** Available user-controllable LEDs on this board. These enums can be can be used to index into the array of LED pins
 * found in the bsp_leds_t structure. */
typedef enum e_bsp_led
{
#if defined(BSP_CFG_CORE_CR52)
 #if (0 == BSP_CFG_CORE_CR52)
    BSP_LED_RLED0 = 0,                 ///< Green
 #elif (1 == BSP_CFG_CORE_CR52)
    BSP_LED_RLED1 = 0,                 ///< Red
 #endif
#elif defined(BSP_CFG_CORE_CA55)
 #if (0 == BSP_CFG_CORE_CA55)
    BSP_LED_RLED2 = 0,                 ///< Green
 #elif (1 == BSP_CFG_CORE_CA55)
    BSP_LED_RLED3 = 0,                 ///< Green
 #elif (2 == BSP_CFG_CORE_CA55)
    BSP_LED_RLED4 = 0,                 ///< Yellow
 #elif (3 == BSP_CFG_CORE_CA55)
    BSP_LED_RLED5 = 0,                 ///< Red
 #endif
#endif
} bsp_led_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public Functions
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/** @} (end defgroup BOARD_RZN2H_EVB_LEDS) */
