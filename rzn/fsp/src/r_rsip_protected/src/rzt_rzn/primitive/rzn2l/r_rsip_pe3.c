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

rsip_ret_t r_rsip_pe3 (const uint32_t InData_HashType[], const uint32_t InData_EncSecret[], uint32_t OutData_EncMsg[])
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

    WR1_PROG(REG_1B00H, 0x00e30002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000c84U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xfff1d120U),
                   bswap_32big(0x2faa4fecU),
                   bswap_32big(0xf55245aeU),
                   bswap_32big(0x44993827U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xdaa88b09U), bswap_32big(0x0d84c308U), bswap_32big(0xac19c263U),
                       bswap_32big(0xb315291fU));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000003c7U);
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncSecret[0]);
        WR1_ADDR(REG_1420H, &InData_EncSecret[1]);
        WR1_ADDR(REG_1420H, &InData_EncSecret[2]);
        WR1_ADDR(REG_1420H, &InData_EncSecret[3]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x0000e301U));
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x7634dd00U), bswap_32big(0xab313544U), bswap_32big(0x26705e8fU),
                       bswap_32big(0x506b1176U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01dec19dU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x0000e301U));
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xb746f1dbU), bswap_32big(0x5a25c51bU), bswap_32big(0x277f6537U),
                       bswap_32big(0x999ae399U));
        r_rsip_func046();
        WR1_PROG(REG_1444H, 0x000007c2U);
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xf7009d07U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncSecret[4]);
        WR1_ADDR(REG_1420H, &InData_EncSecret[5]);
        WR1_ADDR(REG_1420H, &InData_EncSecret[6]);
        WR1_ADDR(REG_1420H, &InData_EncSecret[7]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncSecret[8]);
        WR1_ADDR(REG_1420H, &InData_EncSecret[9]);
        WR1_ADDR(REG_1420H, &InData_EncSecret[10]);
        WR1_ADDR(REG_1420H, &InData_EncSecret[11]);
        WR1_PROG(REG_1600H, 0x000008a5U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x80880005U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1400H, 0x03420021U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncSecret[12]);
        WR1_ADDR(REG_1420H, &InData_EncSecret[13]);
        WR1_ADDR(REG_1420H, &InData_EncSecret[14]);
        WR1_ADDR(REG_1420H, &InData_EncSecret[15]);
        WR1_PROG(REG_1A24H, 0x9c100005U);
        WR1_PROG(REG_1400H, 0x00820011U);
        WAIT_STS(REG_1404H, 30U, 0U);
        WR1_PROG(REG_143CH, 0x00001800U);
        r_rsip_func100(bswap_32big(0xc5418fe3U), bswap_32big(0xfad01d14U), bswap_32big(0x0f79e7eaU),
                       bswap_32big(0xf6e712e5U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x2f9188c2U), bswap_32big(0x06d37b74U), bswap_32big(0x1b4869f0U),
                           bswap_32big(0x360e5c08U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0xc5a06cbfU), bswap_32big(0xb63493f2U), bswap_32big(0xea4a3ec7U),
                           bswap_32big(0xc9e99bd8U));
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
            WR1_PROG(REG_1420H, bswap_32big(0x0000e302U));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xb3188574U), bswap_32big(0xc47e61e6U), bswap_32big(0x4ca44bc4U),
                           bswap_32big(0x6fa98a59U));
            r_rsip_func045();
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01f51082U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000e302U));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x70f66037U), bswap_32big(0x613e57a0U), bswap_32big(0x13cbf372U),
                           bswap_32big(0x940273d0U));
            r_rsip_func046();
            r_rsip_func100(bswap_32big(0xfda5267bU), bswap_32big(0x774a8d2cU), bswap_32big(0x811ad803U),
                           bswap_32big(0x5ff103c6U));
            WR1_PROG(REG_1A2CH, 0x40000100U);
            WR1_PROG(REG_1A24H, 0xe7009d07U);
            WR1_PROG(REG_1608H, 0x81880005U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1400H, 0x00890021U);
            WAIT_STS(REG_1404H, 30U, 0U);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1408H, 0x00002022U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_EncMsg[4]);
            RD1_ADDR(REG_1420H, &OutData_EncMsg[5]);
            RD1_ADDR(REG_1420H, &OutData_EncMsg[6]);
            RD1_ADDR(REG_1420H, &OutData_EncMsg[7]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_EncMsg[8]);
            RD1_ADDR(REG_1420H, &OutData_EncMsg[9]);
            RD1_ADDR(REG_1420H, &OutData_EncMsg[10]);
            RD1_ADDR(REG_1420H, &OutData_EncMsg[11]);
            r_rsip_func100(bswap_32big(0x6604ab0fU), bswap_32big(0xb0f5c619U), bswap_32big(0xf0d1bfd5U),
                           bswap_32big(0xca07fbceU));
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
            RD1_ADDR(REG_1420H, &OutData_EncMsg[12]);
            RD1_ADDR(REG_1420H, &OutData_EncMsg[13]);
            RD1_ADDR(REG_1420H, &OutData_EncMsg[14]);
            RD1_ADDR(REG_1420H, &OutData_EncMsg[15]);
            r_rsip_func100(bswap_32big(0x9a5e5ef4U), bswap_32big(0xb34e7cc6U), bswap_32big(0x4963bbb4U),
                           bswap_32big(0xb5fc4369U));
            WR1_PROG(REG_1608H, 0x81040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_EncMsg[0]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_EncMsg[1]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_EncMsg[2]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_EncMsg[3]);
            r_rsip_func102(bswap_32big(0x10685cd2U), bswap_32big(0x0625f807U), bswap_32big(0x0a786f5eU),
                           bswap_32big(0x8be86c85U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
