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

rsip_ret_t r_rsip_pb6f (const uint32_t InData_TextBitLen[], const uint32_t InData_Text[], uint32_t OutData_Text[])
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
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_TextBitLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000037c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00076bdeU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00026fdeU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000bffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38008c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000007fU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00020020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3420a800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000d3e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x2000abc0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000fffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xe60d201bU),
                   bswap_32big(0xeb01b77cU),
                   bswap_32big(0x8234e238U),
                   bswap_32big(0xec9a12b1U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x759deeffU), bswap_32big(0xf667149fU), bswap_32big(0xef365c65U),
                       bswap_32big(0xb3640011U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0x0b53710cU), bswap_32big(0x527b9218U), bswap_32big(0x232e9c11U),
                       bswap_32big(0x695f53dbU));
        WR1_PROG(REG_1608H, 0x810103c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1408H, 0x00005006U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
        r_rsip_func100(bswap_32big(0x0f9537bcU), bswap_32big(0x02f0ed76U), bswap_32big(0x3c0543d7U),
                       bswap_32big(0x5712f26eU));
        WR1_PROG(REG_1444H, 0x00020061U);
        WR1_PROG(REG_182CH, 0x00000020U);
        WR1_PROG(REG_1824H, 0x0d00890eU);
        WR1_PROG(REG_1408H, 0x000c1000U);
        iLoop = 0;
        if (S_RAM[0] >= 4)
        {
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_Text[0]);
            WR1_ADDR(REG_1420H, &InData_Text[1]);
            WR1_ADDR(REG_1420H, &InData_Text[2]);
            WR1_ADDR(REG_1420H, &InData_Text[3]);
            for (iLoop = 4; iLoop < S_RAM[0]; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_Text[iLoop + 0]);
                WR1_ADDR(REG_1420H, &InData_Text[iLoop + 1]);
                WR1_ADDR(REG_1420H, &InData_Text[iLoop + 2]);
                WR1_ADDR(REG_1420H, &InData_Text[iLoop + 3]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop - 4]);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop - 3]);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop - 2]);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop - 1]);
            }

            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_Text[iLoop - 4]);
            RD1_ADDR(REG_1420H, &OutData_Text[iLoop - 3]);
            RD1_ADDR(REG_1420H, &OutData_Text[iLoop - 2]);
            RD1_ADDR(REG_1420H, &OutData_Text[iLoop - 1]);
        }

        r_rsip_func206();
        r_rsip_func100(bswap_32big(0x2f8db848U), bswap_32big(0xa5e14b5eU), bswap_32big(0x9d88abf3U),
                       bswap_32big(0x63426cf3U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x7d8830b5U), bswap_32big(0x1618a5b1U), bswap_32big(0x534f9601U),
                           bswap_32big(0x116e44adU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1600H, 0x38008c00U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000007fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00A60000U);
            r_rsip_func100(bswap_32big(0x8db6a3ffU), bswap_32big(0x6f10d2d0U), bswap_32big(0x06784f4fU),
                           bswap_32big(0x959d3e92U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func100(bswap_32big(0x805dc68fU),
                               bswap_32big(0x8df298bcU),
                               bswap_32big(0xc35aa806U),
                               bswap_32big(0xd905e76bU));
                WR1_PROG(REG_1444H, 0x000000a1U);
                WR1_PROG(REG_1824H, 0x0c000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1608H, 0x80040140U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1400H, 0x03410011U);
                WAIT_STS(REG_1404H, 30U, 0U);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1444H, 0x000000a1U);
                WR1_PROG(REG_182CH, 0x00000020U);
                WR1_PROG(REG_1824H, 0x0d00880cU);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1444H, 0x000003c1U);
                WR1_PROG(REG_182CH, 0x00000020U);
                WR1_PROG(REG_1824H, 0x0d00890dU);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_Text[iLoop + 0]);
                WR1_ADDR(REG_1420H, &InData_Text[iLoop + 1]);
                WR1_ADDR(REG_1420H, &InData_Text[iLoop + 2]);
                WR1_ADDR(REG_1420H, &InData_Text[iLoop + 3]);
                WR1_PROG(REG_1600H, 0x000008c6U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x80840006U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1400H, 0x03410011U);
                WAIT_STS(REG_1404H, 30U, 0U);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000010U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1444H, 0x000003c7U);
                WR1_PROG(REG_1608H, 0x80840007U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_Text[iLoop + 4]);
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_Text[iLoop + 5]);
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_Text[iLoop + 6]);
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_Text[iLoop + 7]);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b4a0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003500U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00036908U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00008d00U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000000cU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000024c8U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000024e8U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003826U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003847U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003460U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00008c60U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000001fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b480U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0xffffffffU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00004403U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00007484U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000c24U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00001484U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000c44U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00001041U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003c47U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000037e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00008fe0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000007fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x38008fe0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000001fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x1000a7e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000020U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b7c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000080U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002bdfU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00056bdeU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000353eU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x810103c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x00005006U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
                for (jLoop = 0; jLoop < S_RAM[0]; jLoop = jLoop + 1)
                {
                    WR1_PROG(REG_1600H, 0x000024c5U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x000024e5U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00003ba6U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00003fa7U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x000033c0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xaca769faU),
                                   bswap_32big(0x33620c87U),
                                   bswap_32big(0x53665cc9U),
                                   bswap_32big(0xd2b423b3U));
                }

                r_rsip_func100(bswap_32big(0xd18251bcU),
                               bswap_32big(0x9dfd17b9U),
                               bswap_32big(0x37e06a22U),
                               bswap_32big(0xa42a18d2U));
                WR1_PROG(REG_1600H, 0x38000fdeU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1824H, 0x08000045U);
                WR1_PROG(REG_1608H, 0x81040140U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1400H, 0x00490011U);
                WAIT_STS(REG_1404H, 30U, 0U);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000010U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_182CH, 0x00000020U);
                WR1_PROG(REG_1824H, 0x0d00890dU);
                WR1_PROG(REG_1608H, 0x81840007U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1400H, 0x00490011U);
                WAIT_STS(REG_1404H, 30U, 0U);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1408H, 0x00001012U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop]);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 1]);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 2]);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 3]);
                WR1_PROG(REG_1600H, 0x000008c6U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000024c8U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003826U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000c24U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003c26U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000bffU);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (jLoop = 0; jLoop < S_RAM[0]; jLoop = jLoop + 1)
                {
                    WR1_PROG(REG_1600H, 0x000024c5U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00003fe6U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00003120U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x8127a32fU),
                                   bswap_32big(0xff530947U),
                                   bswap_32big(0x1fc40892U),
                                   bswap_32big(0x4c0d4b12U));
                }

                r_rsip_func100(bswap_32big(0x2914c6f6U),
                               bswap_32big(0x91560dfdU),
                               bswap_32big(0xee44e245U),
                               bswap_32big(0xb9b11528U));
                WR1_PROG(REG_1600H, 0x38000d29U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000008c6U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81840006U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x00005012U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 4]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 5]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 6]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 7]);
                r_rsip_func101(bswap_32big(0xa525a1b7U),
                               bswap_32big(0xfa9a07ceU),
                               bswap_32big(0x3e38a224U),
                               bswap_32big(0xafe9d030U));
            }

            r_rsip_func102(bswap_32big(0x5709979cU), bswap_32big(0x3ffb381bU), bswap_32big(0xc447f141U),
                           bswap_32big(0xc6bed177U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
