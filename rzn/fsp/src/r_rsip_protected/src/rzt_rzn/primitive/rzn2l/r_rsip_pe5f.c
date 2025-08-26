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

rsip_ret_t r_rsip_pe5f (const uint32_t InData_Msg[],
                        const uint32_t InData_EncMsg[],
                        uint32_t       OutData_KDFInfo[],
                        const uint32_t MAX_CNT,
                        const uint32_t MAX_CNT2)
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
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010100U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    uint32_t max_cnt2 = bswap_32big(MAX_CNT2);
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
        r_rsip_subfunc009(bswap_32big(0x0000e504U));
        r_rsip_func101(bswap_32big(0x07ede99cU), bswap_32big(0x656155b1U), bswap_32big(0x63cba605U),
                       bswap_32big(0xe5b58f5dU));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01f51082U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x0000e504U));
        r_rsip_func101(bswap_32big(0x15807f76U), bswap_32big(0x8940191aU), bswap_32big(0x9e1e27bdU),
                       bswap_32big(0xe0f5f399U));
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
            r_rsip_subfunc003(0x01420011U);
            WR1_PROG(REG_1600H, 0x00002d20U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xf4ae9fbeU), bswap_32big(0x1fe05c70U), bswap_32big(0x0cb3798eU),
                           bswap_32big(0x9f7c1072U));
        }

        WR1_PROG(REG_1600H, 0x38000909U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[MAX_CNT2 - 4]);
        WR1_ADDR(REG_1420H, &InData_EncMsg[MAX_CNT2 - 3]);
        WR1_ADDR(REG_1420H, &InData_EncMsg[MAX_CNT2 - 2]);
        WR1_ADDR(REG_1420H, &InData_EncMsg[MAX_CNT2 - 1]);
        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_subfunc003(0x00820011U);
        r_rsip_func100(bswap_32big(0x4d502e2bU), bswap_32big(0x96b55e8cU), bswap_32big(0x8b557424U),
                       bswap_32big(0x5945e8aaU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x152450ebU), bswap_32big(0xfd8d7958U), bswap_32big(0xb5bd203fU),
                           bswap_32big(0xbd9274c6U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func101(bswap_32big(0xb867ac57U), bswap_32big(0x6b91cf31U), bswap_32big(0x4ca8dd68U),
                           bswap_32big(0xedd4527fU));
        }
    }
    else
    {
        r_rsip_func101(bswap_32big(0x684e7af4U), bswap_32big(0xbf964f98U), bswap_32big(0x6e853a83U),
                       bswap_32big(0xa84e3dd3U));
    }

    WAIT_STS(REG_2030H, 0U, 1U);
    WR1_PROG(REG_1444H, 0x00020064U);
    for (iLoop = 0; iLoop < (MAX_CNT & 0xfffffff0U); iLoop = iLoop + 16)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 0]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 1]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 2]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 3]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 7]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 8]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 9]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 10]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 11]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 12]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 13]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 14]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 15]);
    }

    WAIT_STS(REG_1444H, 31U, 1U);
    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop = iLoop + 1)
    {
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 0]);
    }

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2030H, 8U, 0U);
    WR1_PROG(REG_143CH, 0x00001600U);
    WAIT_STS(REG_2030H, 4U, 1U);
    r_rsip_func100(bswap_32big(0x4076071eU),
                   bswap_32big(0x0a98c16dU),
                   bswap_32big(0xae852e2fU),
                   bswap_32big(0x8977d7bcU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x0000e505U));
    r_rsip_func101(bswap_32big(0xdfa12bfaU),
                   bswap_32big(0xf899ae17U),
                   bswap_32big(0x2067a848U),
                   bswap_32big(0xc2552d88U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01f51082U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000e505U));
    r_rsip_func101(bswap_32big(0xe56e7cfaU),
                   bswap_32big(0x5b43929dU),
                   bswap_32big(0xcc32763fU),
                   bswap_32big(0xe37c7ae7U));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0x397ca306U),
                   bswap_32big(0xe73f1d00U),
                   bswap_32big(0x91247f26U),
                   bswap_32big(0x38ccc363U));
    WR1_PROG(REG_1A2CH, 0x40000100U);
    WR1_PROG(REG_1A24H, 0xe7009d07U);
    r_rsip_subfunc003(0x00850021U);
    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[4]);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[5]);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[6]);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[7]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[8]);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[9]);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[10]);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[11]);
    r_rsip_func100(bswap_32big(0x14f8d88aU),
                   bswap_32big(0x882eb151U),
                   bswap_32big(0x6baa2a29U),
                   bswap_32big(0x17492e2cU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[12]);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[13]);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[14]);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[15]);
    r_rsip_func100(bswap_32big(0xcd9b66e1U),
                   bswap_32big(0x2db899bbU),
                   bswap_32big(0x05a9f402U),
                   bswap_32big(0x4b4ddf43U));
    WR1_PROG(REG_1608H, 0x81040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[0]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[1]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[2]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[3]);
    r_rsip_func102(bswap_32big(0xe034af69U),
                   bswap_32big(0x376a4b72U),
                   bswap_32big(0x9af1d2a8U),
                   bswap_32big(0xc4330405U));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
