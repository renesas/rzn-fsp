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

rsip_ret_t r_rsip_pf4 (uint32_t const InData_CurveType[],
                       uint32_t const InData_Cmd[],
                       uint32_t       OutData_PubKeyIndex[],
                       uint32_t       OutData_PrivKeyIndex[])
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
    if (0x0U != RD1_MASK(REG_14B8H, 0x1eU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00f40002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010340U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010380U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3020ab80U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00060020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b780U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000bffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x30000f5aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00030020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000d3e1U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000060U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000f9cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000d3e1U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38008be0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xfd30fcc5U),
                   bswap_32big(0x3e087c4dU),
                   bswap_32big(0xf94dc3bfU),
                   bswap_32big(0x242649d2U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x4f3f0d85U), bswap_32big(0xe9ab49c0U), bswap_32big(0x0da11dd2U),
                       bswap_32big(0x92b68d33U));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1404H, 0x10200000U);
        WR1_PROG(REG_1400H, 0x00c00051U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1404H, 0x10700000U);
        WR1_PROG(REG_1400H, 0x00c00051U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1404H, 0x13400000U);
        WR1_PROG(REG_1400H, 0x00c00051U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1404H, 0x17f00000U);
        WR1_PROG(REG_1400H, 0x00c00051U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1404H, 0x18400000U);
        WR1_PROG(REG_1400H, 0x00c00051U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1404H, 0x18900000U);
        WR1_PROG(REG_1400H, 0x00c00051U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        r_rsip_func100(bswap_32big(0xf8cb9308U), bswap_32big(0x71edd6ffU), bswap_32big(0x816f2e9bU),
                       bswap_32big(0xb17d39fdU));
        WR1_PROG(REG_1600H, 0x30003340U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00010020U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b400U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000158U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000060U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x30003380U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00070020U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b400U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00030040U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b400U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x000000C8U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00050040U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b400U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000110U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x81010000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1408H, 0x00005006U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
        OFS_ADR = S_RAM[0];
        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x000000f4U));
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x081228b9U), bswap_32big(0xda711396U), bswap_32big(0x9c422d4dU),
                       bswap_32big(0x2055891fU));
        r_rsip_func086(OFS_ADR);
        r_rsip_func100(bswap_32big(0x68295f65U), bswap_32big(0xdf591263U), bswap_32big(0x3ade490eU),
                       bswap_32big(0x2d7c2488U));
        WR1_PROG(REG_1010H, 0x00000020U);
        WR1_PROG(REG_101CH, 0x000000c0U);
        WR1_PROG(REG_1004H, 0x04040010U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1010H, 0x00000018U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1004H, 0x04040010U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x12c80000U);
        WR1_PROG(REG_1600H, 0x00007c1cU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0x35a1e0a4U), bswap_32big(0x23d7c015U), bswap_32big(0x3ad9b2a3U),
                           bswap_32big(0xe177cadfU));
            WR1_PROG(REG_1400H, 0x00c00009U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1400H, 0x00c20009U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1400H, 0x00020009U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            r_rsip_func101(bswap_32big(0x757f46b8U), bswap_32big(0x339036beU), bswap_32big(0x227269f9U),
                           bswap_32big(0xc98f86b7U));
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0x6d783d6dU), bswap_32big(0x659de292U), bswap_32big(0xb16b1faeU),
                           bswap_32big(0xd8541cb2U));
            WR1_PROG(REG_1400H, 0x00c0000dU);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1400H, 0x00c20005U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1400H, 0x0002000dU);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            r_rsip_func101(bswap_32big(0x1575eab3U), bswap_32big(0xcf770d57U), bswap_32big(0x80bd0405U),
                           bswap_32big(0x538c7fe0U));
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1400H, 0x00c00011U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            r_rsip_func101(bswap_32big(0x4052b8c7U), bswap_32big(0xab41f3d3U), bswap_32big(0xffaba82fU),
                           bswap_32big(0x8b72a662U));
        }

        r_rsip_func100(bswap_32big(0x2199c0aaU), bswap_32big(0x2f331c8bU), bswap_32big(0x669f6e45U),
                       bswap_32big(0xa99abc4cU));
        r_rsip_func103();
        r_rsip_func100(bswap_32big(0x7c4eb8e5U), bswap_32big(0xc1157a2fU), bswap_32big(0xa90535a7U),
                       bswap_32big(0x119a89e5U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1400H, 0x00c20011U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1400H, 0x00c20011U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1404H, 0x10f00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        WR1_PROG(REG_1400H, 0x00c0001dU);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00c20005U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x0002000dU);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1014H, 0x000000c0U);
        WR1_PROG(REG_1018H, 0x00000110U);
        WR1_PROG(REG_1020H, 0x000001b0U);
        WR1_PROG(REG_1004H, 0x0404000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1444H, 0x000009b0U);
        WR1_PROG(REG_0138H, bswap_32big(0x00000000U));
        WR1_PROG(REG_013CH, bswap_32big(0x00000000U));
        WR1_PROG(REG_0140H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0144H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0148H, bswap_32big(0x00000000U));
        WR1_PROG(REG_014CH, bswap_32big(0x00000000U));
        WR1_PROG(REG_0150H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0154H, bswap_32big(0x00000001U));
        WR1_PROG(REG_0158H, bswap_32big(0x00000000U));
        WR1_PROG(REG_015CH, bswap_32big(0x00000000U));
        WR1_PROG(REG_1014H, 0x000001b0U);
        WR1_PROG(REG_1018H, 0x00000160U);
        WR1_PROG(REG_1020H, 0x00000250U);
        WR1_PROG(REG_1004H, 0x04040007U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        r_rsip_func100(bswap_32big(0x2ccd56cdU), bswap_32big(0x209c015dU), bswap_32big(0xe1f19ac5U),
                       bswap_32big(0xabb75ffdU));
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000821U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000863U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1404H, 0x12280000U);
        WR1_PROG(REG_1608H, 0x808a0001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1400H, 0x03430029U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        for (iLoop = 0; iLoop < 10; iLoop = iLoop + 1)
        {
            WR1_PROG(REG_1600H, 0x38000c63U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x20000842U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x10003841U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b7c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000001fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (jLoop = 0; jLoop < 32; jLoop = jLoop + 1)
            {
                WR1_PROG(REG_1600H, 0x3800585eU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x20003460U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x20002c60U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x10002c00U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x100033c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
            }

            WR1_PROG(REG_1600H, 0x0000a420U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000004U);
            WR1_PROG(REG_1458H, 0x00000000U);
        }

        WR1_PROG(REG_1404H, 0x14580000U);
        WR1_PROG(REG_1400H, 0x00c00029U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1014H, 0x00000250U);
        WR1_PROG(REG_1018H, 0x00000480U);
        WR1_PROG(REG_1020H, 0x000001b0U);
        WR1_PROG(REG_1004H, 0x05050009U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x10e80000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
        WR1_PROG(REG_1400H, 0x00c00025U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00c20005U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x0002000dU);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1600H, 0x00003403U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003060U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x81010060U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1408H, 0x00005006U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
        for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
        {
            WR1_PROG(REG_1014H, 0x000001b0U);
            WR1_PROG(REG_1018H, 0x00000110U);
            WR1_PROG(REG_1020H, 0x00000250U);
            WR1_PROG(REG_1004H, 0x05050007U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000250U);
            WR1_PROG(REG_1018H, 0x00000480U);
            WR1_PROG(REG_1020H, 0x000001b0U);
            WR1_PROG(REG_1004H, 0x05050009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1600H, 0x00003060U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xb04aace8U), bswap_32big(0xed0cbe8aU), bswap_32big(0x5aff5d27U),
                           bswap_32big(0x4c5554c6U));
        }

        WR1_PROG(REG_1600H, 0x00007c03U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1404H, 0x10e80000U);
        WR1_PROG(REG_1400H, 0x00c00029U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        r_rsip_func100(bswap_32big(0xc7c2b405U), bswap_32big(0x7240e1d1U), bswap_32big(0xb6a1bd75U),
                       bswap_32big(0x5e825b40U));
        WR1_PROG(REG_1600H, 0x0000a400U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000040U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x81010000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1408H, 0x00005006U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
        for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
        {
            WR1_PROG(REG_1014H, 0x000002f0U);
            WR1_PROG(REG_1018H, 0x000001b0U);
            WR1_PROG(REG_1020H, 0x00000250U);
            WR1_PROG(REG_1004H, 0x0505000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0xc2a690a6U), bswap_32big(0xabd30d4dU), bswap_32big(0xbc4b19fdU),
                           bswap_32big(0x35b3086aU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_1018H, 0x00000110U);
                WR1_PROG(REG_1020H, 0x000002f0U);
                WR1_PROG(REG_1004H, 0x05050009U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                r_rsip_func101(bswap_32big(0xe6b9e5f0U),
                               bswap_32big(0x03ffd701U),
                               bswap_32big(0x0311dcdaU),
                               bswap_32big(0x4dcca3a0U));
            }

            WR1_PROG(REG_1014H, 0x000001b0U);
            WR1_PROG(REG_1020H, 0x00000250U);
            WR1_PROG(REG_1004H, 0x0505000cU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000250U);
            WR1_PROG(REG_1018H, 0x00000110U);
            WR1_PROG(REG_1020H, 0x000001b0U);
            WR1_PROG(REG_1004H, 0x05050009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1600H, 0x00003000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x8fa50808U), bswap_32big(0x4bbcb2d6U), bswap_32big(0xaeb6df8eU),
                           bswap_32big(0x24bdb992U));
        }

        WR1_PROG(REG_1600H, 0x00007c00U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1404H, 0x10f00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        WR1_PROG(REG_1400H, 0x00c0001dU);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00c20005U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x0002000dU);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1014H, 0x000002f0U);
        WR1_PROG(REG_1018H, 0x00000110U);
        WR1_PROG(REG_1020H, 0x00000340U);
        WR1_PROG(REG_1004H, 0x04040009U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x11600000U);
        WR1_PROG(REG_1400H, 0x00c000f1U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x000000f4U));
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x685a515dU), bswap_32big(0xea518654U), bswap_32big(0x45d2297cU),
                       bswap_32big(0x4b9cdff2U));
        r_rsip_func087(OFS_ADR);
        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x000000f4U));
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x6e0ec123U), bswap_32big(0xc4564125U), bswap_32big(0x3ef5795bU),
                       bswap_32big(0x0b52c6edU));
        r_rsip_func088();
        r_rsip_func100(bswap_32big(0x102020d6U), bswap_32big(0x40be0804U), bswap_32big(0x4d3a256fU),
                       bswap_32big(0xc35fca31U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xf29f6d94U), bswap_32big(0x4b1a0f3fU), bswap_32big(0x7c2aa439U),
                           bswap_32big(0xf27d6ca9U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0xbde4ce2fU), bswap_32big(0x3a2037abU), bswap_32big(0x0a8fdb0eU),
                           bswap_32big(0xdbf214a7U));
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1608H, 0x80040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1400H, 0x03420011U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000f401U));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x3e962281U), bswap_32big(0x14c60fb1U), bswap_32big(0xbdabdac7U),
                           bswap_32big(0xafcd343aU));
            r_rsip_func045();
            r_rsip_func022();
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000f401U));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xbde43370U), bswap_32big(0x4831d3a3U), bswap_32big(0xaa2809deU),
                           bswap_32big(0x9d08d83fU));
            r_rsip_func046();
            r_rsip_func100(bswap_32big(0xa8a35895U), bswap_32big(0x3b61326aU), bswap_32big(0xccd4a931U),
                           bswap_32big(0xbd194174U));
            WR1_PROG(REG_1A2CH, 0x40000100U);
            WR1_PROG(REG_1A24H, 0xe7009d07U);
            WR1_PROG(REG_1404H, 0x13200000U);
            WR1_PROG(REG_1400H, 0x00830021U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1408H, 0x00002022U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[4]);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[5]);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[6]);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[7]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[8]);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[9]);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[10]);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[11]);
            r_rsip_func100(bswap_32big(0x32096abdU), bswap_32big(0x4d9b455eU), bswap_32big(0xda2e5a72U),
                           bswap_32big(0xd2128214U));
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x09108105U);
            WR1_PROG(REG_1400H, 0x00820011U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[12]);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[13]);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[14]);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[15]);
            r_rsip_func100(bswap_32big(0xe35b316cU), bswap_32big(0xde49353fU), bswap_32big(0x9ccd2e68U),
                           bswap_32big(0xa485617eU));
            WR1_PROG(REG_1608H, 0x81040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[1]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[2]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[3]);
            r_rsip_func100(bswap_32big(0x8724c4fdU), bswap_32big(0xfdcab4dfU), bswap_32big(0x4c364c86U),
                           bswap_32big(0x52ea27b0U));
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1608H, 0x80040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1400H, 0x03420011U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000f402U));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x1cc0266fU), bswap_32big(0x73ab6276U), bswap_32big(0x63832700U),
                           bswap_32big(0x89e2895aU));
            r_rsip_func045();
            r_rsip_func023();
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000f402U));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xe5c3b7e8U), bswap_32big(0x46882703U), bswap_32big(0xfce8de68U),
                           bswap_32big(0x38aad0a9U));
            r_rsip_func046();
            r_rsip_func100(bswap_32big(0x02961e1dU), bswap_32big(0x3db43b04U), bswap_32big(0xd342cab5U),
                           bswap_32big(0x2c2a5bdaU));
            WR1_PROG(REG_1A2CH, 0x40000200U);
            WR1_PROG(REG_1A24H, 0xe8009107U);
            WR1_PROG(REG_1404H, 0x12800000U);
            WR1_PROG(REG_1400H, 0x00830021U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1404H, 0x12d00000U);
            WR1_PROG(REG_1400H, 0x00830011U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1408H, 0x00002032U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[4]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[5]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[6]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[7]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[8]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[9]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[10]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[11]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[12]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[13]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[14]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[15]);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x49108054U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            r_rsip_func100(bswap_32big(0xbd94a164U), bswap_32big(0x4ae32549U), bswap_32big(0xa5c76cd3U),
                           bswap_32big(0xebccaddfU));
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8008105U);
            WR1_PROG(REG_1400H, 0x00830011U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[16]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[17]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[18]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[19]);
            r_rsip_func100(bswap_32big(0xd2e1edd3U), bswap_32big(0xd4cff76dU), bswap_32big(0x7a98b697U),
                           bswap_32big(0xb2117dcfU));
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c100104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[20]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[21]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[22]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[23]);
            r_rsip_func100(bswap_32big(0x86688a3bU), bswap_32big(0xff090630U), bswap_32big(0xf15b97adU),
                           bswap_32big(0xac755672U));
            WR1_PROG(REG_1608H, 0x81040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[1]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[2]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[3]);
            r_rsip_func102(bswap_32big(0xc3969f53U), bswap_32big(0x9922621eU), bswap_32big(0x7adffba3U),
                           bswap_32big(0x2e399e4eU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
