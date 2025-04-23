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

rsip_ret_t r_rsip_pe2 (const uint32_t InData_PubKeyType[],
                       const uint32_t InData_PubKey[],
                       const uint32_t InData_KeyIndex[],
                       uint32_t       OutData_EncSecret[])
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

    WR1_PROG(REG_1B00H, 0x00e20002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    WR1_PROG(REG_1600H, 0x00000b5aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000b9cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    OFS_ADR = 128;
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
    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x000000e2U));
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func101(bswap_32big(0xa93a3323U),
                   bswap_32big(0xdbb81783U),
                   bswap_32big(0x95c730edU),
                   bswap_32big(0x3ec34b64U));
    r_rsip_func086(OFS_ADR);
    WR1_PROG(REG_1010H, 0x00000018U);
    WR1_PROG(REG_101CH, 0x00000070U);
    WR1_PROG(REG_1004H, 0x04040010U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
    WR1_PROG(REG_1444H, 0x000003c7U);
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[2]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[3]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x0000e201U));
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func101(bswap_32big(0xbc567aceU),
                   bswap_32big(0x0c82e736U),
                   bswap_32big(0xe0a3cd64U),
                   bswap_32big(0x1e30d80dU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x019d1850U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x0000e201U));
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func101(bswap_32big(0xb11b0c68U),
                   bswap_32big(0x9a9d5374U),
                   bswap_32big(0x4e619d08U),
                   bswap_32big(0x8de370a3U));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000007c2U);
    WR1_PROG(REG_1A2CH, 0x40000100U);
    WR1_PROG(REG_1A24H, 0xf7009d07U);
    for (iLoop = 0; iLoop < 8; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
    }

    WR1_PROG(REG_1404H, 0x13200000U);
    WR1_PROG(REG_1400H, 0x00c20021U);
    WAIT_STS(REG_1404H, 30U, 0U);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x07008d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    WR1_PROG(REG_1400H, 0x00820011U);
    WAIT_STS(REG_1404H, 30U, 0U);
    WR1_PROG(REG_143CH, 0x00001800U);
    r_rsip_func100(bswap_32big(0x8440d7b9U),
                   bswap_32big(0x34e0401cU),
                   bswap_32big(0xf792330fU),
                   bswap_32big(0xc2e84561U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x27c41ce0U), bswap_32big(0x250b744fU), bswap_32big(0x7651da2eU),
                       bswap_32big(0x3583b3adU));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1404H, 0x10c00000U);
        WR1_PROG(REG_1400H, 0x00c00051U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1404H, 0x11100000U);
        WR1_PROG(REG_1400H, 0x00c00051U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010360U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_PubKeyType[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38000f7bU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x66662829U), bswap_32big(0xd86941a0U), bswap_32big(0x7ed67ef8U),
                       bswap_32big(0xda9f4076U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1444H, 0x000007d0U);
            for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
            {
                WR1_ADDR((&(REG_00F0H))[iLoop / 4], &InData_PubKey[(iLoop / 4) + 0]);
            }

            WR1_PROG(REG_1444H, 0x000007d0U);
            for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
            {
                WR1_ADDR((&(REG_0140H))[iLoop / 4], &InData_PubKey[(iLoop / 4) + 8]);
            }

            r_rsip_func101(bswap_32big(0xacd95299U), bswap_32big(0x686cd141U), bswap_32big(0xb0b9c319U),
                           bswap_32big(0x372b32b3U));
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000003c7U);
            WR1_PROG(REG_1608H, 0x80040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[1]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[2]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[3]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000e202U));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x33b779f2U), bswap_32big(0xd555c804U), bswap_32big(0x85a8913fU),
                           bswap_32big(0x46257c13U));
            r_rsip_func045();
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01d8c542U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000e202U));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x9e1ebc87U), bswap_32big(0x49cebd39U), bswap_32big(0x1a4d7204U),
                           bswap_32big(0x8aaa29feU));
            r_rsip_func046();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000044U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1444H, 0x00000bc2U);
            WR1_PROG(REG_1A2CH, 0x40000200U);
            WR1_PROG(REG_1A24H, 0xe8009107U);
            for (iLoop = 0; iLoop < 12; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 4]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 5]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 6]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 7]);
            }

            WR1_PROG(REG_1404H, 0x10f00000U);
            WR1_PROG(REG_1400H, 0x00c20021U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1404H, 0x11400000U);
            WR1_PROG(REG_1400H, 0x00c20011U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x49108054U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8008105U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[16]);
            WR1_ADDR(REG_1420H, &InData_PubKey[17]);
            WR1_ADDR(REG_1420H, &InData_PubKey[18]);
            WR1_ADDR(REG_1420H, &InData_PubKey[19]);
            WR1_PROG(REG_1400H, 0x00c20011U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A24H, 0x9c100005U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[20]);
            WR1_ADDR(REG_1420H, &InData_PubKey[21]);
            WR1_ADDR(REG_1420H, &InData_PubKey[22]);
            WR1_ADDR(REG_1420H, &InData_PubKey[23]);
            r_rsip_func100(bswap_32big(0x1772ccf7U), bswap_32big(0xf68f97b1U), bswap_32big(0xb52c70c4U),
                           bswap_32big(0x5c655461U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0xb4454a54U),
                               bswap_32big(0x2beeeca0U),
                               bswap_32big(0x08747307U),
                               bswap_32big(0x610c9781U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func101(bswap_32big(0xc493cf2eU),
                               bswap_32big(0xd82d6647U),
                               bswap_32big(0x0df76a32U),
                               bswap_32big(0xedfafb32U));
            }
        }

        WR1_PROG(REG_1404H, 0x11600000U);
        WR1_PROG(REG_1400H, 0x00c000f1U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000200U);
        WR1_PROG(REG_1004H, 0x04040002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000160U);
        WR1_PROG(REG_1018H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000228U);
        WR1_PROG(REG_1004H, 0x04040002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x000000e2U));
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x075a9426U), bswap_32big(0x54681cfcU), bswap_32big(0x6d628b8cU),
                       bswap_32big(0x82e32b91U));
        r_rsip_func088();
        r_rsip_func100(bswap_32big(0xd2337f09U), bswap_32big(0x34d9b84bU), bswap_32big(0x65b5d895U),
                       bswap_32big(0xf56c332cU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xe09b74e1U), bswap_32big(0x2607a1c1U), bswap_32big(0x59998a61U),
                           bswap_32big(0x55dcb52aU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0xe80419f7U), bswap_32big(0x851be07cU), bswap_32big(0x4eb92985U),
                           bswap_32big(0xbe74d794U));
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
            WR1_PROG(REG_1420H, bswap_32big(0x0000e203U));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x3320d7d5U), bswap_32big(0x04e0def6U), bswap_32big(0x28bbb230U),
                           bswap_32big(0xc1a62e60U));
            r_rsip_func045();
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01dec19dU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000e203U));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xf311d6d8U), bswap_32big(0xd85abc8dU), bswap_32big(0x8f5d8b4cU),
                           bswap_32big(0x6564c8d6U));
            r_rsip_func046();
            r_rsip_func100(bswap_32big(0x064b6d6aU), bswap_32big(0x347a1406U), bswap_32big(0x8cabfb40U),
                           bswap_32big(0xe96d66e2U));
            WR1_PROG(REG_1A2CH, 0x40000100U);
            WR1_PROG(REG_1A24H, 0xe7009d07U);
            WR1_PROG(REG_1404H, 0x12800000U);
            WR1_PROG(REG_1400H, 0x00830021U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1408H, 0x00002022U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_EncSecret[4]);
            RD1_ADDR(REG_1420H, &OutData_EncSecret[5]);
            RD1_ADDR(REG_1420H, &OutData_EncSecret[6]);
            RD1_ADDR(REG_1420H, &OutData_EncSecret[7]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_EncSecret[8]);
            RD1_ADDR(REG_1420H, &OutData_EncSecret[9]);
            RD1_ADDR(REG_1420H, &OutData_EncSecret[10]);
            RD1_ADDR(REG_1420H, &OutData_EncSecret[11]);
            r_rsip_func100(bswap_32big(0xe375225eU), bswap_32big(0xa3c9e6a7U), bswap_32big(0xd36e32ffU),
                           bswap_32big(0xa51f47b0U));
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
            RD1_ADDR(REG_1420H, &OutData_EncSecret[12]);
            RD1_ADDR(REG_1420H, &OutData_EncSecret[13]);
            RD1_ADDR(REG_1420H, &OutData_EncSecret[14]);
            RD1_ADDR(REG_1420H, &OutData_EncSecret[15]);
            r_rsip_func100(bswap_32big(0xd4d60c40U), bswap_32big(0x380c443aU), bswap_32big(0x04e16f60U),
                           bswap_32big(0x17cb5f76U));
            WR1_PROG(REG_1608H, 0x81040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_EncSecret[0]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_EncSecret[1]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_EncSecret[2]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_EncSecret[3]);
            r_rsip_func102(bswap_32big(0xb552ca6fU), bswap_32big(0x1dcbfb2cU), bswap_32big(0x81699094U),
                           bswap_32big(0xae1bc20cU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
