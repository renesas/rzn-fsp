/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
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

rsip_ret_t r_rsip_pe5e (const uint32_t InData_EncMsg[], const uint32_t MAX_CNT2)
{
    uint32_t max_cnt2 = bswap_32big(MAX_CNT2);
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
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010100U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &max_cnt2);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000d08U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xdb9bd31fU),
                   bswap_32big(0xec7b38a7U),
                   bswap_32big(0x3f34effdU),
                   bswap_32big(0x3716c4aaU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1444H, 0x000003c7U);
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[1]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[2]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[3]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x0000e503U));
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xa3a64d0bU), bswap_32big(0x1485bc4cU), bswap_32big(0xe4137b11U),
                       bswap_32big(0x260b77e1U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01f51082U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x0000e503U));
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x2c112c99U), bswap_32big(0xde8a2cdeU), bswap_32big(0x67c3e32aU),
                       bswap_32big(0xdf72e9bdU));
        r_rsip_func046();
        WAIT_STS(REG_2030H, 0U, 1U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000044U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x08000044U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x08000054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        r_rsip_func100(bswap_32big(0x1b37ada6U), bswap_32big(0x5ec8e611U), bswap_32big(0x5a967c2dU),
                       bswap_32big(0x3987fddeU));
        r_rsip_func103();
        r_rsip_func100(bswap_32big(0x7d430dd2U), bswap_32big(0xb57b13ceU), bswap_32big(0xb0dff69eU),
                       bswap_32big(0xf8edfe45U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c2000c4U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WAIT_STS(REG_1A28H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000900U);
        WR1_PROG(REG_1600H, 0x0000a900U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000005U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00026908U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000929U);
        WR1_PROG(REG_1458H, 0x00000000U);
        for (iLoop = 0; iLoop < MAX_CNT2 - 8; iLoop = iLoop + 4)
        {
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xf7008d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 4]);
            WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 5]);
            WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 6]);
            WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 7]);
            r_rsip_func100(bswap_32big(0xe95a532fU), bswap_32big(0xe195ade9U), bswap_32big(0x5a6c815bU),
                           bswap_32big(0xe80abb74U));
            WR1_PROG(REG_1824H, 0xe7040d05U);
            WR1_PROG(REG_1400H, 0x00420011U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1408H, 0x00001012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &S_HEAP[iLoop]);
            RD1_ADDR(REG_1420H, &S_HEAP[iLoop + 1]);
            RD1_ADDR(REG_1420H, &S_HEAP[iLoop + 2]);
            RD1_ADDR(REG_1420H, &S_HEAP[iLoop + 3]);
            WR1_PROG(REG_1600H, 0x00002d20U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x5680d9eaU), bswap_32big(0xa671589aU), bswap_32big(0x246139b3U),
                           bswap_32big(0xa77a8effU));
        }

        WR1_PROG(REG_1600H, 0x38000909U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x600128a6U), bswap_32big(0x86114fd9U), bswap_32big(0x0d8af06fU),
                       bswap_32big(0xe58f8065U));
        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x0c000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1824H, 0x09140105U);
        WR1_PROG(REG_1400H, 0x00410011U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1408H, 0x00001012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &S_HEAP[iLoop]);
        RD1_ADDR(REG_1420H, &S_HEAP[iLoop + 1]);
        RD1_ADDR(REG_1420H, &S_HEAP[iLoop + 2]);
        RD1_ADDR(REG_1420H, &S_HEAP[iLoop + 3]);
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[MAX_CNT2 - 4]);
        WR1_ADDR(REG_1420H, &InData_EncMsg[MAX_CNT2 - 3]);
        WR1_ADDR(REG_1420H, &InData_EncMsg[MAX_CNT2 - 2]);
        WR1_ADDR(REG_1420H, &InData_EncMsg[MAX_CNT2 - 1]);
        WR1_PROG(REG_1A24H, 0x9c100005U);
        WR1_PROG(REG_1400H, 0x00820011U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        r_rsip_func100(bswap_32big(0x38c79c78U), bswap_32big(0xfb76c22dU), bswap_32big(0x4e010096U),
                       bswap_32big(0x816b0244U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xab97687fU), bswap_32big(0xbdff8c6fU), bswap_32big(0xcf8434a1U),
                           bswap_32big(0xc414a644U));

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000000a1U);
            WR1_PROG(REG_1824H, 0x08000044U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1444H, 0x000000a1U);
            WR1_PROG(REG_1824H, 0x08000054U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1600H, 0x00000929U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < MAX_CNT2 - 8; iLoop = iLoop + 4)
            {
                WR1_PROG(REG_1444H, 0x000003c1U);
                WR1_PROG(REG_1824H, 0xf7040d05U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 0]);
                WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 1]);
                WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 2]);
                WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 3]);
                WR1_PROG(REG_1400H, 0x01410011U);
                WAIT_STS(REG_1404H, 30U, 0U);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1600H, 0x00002d20U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xdf03a90bU),
                               bswap_32big(0x772dbcc8U),
                               bswap_32big(0x1e9e0a2eU),
                               bswap_32big(0x0c10ba22U));
            }

            WR1_PROG(REG_1600H, 0x38000909U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0x07040d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 0]);
            WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 1]);
            WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 2]);
            WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 3]);
            WR1_PROG(REG_1824H, 0x8c100005U);
            WR1_PROG(REG_1400H, 0x00410011U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            r_rsip_func100(bswap_32big(0x4cc9d0c0U), bswap_32big(0x285c134cU), bswap_32big(0x694389f1U),
                           bswap_32big(0x70edad2eU));
            WR1_PROG(REG_1408H, 0x00020000U);
            r_rsip_func101(bswap_32big(0x0aa2e517U), bswap_32big(0xa08dff28U), bswap_32big(0x26859917U),
                           bswap_32big(0x2f5a703fU));

            return RSIP_RET_PASS;
        }
    }
    else
    {
        r_rsip_func101(bswap_32big(0xcdc78747U), bswap_32big(0xd3cc54d6U), bswap_32big(0xbc2b3b37U),
                       bswap_32big(0x5cf957d6U));

        return RSIP_RET_PASS;
    }
}
