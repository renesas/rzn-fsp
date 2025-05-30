/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_FEATURE_H
#define BSP_FEATURE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_FEATURE_ADC_ADDITION_SUPPORTED                     (1U)
#define BSP_FEATURE_ADC_CALIBRATION_REG_AVAILABLE              (1U)
#define BSP_FEATURE_ADC_CLOCK_SOURCE                           (FSP_PRIV_CLOCK_PCLKADC)
#define BSP_FEATURE_ADC_GROUP_B_SENSORS_ALLOWED                (1U)
#define BSP_FEATURE_ADC_HAS_ADCER_ADPRC                        (1U)
#define BSP_FEATURE_ADC_HAS_ADCER_ADRFMT                       (1U)
#define BSP_FEATURE_ADC_HAS_PGA                                (1U)
#define BSP_FEATURE_ADC_HAS_SAMPLE_HOLD_REG                    (1U)
#define BSP_FEATURE_ADC_HAS_SAMPLE_HOLD_UNIT_NUM               (3U)
#define BSP_FEATURE_ADC_HAS_VREFAMPCNT                         (0U)
#define BSP_FEATURE_ADC_MAX_RESOLUTION_BITS                    (12U)
#define BSP_FEATURE_ADC_REGISTER_MASK_TYPE                     (3U)
#define BSP_FEATURE_ADC_SAMPLE_STATE_COUNT_TYPE                (2U)
#define BSP_FEATURE_ADC_SENSOR_MIN_SAMPLING_TIME               (4150U)
#define BSP_FEATURE_ADC_SENSORS_EXCLUSIVE                      (0U)
#define BSP_FEATURE_ADC_TSN_CALIBRATION_AVAILABLE              (0U)
#define BSP_FEATURE_ADC_TSN_CALIBRATION32_AVAILABLE            (1U)
#define BSP_FEATURE_ADC_TSN_CALIBRATION32_MASK                 (0x00000FFFU)
#define BSP_FEATURE_ADC_TSN_CONTROL_AVAILABLE                  (1U)
#define BSP_FEATURE_ADC_TSN_SLOPE                              (4000U)
#define BSP_FEATURE_ADC_UNIT                                   (3U)
#define BSP_FEATURE_ADC_UNIT_0_CHANNELS                        (0x000FU) // 0 to 3 in unit 0
#define BSP_FEATURE_ADC_UNIT_1_CHANNELS                        (0x000FU) // 0 to 3 in unit 1
#define BSP_FEATURE_ADC_UNIT_2_CHANNELS                        (0x7FFFU) // 0 to 14 in unit 2
#define BSP_FEATURE_ADC_VALID_UNIT_MASK                        (7U)

#define BSP_FEATURE_ADDRESS_EXPANDER_SUPPORTED                 (1U)

#define BSP_FEATURE_BSC_32BIT_DATA_BUS_WIDTH_SUPPORTED         (1U)
#define BSP_FEATURE_BSC_HAS_CS_MIRROR_AREA                     (0U)
#define BSP_FEATURE_BSC_NOR_CS0_BASE_ADDRESS                   (0x70000000U)
#define BSP_FEATURE_BSC_NOR_CS2_BASE_ADDRESS                   (0x74000000U)
#define BSP_FEATURE_BSC_NOR_CS3_BASE_ADDRESS                   (0x78000000U)
#define BSP_FEATURE_BSC_NOR_CS5_BASE_ADDRESS                   (0x7C000000U)
#define BSP_FEATURE_BSC_NOR_CS0_BASE_MIRROR_ADDRESS            (0x00000000U)
#define BSP_FEATURE_BSC_NOR_CS2_BASE_MIRROR_ADDRESS            (0x00000000U)
#define BSP_FEATURE_BSC_NOR_CS3_BASE_MIRROR_ADDRESS            (0x00000000U)
#define BSP_FEATURE_BSC_NOR_CS5_BASE_MIRROR_ADDRESS            (0x00000000U)

#define BSP_FEATURE_BSP_AFMT_UNIT                              (14U)
#define BSP_FEATURE_BSP_BISS_UNIT                              (14U)
#define BSP_FEATURE_BSP_BOOT_PARAMETER                         (3U)
#define BSP_FEATURE_BSP_CA55_CORE_NUM                          (4U)
#define BSP_FEATURE_BSP_CR52_CORE_NUM                          (2U)
#define BSP_FEATURE_BSP_CS0_BASE_ADDRESS                       (0x70000000U)
#define BSP_FEATURE_BSP_CS0_SIZE                               (0x10000000U)
#define BSP_FEATURE_BSP_DDRSS_SUPPORTED                        (1U)
#define BSP_FEATURE_BSP_ENCOUT_SUPPORTED                       (1U)
#define BSP_FEATURE_BSP_ENDAT_UNIT                             (14U)
#define BSP_FEATURE_BSP_EVENT_NUM_MAX                          (970)
#define BSP_FEATURE_BSP_HAS_CR52_CPU1_TCM                      (1U)
#define BSP_FEATURE_BSP_HAS_CR52_CPU1_LLPP                     (1U)
#define BSP_FEATURE_BSP_HAS_SYSTEMRAM_MIRROR_AREA              (0U)
#define BSP_FEATURE_BSP_HDSL_UNIT                              (14U)
#define BSP_FEATURE_BSP_IO_REGION_ADDRESS_DIFF_DEDICATED       (R_PORT_NSR_BASE - R_PORT_SRN_BASE)
#define BSP_FEATURE_BSP_IO_REGION_ADDRESS_DIFF_SELECTABLE      (R_PORT_SRS_BASE - R_PORT_SRN_BASE)
#define BSP_FEATURE_BSP_IO_SELECTABLE_NON_SAFETY_BASE          (R_PORT_SRN_BASE)
#define BSP_FEATURE_BSP_IO_SELECTABLE_NON_SAFETY_PORT          (13U)
#define BSP_FEATURE_BSP_IRQ_CR52_SEL_SUPPORTED                 (1U)
#define BSP_FEATURE_BSP_IRQ_ENCIF_SEL_SUPPORTED                (1U)
#define BSP_FEATURE_BSP_IRQ_GPT_SEL_SUPPORTED                  (1U)
#define BSP_FEATURE_BSP_IRQ_PRIORITY_MASK                      (0xF8U)
#define BSP_FEATURE_BSP_IRQ_PRIORITY_POS_BIT                   (3U)
#define BSP_FEATURE_BSP_LCDC_SUPPORTED                         (1U)
#define BSP_FEATURE_BSP_MASTER_MPU_REGION_TYPE                 (2U)
#define BSP_FEATURE_BSP_MASTER_MPU0_SUPPORTED                  (1U)
#define BSP_FEATURE_BSP_MASTER_MPU1_SUPPORTED                  (1U)
#define BSP_FEATURE_BSP_MASTER_MPU2_SUPPORTED                  (1U)
#define BSP_FEATURE_BSP_MASTER_MPU3_SUPPORTED                  (1U)
#define BSP_FEATURE_BSP_MASTER_MPU4_SUPPORTED                  (1U)
#define BSP_FEATURE_BSP_MASTER_MPU5_SUPPORTED                  (1U)
#define BSP_FEATURE_BSP_MASTER_MPU6_SUPPORTED                  (1U)
#define BSP_FEATURE_BSP_MASTER_MPU7_SUPPORTED                  (1U)
#define BSP_FEATURE_BSP_MASTER_MPU8_SUPPORTED                  (1U)
#define BSP_FEATURE_BSP_MASTER_MPU9_SUPPORTED                  (1U)
#define BSP_FEATURE_BSP_MASTER_MPU10_SUPPORTED                 (1U)
#define BSP_FEATURE_BSP_MASTER_MPU11_SUPPORTED                 (1U)
#define BSP_FEATURE_BSP_MASTER_MPU12_SUPPORTED                 (1U)
#define BSP_FEATURE_BSP_MASTER_MPU13_SUPPORTED                 (1U)
#define BSP_FEATURE_BSP_MASTER_MPU14_SUPPORTED                 (1U)
#define BSP_FEATURE_BSP_MASTER_MPU15_SUPPORTED                 (1U)
#define BSP_FEATURE_BSP_MODULE_RESET_DUMMY_READ_COUNT          (7U)
#define BSP_FEATURE_BSP_MSTP_CA55_HAS_MSTPCRN                  (1U)
#define BSP_FEATURE_BSP_MSTP_CR52_CPU1_HAS_MSTPCRH             (0U)
#define BSP_FEATURE_BSP_MSTP_CR52_HAS_MSTPCRN                  (1U)
#define BSP_FEATURE_BSP_NON_SELECTABLE_INTERRUPT_EVENT_NUM     (384)
#define BSP_FEATURE_BSP_PCIE_SUPPORTED                         (1U)
#define BSP_FEATURE_BSP_SDHI_SUPPORTED                         (1U)
#define BSP_FEATURE_BSP_SELECTABLE_INTERRUPT_EVENT_NUM         (160)
#define BSP_FEATURE_BSP_SELECTABLE_INTERRUPT_START             (384)
#define BSP_FEATURE_BSP_SEMAPHORE_SUPPORTED                    (1U)
#define BSP_FEATURE_BSP_SHOSTIF_SUPPORTED                      (1U)
#define BSP_FEATURE_BSP_PHOSTIF_SUPPORTED                      (0U)
#define BSP_FEATURE_BSP_SLAVE_STOP_SUPPORTED                   (1U)
#define BSP_FEATURE_BSP_TRACE_CLOCK_SUPPORTED                  (0U)
#define BSP_FEATURE_BSP_XSPI0_CS0_BASE_ADDRESS                 (0x40000000U)
#define BSP_FEATURE_BSP_XSPI0_CS0_SIZE                         (0x10000000U)
#define BSP_FEATURE_BSP_XSPI1_CS0_BASE_ADDRESS                 (0x50000000U)
#define BSP_FEATURE_BSP_XSPI1_CS0_SIZE                         (0x10000000U)

#define BSP_FEATURE_CAN_CHECK_PCLKB_RATIO                      (0U)
#define BSP_FEATURE_CAN_CLOCK                                  (0U)
#define BSP_FEATURE_CAN_MCLOCK_ONLY                            (0U)
#define BSP_FEATURE_CAN_NUM_CHANNELS                           (2U)

#define BSP_FEATURE_CANFD_NUM_CHANNELS                         (2U)
#define BSP_FEATURE_CANFD_NUM_INSTANCES                        (1U)

#define BSP_FEATURE_CGC_CKIO_CLOCK_FREQ_TYPE                   (2U)
#define BSP_FEATURE_CGC_CLMA_UNIT                              (7U)
#define BSP_FEATURE_CGC_CLOCK_SOURCE_NUM                       (6)
#define BSP_FEATURE_CGC_CR52_ATCM_0WAIT_MAX_FREQ_HZ            (500000000U)
#define BSP_FEATURE_CGC_CR52_CLOCK_TYPE                        (2U)
#define BSP_FEATURE_CGC_HAS_BCLK                               (1U)
#define BSP_FEATURE_CGC_HAS_FCLK                               (1U)
#define BSP_FEATURE_CGC_HAS_FLDWAITR                           (0U)
#define BSP_FEATURE_CGC_HAS_FLWT                               (1U)
#define BSP_FEATURE_CGC_HAS_HOCOWTCR                           (1U)
#define BSP_FEATURE_CGC_HAS_MEMWAIT                            (0U)
#define BSP_FEATURE_CGC_HAS_PCLKA                              (1U)
#define BSP_FEATURE_CGC_HAS_PCLKB                              (1U)
#define BSP_FEATURE_CGC_HAS_PCLKC                              (1U)
#define BSP_FEATURE_CGC_HAS_PCLKD                              (1U)
#define BSP_FEATURE_CGC_HAS_PLL                                (1U)
#define BSP_FEATURE_CGC_HAS_PLL2                               (1U)
#define BSP_FEATURE_CGC_HAS_PLL3                               (1U)
#define BSP_FEATURE_CGC_HAS_PLL4                               (1U)
#define BSP_FEATURE_CGC_HAS_SRAMPRCR2                          (0U)
#define BSP_FEATURE_CGC_HAS_SRAMWTSC                           (1U)
#define BSP_FEATURE_CGC_HOCOSF_BEFORE_OPCCR                    (0U)
#define BSP_FEATURE_CGC_HOCOWTCR_64MHZ_ONLY                    (0U)
#define BSP_FEATURE_CGC_ICLK_DIV_RESET                         (BSP_CLOCKS_SYS_CLOCK_DIV_4)
#define BSP_FEATURE_CGC_LOCO_CONTROL_ADDRESS                   (0x81280070U)
#define BSP_FEATURE_CGC_LOCO_STABILIZATION_MAX_US              (61U)
#define BSP_FEATURE_CGC_LOW_SPEED_MAX_FREQ_HZ                  (1000000U) // This MCU does have Low Speed Mode, up to 1MHz
#define BSP_FEATURE_CGC_LOW_VOLTAGE_MAX_FREQ_HZ                (0U)       // This MCU does not have Low Voltage Mode
#define BSP_FEATURE_CGC_MIDDLE_SPEED_MAX_FREQ_HZ               (0U)       // This MCU does not have Middle Speed Mode
#define BSP_FEATURE_CGC_MOCO_STABILIZATION_MAX_US              (15U)
#define BSP_FEATURE_CGC_MODRV_MASK                             (0x30U)
#define BSP_FEATURE_CGC_MODRV_SHIFT                            (0x4U)
#define BSP_FEATURE_CGC_PCLKSCI_CLOCK_FREQ_TYPE                (2U)
#define BSP_FEATURE_CGC_PCLKSPI_CLOCK_FREQ_TYPE                (2U)
#define BSP_FEATURE_CGC_PLL_OR_MAIN_CLOCK_SELECTABLE           (1U)
#define BSP_FEATURE_CGC_PLL_START_PROCESS_TYPE                 (2U)
#define BSP_FEATURE_CGC_PLL0_CONTROL_ADDRESS                   (0x81280030U)
#define BSP_FEATURE_CGC_PLL0_PROTECT                           (BSP_REG_PROTECT_CGC)
#define BSP_FEATURE_CGC_PLL0_SSC_SUPPORTED                     (1U)
#define BSP_FEATURE_CGC_PLL0_STANDBY_STATE_SUPPORTED           (1U)
#define BSP_FEATURE_CGC_PLL1_CONTROL_ADDRESS                   (NULL)
#define BSP_FEATURE_CGC_PLL1_PROTECT                           (NULL)
#define BSP_FEATURE_CGC_PLL1_STANDBY_STATE_SUPPORTED           (0U)
#define BSP_FEATURE_CGC_PLL2_CONTROL_ADDRESS                   (0x812800A0U)
#define BSP_FEATURE_CGC_PLL2_PROTECT                           (BSP_REG_PROTECT_CGC)
#define BSP_FEATURE_CGC_PLL2_SSC_SUPPORTED                     (1U)
#define BSP_FEATURE_CGC_PLL2_STANDBY_STATE_SUPPORTED           (1U)
#define BSP_FEATURE_CGC_PLL3_CONTROL_ADDRESS                   (0x812800C0U)
#define BSP_FEATURE_CGC_PLL3_PROTECT                           (BSP_REG_PROTECT_CGC)
#define BSP_FEATURE_CGC_PLL3_STANDBY_STATE_SUPPORTED           (1U)
#define BSP_FEATURE_CGC_PLL3_VCO_SETTING_SUPPORTED             (1U)
#define BSP_FEATURE_CGC_PLLCCR_MAX_HZ                          (240000000U)
#define BSP_FEATURE_CGC_PLLCCR_TYPE                            (1U)
#define BSP_FEATURE_CGC_PLLCCR_WAIT_US                         (0U) // No wait between setting PLLCCR and clearing PLLSTP
#define BSP_FEATURE_CGC_SCKCR_TYPE                             (2U)
#define BSP_FEATURE_CGC_SCKDIVCR_BCLK_MATCHES_PCLKB            (0U)
#define BSP_FEATURE_CGC_SODRV_MASK                             (0x02U)
#define BSP_FEATURE_CGC_SODRV_SHIFT                            (0x1U)
#define BSP_FEATURE_CGC_STARTUP_OPCCR_MODE                     (0U)

#define BSP_FEATURE_CMT_VALID_CHANNEL_MASK                     (0x3FU)

#define BSP_FEATURE_CMTW_VALID_CHANNEL_MASK                    (0x3U)

#define BSP_FEATURE_CRC_VALID_CHANNEL_MASK                     (0x3U)

#define BSP_FEATURE_DDR_SUPPORTED                              (1U)
#define BSP_FEATURE_DMAC_HAS_CPU1_TCM_AREA                     (1U)
#define BSP_FEATURE_DMAC_MAX_CHANNEL                           (16U)
#define BSP_FEATURE_DMAC_MAX_UNIT                              (3U)
#define BSP_FEATURE_DMAC_UNIT0_ERROR_NUM                       (8U)

#define BSP_FEATURE_DSMIF_ADDRESS_OFFSET                       (0x1000)
#define BSP_FEATURE_DSMIF_CHANNEL_STATUS                       (3U)
#define BSP_FEATURE_DSMIF_CORE_CLOCK_SELECTABLE                (1U)
#define BSP_FEATURE_DSMIF_DATA_FORMAT_SEL                      (1U)
#define BSP_FEATURE_DSMIF_ERROR_STATUS_CLR                     (3U)
#define BSP_FEATURE_DSMIF_HAS_LLPP_UNIT                        (6U)
#define BSP_FEATURE_DSMIF_LLPP_BASE_ADDRESS                    (R_DSMIF0_BASE)
#define BSP_FEATURE_DSMIF_LLPP1_BASE_ADDRESS                   (R_DSMIF6_BASE)
#define BSP_FEATURE_DSMIF_MCLK_FREQ_TYPE                       (2U)
#define BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_CONTROL           (3U)
#define BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_ISR               (3U)
#define BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_NOTIFY            (4U)
#define BSP_FEATURE_DSMIF_OVERCURRENT_ERROR_STATUS             (3U)
#define BSP_FEATURE_DSMIF_OVERCURRENT_NOTIFY_STATUS            (1U)
#define BSP_FEATURE_DSMIF_UNIT                                 (10U) // Unit 6 and Unit 9 are not available.
#define BSP_FEATURE_DSMIF_VALID_UNIT_MASK                      (0x1BFU)
#define BSP_FEATURE_DSMIF_VERSION                              (2U)

#define BSP_FEATURE_ELC_ELC_SSEL_NUM                           (65)
#define BSP_FEATURE_ELC_EVENT_MASK_NUM                         (8U)
#define BSP_FEATURE_ELC_GPT_EVENT_SOURCE_NUM                   (26U)
#define BSP_FEATURE_ELC_GPT_EVENT_MASK_NUM                     (26U)
#define BSP_FEATURE_ELC_GROUP1_PORT_NUM                        (BSP_IO_PORT_14)
#define BSP_FEATURE_ELC_GROUP2_PORT_NUM                        (BSP_IO_PORT_30)
#define BSP_FEATURE_ELC_PERIPHERAL_0_MASK                      (0xFFFFFFFFU) // ELC event source no.0 to 31 available on this MCU
#define BSP_FEATURE_ELC_PERIPHERAL_1_MASK                      (0xFFFFFFFFU) // ELC event source no.32 to 63 available on this MCU.
#define BSP_FEATURE_ELC_PERIPHERAL_2_MASK                      (0xFFFFFFFFU) // ELC event source no.64 to 95 available on this MCU.
#define BSP_FEATURE_ELC_PERIPHERAL_3_MASK                      (0xFFFFFFFFU) // ELC event source no.96 to 127 available on this MCU.
#define BSP_FEATURE_ELC_PERIPHERAL_4_MASK                      (0xFFFFFFFFU) // ELC event source no.128 to 159 available on this MCU.
#define BSP_FEATURE_ELC_PERIPHERAL_5_MASK                      (0xFFFFFFFFU) // ELC event source no.160 to 191 available on this MCU.
#define BSP_FEATURE_ELC_PERIPHERAL_6_MASK                      (0x00000003U) // ELC event source no.192 to 223 available on this MCU.
#define BSP_FEATURE_ELC_PERIPHERAL_7_MASK                      (0x00000000U) // ELC event source no.224 to 255 available on this MCU.
#define BSP_FEATURE_ELC_PERIPHERAL_TYPE                        (3U)

#define BSP_FEATURE_ESC_MAX_PORTS                              (3U)
#define BSP_FEATURE_ETHER_FIFO_DEPTH                           (0x0000070FU)
#define BSP_FEATURE_ETHER_PHY_MAX_CHANNELS                     (4U)
#define BSP_FEATURE_ETHSS_MAX_PORTS                            (4U)
#define BSP_FEATURE_ETHSS_SWITCH_MODE_BIT_MASK                 (3U)
#define BSP_FEATURE_ETHSW_MAX_CHANNELS                         (1U)
#define BSP_FEATURE_ETHSW_SUPPORTED                            (1U)
#define BSP_FEATURE_GMAC_B_SUPPORTED                           (1U)
#define BSP_FEATURE_GMAC_MAX_CHANNELS                          (3U)
#define BSP_FEATURE_GMAC_MAX_PORTS                             (4U)
#define BSP_FEATURE_GMAC_UNIT                                  (3U)

#define BSP_FEATURE_GPT_32BIT_CHANNEL_MASK                     (0x3FFFF)
#define BSP_FEATURE_GPT_CHANNEL                                (56U)
#define BSP_FEATURE_GPT_INPUT_CAPTURE_SIGNAL_SELECTABLE        (1U)
#define BSP_FEATURE_GPT_LLPP_BASE_ADDRESS                      (R_GPT00_0_BASE)
#define BSP_FEATURE_GPT_LLPP_BASE_CHANNEL                      (0U) // LLPP channel: ch0-29
#define BSP_FEATURE_GPT_LLPP_CHANNEL_ADDRESS_OFFSET            (R_GPT00_1_BASE - R_GPT00_0_BASE)
#define BSP_FEATURE_GPT_LLPP_CHANNEL_MASK                      (0x001FU)
#define BSP_FEATURE_GPT_LLPP_CHANNEL_PER_UNIT                  (5U)
#define BSP_FEATURE_GPT_LLPP_UNIT_ADDRESS_OFFSET               (R_GPT01_0_BASE - R_GPT00_0_BASE)
#define BSP_FEATURE_GPT_LLPP1_BASE_ADDRESS                     (R_GPT06_0_BASE)
#define BSP_FEATURE_GPT_LLPP1_BASE_CHANNEL                     (30U) // LLPP1 channel: ch30-44
#define BSP_FEATURE_GPT_LLPP1_CHANNEL_ADDRESS_OFFSET           (R_GPT06_1_BASE - R_GPT06_0_BASE)
#define BSP_FEATURE_GPT_LLPP1_CHANNEL_MASK                     (0x001FU)
#define BSP_FEATURE_GPT_LLPP1_UNIT_ADDRESS_OFFSET              (R_GPT07_0_BASE - R_GPT06_0_BASE)
#define BSP_FEATURE_GPT_NONSAFETY_BASE_ADDRESS                 (R_GPT09_0_BASE)
#define BSP_FEATURE_GPT_NONSAFETY_BASE_CHANNEL                 (45U) // Non-safety channel: ch45-51
#define BSP_FEATURE_GPT_NONSAFETY_CHANNEL_ADDRESS_OFFSET       (R_GPT09_1_BASE - R_GPT09_0_BASE)
#define BSP_FEATURE_GPT_NONSAFETY_CHANNEL_MASK                 (0x007FU)
#define BSP_FEATURE_GPT_REGISTER_MASK_TYPE                     (2U)
#define BSP_FEATURE_GPT_SAFETY_BASE_ADDRESS                    (R_GPT10_0_BASE)
#define BSP_FEATURE_GPT_SAFETY_BASE_CHANNEL                    (52U) // safety channel: ch52-55
#define BSP_FEATURE_GPT_SAFETY_CHANNEL_ADDRESS_OFFSET          (R_GPT10_1_BASE - R_GPT10_0_BASE)
#define BSP_FEATURE_GPT_SAFETY_CHANNEL_MASK                    (0x000FU)
#define BSP_FEATURE_GPT_VALID_CHANNEL_MASK                     (0x3FFFF)
#define BSP_FEATURE_GPTE_CHANNEL_MASK                          (0xF0)
#define BSP_FEATURE_GPTEH_CHANNEL_MASK                         (0xF)

#define BSP_FEATURE_ICU_ERROR_CA55_SUPPORTED                   (1U)
#define BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED              (1U)
#define BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED    (1U)
#define BSP_FEATURE_ICU_ERROR_DSMIF_ERR_REG_NUM                (12U)
#define BSP_FEATURE_ICU_ERROR_DSMIF_ERR0_REG_MASK              (0x1FFFFFFFU)
#define BSP_FEATURE_ICU_ERROR_DSMIF_ERR1_REG_MASK              (0x1FFFFFFFU)
#define BSP_FEATURE_ICU_ERROR_DSMIF_ERR2_REG_MASK              (0x1FFFFFFFU)
#define BSP_FEATURE_ICU_ERROR_DSMIF_ERR3_REG_MASK              (0x1FFFFFFFU)
#define BSP_FEATURE_ICU_ERROR_DSMIF_ERR4_REG_MASK              (0x1FFFFFFFU)
#define BSP_FEATURE_ICU_ERROR_DSMIF_ERR5_REG_MASK              (0x1FFFFFFFU)
#define BSP_FEATURE_ICU_ERROR_DSMIF_ERR7_REG_MASK              (0x1FFFFFFFU)
#define BSP_FEATURE_ICU_ERROR_DSMIF_ERR8_REG_MASK              (0x1FFFFFFFU)
#define BSP_FEATURE_ICU_ERROR_DSMIF_ERR10_REG_MASK             (0x3FFFFFFFU)
#define BSP_FEATURE_ICU_ERROR_DSMIF_ERR11_REG_MASK             (0x3FFFFFFFU)
#define BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED    (1U)
#define BSP_FEATURE_ICU_ERROR_ENCIF_ERR_REG_NUM                (5U)
#define BSP_FEATURE_ICU_ERROR_ENCIF_ERR0_REG_MASK              (0xFFFFFFFFU)
#define BSP_FEATURE_ICU_ERROR_ENCIF_ERR1_REG_MASK              (0x7F7F7F7FU)
#define BSP_FEATURE_ICU_ERROR_ENCIF_ERR2_REG_MASK              (0x7F7F7F7FU)
#define BSP_FEATURE_ICU_ERROR_ENCIF_ERR3_REG_MASK              (0x7F7F7F7FU)
#define BSP_FEATURE_ICU_ERROR_ENCIF_ERR4_REG_MASK              (0x7F7F7F7FU)
#define BSP_FEATURE_ICU_ERROR_ERR_SOURCE_NUM                   (23U)
#define BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM                 (3U)
#define BSP_FEATURE_ICU_ERROR_PERI_ERR0_REG_MASK               (0x7FFFFFFFU)
#define BSP_FEATURE_ICU_ERROR_PERI_ERR1_REG_MASK               (0x7FFFFFFFU)
#define BSP_FEATURE_ICU_ERROR_PERI_ERR2_REG_MASK               (0x1FFFFFFFU)
#define BSP_FEATURE_ICU_ERROR_PERI_ERR3_REG_MASK               (0x00000000U)
#define BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE                  (3U)
#define BSP_FEATURE_ICU_HAS_WUPEN1                             (0U)
#define BSP_FEATURE_ICU_INTER_CPU_IRQ_CHANNEL                  (2U)
#define BSP_FEATURE_ICU_INTER_CPU_IRQ_CHANNELS_MASK            (0xFFFFU)
#define BSP_FEATURE_ICU_INTER_CPU_IRQ_NS_SWINT_MASK            (0x3FFFU) // Non-safety channel: ch0-13 (bit0-13)
#define BSP_FEATURE_ICU_INTER_CPU_IRQ_S_SWINT_MASK             (0xC000U) // Safety channel: ch14-15 (bit14-15)
#define BSP_FEATURE_ICU_INTER_CPU_IRQ_S_SWINT_SHIFT            (14U)
#define BSP_FEATURE_ICU_IRQ_CHANNELS_MASK                      (0xFFFFU)
#define BSP_FEATURE_ICU_SAFETY_REGISTER_TYPE                   (2)
#define BSP_FEATURE_ICU_WUPEN_MASK                             (0xFF4FFFFFU)

#define BSP_FEATURE_IIC_FAST_MODE_PLUS                         (0U)
#define BSP_FEATURE_IIC_SAFETY_CHANNEL                         (2U)
#define BSP_FEATURE_IIC_SAFETY_CHANNEL_BASE_ADDRESS            (R_IIC2_BASE)
#define BSP_FEATURE_IIC_VALID_CHANNEL_MASK                     (0x07)

#define BSP_FEATURE_IOPORT_ELC_PORTS                           (4U)
#define BSP_FEATURE_IOPORT_HAS_ETHERNET                        (1U)
#define BSP_FEATURE_IOPORT_HAS_NONSAFETY_DEDICATED_PORT        (1U)
#define BSP_FEATURE_IOPORT_PIN_PFC_TYPE                        (3U)
#define BSP_FEATURE_IOPORT_PORT_NUM                            (36U)
#define BSP_FEATURE_IOPORT_SELECTABLE_PORT_MAX                 (12U)

#define BSP_FEATURE_LPM_CHANGE_MSTP_ARRAY                      {{0, 15}, {0, 13}, {1, 31}, {1, 6}, {1, 5}, {1, 4}, \
                                                                {2, 5}                                             \
}
#define BSP_FEATURE_LPM_CHANGE_MSTP_REQUIRED                   (1U)
#define BSP_FEATURE_LPM_DPSIEGR_MASK                           (0x00137FFFU)
#define BSP_FEATURE_LPM_DPSIER_MASK                            (0x071F7FFFU)
#define BSP_FEATURE_LPM_HAS_DEEP_STANDBY                       (1U)
#define BSP_FEATURE_LPM_HAS_SBYCR_OPE                          (1U)
#define BSP_FEATURE_LPM_HAS_SNZEDCR1                           (0U)
#define BSP_FEATURE_LPM_HAS_SNZREQCR1                          (0U)
#define BSP_FEATURE_LPM_HAS_STCONR                             (1U)
#define BSP_FEATURE_LPM_SBYCR_WRITE1_B14                       (0U)
#define BSP_FEATURE_LPM_SNZEDCR_MASK                           (0x000000FFU)
#define BSP_FEATURE_LPM_SNZREQCR_MASK                          (0x7342FFFFU)

#define BSP_FEATURE_MAILBOX_SEM_SUPPORTED                      (1U)

#define BSP_FEATURE_MTU3_MAX_CHANNELS                          (9U)
#define BSP_FEATURE_MTU3_UVW_MAX_CHANNELS                      (3U)
#define BSP_FEATURE_MTU3_VALID_CHANNEL_MASK                    (0x01FF)

#define BSP_FEATURE_OSPI_DEVICE_0_START_ADDRESS                (0x0U)
#define BSP_FEATURE_OSPI_DEVICE_1_START_ADDRESS                (0x0U)

#define BSP_FEATURE_PCIE_CHANNEL0_ERROR_AXI_NUM                (85)
#define BSP_FEATURE_PCIE_CHANNEL0_ERROR_CORRECTABLE_RC_NUM     (82)
#define BSP_FEATURE_PCIE_CHANNEL0_ERROR_FATAL_RC_NUM           (84)
#define BSP_FEATURE_PCIE_CHANNEL0_ERROR_NON_FATAL_RC_NUM       (83)
#define BSP_FEATURE_PCIE_CHANNEL0_ERROR_RC_NUM                 (81)
#define BSP_FEATURE_PCIE_CHANNEL1_ERROR_AXI_NUM                (90)
#define BSP_FEATURE_PCIE_CHANNEL1_ERROR_CORRECTABLE_RC_NUM     (87)
#define BSP_FEATURE_PCIE_CHANNEL1_ERROR_FATAL_RC_NUM           (89)
#define BSP_FEATURE_PCIE_CHANNEL1_ERROR_NON_FATAL_RC_NUM       (88)
#define BSP_FEATURE_PCIE_CHANNEL1_ERROR_RC_NUM                 (86)

#define BSP_FEATURE_POE3_ERROR_SIGNAL_TYPE                     (3U)
#define BSP_FEATURE_POE3_PIN_SELECT_TYPE                       (3U)

#define BSP_FEATURE_POEG_CHANNEL_MASK                          (0xFU)
#define BSP_FEATURE_POEG_ERROR_SIGNAL_TYPE                     (3U)
#define BSP_FEATURE_POEG_GROUP_OFSSET_ADDRESS                  (0x400)
#define BSP_FEATURE_POEG_LLPP_UNIT                             (0U)
#define BSP_FEATURE_POEG_MAX_UNIT                              (2U)
#define BSP_FEATURE_POEG_NONSAFETY_UNIT                        (1U)
#define BSP_FEATURE_POEG_SAFETY_UNIT                           (2U)

#define BSP_FEATURE_RSIP_JTAG_DEBUG_AUTH_LEVEL1                (1U)
#define BSP_FEATURE_RSIP_JTAG_DEBUG_AUTH_LEVEL2                (1U)
#define BSP_FEATURE_RSIP_SCI_USB_BOOT_AUTH                     (1U)
#define BSP_FEATURE_RSIP_OTP_ADDRESS_SPACE                     (2U)
#define BSP_FEATURE_RSIP_OTF_CHANNEL                           (0U)

#define BSP_FEATURE_RTC_MODULE_START_TYPE                      (2U)

#define BSP_FEATURE_SCI_ADDRESS_MATCH_CHANNELS                 (BSP_FEATURE_SCI_CHANNELS)
#define BSP_FEATURE_SCI_CHANNELS                               (0x3FU)
#define BSP_FEATURE_SCI_SAFETY_CHANNEL                         (5U)
#define BSP_FEATURE_SCI_SAFETY_CHANNEL_BASE_ADDRESS            (R_SCI5_BASE)
#define BSP_FEATURE_SCI_SPI_MAX_CPUCLK_MHZ                     (1200U)
#define BSP_FEATURE_SCI_SPI_MIN_PCLKM_MHZ                      (125U) // Minimum PCLKM greater than minimum SCInASYNCCLK
#define BSP_FEATURE_SCI_SPI_MIN_SCINASYNCCLK_MHZ               (75U)
#define BSP_FEATURE_SCI_UART_CTSPEN_CHANNELS                   (0x03FU)
#define BSP_FEATURE_SCI_UART_FIFO_CHANNELS                     (0x3FFU)
#define BSP_FEATURE_SCI_UART_FIFO_DEPTH                        (16U)
#define BSP_FEATURE_SCIE_SUPPORTED                             (1U)

#define BSP_FEATURE_SDHI_CLOCK                                 (FSP_PRIV_CLOCK_PCLKAM)
#define BSP_FEATURE_SDHI_HAS_CARD_DETECTION                    (1U)
#define BSP_FEATURE_SDHI_MAX_CHANNELS                          (2U)
#define BSP_FEATURE_SDHI_MIN_CLOCK_DIVISION_SHIFT              (0U) // 1 (2^0) is minimum division supported
#define BSP_FEATURE_SDHI_SUPPORTS_8_BIT_MMC                    (1U)
#define BSP_FEATURE_SDHI_VALID_CHANNEL_MASK                    (0x03U)

#define BSP_FEATURE_SEM_SUPPORTED                              (0U)
#define BSP_FEATURE_SHARED_MEMORY_SETTING_TYPE                 (2U)

#define BSP_FEATURE_SPI_HAS_BYTE_SWAP                          (1U)
#define BSP_FEATURE_SPI_HAS_SPCR3                              (0U)
#define BSP_FEATURE_SPI_HAS_SSL_LEVEL_KEEP                     (1U)
#define BSP_FEATURE_SPI_MAX_CHANNEL                            (4U)
#define BSP_FEATURE_SPI_SAFETY_CHANNEL                         (3U)
#define BSP_FEATURE_SPI_SAFETY_CHANNEL_BASE_ADDRESS            (R_SPI3_BASE)

#define BSP_FEATURE_TFU_FIXED_POINT_SUPPORTED                  (1)
#define BSP_FEATURE_TFU_SUPPORTED                              (1U)
#define BSP_FEATURE_TFU_UNIT                                   (2U)
#define BSP_FEATURE_TFU_UNIT_NUMBER                            (BSP_CFG_CORE_CR52)
#define BSP_FEATURE_TFU_VERSION                                (2)

#define BSP_FEATURE_TSU_B_CALIBRAION_DATA_CHECK_ENABLE         (1)
#define BSP_FEATURE_TSU_B_CALIBRAION_DATA_INVALID              (0)
#define BSP_FEATURE_TSU_B_CALIBRAION_DATA_MASK                 (0xFFFU)
#define BSP_FEATURE_TSU_B_CONTINUOUS_MODE_SUPPORTED            (1)
#define BSP_FEATURE_TSU_B_ELC_TRIGGER_SUPPORTED                (0)
#define BSP_FEATURE_TSU_B_HIGH_TEMPERATURE                     (125.0F)
#define BSP_FEATURE_TSU_B_LOW_TEMPERATURE                      (-40.0F)
#define BSP_FEATURE_TSU_B_UNIT_0_HIGH_TEMPERATURE_REGISTER     (0x1DC)
#define BSP_FEATURE_TSU_B_UNIT_0_LOW_TEMPERATURE_REGISTER      (0x1DD)
#define BSP_FEATURE_TSU_VERSION                                (2U)

#define BSP_FEATURE_TZC400_SUPPORTED                           (1U)
#define BSP_FEATURE_USB_HOST_HS_SET_TYPE                       (2U)
#define BSP_FEATURE_USB_HOST_INIT_TYPE                         (2U)
#define BSP_FEATURE_USB_PERI_INIT_TYPE                         (2U)

#define BSP_FEATURE_XSPI_CHANNELS                              (0x03U)
#define BSP_FEATURE_XSPI_CS_ADDRESS_SPACE_SETTING_TYPE         (2U)
#define BSP_FEATURE_XSPI_DEVICE_0_MIRROR_START_ADDRESS         (0x0U)
#define BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS                (0x40000000U)
#define BSP_FEATURE_XSPI_DEVICE_1_MIRROR_START_ADDRESS         (0x0U)
#define BSP_FEATURE_XSPI_DEVICE_1_START_ADDRESS                (0x50000000U)
#define BSP_FEATURE_XSPI_DEVICE_ADDRESS_SPACE_SIZE             (0x10000000U)
#define BSP_FEATURE_XSPI_HAS_AXI_BRIDGE                        (1U)
#define BSP_FEATURE_XSPI_NUM_CHIP_SELECT                       (2U)
#define BSP_FEATURE_XSPI_VOLTAGE_SETTING_SUPPORTED             (1U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
