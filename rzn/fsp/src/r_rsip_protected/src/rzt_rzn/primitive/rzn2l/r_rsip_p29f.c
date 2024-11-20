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

rsip_ret_t r_rsip_p29f (const uint32_t InData_Text[],
                        const uint32_t InData_DataALen[],
                        const uint32_t InData_TextLen[],
                        uint32_t       OutData_Text[],
                        uint32_t       OutData_DataT[])
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
    WR1_PROG(REG_1444H, 0x000001c7U);
    WR1_PROG(REG_1608H, 0x80020100U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_TextLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_TextLen[1]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b580U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000007FU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b5a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0xFFFFFF00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0c0029a9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x04a02988U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    r_rsip_func100(bswap_32big(0xda54e742U),
                   bswap_32big(0x0a9dd78dU),
                   bswap_32big(0x92b5667cU),
                   bswap_32big(0xc7e55a1dU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xbd75a888U), bswap_32big(0xc08ef6b0U), bswap_32big(0x249baf09U),
                       bswap_32big(0xd1edd790U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1600H, 0x00003409U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00036800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x08008c00U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000000fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        r_rsip_func100(bswap_32big(0x20faf0b7U), bswap_32big(0x62e017f6U), bswap_32big(0xf561d62cU),
                       bswap_32big(0x1ee23a1bU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func100(bswap_32big(0x8d0cbe61U), bswap_32big(0x183a82aeU), bswap_32big(0x1a05bfe8U),
                           bswap_32big(0x2df45752U));
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_182CH, 0x00000020U);
            WR1_PROG(REG_1824H, 0x07008d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_Text[0]);
            WR1_ADDR(REG_1420H, &InData_Text[1]);
            WR1_ADDR(REG_1420H, &InData_Text[2]);
            WR1_ADDR(REG_1420H, &InData_Text[3]);
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x80840001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1400H, 0x03410011U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_1600H, 0x3c002be0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x12003c3fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002fe0U);
                WR1_PROG(REG_1458H, 0x00000000U);
            }

            WR1_PROG(REG_182CH, 0x00018000U);
            WR1_PROG(REG_1824H, 0x0a008005U);
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81840001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1400H, 0x00490011U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1608H, 0x81840001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_Text[0]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_Text[1]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_Text[2]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_Text[3]);
            r_rsip_func101(bswap_32big(0x5cd49af7U), bswap_32big(0xf2ae6979U), bswap_32big(0x930e9e4fU),
                           bswap_32big(0x8d165eedU));
        }

        r_rsip_func100(bswap_32big(0xd2e1b039U), bswap_32big(0xea2719aaU), bswap_32big(0x1ed3318cU),
                       bswap_32big(0xa4cc70aeU));
        WR1_PROG(REG_1444H, 0x000001c1U);
        WR1_PROG(REG_182CH, 0x00018000U);
        WR1_PROG(REG_1824H, 0x0a008005U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_DataALen[0]);
        WR1_ADDR(REG_1420H, &InData_DataALen[1]);
        WR1_PROG(REG_1608H, 0x81020100U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1400H, 0x00490009U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1824H, 0x08000045U);
        WR1_PROG(REG_1608H, 0x81040080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1400H, 0x00490011U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_182CH, 0x00400000U);
        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x0c008104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_182CH, 0x00000020U);
        WR1_PROG(REG_1824H, 0x07008d05U);
        WR1_PROG(REG_1400H, 0x00410011U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1408H, 0x00001012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_DataT[0]);
        RD1_ADDR(REG_1420H, &OutData_DataT[1]);
        RD1_ADDR(REG_1420H, &OutData_DataT[2]);
        RD1_ADDR(REG_1420H, &OutData_DataT[3]);
        r_rsip_func102(bswap_32big(0x6d175d60U), bswap_32big(0x921dfe34U), bswap_32big(0x12d34ad5U),
                       bswap_32big(0x92ac1a28U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PASS;
    }
}
