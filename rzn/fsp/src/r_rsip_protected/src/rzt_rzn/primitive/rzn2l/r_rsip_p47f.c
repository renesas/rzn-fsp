/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_rsip_primitive.h"
#include "r_rsip_reg.h"
#include "r_rsip_util.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

RSIP_PRV_PRIMITIVE_FUNC

rsip_ret_t r_rsip_p47f (void)
{
    uint32_t iLoop;
    uint32_t jLoop;
    uint32_t kLoop;
    uint32_t oLoop;
    uint32_t oLoop1;
    uint32_t OFS_ADR;
    (void) iLoop;
    (void) jLoop;
    (void) kLoop;
    (void) oLoop;
    (void) oLoop1;
    (void) OFS_ADR;
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func101(bswap_32big(0x6d52952bU), bswap_32big(0x3f411b7bU), bswap_32big(0x6169a553U),
                       bswap_32big(0xa3a4c748U));
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func101(bswap_32big(0x3138081dU), bswap_32big(0xb1c1ca90U), bswap_32big(0xc680863cU),
                       bswap_32big(0x9e4e0193U));
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func101(bswap_32big(0xcf2a7e93U), bswap_32big(0x232ff36cU), bswap_32big(0x79b95718U),
                       bswap_32big(0xa8805494U));
    }
    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func101(bswap_32big(0x087d557fU), bswap_32big(0x9a2ecfb6U), bswap_32big(0xb7d1131bU),
                       bswap_32big(0xea3abc26U));
    }

    r_rsip_func102(bswap_32big(0x179fa27aU),
                   bswap_32big(0x48b12223U),
                   bswap_32big(0x708d9cf1U),
                   bswap_32big(0x8249b263U));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}