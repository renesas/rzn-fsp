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

rsip_ret_t r_rsip_pe7 (const uint32_t InData_HashType[],
                       const uint32_t InData_KDFInfo[],
                       const uint32_t InData_KDFInfo_Count[],
                       const uint32_t InData_OutDataType[],
                       const uint32_t InData_OutDataLocation[],
                       const uint32_t InData_SeqNum[],
                       uint32_t       OutData_HMACKeyIndex[],
                       uint32_t       OutData_KeyIndex[],
                       uint32_t       OutData_EncIV[])
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

    WR1_PROG(REG_1B00H, 0x00e70002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000002c7U);
    WR1_PROG(REG_1608H, 0x80030080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KDFInfo_Count[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_OutDataType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000c84U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    WR1_PROG(REG_1600H, 0x38000ca5U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_1600H, 0x3420a8c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000007U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xa3be5c7bU),
                   bswap_32big(0x4627ace0U),
                   bswap_32big(0x6125f4e1U),
                   bswap_32big(0xf6665e4fU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x6c00ec90U), bswap_32big(0xc669eb7cU), bswap_32big(0xb65696d1U),
                       bswap_32big(0x63cd27b9U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0x36772fe8U), bswap_32big(0xff621790U), bswap_32big(0x46f02b4bU),
                       bswap_32big(0xfa72e5d6U));
        WR1_PROG(REG_1600H, 0x00007c06U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01151dd8U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000000fU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x75139eb2U), bswap_32big(0xc7955e0aU), bswap_32big(0xd152f30bU),
                           bswap_32big(0x1eb86466U));
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01c38653U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000001fU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x6ba27948U), bswap_32big(0xc797cc96U), bswap_32big(0xc3bbf590U),
                           bswap_32big(0x6131de9eU));
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01dca3a3U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000000fU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x368d4f24U), bswap_32big(0x8a78286bU), bswap_32big(0xc55f7893U),
                           bswap_32big(0xf008a57dU));
        }
        else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01dca3a3U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000003U));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xe59fc0cdU), bswap_32big(0x4b0673b2U), bswap_32big(0x20758183U),
                           bswap_32big(0xfb3d80cdU));
        }
        else if (0x00000004U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01dca3a3U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000000bU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x461051d0U), bswap_32big(0x220ef9a8U), bswap_32big(0x11f7b7e4U),
                           bswap_32big(0xcbbae4b3U));
        }
        else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01ad9be9U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000013U));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xd5fcf62fU), bswap_32big(0xa37403a1U), bswap_32big(0x63361a8bU),
                           bswap_32big(0x23313203U));
        }
        else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01825405U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000001fU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x64f8548aU), bswap_32big(0x729b7d3aU), bswap_32big(0xb0429c94U),
                           bswap_32big(0x6d29dd7bU));
        }

        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010100U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_OutDataLocation[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003608U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00056a10U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003628U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000262eU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00056a31U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00002e20U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x342028b1U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_1600H, 0x34202a11U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        r_rsip_func100(bswap_32big(0x497f7df3U), bswap_32big(0x707f3e44U), bswap_32big(0xb7abc0d8U),
                       bswap_32big(0x9dba6594U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x639120d7U), bswap_32big(0x9e5dc8deU), bswap_32big(0x68d9bdeaU),
                           bswap_32big(0xbcc211a7U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0xe774e5c1U), bswap_32big(0x92a00efcU), bswap_32big(0xcdad24e9U),
                           bswap_32big(0xf0b92668U));
            WR1_PROG(REG_1600H, 0x00003651U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00002a50U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000a73U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x000009efU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000a94U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000ad6U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81010200U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
            r_rsip_func100(bswap_32big(0x5e6bbb87U), bswap_32big(0xab8e379cU), bswap_32big(0x5b0269dcU),
                           bswap_32big(0xc4969099U));
            WR1_PROG(REG_1608H, 0x81010220U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[1]);
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01f51082U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = S_RAM[0]; iLoop < S_RAM[0 + 1]; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_1600H, 0x34202a72U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x2000d2c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00007c16U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_143CH, 0x00602000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1444H, 0x000003c7U);
                WR1_PROG(REG_1608H, 0x80040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * 16 + 0]);
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * 16 + 1]);
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * 16 + 2]);
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * 16 + 3]);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x0000e701U));
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x89aad925U),
                               bswap_32big(0x258884baU),
                               bswap_32big(0xd70be1d4U),
                               bswap_32big(0x44bae9c6U));
                r_rsip_func045();
                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x0000e701U));
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xf16d6144U),
                               bswap_32big(0x2a0a259dU),
                               bswap_32big(0x9e40e504U),
                               bswap_32big(0x5c6668f1U));
                r_rsip_func046();
                WR1_PROG(REG_1444H, 0x000007c2U);
                WR1_PROG(REG_1A2CH, 0x40000100U);
                WR1_PROG(REG_1A24H, 0xf7009d07U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * 16 + 4]);
                WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * 16 + 5]);
                WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * 16 + 6]);
                WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * 16 + 7]);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * 16 + 8]);
                WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * 16 + 9]);
                WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * 16 + 10]);
                WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * 16 + 11]);
                WR1_PROG(REG_1608H, 0x8088000fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1400H, 0x03420021U);
                WAIT_STS(REG_1404H, 30U, 0U);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1444H, 0x000003c2U);
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x07008d05U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * 16 + 12]);
                WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * 16 + 13]);
                WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * 16 + 14]);
                WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * 16 + 15]);
                WR1_PROG(REG_1A24H, 0x9c100005U);
                WR1_PROG(REG_1400H, 0x00820011U);
                WAIT_STS(REG_1404H, 30U, 0U);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1600H, 0x0000a5e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000020U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002e60U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func100(bswap_32big(0xa4ca7eb4U),
                               bswap_32big(0x75d65ef8U),
                               bswap_32big(0xae9d1d1cU),
                               bswap_32big(0x1c9dbdedU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1600H, 0x0000d280U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x99dc3135U),
                                   bswap_32big(0xa5d3a1b1U),
                                   bswap_32big(0xb1fed39dU),
                                   bswap_32big(0x29a8d9ecU));
                }
                else
                {
                    r_rsip_func101(bswap_32big(0x3135083fU),
                                   bswap_32big(0xfc0385fbU),
                                   bswap_32big(0xc60c038bU),
                                   bswap_32big(0x561d2c4fU));
                }
            }

            WR1_PROG(REG_1600H, 0x38000a72U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x38000e94U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00A60000U);
            r_rsip_func100(bswap_32big(0xcbec165aU), bswap_32big(0xcb5ac25aU), bswap_32big(0x1253f52eU),
                           bswap_32big(0xf475acb1U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x10bc897dU),
                               bswap_32big(0xf4ea44e5U),
                               bswap_32big(0xc1d5daceU),
                               bswap_32big(0x1f480bc1U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0xd4bf6de2U),
                               bswap_32big(0x02d99dd9U),
                               bswap_32big(0x9dab61c8U),
                               bswap_32big(0xcaccd797U));
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
                WR1_PROG(REG_1420H, bswap_32big(0x0000e702U));
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x44be1dedU),
                               bswap_32big(0xf5fc3c35U),
                               bswap_32big(0xab7a48afU),
                               bswap_32big(0x0d8a33e0U));
                r_rsip_func045();
                WR1_PROG(REG_1600H, 0x000034e9U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x0000e702U));
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xb5aced5cU),
                               bswap_32big(0x2fdec34fU),
                               bswap_32big(0x810191ccU),
                               bswap_32big(0xcd8ea39bU));
                r_rsip_func046();
                WR1_PROG(REG_1600H, 0x00008d00U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000001fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b5e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000080U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x3420a8c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000002U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                r_rsip_func100(bswap_32big(0xdb651402U),
                               bswap_32big(0x715e36ceU),
                               bswap_32big(0xed6d576dU),
                               bswap_32big(0xbf6f183bU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    for (iLoop = 0; iLoop < 32; iLoop = iLoop + 1)
                    {
                        WR1_PROG(REG_1600H, 0x00000ab5U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x02003aa8U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x02003eafU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00002d00U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00002de0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                    }

                    WR1_PROG(REG_1600H, 0x0000b5e0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000080U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x38000cc6U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    r_rsip_func100(bswap_32big(0x8b08ee35U),
                                   bswap_32big(0x9014ca53U),
                                   bswap_32big(0xc8e1d09cU),
                                   bswap_32big(0xe863a94cU));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_func100(bswap_32big(0x410e2219U),
                                       bswap_32big(0x1d5846baU),
                                       bswap_32big(0x430c1e64U),
                                       bswap_32big(0xb2fc422eU));
                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0xe7009d05U);
                        WR1_PROG(REG_1608H, 0x8184000fU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1400H, 0x00890011U);
                        WAIT_STS(REG_1404H, 30U, 0U);
                        WR1_PROG(REG_143CH, 0x00001800U);
                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[4]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[5]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[6]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[7]);
                        r_rsip_func100(bswap_32big(0xce26adfbU),
                                       bswap_32big(0xa8144e06U),
                                       bswap_32big(0xb9b20129U),
                                       bswap_32big(0x459cd744U));
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
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[8]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[9]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[10]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[11]);
                        r_rsip_func101(bswap_32big(0xd94eb17cU),
                                       bswap_32big(0x106fca7eU),
                                       bswap_32big(0x7fa0bb26U),
                                       bswap_32big(0x319cd237U));
                    }
                    else
                    {
                        r_rsip_func100(bswap_32big(0x204c4e85U),
                                       bswap_32big(0x1078f9bcU),
                                       bswap_32big(0x889134ffU),
                                       bswap_32big(0x7e38f106U));
                        WR1_PROG(REG_1A2CH, 0x40000100U);
                        WR1_PROG(REG_1A24H, 0xe7009d07U);
                        WR1_PROG(REG_1608H, 0x8188000fU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1400H, 0x00890021U);
                        WAIT_STS(REG_1404H, 30U, 0U);
                        WR1_PROG(REG_143CH, 0x00001800U);
                        WR1_PROG(REG_1408H, 0x00002022U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[4]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[5]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[6]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[7]);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[8]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[9]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[10]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[11]);
                        r_rsip_func100(bswap_32big(0x754e6a31U),
                                       bswap_32big(0xc1139285U),
                                       bswap_32big(0x55916d5aU),
                                       bswap_32big(0xb581c007U));
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
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[12]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[13]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[14]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[15]);
                        r_rsip_func101(bswap_32big(0x52b02220U),
                                       bswap_32big(0x6f280d4eU),
                                       bswap_32big(0xe3f11c13U),
                                       bswap_32big(0xaa898301U));
                    }

                    r_rsip_func100(bswap_32big(0x082c10ceU),
                                   bswap_32big(0x5b7c64deU),
                                   bswap_32big(0x0237214bU),
                                   bswap_32big(0x6ebaaf3eU));
                    WR1_PROG(REG_1608H, 0x81040000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1408H, 0x00005012U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[1]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[2]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[3]);
                    r_rsip_func102(bswap_32big(0xbc5b015cU),
                                   bswap_32big(0x828b3332U),
                                   bswap_32big(0xad431e54U),
                                   bswap_32big(0x7d80dd70U));
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_PASS;
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x3420a8c0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000005U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00A60000U);
                    r_rsip_func100(bswap_32big(0xe2828cb0U),
                                   bswap_32big(0xee281288U),
                                   bswap_32big(0x16dcbd18U),
                                   bswap_32big(0x0ab05984U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        for (iLoop = 0; iLoop < 32; iLoop = iLoop + 1)
                        {
                            WR1_PROG(REG_1600H, 0x00000ab5U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x02003aa8U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x02003eafU);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00002d00U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00002de0U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                        }

                        WR1_PROG(REG_1600H, 0x0000b5e0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00000080U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x380088c0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00000005U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1608H, 0x00000080U);
                        WR1_PROG(REG_143CH, 0x00260000U);
                        r_rsip_func100(bswap_32big(0x1dee20f8U),
                                       bswap_32big(0x8384dd43U),
                                       bswap_32big(0x6fd7b2c8U),
                                       bswap_32big(0x8fec8e1fU));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            WR1_PROG(REG_1600H, 0x0000a5e0U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00000014U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1608H, 0x8083000fU);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1400H, 0x0340000dU);
                            WAIT_STS(REG_1404H, 30U, 0U);
                            WR1_PROG(REG_143CH, 0x00001800U);
                            WR1_PROG(REG_1600H, 0x0000b5e0U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00000080U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_func101(bswap_32big(0x7e9da1ceU),
                                           bswap_32big(0x785344a9U),
                                           bswap_32big(0x53bb965fU),
                                           bswap_32big(0x0b2b1b75U));
                        }
                        else
                        {
                            r_rsip_func101(bswap_32big(0xcc0f6275U),
                                           bswap_32big(0x05aa7843U),
                                           bswap_32big(0x8466f144U),
                                           bswap_32big(0x7566a578U));
                        }

                        r_rsip_func100(bswap_32big(0x52714255U),
                                       bswap_32big(0xcedd7a6dU),
                                       bswap_32big(0xd089f56aU),
                                       bswap_32big(0xeb05934aU));
                        WR1_PROG(REG_1A2CH, 0x40000100U);
                        WR1_PROG(REG_1A24H, 0xe7009d07U);
                        WR1_PROG(REG_1608H, 0x8188000fU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1400H, 0x00890021U);
                        WAIT_STS(REG_1404H, 30U, 0U);
                        WR1_PROG(REG_143CH, 0x00001800U);
                        WR1_PROG(REG_1408H, 0x00002022U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[4]);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[5]);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[6]);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[7]);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[8]);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[9]);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[10]);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[11]);
                        r_rsip_func100(bswap_32big(0x316376c7U),
                                       bswap_32big(0xd88a7a7cU),
                                       bswap_32big(0x55a2c181U),
                                       bswap_32big(0xe799534dU));
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
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[12]);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[13]);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[14]);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[15]);
                        r_rsip_func100(bswap_32big(0xe79480b7U),
                                       bswap_32big(0xc18c5fbbU),
                                       bswap_32big(0x65d29862U),
                                       bswap_32big(0x6dcace1cU));
                        WR1_PROG(REG_1608H, 0x81040000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1408H, 0x00005012U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[0]);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[1]);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[2]);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[3]);
                        r_rsip_func102(bswap_32big(0x745f812eU),
                                       bswap_32big(0xf363f00bU),
                                       bswap_32big(0x91db2becU),
                                       bswap_32big(0xf4c8a449U));
                        WR1_PROG(REG_14B8H, 0x00000040U);
                        WAIT_STS(REG_142CH, 12U, 0U);

                        return RSIP_RET_PASS;
                    }
                    else
                    {
                        for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
                        {
                            WR1_PROG(REG_1600H, 0x00000ab5U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x02003aa8U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x02003eafU);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00002d00U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00002de0U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                        }

                        WR1_PROG(REG_1600H, 0x0000b5e0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00000080U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x380088c0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00000002U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1608H, 0x00000080U);
                        WR1_PROG(REG_143CH, 0x00260000U);
                        r_rsip_func100(bswap_32big(0xb1ab7184U),
                                       bswap_32big(0x131c1a79U),
                                       bswap_32big(0x8ddf3645U),
                                       bswap_32big(0x43546d11U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            WR1_PROG(REG_1A24H, 0x08000105U);
                            WR1_PROG(REG_1608H, 0x8184000fU);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1400H, 0x00890011U);
                            WAIT_STS(REG_1404H, 30U, 0U);
                            WR1_PROG(REG_143CH, 0x00001800U);
                            WR1_PROG(REG_1608H, 0x80040140U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1400H, 0x03420011U);
                            WAIT_STS(REG_1404H, 30U, 0U);
                            WR1_PROG(REG_143CH, 0x00001800U);
                            r_rsip_func101(bswap_32big(0xdac7eb6bU),
                                           bswap_32big(0x971b26dfU),
                                           bswap_32big(0x8490bef2U),
                                           bswap_32big(0xa36ccd6dU));
                        }
                        else
                        {
                            WR1_PROG(REG_1444H, 0x000001c7U);
                            WR1_PROG(REG_1608H, 0x80020080U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WAIT_STS(REG_1444H, 31U, 1U);
                            WR1_ADDR(REG_1420H, &InData_SeqNum[0]);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WAIT_STS(REG_1444H, 31U, 1U);
                            WR1_ADDR(REG_1420H, &InData_SeqNum[1]);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x380088c0U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00000003U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1608H, 0x00000080U);
                            WR1_PROG(REG_143CH, 0x00260000U);
                            r_rsip_func100(bswap_32big(0x5ae0bb2bU),
                                           bswap_32big(0x81f344a4U),
                                           bswap_32big(0x6dea862eU),
                                           bswap_32big(0x4b1e6ebaU));
                            WR1_PROG(REG_143CH, 0x00400000U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            if (CHCK_STS(REG_143CH, 22U, 1U))
                            {
                                WR1_PROG(REG_1600H, 0x0000394fU);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1600H, 0x00003564U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1600H, 0x00003585U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1600H, 0x0000b5a0U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1600H, 0x00000001U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                r_rsip_func101(bswap_32big(0xfe4a9d1bU), bswap_32big(0xaa68c734U),
                                               bswap_32big(0x08db4efeU), bswap_32big(0xb1003a74U));
                            }
                            else
                            {
                                WR1_PROG(REG_1A24H, 0x08000105U);
                                WR1_PROG(REG_1608H, 0x8183000fU);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1400H, 0x0089000dU);
                                WAIT_STS(REG_1404H, 30U, 0U);
                                WR1_PROG(REG_143CH, 0x00001800U);
                                WR1_PROG(REG_1400H, 0x00800005U);
                                WAIT_STS(REG_1404H, 30U, 0U);
                                WR1_PROG(REG_143CH, 0x00001800U);
                                WR1_PROG(REG_1608H, 0x80040140U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1400H, 0x03420011U);
                                WAIT_STS(REG_1404H, 30U, 0U);
                                WR1_PROG(REG_143CH, 0x00001800U);
                                WR1_PROG(REG_1600H, 0x00000964U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1600H, 0x00000985U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1600H, 0x0000b5a0U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1600H, 0x00000001U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                r_rsip_func101(bswap_32big(0x7ca3e992U), bswap_32big(0x0ea1e86aU),
                                               bswap_32big(0x7fec74aaU), bswap_32big(0xff751002U));
                            }
                        }

                        r_rsip_func100(bswap_32big(0x0d4cd8ebU),
                                       bswap_32big(0x8ec1ec1cU),
                                       bswap_32big(0x1f661bc8U),
                                       bswap_32big(0xe0de9cd6U));
                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0xe7009d05U);
                        WR1_PROG(REG_1608H, 0x81040140U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1400H, 0x00890011U);
                        WAIT_STS(REG_1404H, 30U, 0U);
                        WR1_PROG(REG_143CH, 0x00001800U);
                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[4]);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[5]);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[6]);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[7]);
                        r_rsip_func100(bswap_32big(0xf44805deU),
                                       bswap_32big(0xbdfa5495U),
                                       bswap_32big(0xa1c0dd0eU),
                                       bswap_32big(0x5cb9d4a9U));
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
                        RD1_ADDR(REG_1420H, &OutData_EncIV[8]);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[9]);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[10]);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[11]);
                        r_rsip_func100(bswap_32big(0x8b37a0c4U),
                                       bswap_32big(0x82fc6cebU),
                                       bswap_32big(0x75b23765U),
                                       bswap_32big(0xc2441275U));
                        WR1_PROG(REG_1608H, 0x81040000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1408H, 0x00005012U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[0]);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[1]);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[2]);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[3]);
                        r_rsip_func102(bswap_32big(0x750d13f9U),
                                       bswap_32big(0x3ad8e0d3U),
                                       bswap_32big(0x7b2b88c4U),
                                       bswap_32big(0x2f3f532dU));
                        WR1_PROG(REG_14B8H, 0x00000040U);
                        WAIT_STS(REG_142CH, 12U, 0U);

                        return RSIP_RET_PASS;
                    }
                }
            }
        }
    }
}
