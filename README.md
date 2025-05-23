## Overview

Flexible Software Package (FSP) for Renesas RZ/N series.

FSP is the next generation Arm® MCU software package from Renesas, that enables secure devices and IoT connectivity through production ready peripheral drivers, FreeRTOS, and portable middleware stacks.
FSP includes best-in-class HAL drivers with high performance and low memory footprint. Middleware stacks with FreeRTOS integration are included to ease implementation of complex modules like communication and security.
The e² studio provides support with intuitive configurators and intelligent code generation to make programming and debugging easier and faster.

FSP uses an open software ecosystem and provides flexibility in using your preferred RTOS, legacy code, and third-party ecosystem solutions.

### Current Release

[FSP v2.2.0](https://github.com/renesas/rzn-fsp/releases/tag/v2.2.0)

### Supported RZ/N series Kits

- RSK+RZN2L
- RZ/N2H Evaluation Board

### Supported Software Packaged with FSP

For a list of software modules packaged with FSP, see [Supported Software](SUPPORTED_SOFTWARE.md).

### Product Security Advisories

[Product Security Advisories](https://github.com/renesas/rzn-fsp/issues?q=label%3Aproduct_security_advisory) for FSP and third party software (where available) are tagged with the 'product_security_advisory' label. Please check these issues for information from the respective vendors for affected versions and a recommended workaround or patch upgrade.

### Known Issues

Known issues checks Getting Started with Flexible Software Package (Documentation No:R01AN6434EJ) in each product page.
* [RZ/N2L](https://www.renesas.com/rzn2l)
* [RZ/N2H](https://www.renesas.com/rzn2h)

### Setup Instructions

See Getting Started with Flexible Software Package (Documentation No: R01AN6434EJ).  

#### For existing users that are using FSP with e² studio

- FSP versions of 1.0.0 and later require a minimum e² studio version of 2022-07.
- FSP versions of 1.1.0 and later require a minimum e² studio version of 2022-10.
- FSP versions of 1.2.0 and later require a minimum e² studio version of 2023-01.
- FSP versions of 1.3.0 and later require a minimum e² studio version of 2023-07.
- FSP versions of 2.0.0 and later require a minimum e² studio version of 2024-01.1.
- FSP versions of 2.1.0 and later require a minimum e² studio version of 2024-10.
- FSP versions of 2.2.0 and later require a minimum e² studio version of 2025-01.

If you have already installed a previous FSP release that included e² studio then you can download the packs separately. These are available for download under the Assets section for each release. There is a zipped version, FSP_Packs_\<version\>.zip, and an installer version, FSP_Packs_\<version\>.exe.

#### For new users that are using FSP with e² studio

1.	Download the FSP with e² studio Installer from the Assets section of the [current release](https://github.com/renesas/rzn-fsp/releases/tag/v2.2.0).
2.	Run the installer. This will install the e² studio tool, FSP packs, GCC toolchain and other tools required to use this software. No additional installations are required.

#### If using FSP Smart Configurator (FSP SC) with IAR Embedded Workbench for ARM ####

1. Download the IAR Embedded Workbench for ARM installer from [IAR website](https://www.iar.com/products/architectures/arm/iar-embedded-workbench-for-arm/).
2. Download the FSP Smart Configurator Installer from the Assets section of the [current release](https://github.com/renesas/rzn-fsp/releases/tag/v2.2.0).
3. Run each installer.


### Related Links

FSP Releases :  https://github.com/renesas/rzn-fsp/releases

FSP Documentation : https://renesas.github.io/rzn-fsp

RZ/N2L Product Information : www.renesas.com/rzn2l

RZ/N2H Product Information : www.renesas.com/rzn2h

e² studio : www.renesas.com/e2studio

Example Projects : [RZ/N2L sample code](https://www.renesas.com/products/microcontrollers-microprocessors/rz-mpus/rzn2l-integrated-tsn-compliant-3-port-gigabit-ethernet-switch-enables-various-industrial-applications#tab-sample-code), [RZ/N2H sample code](https://www.renesas.com/products/microcontrollers-microprocessors/rz-mpus/rzn2h-advanced-mpu-delivers-high-performance-application-processing-and-real-time-operation-industrial#tab-sample-code)

Knowledge Base: https://en-support.renesas.com/knowledgeBase/category/31243

Support: www.renesas.com/support
