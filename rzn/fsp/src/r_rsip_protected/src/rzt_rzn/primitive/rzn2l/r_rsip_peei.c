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

rsip_ret_t r_rsip_peei (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_MsgDgst[],
                        const uint32_t InData_Signature[])
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
    if (0x0U != RD1_MASK(REG_14BCH, 0x1fU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00ee0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000b5aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000b9cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    WR1_PROG(REG_1404H, 0x18e00000U);
    WR1_PROG(REG_1400H, 0x00c00051U);
    WAIT_STS(REG_1404H, 30U, 0U);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1404H, 0x19300000U);
    WR1_PROG(REG_1400H, 0x00c00051U);
    WAIT_STS(REG_1404H, 30U, 0U);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1404H, 0x19100000U);
    WR1_PROG(REG_1444H, 0x000007c2U);
    WR1_PROG(REG_1A2CH, 0x00000100U);
    WR1_PROG(REG_1A24H, 0x08008107U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_Signature[0]);
    WR1_ADDR(REG_1420H, &InData_Signature[1]);
    WR1_ADDR(REG_1420H, &InData_Signature[2]);
    WR1_ADDR(REG_1420H, &InData_Signature[3]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_Signature[4]);
    WR1_ADDR(REG_1420H, &InData_Signature[5]);
    WR1_ADDR(REG_1420H, &InData_Signature[6]);
    WR1_ADDR(REG_1420H, &InData_Signature[7]);
    WR1_PROG(REG_1400H, 0x00c20021U);
    WAIT_STS(REG_1404H, 30U, 0U);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1404H, 0x19600000U);
    WR1_PROG(REG_1444H, 0x000007c2U);
    WR1_PROG(REG_1A2CH, 0x00000100U);
    WR1_PROG(REG_1A24H, 0x08008107U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_Signature[8]);
    WR1_ADDR(REG_1420H, &InData_Signature[9]);
    WR1_ADDR(REG_1420H, &InData_Signature[10]);
    WR1_ADDR(REG_1420H, &InData_Signature[11]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_Signature[12]);
    WR1_ADDR(REG_1420H, &InData_Signature[13]);
    WR1_ADDR(REG_1420H, &InData_Signature[14]);
    WR1_ADDR(REG_1420H, &InData_Signature[15]);
    WR1_PROG(REG_1400H, 0x00c20021U);
    WAIT_STS(REG_1404H, 30U, 0U);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1600H, 0x00000bdeU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000007c7U);
    WR1_PROG(REG_1608H, 0x8088001eU);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0; iLoop < 8; iLoop = iLoop + 1)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_MsgDgst[iLoop + 0]);
        WR1_PROG(REG_1458H, 0x00000000U);
    }

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
    WR1_PROG(REG_1420H, bswap_32big(0x0000ee01U));
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func101(bswap_32big(0x211e8584U),
                   bswap_32big(0x54058628U),
                   bswap_32big(0x31e9c1acU),
                   bswap_32big(0xa046e76cU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01d8c542U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x0000ee01U));
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func101(bswap_32big(0xfe92bfefU),
                   bswap_32big(0x42cc787dU),
                   bswap_32big(0xc5a1c34cU),
                   bswap_32big(0x716e586dU));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000044U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x00000bc2U);
    WR1_PROG(REG_1A2CH, 0x40000200U);
    WR1_PROG(REG_1A24H, 0xe8009107U);
    WR1_PROG(REG_1600H, 0x0000b420U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000060U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80900001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[4]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[5]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[6]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[7]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[8]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[9]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[10]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[11]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[12]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[13]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[14]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[15]);
    WR1_PROG(REG_1400H, 0x03420031U);
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
    WR1_ADDR(REG_1420H, &InData_KeyIndex[16]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[17]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[18]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[19]);
    WR1_PROG(REG_1400H, 0x03420011U);
    WAIT_STS(REG_1404H, 30U, 0U);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[20]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[21]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[22]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[23]);
    r_rsip_func100(bswap_32big(0x8ca19877U),
                   bswap_32big(0xca49742fU),
                   bswap_32big(0x71a1b57aU),
                   bswap_32big(0x0803b259U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x4354515fU), bswap_32big(0x94ec2adbU), bswap_32big(0x9d1a5f93U),
                       bswap_32big(0x983d6eeeU));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        OFS_ADR = 128;
        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x000000eeU));
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x0e252805U), bswap_32big(0xd002410bU), bswap_32big(0x8e0af417U),
                       bswap_32big(0x0b4b155dU));
        r_rsip_func073(OFS_ADR);
        r_rsip_func100(bswap_32big(0xc7f1a0edU), bswap_32big(0x9b04b646U), bswap_32big(0xe161a4e4U),
                       bswap_32big(0x467b7353U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xa377f39eU), bswap_32big(0xce49a4b9U), bswap_32big(0xd4e221ccU),
                           bswap_32big(0xdd733653U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func101(bswap_32big(0x9cf5fe5cU), bswap_32big(0x4b987478U), bswap_32big(0x1cb9a479U),
                           bswap_32big(0x88f502daU));

            return RSIP_RET_PASS;
        }
    }
}
