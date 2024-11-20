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

rsip_ret_t r_rsip_pe6 (const uint32_t InData_HashType[],
                       const uint32_t InData_KDFInfo[],
                       const uint32_t InData_KDFInfo_Count[],
                       const uint32_t InData_OutDataLength[],
                       uint32_t       OutData_KeyIndex[])
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

    WR1_PROG(REG_1B00H, 0x00e60002U);
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
    WR1_ADDR(REG_1420H, &InData_OutDataLength[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000c84U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xdaa92e49U),
                   bswap_32big(0xbf15bd42U),
                   bswap_32big(0x2095e20bU),
                   bswap_32big(0x69a93077U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x03c4fbc5U), bswap_32big(0x84ba84f6U), bswap_32big(0x77823b08U),
                       bswap_32big(0xc49e04c2U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x380088a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x380088a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000002U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38000fffU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x8b3e37d1U), bswap_32big(0x55ce3121U), bswap_32big(0xa625cdfdU),
                       bswap_32big(0x9fc322e0U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xe6910602U), bswap_32big(0x3ebe9333U), bswap_32big(0x56de0e1dU),
                           bswap_32big(0x9f2645ddU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1600H, 0x00003545U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00056d4aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x3420a8c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_1600H, 0x34202946U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0x623b122cU), bswap_32big(0x3f1a1a79U), bswap_32big(0xd17d2fc3U),
                           bswap_32big(0x12268eb5U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x18b10b09U),
                               bswap_32big(0xde75c392U),
                               bswap_32big(0x2e732903U),
                               bswap_32big(0xd85d343eU));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0x965fc11eU),
                               bswap_32big(0x5bcc0fdcU),
                               bswap_32big(0x9330f529U),
                               bswap_32big(0x7ed7cb57U));
                WR1_PROG(REG_1608H, 0x810100a0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x00005006U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
                WR1_PROG(REG_1600H, 0x00000908U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000929U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000009ceU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000009efU);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
                {
                    WR1_PROG(REG_1600H, 0x34202905U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x2000d1e0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00007c0fU);
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
                    WR1_PROG(REG_1420H, bswap_32big(0x0000e601U));
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x1c8df9aeU),
                                   bswap_32big(0xa3bf93d1U),
                                   bswap_32big(0x39236c6fU),
                                   bswap_32big(0x53ea9d05U));
                    r_rsip_func045();
                    WR1_PROG(REG_1600H, 0x0000b4e0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x01f51082U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1444H, 0x000000a7U);
                    WR1_PROG(REG_1608H, 0x800103a0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x0000e601U));
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x990110efU),
                                   bswap_32big(0x98982ec6U),
                                   bswap_32big(0xa7ec89f5U),
                                   bswap_32big(0xcdea7a72U));
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
                    WR1_PROG(REG_1608H, 0x80880009U);
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
                    WR1_PROG(REG_1600H, 0x00002d00U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x0000a520U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000020U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0xf1227f88U),
                                   bswap_32big(0x152c2c9cU),
                                   bswap_32big(0xd586f1b9U),
                                   bswap_32big(0xe7cedf84U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        WR1_PROG(REG_1600H, 0x0000d1c0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func101(bswap_32big(0xd66d7f74U),
                                       bswap_32big(0xb6a15fa3U),
                                       bswap_32big(0xc1cc2e0eU),
                                       bswap_32big(0xb9739bafU));
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0x73d2764dU),
                                       bswap_32big(0x10548afdU),
                                       bswap_32big(0xee5808a6U),
                                       bswap_32big(0x4c44551bU));
                    }
                }

                WR1_PROG(REG_1600H, 0x38000905U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x38000dceU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00A60000U);
                r_rsip_func100(bswap_32big(0xbb95ba3aU),
                               bswap_32big(0x4da0a56aU),
                               bswap_32big(0x59f95818U),
                               bswap_32big(0xef59db88U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func102(bswap_32big(0x51845803U),
                                   bswap_32big(0xcc61e3c8U),
                                   bswap_32big(0x034ee0b1U),
                                   bswap_32big(0x69c67cacU));
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    r_rsip_func100(bswap_32big(0xa9ff5aeeU),
                                   bswap_32big(0x9c7a689eU),
                                   bswap_32big(0x388f4781U),
                                   bswap_32big(0x9b733041U));
                    WR1_PROG(REG_1608H, 0x810100c0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1408H, 0x00005006U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
                    WR1_PROG(REG_1600H, 0x0000094aU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x0000b560U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000040U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002966U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000908U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00003526U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    for (iLoop = S_RAM[0]; iLoop < 64; iLoop = iLoop + 1)
                    {
                        WR1_PROG(REG_1600H, 0x02003d49U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00002d00U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00002d20U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func101(bswap_32big(0x690ed3c1U),
                                       bswap_32big(0xab89dbafU),
                                       bswap_32big(0xc1f0227aU),
                                       bswap_32big(0xc75e8a72U));
                    }

                    WR1_PROG(REG_1600H, 0x3800090bU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    WR1_PROG(REG_143CH, 0x00402000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0x3370c78eU),
                                   bswap_32big(0x940bf264U),
                                   bswap_32big(0x9bfd492bU),
                                   bswap_32big(0x6a874195U));
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
                    WR1_PROG(REG_1420H, bswap_32big(0x0000e602U));
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x215ba3aaU),
                                   bswap_32big(0x09fba440U),
                                   bswap_32big(0xcc4a5294U),
                                   bswap_32big(0xc058efaaU));
                    r_rsip_func045();
                    WR1_PROG(REG_1600H, 0x0000b4e0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x01c54b98U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1444H, 0x000000a7U);
                    WR1_PROG(REG_1608H, 0x800103a0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x0000e602U));
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xcd7bc21dU),
                                   bswap_32big(0xf8a8aefdU),
                                   bswap_32big(0x2c709eaeU),
                                   bswap_32big(0x92ba0557U));
                    r_rsip_func046();
                    r_rsip_func100(bswap_32big(0x8659916fU),
                                   bswap_32big(0xa969c878U),
                                   bswap_32big(0xdfa3a253U),
                                   bswap_32big(0x6b06932fU));
                    WR1_PROG(REG_1600H, 0x00000929U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1A2CH, 0x40000100U);
                    WR1_PROG(REG_1A24H, 0xe7009d07U);
                    WR1_PROG(REG_1608H, 0x81900009U);
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
                    r_rsip_func100(bswap_32big(0xe357f521U),
                                   bswap_32big(0x4e7ecb4aU),
                                   bswap_32big(0x2f6534b3U),
                                   bswap_32big(0x6b4c6632U));
                    WR1_PROG(REG_1A2CH, 0x40000100U);
                    WR1_PROG(REG_1A24H, 0xe7008d07U);
                    WR1_PROG(REG_1400H, 0x00890021U);
                    WAIT_STS(REG_1404H, 30U, 0U);
                    WR1_PROG(REG_143CH, 0x00001800U);
                    WR1_PROG(REG_1408H, 0x00002022U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[12]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[13]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[14]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[15]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[16]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[17]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[18]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[19]);
                    r_rsip_func100(bswap_32big(0x13ef7c55U),
                                   bswap_32big(0x05cf7d47U),
                                   bswap_32big(0x3a0d9b10U),
                                   bswap_32big(0xa8eecd55U));
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
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[20]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[21]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[22]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[23]);
                    r_rsip_func100(bswap_32big(0xd24ccb85U),
                                   bswap_32big(0x2522084aU),
                                   bswap_32big(0x741598ebU),
                                   bswap_32big(0xaf1a140eU));
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
                    r_rsip_func102(bswap_32big(0xbe150d2bU),
                                   bswap_32big(0xdbfa5268U),
                                   bswap_32big(0xf510a91eU),
                                   bswap_32big(0x36d34f39U));
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
