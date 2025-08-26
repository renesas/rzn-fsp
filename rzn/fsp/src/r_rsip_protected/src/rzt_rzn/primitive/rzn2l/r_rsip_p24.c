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

rsip_ret_t r_rsip_p24 (const uint32_t InData_Cmd[],
                       const uint32_t InData_KeyCertificate[],
                       const uint32_t InData_KeyCertificateLength[],
                       const uint32_t InData_KeyCertificateSignature[],
                       const uint32_t InData_KeyCertificatePubKey[],
                       const uint32_t InData_ImgPkHash[],
                       const uint32_t InData_OemRootPkHash[],
                       const uint32_t InData_CodeCertificate[],
                       const uint32_t InData_CodeCertificateLength[],
                       const uint32_t InData_CodeCertificateSignature[],
                       const uint32_t InData_CodeCertificatePubKey[],
                       const uint32_t InData_ImageHash[],
                       const uint32_t InData_Image[],
                       uint32_t       MAX_CNT)

{
    RSIP_PRV_PRIMITIVE_ENTRY;
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

    WR1_PROG(REG_1B00H, 0x00240001U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000005c7U);
    WR1_PROG(REG_1608H, 0x800601c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_CodeCertificateLength[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0; iLoop < 4; iLoop = iLoop + 1)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_CodeCertificatePubKey[iLoop + 0]);
        WR1_PROG(REG_1458H, 0x00000000U);
    }

    WR1_PROG(REG_1600H, 0x38000dceU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x4d41ea59U),
                   bswap_32big(0x4ee9aef9U),
                   bswap_32big(0x90098c05U),
                   bswap_32big(0x30698d92U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1444H, 0x000001c7U);
        WR1_PROG(REG_1608H, 0x80020280U);
        WR1_PROG(REG_1458H, 0x00000000U);
        for (iLoop = 0; iLoop < 2; iLoop = iLoop + 1)
        {
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_ImageHash[iLoop + 0]);
            WR1_PROG(REG_1458H, 0x00000000U);
        }

        r_rsip_func101(bswap_32big(0x4b22a395U), bswap_32big(0xde850bfaU), bswap_32big(0xe7ef3440U),
                       bswap_32big(0x4aca1895U));
    }

    WR1_PROG(REG_1444H, 0x000006c7U);
    WR1_PROG(REG_1608H, 0x800702c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyCertificateLength[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0; iLoop < 4; iLoop = iLoop + 1)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyCertificatePubKey[iLoop + 0]);
        WR1_PROG(REG_1458H, 0x00000000U);
    }

    for (iLoop = 0; iLoop < 2; iLoop = iLoop + 1)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_ImgPkHash[iLoop + 0]);
        WR1_PROG(REG_1458H, 0x00000000U);
    }

    WR1_PROG(REG_1600H, 0x00000bffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3c002af8U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000d3e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3c002b19U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000d3e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3c002b3aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000d3e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3c002b5bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000d3e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3c002b7cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000d3e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3c002b96U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000d3e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00003417U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000a400U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000001fU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x08002818U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x2000d3e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00003419U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000a400U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000001fU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0800281aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x2000d3e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000341bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000a400U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000001fU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0800281cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x2000d3e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000dceU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    r_rsip_func100(bswap_32big(0xed2b87e1U),
                   bswap_32big(0xb70fe1edU),
                   bswap_32big(0xde12957fU),
                   bswap_32big(0x454c225bU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x3c002a11U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x3c002a32U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x3c002a53U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x3c002a6fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003410U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000a400U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000001fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x08002811U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003412U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000a400U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000001fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x08002813U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x7b0fb629U), bswap_32big(0xfdc5897dU), bswap_32big(0xc04fcc5fU),
                       bswap_32big(0x79ac3179U));
    }
    else
    {
        WR1_PROG(REG_1600H, 0x3c002a11U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x3c002a32U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x3c002a53U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x3c002a74U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x3c002a95U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x3c002aafU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003410U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000a400U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000001fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x08002811U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003412U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000a400U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000001fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x08002813U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003414U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000a400U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000001fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x08002815U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x09c321c6U), bswap_32big(0x093a3b2fU), bswap_32big(0x8eb8ac5bU),
                       bswap_32big(0x12a0102cU));
    }

    WR1_PROG(REG_1600H, 0x38000fffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xf74f2194U),
                   bswap_32big(0x350a1741U),
                   bswap_32big(0xef44a50aU),
                   bswap_32big(0x36ca3bfbU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_14BCH, 0x00000020U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PARAM_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0x181989b9U), bswap_32big(0xe8cb1537U), bswap_32big(0x6d749c79U),
                       bswap_32big(0x936b2c06U));
        WR1_PROG(REG_2000H, 0x00000001U);
        WR1_PROG(REG_2004H, 0x00000050U);
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
        r_rsip_func100(bswap_32big(0x89ef9055U), bswap_32big(0xd86deab5U), bswap_32big(0x43f060daU),
                       bswap_32big(0xcfbea75cU));
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
            WR1_ADDR(REG_1420H, &InData_KeyCertificate[iLoop + 0]);
            WR1_ADDR(REG_1420H, &InData_KeyCertificate[iLoop + 1]);
            WR1_ADDR(REG_1420H, &InData_KeyCertificate[iLoop + 2]);
            WR1_ADDR(REG_1420H, &InData_KeyCertificate[iLoop + 3]);
            WR1_PROG(REG_1600H, 0x0000a4a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000004U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x0a0b10c2U), bswap_32big(0x94edadcaU), bswap_32big(0x0dcca15dU),
                           bswap_32big(0x24f43a32U));
        }

        r_rsip_func100(bswap_32big(0xe26259b7U), bswap_32big(0x9b8337c4U), bswap_32big(0x83c777daU),
                       bswap_32big(0x6efe6024U));
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
        WR1_PROG(REG_1600H, 0x00026800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38008ec0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000003U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x20002c00U);
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
        WR1_PROG(REG_1600H, 0x0000b520U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000180U);
        WR1_PROG(REG_1458H, 0x00000000U);
        for ( ; iLoop < S_RAM[0]; iLoop = iLoop + 1)
        {
            WR1_PROG(REG_1444H, 0x000000c7U);
            WR1_PROG(REG_1608H, 0x80010100U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyCertificate[iLoop + 0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b420U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000004U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (jLoop = 0; jLoop < 4; jLoop = jLoop + 1)
            {
                WR1_PROG(REG_1600H, 0x00003020U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x01886ce8U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00086d08U);
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
                r_rsip_func100(bswap_32big(0xd7ad2961U),
                               bswap_32big(0x5b3a6271U),
                               bswap_32big(0x4bf4d57cU),
                               bswap_32big(0xda40be96U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1608H, 0x810100e0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x1009000dU);
                    r_rsip_subfunc003(0x10c90005U);
                    r_rsip_func101(bswap_32big(0xc016acc1U),
                                   bswap_32big(0xa3c84948U),
                                   bswap_32big(0xf5816ba1U),
                                   bswap_32big(0x11f7350eU));
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
                r_rsip_func100(bswap_32big(0x6ff13390U),
                               bswap_32big(0xe641ef6eU),
                               bswap_32big(0x31064211U),
                               bswap_32big(0x8fb38b02U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1608H, 0x810100e0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x1009000dU);
                    r_rsip_subfunc003(0x10c90005U);
                    r_rsip_func101(bswap_32big(0x34e571fdU),
                                   bswap_32big(0x974a22a2U),
                                   bswap_32big(0x4f0cdc45U),
                                   bswap_32big(0x4dcbe15dU));
                }

                WR1_PROG(REG_1600H, 0x00000863U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x3c00285bU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x20002c60U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x3c002b82U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x20002c60U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x38000c63U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                r_rsip_func100(bswap_32big(0xcdd932b7U),
                               bswap_32big(0x23eb745fU),
                               bswap_32big(0x26970e18U),
                               bswap_32big(0xe7f67b9fU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1600H, 0x02003ce9U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002d20U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x46cdbb5bU),
                                   bswap_32big(0x6bece306U),
                                   bswap_32big(0x6c610904U),
                                   bswap_32big(0x3f220107U));
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
                r_rsip_func100(bswap_32big(0xc5dc759fU),
                               bswap_32big(0x124ae45bU),
                               bswap_32big(0x35bff483U),
                               bswap_32big(0x74ed4983U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1608H, 0x810100e0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x1009000dU);
                    r_rsip_subfunc003(0x11490005U);
                    r_rsip_func101(bswap_32big(0x1efc5aceU),
                                   bswap_32big(0xa986233bU),
                                   bswap_32big(0x10638d87U),
                                   bswap_32big(0x92ca0809U));
                }

                WR1_PROG(REG_1600H, 0x00002c40U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x273acd4cU),
                               bswap_32big(0x85f74b64U),
                               bswap_32big(0xdeb3c4eaU),
                               bswap_32big(0x6d4e52f5U));
            }

            WR1_PROG(REG_1600H, 0x08000c21U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00002ca0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x99ec5869U), bswap_32big(0x5a282c22U), bswap_32big(0xe3a5c987U),
                           bswap_32big(0x8f376130U));
        }

        WR1_PROG(REG_1600H, 0x38000805U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x877ad32aU), bswap_32big(0xf4778849U), bswap_32big(0x9fe74b4fU),
                       bswap_32big(0x1827c5f2U));
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
            r_rsip_subfunc003(0x11490005U);
            r_rsip_subfunc003(0x1009000dU);
            WR1_PROG(REG_1600H, 0x00086c63U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00002ca0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xa6f789fbU), bswap_32big(0xc16b9a95U), bswap_32big(0x9c3ed66bU),
                           bswap_32big(0xb63bd375U));
        }

        WR1_PROG(REG_1600H, 0x38000845U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_2030H, 4U, 1U);
        WR1_PROG(REG_1600H, 0x00000929U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x80880009U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03450021U);
        WR1_PROG(REG_2000H, 0x00000001U);
        WR1_PROG(REG_2004H, 0x00000050U);
        WR1_PROG(REG_2014H, 0x00000000U);
        WR1_PROG(REG_2010H, 0x00000200U);
        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_subfunc003(0x01430041U);
        WAIT_STS(REG_2030H, 4U, 1U);
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A24H, 0x08000055U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_OemRootPkHash[0]);
        WR1_ADDR(REG_1420H, &InData_OemRootPkHash[1]);
        WR1_ADDR(REG_1420H, &InData_OemRootPkHash[2]);
        WR1_ADDR(REG_1420H, &InData_OemRootPkHash[3]);
        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_subfunc003(0x00850011U);
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A24H, 0x08000055U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_OemRootPkHash[4]);
        WR1_ADDR(REG_1420H, &InData_OemRootPkHash[5]);
        WR1_ADDR(REG_1420H, &InData_OemRootPkHash[6]);
        WR1_ADDR(REG_1420H, &InData_OemRootPkHash[7]);
        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_subfunc003(0x00850011U);
        r_rsip_func100(bswap_32big(0x4a9ece47U), bswap_32big(0x0fda23c5U), bswap_32big(0x03c6500eU),
                       bswap_32big(0xcab13ab8U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_14BCH, 0x00000020U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_VERIFICATION_FAIL;
        }
        else
        {
            WR1_PROG(REG_1404H, 0x10000000U);
            WR1_PROG(REG_1600H, 0x0000b420U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000060U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x80900001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03430041U);
            WR1_PROG(REG_1600H, 0x00000b9cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x80010360U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x000000e2U));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x783111c6U), bswap_32big(0x6cd45e51U), bswap_32big(0xd4733a9dU),
                           bswap_32big(0x1f9dcec2U));
            r_rsip_func400(InData_KeyCertificateSignature);
            r_rsip_func100(bswap_32big(0x9945fb46U), bswap_32big(0xc09baf5aU), bswap_32big(0xb074bcf5U),
                           bswap_32big(0xa4733c17U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_14BCH, 0x00000020U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_VERIFICATION_FAIL;
            }
            else
            {
                WR1_PROG(REG_1600H, 0x000036cfU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000036f0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003711U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003732U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003753U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003774U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003795U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_2000H, 0x00000001U);
                WR1_PROG(REG_2004H, 0x00000050U);
                WR1_PROG(REG_1444H, 0x000000c7U);
                WR1_PROG(REG_1608H, 0x80010160U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &MAX_CNT);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x38000dceU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                r_rsip_func100(bswap_32big(0x4fafe5e4U),
                               bswap_32big(0xb65d4e6dU),
                               bswap_32big(0xf15212a5U),
                               bswap_32big(0xfb85059dU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x0000342bU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x01826c01U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00026c21U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x000008c6U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x0c002436U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00802406U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x01836c01U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00036c21U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x09cf23d2U),
                                   bswap_32big(0x4cca0ebdU),
                                   bswap_32big(0x146e38f6U),
                                   bswap_32big(0xc3075d14U));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x00000800U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00003436U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x01836c01U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00036c21U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x091b211eU),
                                   bswap_32big(0x50f46f3bU),
                                   bswap_32big(0xe1c14ecaU),
                                   bswap_32big(0xfb9fe9c6U));
                }

                r_rsip_func100(bswap_32big(0x5ee5d626U),
                               bswap_32big(0x61e18c9aU),
                               bswap_32big(0x7a2d1df7U),
                               bswap_32big(0xb9982aefU));
                WR1_PROG(REG_1608H, 0x81020000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x0000500aU);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[1]);
                r_rsip_func100(bswap_32big(0xea12a474U),
                               bswap_32big(0x11b0a01cU),
                               bswap_32big(0xd5a2bcf9U),
                               bswap_32big(0xb0d93de2U));
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
                    WR1_ADDR(REG_1420H, &InData_CodeCertificate[iLoop + 0]);
                    WR1_ADDR(REG_1420H, &InData_CodeCertificate[iLoop + 1]);
                    WR1_ADDR(REG_1420H, &InData_CodeCertificate[iLoop + 2]);
                    WR1_ADDR(REG_1420H, &InData_CodeCertificate[iLoop + 3]);
                    WR1_PROG(REG_1600H, 0x0000a4a0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000004U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x267b21afU),
                                   bswap_32big(0x33f1bc52U),
                                   bswap_32big(0xf62f9072U),
                                   bswap_32big(0xb89fe7e7U));
                }

                r_rsip_func100(bswap_32big(0x40d6d8a3U),
                               bswap_32big(0x0cc39fe6U),
                               bswap_32big(0x47c42609U),
                               bswap_32big(0x33a31f14U));
                WR1_PROG(REG_1600H, 0x38000805U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1404H, 0x10000000U);
                WR1_PROG(REG_1600H, 0x00003416U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00026800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x38008ec0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000003U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x20002c00U);
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
                WR1_PROG(REG_1600H, 0x0000b520U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000001a0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                for ( ; iLoop < S_RAM[0]; iLoop = iLoop + 1)
                {
                    WR1_PROG(REG_1444H, 0x000000c7U);
                    WR1_PROG(REG_1608H, 0x80010100U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_CodeCertificate[iLoop + 0]);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x0000b420U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000004U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    for (jLoop = 0; jLoop < 4; jLoop = jLoop + 1)
                    {
                        WR1_PROG(REG_1600H, 0x00003020U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x01886ce8U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00086d08U);
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
                        r_rsip_func100(bswap_32big(0x0a7a4634U),
                                       bswap_32big(0x5916cfbaU),
                                       bswap_32big(0x90e820f4U),
                                       bswap_32big(0xbf1c7f77U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            WR1_PROG(REG_1608H, 0x810100e0U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_subfunc003(0x1009000dU);
                            r_rsip_subfunc003(0x10c90005U);
                            r_rsip_func101(bswap_32big(0x06b3249eU),
                                           bswap_32big(0x54dac96cU),
                                           bswap_32big(0xef9112b1U),
                                           bswap_32big(0x17f7c1b3U));
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
                        r_rsip_func100(bswap_32big(0x1a8465eaU),
                                       bswap_32big(0x3b92ab83U),
                                       bswap_32big(0x1118db2fU),
                                       bswap_32big(0xa3ccdc32U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            WR1_PROG(REG_1608H, 0x810100e0U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_subfunc003(0x1009000dU);
                            r_rsip_subfunc003(0x10c90005U);
                            r_rsip_func101(bswap_32big(0x55aa0aadU),
                                           bswap_32big(0xb5e50134U),
                                           bswap_32big(0x05e34a28U),
                                           bswap_32big(0x9c0be861U));
                        }

                        WR1_PROG(REG_1600H, 0x00000863U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x38000dceU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00020020U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x3c00285bU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x20002c60U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x3c002b82U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x20002c60U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00000060U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00002c60U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00000080U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x38000c63U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1608H, 0x00000080U);
                        WR1_PROG(REG_143CH, 0x00260000U);
                        r_rsip_func100(bswap_32big(0xd5e9d798U),
                                       bswap_32big(0x301a8433U),
                                       bswap_32big(0x4bccaf3dU),
                                       bswap_32big(0xd42d10c9U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            WR1_PROG(REG_1600H, 0x02003ce9U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00002d20U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_func101(bswap_32big(0x46b60b21U),
                                           bswap_32big(0x01cc8520U),
                                           bswap_32big(0xed304398U),
                                           bswap_32big(0x12f55a14U));
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
                        r_rsip_func100(bswap_32big(0x1a4a7308U),
                                       bswap_32big(0x0017060cU),
                                       bswap_32big(0xb2dc32bfU),
                                       bswap_32big(0xfccee554U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            WR1_PROG(REG_1608H, 0x810100e0U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_subfunc003(0x1009000dU);
                            r_rsip_subfunc003(0x11490005U);
                            r_rsip_func101(bswap_32big(0x455309cbU),
                                           bswap_32big(0x7e8b9c3fU),
                                           bswap_32big(0x0acb2b74U),
                                           bswap_32big(0x8b095edcU));
                        }

                        WR1_PROG(REG_1600H, 0x00002c40U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func101(bswap_32big(0x88a2b316U),
                                       bswap_32big(0x651a1526U),
                                       bswap_32big(0x11e5a6acU),
                                       bswap_32big(0x914c91f0U));
                    }

                    WR1_PROG(REG_1600H, 0x08000c21U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    WR1_PROG(REG_143CH, 0x00402000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002ca0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xead912f9U),
                                   bswap_32big(0xfbfb7345U),
                                   bswap_32big(0xbf7bb6f0U),
                                   bswap_32big(0xb65b9dbaU));
                }

                WR1_PROG(REG_1600H, 0x38000805U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x38000dceU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                r_rsip_func100(bswap_32big(0x927401beU),
                               bswap_32big(0x6a24f60fU),
                               bswap_32big(0xb8e2a88cU),
                               bswap_32big(0x36254c38U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func100(bswap_32big(0xc9005159U),
                                   bswap_32big(0x6ba08c3cU),
                                   bswap_32big(0x2691a1a8U),
                                   bswap_32big(0x403e2a91U));
                    WR1_PROG(REG_1444H, 0x000000c7U);
                    WR1_PROG(REG_1608H, 0x800100c0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_Image[0]);
                    WR1_PROG(REG_1458H, 0x00000000U);
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
                    WR1_PROG(REG_1608H, 0x81010040U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1408H, 0x00005006U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
                    WR1_PROG(REG_1600H, 0x000008a5U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00003466U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
                    {
                        WR1_PROG(REG_1608H, 0x81010060U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_subfunc003(0x11490005U);
                        r_rsip_subfunc003(0x1009000dU);
                        WR1_PROG(REG_1600H, 0x00086c63U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00002ca0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func101(bswap_32big(0xf3543969U),
                                       bswap_32big(0x803ddbf2U),
                                       bswap_32big(0x9f3baf22U),
                                       bswap_32big(0x2a2aa54eU));
                    }

                    WR1_PROG(REG_1600H, 0x38000845U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    WR1_PROG(REG_143CH, 0x00402000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0xb77b4dcbU),
                                   bswap_32big(0x2b306108U),
                                   bswap_32big(0x85f19ea3U),
                                   bswap_32big(0xcce56a6dU));
                    WR1_PROG(REG_1600H, 0x000034e6U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00036c00U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00004400U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x81010160U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1408H, 0x00005006U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
                    WR1_PROG(REG_1600H, 0x0000b4a0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000001U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    for (iLoop = 1; iLoop < S_RAM[0]; iLoop = iLoop + 1)
                    {
                        WR1_PROG(REG_1444H, 0x000000c7U);
                        WR1_PROG(REG_1608H, 0x800100c0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WAIT_STS(REG_1444H, 31U, 1U);
                        WR1_ADDR(REG_1420H, &InData_Image[iLoop + 0]);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00003506U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x01807507U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1608H, 0x81010100U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_subfunc003(0x01490005U);
                        WR1_PROG(REG_1600H, 0x000034e6U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00002ca0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func101(bswap_32big(0xdf28add5U),
                                       bswap_32big(0x51e38d74U),
                                       bswap_32big(0x3e611caeU),
                                       bswap_32big(0x83e24b67U));
                    }

                    WR1_PROG(REG_1600H, 0x38000965U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    WR1_PROG(REG_143CH, 0x00402000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x38008ec0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000003U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00A60000U);
                    r_rsip_func100(bswap_32big(0x7e27ae28U),
                                   bswap_32big(0x09ba45f8U),
                                   bswap_32big(0x27d28d3fU),
                                   bswap_32big(0xe32397efU));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        WR1_PROG(REG_1600H, 0x00000908U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x01807507U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1608H, 0x81010100U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_subfunc003(0x01490005U);
                        r_rsip_func101(bswap_32big(0x0db43cdfU),
                                       bswap_32big(0xd8540856U),
                                       bswap_32big(0x040c2c62U),
                                       bswap_32big(0x07df7149U));
                    }

                    WAIT_STS(REG_2030H, 4U, 1U);
                    r_rsip_func101(bswap_32big(0xbe1fd50dU),
                                   bswap_32big(0x17c4bf1cU),
                                   bswap_32big(0x265df71fU),
                                   bswap_32big(0xe10ca97bU));
                }
                else
                {
                    r_rsip_func100(bswap_32big(0x813dc93cU),
                                   bswap_32big(0x2c030a03U),
                                   bswap_32big(0x5757014bU),
                                   bswap_32big(0x693f8d00U));
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
                        r_rsip_subfunc003(0x11490005U);
                        r_rsip_subfunc003(0x1009000dU);
                        WR1_PROG(REG_1600H, 0x00086c63U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00002ca0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func101(bswap_32big(0x0ca4a7abU),
                                       bswap_32big(0x417729faU),
                                       bswap_32big(0xd2397ecfU),
                                       bswap_32big(0x06a9c758U));
                    }

                    WR1_PROG(REG_1600H, 0x38000845U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    WR1_PROG(REG_143CH, 0x00402000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WAIT_STS(REG_2030H, 4U, 1U);
                    r_rsip_func101(bswap_32big(0xcef7f73dU),
                                   bswap_32big(0x06a6ae08U),
                                   bswap_32big(0x1e1e5ab1U),
                                   bswap_32big(0x9d6c5139U));
                }

                WR1_PROG(REG_1600H, 0x00000929U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x80880009U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03450021U);
                WR1_PROG(REG_2000H, 0x00000001U);
                WR1_PROG(REG_2004H, 0x00000050U);
                WR1_PROG(REG_2014H, 0x00000000U);
                WR1_PROG(REG_2010H, 0x00000200U);
                WR1_PROG(REG_1404H, 0x10000000U);
                r_rsip_subfunc003(0x01430041U);
                WAIT_STS(REG_2030H, 4U, 1U);
                WR1_PROG(REG_1600H, 0x0000b520U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000180U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1A24H, 0x08000045U);
                WR1_PROG(REG_1608H, 0x81840009U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00890011U);
                WR1_PROG(REG_1A24H, 0x9c000005U);
                r_rsip_subfunc003(0x00850011U);
                WR1_PROG(REG_1600H, 0x0000a520U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000010U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1A24H, 0x08000045U);
                WR1_PROG(REG_1608H, 0x81840009U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00890011U);
                WR1_PROG(REG_1A24H, 0x9c000005U);
                r_rsip_subfunc003(0x00850011U);
                r_rsip_func100(bswap_32big(0xd15adea1U),
                               bswap_32big(0x6d05184fU),
                               bswap_32big(0x2a72a0f6U),
                               bswap_32big(0x4b34cc35U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_14BCH, 0x00000020U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_VERIFICATION_FAIL;
                }
                else
                {
                    WR1_PROG(REG_1404H, 0x10000000U);
                    WR1_PROG(REG_1600H, 0x0000b420U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000060U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x80900001U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x03430041U);
                    WR1_PROG(REG_1600H, 0x00000b9cU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1444H, 0x000000a7U);
                    WR1_PROG(REG_1608H, 0x80010360U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x000000e3U));
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xb982ebbfU),
                                   bswap_32big(0x5165e7ceU),
                                   bswap_32big(0xc3c41551U),
                                   bswap_32big(0xa5f89e58U));
                    r_rsip_func400(InData_CodeCertificateSignature);
                    r_rsip_func100(bswap_32big(0xa82a0023U),
                                   bswap_32big(0x52e423eaU),
                                   bswap_32big(0x22e70f9eU),
                                   bswap_32big(0xc418c95bU));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        WR1_PROG(REG_14BCH, 0x00000020U);
                        WAIT_STS(REG_142CH, 12U, 0U);

                        return RSIP_RET_VERIFICATION_FAIL;
                    }
                    else
                    {
                        WR1_PROG(REG_1600H, 0x38000dceU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1608H, 0x00000080U);
                        WR1_PROG(REG_143CH, 0x00260000U);
                        r_rsip_func100(bswap_32big(0x4f57f912U),
                                       bswap_32big(0xe2aab7ffU),
                                       bswap_32big(0x7c2c66d8U),
                                       bswap_32big(0xb2eba0c9U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            r_rsip_func102(bswap_32big(0xa64bcd93U),
                                           bswap_32big(0x4f6dee59U),
                                           bswap_32big(0x1184fe52U),
                                           bswap_32big(0x50fa3920U));
                            WR1_PROG(REG_14BCH, 0x00000040U);
                            WAIT_STS(REG_142CH, 12U, 0U);

                            return RSIP_RET_PASS;
                        }
                        else
                        {
                            r_rsip_func100(bswap_32big(0x96bbd23eU),
                                           bswap_32big(0x5ddf6c7aU),
                                           bswap_32big(0x714062e5U),
                                           bswap_32big(0x31f37b69U));
                            WR1_PROG(REG_2000H, 0x00000001U);
                            WR1_PROG(REG_2004H, 0x00000050U);
                            WR1_PROG(REG_1600H, 0x00000800U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x0000342bU);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x01856c01U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00056c21U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1608H, 0x81020000U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1408H, 0x0000500aU);
                            WAIT_STS(REG_1408H, 30U, 1U);
                            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
                            WAIT_STS(REG_1408H, 30U, 1U);
                            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[1]);
                            r_rsip_func100(bswap_32big(0x36860670U),
                                           bswap_32big(0x1c0d9e0cU),
                                           bswap_32big(0xfbd4053cU),
                                           bswap_32big(0x81a817c1U));
                            WR1_PROG(REG_1444H, 0x00000040U);
                            WR1_ADDR(REG_2014H, &S_RAM[0]);
                            WR1_PROG(REG_1444H, 0x00000040U);
                            WR1_ADDR(REG_2010H, &S_RAM[1]);
                            WR1_PROG(REG_1608H, 0x81010160U);
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
                                WR1_ADDR(REG_1420H, &InData_Image[iLoop + 0]);
                                WR1_ADDR(REG_1420H, &InData_Image[iLoop + 1]);
                                WR1_ADDR(REG_1420H, &InData_Image[iLoop + 2]);
                                WR1_ADDR(REG_1420H, &InData_Image[iLoop + 3]);
                                WR1_PROG(REG_1600H, 0x0000a4a0U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1600H, 0x00000004U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                r_rsip_func101(bswap_32big(0x21b4307bU), bswap_32big(0x5bafc2bfU),
                                               bswap_32big(0x9be4684cU), bswap_32big(0x8bd7a2edU));
                            }

                            WR1_PROG(REG_1600H, 0x38000965U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1608H, 0x00000080U);
                            WR1_PROG(REG_143CH, 0x00260000U);
                            WR1_PROG(REG_143CH, 0x00402000U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WAIT_STS(REG_2030H, 4U, 1U);
                            WR1_PROG(REG_1600H, 0x0000b520U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x000001a0U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1A24H, 0x08000045U);
                            WR1_PROG(REG_1608H, 0x81840009U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_subfunc003(0x00890011U);
                            WR1_PROG(REG_1A24H, 0x9c000005U);
                            r_rsip_subfunc003(0x00850011U);
                            WR1_PROG(REG_1600H, 0x0000a520U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00000010U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1A24H, 0x08000045U);
                            WR1_PROG(REG_1608H, 0x81840009U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_subfunc003(0x00890011U);
                            WR1_PROG(REG_1A24H, 0x9c000005U);
                            r_rsip_subfunc003(0x00850011U);
                            r_rsip_func100(bswap_32big(0x4eb40a21U),
                                           bswap_32big(0xa39f85b0U),
                                           bswap_32big(0xa3c522cdU),
                                           bswap_32big(0xf44e4edeU));
                            WR1_PROG(REG_143CH, 0x00400000U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            if (CHCK_STS(REG_143CH, 22U, 1U))
                            {
                                WR1_PROG(REG_14BCH, 0x00000020U);
                                WAIT_STS(REG_142CH, 12U, 0U);

                                return RSIP_RET_VERIFICATION_FAIL;
                            }
                            else
                            {
                                r_rsip_func102(bswap_32big(0x250674d8U), bswap_32big(0x43a80b22U),
                                               bswap_32big(0xc8f8ec50U), bswap_32big(0xff775294U));
                                WR1_PROG(REG_14BCH, 0x00000040U);
                                WAIT_STS(REG_142CH, 12U, 0U);

                                return RSIP_RET_PASS;
                            }
                        }
                    }
                }
            }
        }
    }
}
