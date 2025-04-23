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

rsip_ret_t r_rsip_pe1 (const uint32_t InData_Sel_KeyType[],
                       const uint32_t InData_HashType[],
                       const uint32_t InData_Certificate[],
                       const uint32_t InData_CertificateLength[],
                       const uint32_t InData_CertificatePubKey[],
                       const uint32_t InData_EncCertificateInfo[],
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
    if (0x0U != RD1_MASK(REG_14BCH, 0x1fU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00e10002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x800101e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_Sel_KeyType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000bffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000defU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000d3e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x380089e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000d3e1U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000fffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    r_rsip_func100(bswap_32big(0x47c39b3bU),
                   bswap_32big(0x687f9c84U),
                   bswap_32big(0xbf3d23e0U),
                   bswap_32big(0x9877e76bU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xed8d447eU), bswap_32big(0xec781d62U), bswap_32big(0x1dbd592cU),
                       bswap_32big(0x142761b1U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000003c7U);
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncCertificateInfo[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncCertificateInfo[1]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncCertificateInfo[2]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncCertificateInfo[3]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x0000e101U));
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x8a70cd95U), bswap_32big(0xcb84ec15U), bswap_32big(0xa498a0dcU),
                       bswap_32big(0xd7529910U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01254523U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x0000e101U));
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xfed0ba7cU), bswap_32big(0xdeeb1cd7U), bswap_32big(0x06e42f0eU),
                       bswap_32big(0xc108a2ccU));
        r_rsip_func046();
        WR1_PROG(REG_1444H, 0x000007c2U);
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xf7009d07U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncCertificateInfo[4]);
        WR1_ADDR(REG_1420H, &InData_EncCertificateInfo[5]);
        WR1_ADDR(REG_1420H, &InData_EncCertificateInfo[6]);
        WR1_ADDR(REG_1420H, &InData_EncCertificateInfo[7]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncCertificateInfo[8]);
        WR1_ADDR(REG_1420H, &InData_EncCertificateInfo[9]);
        WR1_ADDR(REG_1420H, &InData_EncCertificateInfo[10]);
        WR1_ADDR(REG_1420H, &InData_EncCertificateInfo[11]);
        WR1_PROG(REG_1824H, 0x08000045U);
        WR1_PROG(REG_1400H, 0x00420011U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1824H, 0x08000055U);
        WR1_PROG(REG_1400H, 0x00420011U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncCertificateInfo[12]);
        WR1_ADDR(REG_1420H, &InData_EncCertificateInfo[13]);
        WR1_ADDR(REG_1420H, &InData_EncCertificateInfo[14]);
        WR1_ADDR(REG_1420H, &InData_EncCertificateInfo[15]);
        WR1_PROG(REG_1A24H, 0x9c100005U);
        WR1_PROG(REG_1400H, 0x00820011U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        r_rsip_func100(bswap_32big(0xd28dee06U), bswap_32big(0x78e9d73cU), bswap_32big(0x56d8fd4bU),
                       bswap_32big(0x20d755ecU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xee53add9U), bswap_32big(0xe5e11434U), bswap_32big(0x4d34960cU),
                           bswap_32big(0x88692ffeU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000000c7U);
            WR1_PROG(REG_1608H, 0x800102c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_CertificateLength[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000003c7U);
            WR1_PROG(REG_1608H, 0x800402e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_CertificatePubKey[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_CertificatePubKey[1]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_CertificatePubKey[2]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_CertificatePubKey[3]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_2000H, 0x00000001U);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x38000defU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0x479256a7U), bswap_32big(0x0d0b7f3fU), bswap_32big(0x684e622fU),
                           bswap_32big(0x414fb827U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func100(bswap_32big(0x03436d45U),
                               bswap_32big(0xfce4f11cU),
                               bswap_32big(0xb0218077U),
                               bswap_32big(0xd2d884a4U));
                WR1_PROG(REG_1444H, 0x000000c7U);
                WR1_PROG(REG_1608H, 0x80010080U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_HashType[0]);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x3420a880U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000006U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x2000b480U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000005U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00007c04U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_143CH, 0x00600000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
                {
                    WR1_PROG(REG_2004H, 0x00000040U);
                    r_rsip_func101(bswap_32big(0x0652bbb8U),
                                   bswap_32big(0x3668fa0fU),
                                   bswap_32big(0x142f07b2U),
                                   bswap_32big(0x0e835710U));
                }
                else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
                {
                    WR1_PROG(REG_2004H, 0x00000050U);
                    r_rsip_func101(bswap_32big(0x5ea366f4U),
                                   bswap_32big(0xfe31fafaU),
                                   bswap_32big(0xc45a6936U),
                                   bswap_32big(0x3a419f4bU));
                }
                else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
                {
                    WR1_PROG(REG_2004H, 0x00000080U);
                    r_rsip_func101(bswap_32big(0x1e3040e2U),
                                   bswap_32big(0x9c20a8f1U),
                                   bswap_32big(0x15467e2fU),
                                   bswap_32big(0xf962e98dU));
                }
                else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
                {
                    WR1_PROG(REG_2004H, 0x00000090U);
                    r_rsip_func101(bswap_32big(0xc0321d02U),
                                   bswap_32big(0xfe774b4dU),
                                   bswap_32big(0x6586007eU),
                                   bswap_32big(0x9beedd0cU));
                }
                else if (0x00000004U == RD1_MASK(REG_1440H, 0xffffffffU))
                {
                    WR1_PROG(REG_2004H, 0x000000a0U);
                    r_rsip_func101(bswap_32big(0x73620a15U),
                                   bswap_32big(0x993acae9U),
                                   bswap_32big(0x3df38641U),
                                   bswap_32big(0x3b242244U));
                }
                else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
                {
                    WR1_PROG(REG_2004H, 0x000000b0U);
                    r_rsip_func101(bswap_32big(0xe37a2549U),
                                   bswap_32big(0xa40e3453U),
                                   bswap_32big(0x0ab6ac94U),
                                   bswap_32big(0x4578b698U));
                }

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000000ffU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b420U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000003U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x3c002b59U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x2000d3e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002439U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x3c00283aU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x2000d3e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b760U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000040U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0185023cU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x7b51ac7cU),
                               bswap_32big(0x7e7a36ffU),
                               bswap_32big(0x424720dcU),
                               bswap_32big(0x64a0ec5eU));
            }
            else
            {
                WR1_PROG(REG_1600H, 0x0000b480U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_2004H, 0x00000050U);
                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000001fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b420U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000001fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x3c002b3aU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x1000d3e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002439U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0800283aU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x2000d3e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b760U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000000cU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x01d8c542U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x1ea247bbU),
                               bswap_32big(0xc9e01887U),
                               bswap_32big(0x8bc8572fU),
                               bswap_32big(0xb9dec4adU));
            }

            WR1_PROG(REG_1600H, 0x3c002af8U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x1000d3e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x3c002b19U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x1000d3e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00002417U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x08002818U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x2000d3e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x3c002b56U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x1000d3e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x38000fffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00A60000U);
            r_rsip_func100(bswap_32big(0xd20f1835U), bswap_32big(0xc21a69e8U), bswap_32big(0xd8b287cfU),
                           bswap_32big(0x45378874U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0xb14e62c9U),
                               bswap_32big(0xd201f1b2U),
                               bswap_32big(0xc35be943U),
                               bswap_32big(0x68f9d44aU));
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0x10d686cbU),
                               bswap_32big(0xe50866e3U),
                               bswap_32big(0x59c973b0U),
                               bswap_32big(0x71622ca3U));
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003436U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x01836c01U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00036c21U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81020000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x0000500aU);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[1]);
                r_rsip_func100(bswap_32big(0x9d1ab374U),
                               bswap_32big(0x07e0febeU),
                               bswap_32big(0xcf90a12aU),
                               bswap_32big(0x1048a12cU));
                WR1_PROG(REG_1444H, 0x00000040U);
                WR1_ADDR(REG_2014H, &S_RAM[0]);
                WR1_PROG(REG_1444H, 0x00000040U);
                WR1_ADDR(REG_2010H, &S_RAM[1]);
                WR1_PROG(REG_1600H, 0x00003417U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00046800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00026c00U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81010000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x00005006U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
                WR1_PROG(REG_1600H, 0x000008a5U);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 4)
                {
                    WR1_PROG(REG_1444H, 0x000003c4U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_Certificate[iLoop + 0]);
                    WR1_ADDR(REG_1420H, &InData_Certificate[iLoop + 1]);
                    WR1_ADDR(REG_1420H, &InData_Certificate[iLoop + 2]);
                    WR1_ADDR(REG_1420H, &InData_Certificate[iLoop + 3]);
                    WR1_PROG(REG_1600H, 0x0000a4a0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000004U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x68f82112U),
                                   bswap_32big(0xb7d3ad59U),
                                   bswap_32big(0x29202d11U),
                                   bswap_32big(0xcf16e5a5U));
                }

                r_rsip_func100(bswap_32big(0x89d91ebcU),
                               bswap_32big(0x8e5d651aU),
                               bswap_32big(0x1d7f6e74U),
                               bswap_32big(0x2a689916U));
                WR1_PROG(REG_1600H, 0x38000805U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1000H, 0x00010000U);
                WR1_PROG(REG_1404H, 0x10000000U);
                WR1_PROG(REG_1600H, 0x00003416U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000a400U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000003U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00026800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81010000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x00005006U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
                WR1_PROG(REG_1600H, 0x00003445U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00026c42U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000034d6U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000030c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                for ( ; iLoop < S_RAM[0]; iLoop = iLoop + 1)
                {
                    WR1_PROG(REG_1444H, 0x000000c7U);
                    WR1_PROG(REG_1608H, 0x80010120U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_Certificate[iLoop + 0]);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000821U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    for (jLoop = 0; jLoop < 4; jLoop = jLoop + 1)
                    {
                        WR1_PROG(REG_1600H, 0x00002c20U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x01886d09U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00086d29U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00000863U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x3c002859U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x20002c60U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x3c002b42U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x20002c60U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x38000c63U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1608H, 0x00000080U);
                        WR1_PROG(REG_143CH, 0x00260000U);
                        r_rsip_func100(bswap_32big(0xd03e7457U),
                                       bswap_32big(0x14fd48b1U),
                                       bswap_32big(0x4601a137U),
                                       bswap_32big(0x651649c4U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            WR1_PROG(REG_1600H, 0x38000defU);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1608H, 0x00000080U);
                            WR1_PROG(REG_143CH, 0x00260000U);
                            r_rsip_func100(bswap_32big(0xd9a0b4cfU),
                                           bswap_32big(0x3b73c01bU),
                                           bswap_32big(0x764af32fU),
                                           bswap_32big(0x7f746251U));
                            WR1_PROG(REG_143CH, 0x00400000U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            if (CHCK_STS(REG_143CH, 22U, 1U))
                            {
                                WR1_PROG(REG_1600H, 0x00186d08U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1600H, 0x01886e88U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1600H, 0x00186908U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                r_rsip_func101(bswap_32big(0x95769f9dU), bswap_32big(0xb8a8f214U),
                                               bswap_32big(0x5294f6dbU), bswap_32big(0x41b770f2U));
                            }
                            else
                            {
                                WR1_PROG(REG_1608H, 0x81010100U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1400H, 0x1009000dU);
                                WAIT_STS(REG_1404H, 30U, 0U);
                                WR1_PROG(REG_143CH, 0x00001800U);
                                WR1_PROG(REG_1400H, 0x10c90005U);
                                WAIT_STS(REG_1404H, 30U, 0U);
                                WR1_PROG(REG_143CH, 0x00001800U);
                                r_rsip_func101(bswap_32big(0x8bf5d914U), bswap_32big(0x39809320U),
                                               bswap_32big(0xf8af3381U), bswap_32big(0x88552124U));
                            }
                        }

                        WR1_PROG(REG_1600H, 0x00000863U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x3c002857U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x20002c60U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x3c002b02U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x20002c60U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x38000c63U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1608H, 0x00000080U);
                        WR1_PROG(REG_143CH, 0x00260000U);
                        r_rsip_func100(bswap_32big(0x5ae64870U),
                                       bswap_32big(0x4684229cU),
                                       bswap_32big(0x3a8b4c9cU),
                                       bswap_32big(0xcc78f07eU));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            WR1_PROG(REG_1608H, 0x81010100U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1400H, 0x1009000dU);
                            WAIT_STS(REG_1404H, 30U, 0U);
                            WR1_PROG(REG_143CH, 0x00001800U);
                            WR1_PROG(REG_1400H, 0x10c90005U);
                            WAIT_STS(REG_1404H, 30U, 0U);
                            WR1_PROG(REG_143CH, 0x00001800U);
                            r_rsip_func101(bswap_32big(0x962ed4cbU),
                                           bswap_32big(0x04280c84U),
                                           bswap_32big(0x7377a285U),
                                           bswap_32big(0xdcc114e9U));
                        }

                        WR1_PROG(REG_1600H, 0x00000863U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x3c0028c2U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x20002c60U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x38000c63U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1608H, 0x00000080U);
                        WR1_PROG(REG_143CH, 0x00260000U);
                        r_rsip_func100(bswap_32big(0x9f7c6268U),
                                       bswap_32big(0x5543dabfU),
                                       bswap_32big(0xa9930768U),
                                       bswap_32big(0x5a93a5d5U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            WR1_PROG(REG_1608H, 0x81010100U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1400H, 0x1009000dU);
                            WAIT_STS(REG_1404H, 30U, 0U);
                            WR1_PROG(REG_143CH, 0x00001800U);
                            WR1_PROG(REG_1400H, 0x11490005U);
                            WAIT_STS(REG_1404H, 30U, 0U);
                            WR1_PROG(REG_143CH, 0x00001800U);
                            r_rsip_func101(bswap_32big(0x3e31c891U),
                                           bswap_32big(0xc47740d0U),
                                           bswap_32big(0xe30506edU),
                                           bswap_32big(0xf6096e99U));
                        }

                        WR1_PROG(REG_1600H, 0x00002c40U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func101(bswap_32big(0x81614561U),
                                       bswap_32big(0x6b287f2cU),
                                       bswap_32big(0xde6ba588U),
                                       bswap_32big(0xbe23d972U));
                    }

                    WR1_PROG(REG_1600H, 0x38008820U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000004U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    WR1_PROG(REG_143CH, 0x00402000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002ca0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xb871119fU),
                                   bswap_32big(0xd0f18159U),
                                   bswap_32big(0x5a09f7a2U),
                                   bswap_32big(0xd72948f0U));
                }

                WR1_PROG(REG_1600H, 0x38000805U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func100(bswap_32big(0x0954cc3dU),
                               bswap_32big(0x112eab6aU),
                               bswap_32big(0x7f4ba54bU),
                               bswap_32big(0x8682ec48U));
                WR1_PROG(REG_1600H, 0x00003416U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00008c00U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000003U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b440U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002840U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00008c40U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000003U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81010040U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x00005006U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
                WR1_PROG(REG_1600H, 0x000008a5U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000863U);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
                {
                    WR1_PROG(REG_1608H, 0x81010060U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1400H, 0x11490005U);
                    WAIT_STS(REG_1404H, 30U, 0U);
                    WR1_PROG(REG_143CH, 0x00001800U);
                    WR1_PROG(REG_1400H, 0x1009000dU);
                    WAIT_STS(REG_1404H, 30U, 0U);
                    WR1_PROG(REG_143CH, 0x00001800U);
                    WR1_PROG(REG_1600H, 0x00086c63U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002ca0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x09a2f0c6U),
                                   bswap_32big(0x5e5ada23U),
                                   bswap_32big(0x48357db2U),
                                   bswap_32big(0x3f6b9a1fU));
                }

                WR1_PROG(REG_1600H, 0x38000845U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_2030H, 4U, 1U);
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x38000c84U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_1600H, 0x38008880U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000002U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                r_rsip_func100(bswap_32big(0x23dffc29U),
                               bswap_32big(0x016b2d9cU),
                               bswap_32big(0x8b0bd582U),
                               bswap_32big(0x24b4e05dU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1608H, 0x80880000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1400H, 0x0345001dU);
                    WAIT_STS(REG_1404H, 30U, 0U);
                    WR1_PROG(REG_143CH, 0x00001800U);
                    WR1_PROG(REG_1400H, 0x03400005U);
                    WAIT_STS(REG_1404H, 30U, 0U);
                    WR1_PROG(REG_143CH, 0x00001800U);
                    r_rsip_func101(bswap_32big(0x8b068c19U),
                                   bswap_32big(0xff565576U),
                                   bswap_32big(0x13cbc508U),
                                   bswap_32big(0xce895482U));
                }
                else
                {
                    WR1_PROG(REG_1608H, 0x80880000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1400H, 0x03450021U);
                    WAIT_STS(REG_1404H, 30U, 0U);
                    WR1_PROG(REG_143CH, 0x00001800U);
                    r_rsip_func101(bswap_32big(0xf5b51919U),
                                   bswap_32big(0x9b44a985U),
                                   bswap_32big(0x3ed843ebU),
                                   bswap_32big(0x28ea017bU));
                }

                WR1_PROG(REG_1608H, 0x81880000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1824H, 0x9c000005U);
                WR1_PROG(REG_1400H, 0x00490011U);
                WAIT_STS(REG_1404H, 30U, 0U);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1824H, 0x9c100005U);
                WR1_PROG(REG_1400H, 0x00490011U);
                WAIT_STS(REG_1404H, 30U, 0U);
                WR1_PROG(REG_143CH, 0x00001800U);
                r_rsip_func100(bswap_32big(0x216be70dU),
                               bswap_32big(0x9c690b80U),
                               bswap_32big(0x29f02830U),
                               bswap_32big(0x2f5ca020U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func102(bswap_32big(0xde4e315dU),
                                   bswap_32big(0x78970bbeU),
                                   bswap_32big(0x6ac32e9fU),
                                   bswap_32big(0x6508cb33U));
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    r_rsip_func100(bswap_32big(0x562c7ef9U),
                                   bswap_32big(0x7170d67fU),
                                   bswap_32big(0x167c5484U),
                                   bswap_32big(0xebc1f88eU));
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
                    WR1_PROG(REG_1420H, bswap_32big(0x0000e102U));
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xf814e3ecU),
                                   bswap_32big(0x9108376bU),
                                   bswap_32big(0x9c050232U),
                                   bswap_32big(0xa1039c0fU));
                    r_rsip_func045();
                    WR1_PROG(REG_1444H, 0x000000a7U);
                    WR1_PROG(REG_1608H, 0x800103a0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x0000e102U));
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x2f839479U),
                                   bswap_32big(0x55af3cccU),
                                   bswap_32big(0xa9eb0e90U),
                                   bswap_32big(0xb3a77692U));
                    r_rsip_func046();
                    r_rsip_func100(bswap_32big(0x5a724ed7U),
                                   bswap_32big(0x4b7d692bU),
                                   bswap_32big(0x1472797dU),
                                   bswap_32big(0xbe80b8f5U));
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x08000044U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x08000054U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                    WR1_PROG(REG_1608H, 0x81010360U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1408H, 0x00005006U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
                    WR1_PROG(REG_1600H, 0x00000884U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x000008a5U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1404H, 0x10000000U);
                    for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 4)
                    {
                        WR1_PROG(REG_1600H, 0x342028bbU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x2000d080U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00007c04U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_143CH, 0x00602000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func100(bswap_32big(0xc5261148U),
                                       bswap_32big(0x66867d4cU),
                                       bswap_32big(0xeb0d6a18U),
                                       bswap_32big(0xa80245fbU));
                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0xe8008105U);
                        WR1_PROG(REG_1400H, 0x00830011U);
                        WAIT_STS(REG_1404H, 30U, 0U);
                        WR1_PROG(REG_143CH, 0x00001800U);
                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 4]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 5]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 6]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 7]);
                        WR1_PROG(REG_1600H, 0x0000a4a0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00000004U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func101(bswap_32big(0x714319b4U),
                                       bswap_32big(0x1328ed35U),
                                       bswap_32big(0x9db07d76U),
                                       bswap_32big(0x159db45fU));
                    }

                    r_rsip_func100(bswap_32big(0x5d7401c3U),
                                   bswap_32big(0x57649e44U),
                                   bswap_32big(0x8090210fU),
                                   bswap_32big(0x0b0f9212U));
                    WR1_PROG(REG_1600H, 0x380008bbU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    WR1_PROG(REG_143CH, 0x00402000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A2CH, 0x40000000U);
                    WR1_PROG(REG_1A24H, 0x49108054U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                    WR1_PROG(REG_1600H, 0x00007c0fU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_143CH, 0x00600000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
                    {
                        r_rsip_func100(bswap_32big(0xd6cb4006U),
                                       bswap_32big(0x4817c67cU),
                                       bswap_32big(0xa82a6821U),
                                       bswap_32big(0x0c134798U));
                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0xe8008104U);
                        WR1_PROG(REG_1608H, 0x81010280U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1400H, 0x00890005U);
                        WAIT_STS(REG_1404H, 30U, 0U);
                        WR1_PROG(REG_143CH, 0x00001800U);
                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 4]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 5]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 6]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 7]);
                        r_rsip_func101(bswap_32big(0x60003e8aU),
                                       bswap_32big(0x3f5f38b4U),
                                       bswap_32big(0xcf1895bcU),
                                       bswap_32big(0x5f43ee7bU));
                    }
                    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
                    {
                        r_rsip_func100(bswap_32big(0x4a73d8d7U),
                                       bswap_32big(0x02fd6b29U),
                                       bswap_32big(0x3c07ec2fU),
                                       bswap_32big(0x26b70d72U));
                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0xe8008105U);
                        WR1_PROG(REG_1400H, 0x00830011U);
                        WAIT_STS(REG_1404H, 30U, 0U);
                        WR1_PROG(REG_143CH, 0x00001800U);
                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 4]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 5]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 6]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 7]);
                        r_rsip_func101(bswap_32big(0x84ee8b06U),
                                       bswap_32big(0x58705839U),
                                       bswap_32big(0xa9fce859U),
                                       bswap_32big(0xe678a9e7U));
                    }

                    r_rsip_func100(bswap_32big(0x9e9683a8U),
                                   bswap_32big(0xdc534cf2U),
                                   bswap_32big(0x7be0689aU),
                                   bswap_32big(0xf3416012U));
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x0c100104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 8]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 9]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 10]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 11]);
                    r_rsip_func100(bswap_32big(0xe96c4e8dU),
                                   bswap_32big(0x79a8c31bU),
                                   bswap_32big(0xfb7a5ac4U),
                                   bswap_32big(0xaf755548U));
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
                    r_rsip_func102(bswap_32big(0x357e8f9aU),
                                   bswap_32big(0x40aa2539U),
                                   bswap_32big(0x6ce20c59U),
                                   bswap_32big(0x87c20b4aU));
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
