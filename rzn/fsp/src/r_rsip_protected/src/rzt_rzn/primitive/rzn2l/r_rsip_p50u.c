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

void r_rsip_p50u (const uint32_t InData_Text[], uint32_t OutData_Text[], const uint32_t MAX_CNT)
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
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        r_rsip_func100(bswap_32big(0xe8927a95U), bswap_32big(0xfdab44dbU), bswap_32big(0xfd633707U),
                       bswap_32big(0xec623457U));
        WR1_PROG(REG_1444H, 0x00020061U);
        WR1_PROG(REG_182CH, 0x40000000U);
        WR1_PROG(REG_1824H, 0x0a008106U);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        r_rsip_func100(bswap_32big(0xaf41348eU), bswap_32big(0x284c9eadU), bswap_32big(0x3ea046e6U),
                       bswap_32big(0x93e0645eU));
        WR1_PROG(REG_1444H, 0x00020061U);
        WR1_PROG(REG_182CH, 0x40000000U);
        WR1_PROG(REG_1824H, 0x0a00810eU);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        r_rsip_func100(bswap_32big(0x8aa2cf9fU), bswap_32big(0x6260ee0fU), bswap_32big(0xa0f48a0bU),
                       bswap_32big(0x6a0d8aedU));
        WR1_PROG(REG_1444H, 0x00020061U);
        WR1_PROG(REG_182CH, 0x40000000U);
        WR1_PROG(REG_1824H, 0x0e008506U);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        r_rsip_func100(bswap_32big(0x48f5dc47U), bswap_32big(0x49e22536U), bswap_32big(0x73c9cd42U),
                       bswap_32big(0xdb0413d9U));
        WR1_PROG(REG_1444H, 0x00020061U);
        WR1_PROG(REG_182CH, 0x40000000U);
        WR1_PROG(REG_1824H, 0x0900890eU);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (0x00000004U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        r_rsip_func100(bswap_32big(0xc4b80483U), bswap_32big(0xc757e426U), bswap_32big(0x1b3715d0U),
                       bswap_32big(0x98b932ecU));
        WR1_PROG(REG_1444H, 0x00020061U);
        WR1_PROG(REG_182CH, 0x40000000U);
        WR1_PROG(REG_1824H, 0x07008d06U);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }

    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_Text[0]);
    WR1_ADDR(REG_1420H, &InData_Text[1]);
    WR1_ADDR(REG_1420H, &InData_Text[2]);
    WR1_ADDR(REG_1420H, &InData_Text[3]);
    for (iLoop = 4; iLoop < MAX_CNT; iLoop = iLoop + 4)
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
    RD1_ADDR(REG_1420H, &OutData_Text[MAX_CNT - 4]);
    RD1_ADDR(REG_1420H, &OutData_Text[MAX_CNT - 3]);
    RD1_ADDR(REG_1420H, &OutData_Text[MAX_CNT - 2]);
    RD1_ADDR(REG_1420H, &OutData_Text[MAX_CNT - 1]);
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func206();
        r_rsip_func101(bswap_32big(0x24683ebbU), bswap_32big(0xa6a797cdU), bswap_32big(0xc7740e85U),
                       bswap_32big(0x6b5f1107U));
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func206();
        r_rsip_func101(bswap_32big(0x5db915f7U), bswap_32big(0x7bcd4bb9U), bswap_32big(0xf60674e5U),
                       bswap_32big(0x82bc8a4dU));
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func206();
        r_rsip_func101(bswap_32big(0x318cb320U), bswap_32big(0xe3977a99U), bswap_32big(0xf3421485U),
                       bswap_32big(0x94744633U));
    }
    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func206();
        r_rsip_func101(bswap_32big(0x2b71d23eU), bswap_32big(0x8f4b7dbfU), bswap_32big(0x718e9445U),
                       bswap_32big(0x8b9a1858U));
    }
    else if (0x00000004U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func206();
        r_rsip_func101(bswap_32big(0xcbede642U), bswap_32big(0x5a2e370aU), bswap_32big(0x621f3cfaU),
                       bswap_32big(0x8234524bU));
    }
}
