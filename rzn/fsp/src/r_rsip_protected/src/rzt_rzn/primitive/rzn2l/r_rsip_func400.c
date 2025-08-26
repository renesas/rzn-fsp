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

void r_rsip_func400 (const uint32_t ARG1[])
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
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    WR1_PROG(REG_1600H, 0x00000b5aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000b9cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x000000ffU));
    r_rsip_func101(bswap_32big(0x3ea03154U),
                   bswap_32big(0x821c4c27U),
                   bswap_32big(0xd38d71a1U),
                   bswap_32big(0xc3979f56U));
    r_rsip_func084();
    r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x04040010U);
    r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x04040010U);
    WR1_PROG(REG_1404H, 0x19100000U);
    WR1_PROG(REG_1444H, 0x00000fc1U);
    WR1_PROG(REG_182CH, 0x00000300U);
    WR1_PROG(REG_1824H, 0x08008107U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[0]);
    WR1_ADDR(REG_1420H, &ARG1[1]);
    WR1_ADDR(REG_1420H, &ARG1[2]);
    WR1_ADDR(REG_1420H, &ARG1[3]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[4]);
    WR1_ADDR(REG_1420H, &ARG1[5]);
    WR1_ADDR(REG_1420H, &ARG1[6]);
    WR1_ADDR(REG_1420H, &ARG1[7]);
    r_rsip_subfunc003(0x00c10021U);
    WR1_PROG(REG_1404H, 0x19600000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[8]);
    WR1_ADDR(REG_1420H, &ARG1[9]);
    WR1_ADDR(REG_1420H, &ARG1[10]);
    WR1_ADDR(REG_1420H, &ARG1[11]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[12]);
    WR1_ADDR(REG_1420H, &ARG1[13]);
    WR1_ADDR(REG_1420H, &ARG1[14]);
    WR1_ADDR(REG_1420H, &ARG1[15]);
    r_rsip_subfunc003(0x00c10021U);
    WR1_PROG(REG_1404H, 0x11e00000U);
    WR1_PROG(REG_1444H, 0x000000a1U);
    WR1_PROG(REG_1824H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0001dU);
    r_rsip_subfunc003(0x00c10005U);
    r_rsip_subfunc003(0x0001000dU);
    WR1_PROG(REG_1014H, 0x000000c0U);
    WR1_PROG(REG_1018H, 0x00000200U);
    r_rsip_subfunc002(0x000000c0U, 0x00000160U, 0x0404000aU);
    r_rsip_subfunc001(0x00000160U, 0x00000930U, 0x000001b0U, 0x0404000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_subfunc001(0x00000930U, 0x00000200U, 0x000001b0U, 0x0404000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_subfunc001(0x00000160U, 0x00000980U, 0x000001b0U, 0x0404000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_subfunc001(0x00000980U, 0x00000200U, 0x000001b0U, 0x0404000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_func100(bswap_32big(0x00e99ec1U),
                   bswap_32big(0xd4c94877U),
                   bswap_32big(0xde28b241U),
                   bswap_32big(0x775545c4U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x1f4510a9U), bswap_32big(0x9e2c2e0fU), bswap_32big(0xffc4faedU),
                       bswap_32big(0x772debf1U));
    }
    else
    {
        r_rsip_func100(bswap_32big(0x5ef5cb0eU), bswap_32big(0x6ab1a279U), bswap_32big(0x732e2d95U),
                       bswap_32big(0xd0c7ded0U));
        WR1_PROG(REG_1014H, 0x00000160U);
        WR1_PROG(REG_1018H, 0x00000200U);
        r_rsip_subfunc002(0x000000c0U, 0x000001b0U, 0x0404000aU);
        WR1_PROG(REG_1014H, 0x00000980U);
        WR1_PROG(REG_1018H, 0x000001b0U);
        WR1_PROG(REG_101CH, 0x000000c0U);
        WR1_PROG(REG_1020H, 0x00000110U);
        WR1_PROG(REG_1010H, 0x00000020U);
        WR1_PROG(REG_1004H, 0x0404000fU);
        WR1_PROG(REG_1408H, 0x00020000U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_143CH, 0x00000d00U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000840U);
        r_rsip_subfunc002(0x000000c0U, 0x00000160U, 0x04040002U);
        WR1_PROG(REG_1404H, 0x10f00000U);
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x8188001fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00c90021U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000160U);
        r_rsip_subfunc002(0x000000c0U, 0x00000340U, 0x04040002U);
        WR1_PROG(REG_1014H, 0x00000930U);
        WR1_PROG(REG_1018H, 0x00000160U);
        r_rsip_subfunc002(0x000000c0U, 0x00000110U, 0x04040002U);
        WR1_PROG(REG_1010H, 0x00000018U);
        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_subfunc003(0x00c000f1U);
        r_rsip_subfunc009(bswap_32big(0x000000ffU));
        r_rsip_func101(bswap_32big(0x9e2427f4U), bswap_32big(0x831ec521U), bswap_32big(0xc0b27d6cU),
                       bswap_32big(0x6f163d86U));
        r_rsip_func085();
        WR1_PROG(REG_1014H, 0x00000390U);
        r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x04040004U);
        WR1_PROG(REG_1404H, 0x18700000U);
        WR1_PROG(REG_182CH, 0x00000100U);
        WR1_PROG(REG_1824H, 0x08008107U);
        r_rsip_subfunc003(0x00430021U);
        WR1_PROG(REG_1404H, 0x12a80000U);
        r_rsip_subfunc003(0x00c10021U);
        r_rsip_func100(bswap_32big(0x50571350U), bswap_32big(0x6f1e5292U), bswap_32big(0x39f970c0U),
                       bswap_32big(0xecc3e604U));
        WR1_PROG(REG_1404H, 0x10500000U);
        WR1_PROG(REG_182CH, 0x00000100U);
        WR1_PROG(REG_1824H, 0x08008107U);
        r_rsip_subfunc003(0x00430021U);
        WR1_PROG(REG_1404H, 0x12d00000U);
        r_rsip_subfunc003(0x00c10021U);
        r_rsip_subfunc005(0x00000250U, 0x00000340U, 0x000002f0U, 0x00000480U, 0x04040015U, 0x00020000U);
        WR1_PROG(REG_143CH, 0x00000d00U);
        WR1_PROG(REG_1404H, 0x11e00000U);
        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0001dU);
        r_rsip_subfunc003(0x00c10005U);
        r_rsip_subfunc003(0x0001000dU);
        r_rsip_subfunc001(0x00000480U, 0x00000200U, 0x000001b0U, 0x0404000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x4b90f648U), bswap_32big(0x9c1022c6U), bswap_32big(0xd91abeebU),
                       bswap_32big(0x28d70a33U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x019129d4U), bswap_32big(0xdc85072cU), bswap_32big(0xa4e499eeU),
                           bswap_32big(0x8c2fbfbaU));
        }
        else
        {
            r_rsip_func100(bswap_32big(0xfcec475eU), bswap_32big(0x80b35decU), bswap_32big(0x2f99c157U),
                           bswap_32big(0xff16a1c6U));
            WR1_PROG(REG_1404H, 0x10f00000U);
            WR1_PROG(REG_182CH, 0x00000100U);
            WR1_PROG(REG_1824H, 0x08008107U);
            r_rsip_subfunc003(0x00430021U);
            WR1_PROG(REG_1404H, 0x13200000U);
            r_rsip_subfunc003(0x00c10021U);
            WR1_PROG(REG_1404H, 0x10f00000U);
            WR1_PROG(REG_1608H, 0x81880001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c90021U);
            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000390U);
            r_rsip_subfunc002(0x00000070U, 0x00000200U, 0x04040002U);
            WR1_PROG(REG_1404H, 0x10f00000U);
            WR1_PROG(REG_1600H, 0x000037e1U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000a7e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x8188001fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c90021U);
            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000390U);
            r_rsip_subfunc002(0x00000070U, 0x00000228U, 0x04040002U);
            r_rsip_subfunc005(0x00000250U, 0x00000340U, 0x000002f0U, 0x00000570U, 0x04040015U, 0x00020000U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            WR1_PROG(REG_1404H, 0x11e00000U);
            WR1_PROG(REG_1444H, 0x000000a1U);
            WR1_PROG(REG_1824H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c0001dU);
            r_rsip_subfunc003(0x00c10005U);
            r_rsip_subfunc003(0x0001000dU);
            r_rsip_subfunc001(0x00000570U, 0x00000200U, 0x000001b0U, 0x0404000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x9b66d3b7U), bswap_32big(0xe65e0c96U), bswap_32big(0xbdada6f2U),
                           bswap_32big(0xa2a0f262U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xacc26801U),
                               bswap_32big(0xdc32cd17U),
                               bswap_32big(0x23369f26U),
                               bswap_32big(0x554a58f7U));
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000480U);
                WR1_PROG(REG_1018H, 0x00000570U);
                r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x04040013U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                WR1_PROG(REG_1404H, 0x12800000U);
                WR1_PROG(REG_1444H, 0x000000a1U);
                WR1_PROG(REG_1824H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c0001dU);
                r_rsip_subfunc003(0x00c10005U);
                r_rsip_subfunc003(0x0001000dU);
                r_rsip_subfunc001(0x00000480U, 0x000002a0U, 0x000002f0U, 0x0404000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0x62687de7U),
                               bswap_32big(0x0a8233dfU),
                               bswap_32big(0x7bee52abU),
                               bswap_32big(0xdd47d213U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xa7a0ae1aU),
                                   bswap_32big(0x816cfc2aU),
                                   bswap_32big(0x480f1d95U),
                                   bswap_32big(0x34631fc8U));
                }
                else
                {
                    r_rsip_func100(bswap_32big(0xc6e21419U),
                                   bswap_32big(0x41b98eb8U),
                                   bswap_32big(0x298bd25fU),
                                   bswap_32big(0xee784cc8U));
                    WR1_PROG(REG_1014H, 0x00000250U);
                    r_rsip_subfunc002(0x00000070U, 0x000002a0U, 0x04040004U);
                    WR1_PROG(REG_1404H, 0x11400000U);
                    WR1_PROG(REG_1444H, 0x000000a1U);
                    WR1_PROG(REG_1824H, 0x08000104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                    r_rsip_subfunc003(0x00c0001dU);
                    r_rsip_subfunc003(0x00c10005U);
                    r_rsip_subfunc003(0x0001000dU);
                    WR1_PROG(REG_1014H, 0x00000070U);
                    WR1_PROG(REG_1018H, 0x00000160U);
                    r_rsip_subfunc002(0x00000070U, 0x00000110U, 0x0404000aU);
                    r_rsip_subfunc005(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0404000fU, 0x00020000U);
                    WR1_PROG(REG_143CH, 0x00000d00U);
                    WR1_PROG(REG_1014H, 0x00000200U);
                    WR1_PROG(REG_1018H, 0x00000160U);
                    r_rsip_subfunc002(0x00000070U, 0x000002a0U, 0x04040002U);
                    r_rsip_subfunc001(0x000002a0U, 0x00000930U, 0x000001b0U, 0x0404000aU);
                    WR1_PROG(REG_143CH, 0x00210000U);
                    r_rsip_subfunc001(0x00000930U, 0x000002a0U, 0x000001b0U, 0x0404000aU);
                    WR1_PROG(REG_143CH, 0x00210000U);
                    r_rsip_func100(bswap_32big(0xd7cf0ff0U),
                                   bswap_32big(0x942ed956U),
                                   bswap_32big(0x18f973deU),
                                   bswap_32big(0x531764c8U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        WR1_PROG(REG_1600H, 0x00000800U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func101(bswap_32big(0x60040804U),
                                       bswap_32big(0x0ac57871U),
                                       bswap_32big(0x6ce0dd79U),
                                       bswap_32big(0x07c8a00eU));
                    }
                    else
                    {
                        WR1_PROG(REG_1600H, 0x0000b400U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x19bac63dU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func101(bswap_32big(0x2e2e883fU),
                                       bswap_32big(0x56baa95dU),
                                       bswap_32big(0x77a51f30U),
                                       bswap_32big(0x43c91236U));
                    }
                }
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x19bac63dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    WR1_PROG(REG_1600H, 0x00007c1bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
