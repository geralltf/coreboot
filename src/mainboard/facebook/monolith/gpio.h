/*
 * This file is part of the coreboot project.
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 */

#ifndef MAINBOARD_GPIO_H
#define MAINBOARD_GPIO_H

#include <soc/gpe.h>
#include <soc/gpio.h>

#ifndef __ACPI__
/* Pad configuration in ramstage. */
static const struct pad_config gpio_table[] = {
/* PCH_RCIN# */		PAD_CFG_NF(GPP_A0, NONE, DEEP, NF1),
/* LAD_0 */		PAD_CFG_NF(GPP_A1, 20K_PD, DEEP, NF1),
/* LAD_1 */		PAD_CFG_NF(GPP_A2, 20K_PD, DEEP, NF1),
/* LAD_2 */		PAD_CFG_NF(GPP_A3, 20K_PD, DEEP, NF1),
/* LAD_3 */		PAD_CFG_NF(GPP_A4, 20K_PD, DEEP, NF1),
/* LFRAME# */		PAD_CFG_NF(GPP_A5, NONE, DEEP, NF1),
/* PCH_SERIRQ */	PAD_CFG_NF(GPP_A6, NONE, DEEP, NF1),
/* PIRQA# */	        PAD_CFG_GPO(GPP_A7, 1, DEEP),
/* PM_CLKRUN_N */	PAD_CFG_NF(GPP_A8, NONE, DEEP, NF1),
/* CLK_LPC_EC */	PAD_CFG_NF(GPP_A9, 20K_PD, DEEP, NF1),
/* CLKOUT_LPC_CN */	PAD_CFG_NF(GPP_A10, 20K_PD, DEEP, NF1),
/* SLEEP */	        PAD_CFG_NC(GPP_A11),	/* available on the module not used here */
/* NC */		PAD_CFG_NC(GPP_A12),
/* PCH_SYSWARN */	PAD_CFG_NF(GPP_A13, NONE, DEEP, NF1),
/* PM_SUS_STAT */	PAD_CFG_NF(GPP_A14, NONE, DEEP, NF1),
/* KBC_SUSACK */	PAD_CFG_NF(GPP_A15, 20K_PD, DEEP, NF1),
/* SD_1P8_SEL */	PAD_CFG_NF(GPP_A16, NONE, DEEP, NF1),
/* SD_PWR_EN */		PAD_CFG_NF(GPP_A17, NONE, DEEP, NF1),
/* NC */		PAD_CFG_NC(GPP_A18),
/* NC */		PAD_CFG_NC(GPP_A19),
/* NC */		PAD_CFG_NC(GPP_A20),
/* NC */		PAD_CFG_NC(GPP_A21),
/* NC */		PAD_CFG_NC(GPP_A22),
/* NC */		PAD_CFG_NC(GPP_A23),
/* CORE_VID0 */		PAD_CFG_NC(GPP_B0),
/* CORE_VID1 */		PAD_CFG_NC(GPP_B1),
/* VRALERT# */		PAD_CFG_NF(GPP_B2, NONE, DEEP, NF1),
/* NC */		PAD_CFG_NC(GPP_B3),
/* NC */		PAD_CFG_NC(GPP_B4),
/* SRCCLKREQ0 */	PAD_CFG_NC(GPP_B5),
/* SRCCLKREQ1 */	PAD_CFG_NC(GPP_B6),
/* SRCCLKREQ2 */	PAD_CFG_NC(GPP_B7),
/* SRCCLKREQ3 */	PAD_CFG_NC(GPP_B8),
/* SRCCLKREQ4 */	PAD_CFG_NC(GPP_B9),
/* SRCCLKREQ5 */	PAD_CFG_NC(GPP_B10),
/* EXT_PWR_GATE */	PAD_CFG_NF(GPP_B11, NONE, DEEP, NF1),
/* SLP_S0 */		PAD_CFG_NF(GPP_B12, NONE, DEEP, NF1),
/* PCH_PLTRST */	PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1),
/* PCH_SPKR */		PAD_CFG_NF(GPP_B14, NONE, DEEP, NF1),
/* NC */		PAD_CFG_NC(GPP_B15),
/* NC */		PAD_CFG_NC(GPP_B16),
/* NC */		PAD_CFG_NC(GPP_B17),
/* GSPI0_MOSI */	PAD_CFG_NC(GPP_B18),
/* NC */		PAD_CFG_NC(GPP_B19),
/* NC */		PAD_CFG_NC(GPP_B20),
/* NC */		PAD_CFG_NC(GPP_B21),
/* BIOS_SEL */		PAD_CFG_NC(GPP_B22),
/* CB_OVT# */		PAD_CFG_GPO(GPP_B23, 1, DEEP),

/* SMB_SCL */		PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1),
/* SMB_SDA */		PAD_CFG_NF(GPP_C1, NONE, DEEP, NF1),
/* SMBALERT# */		PAD_CFG_GPO(GPP_C2, 1, DEEP),
/* SML0_CLK */		PAD_CFG_NF(GPP_C3, NONE, DEEP, NF1),
/* SML0_SDA */		PAD_CFG_NF(GPP_C4, NONE, DEEP, NF1),
/* SML0_ALERT */	PAD_CFG_NC(GPP_C5),
/* GPP_C6 - RESERVED */
/* GPP_C7 - RESERVED */
/* CPU_UART0_RXD */	PAD_CFG_NF(GPP_C8, NONE, DEEP, NF1),
/* CPU_UART0_TXD */	PAD_CFG_NF(GPP_C9, NONE, DEEP, NF1),
/* CPU_UART0_RTS */	PAD_CFG_NF(GPP_C10, NONE, DEEP, NF1),
/* CPU_UART0_CTS */	PAD_CFG_NF(GPP_C11, NONE, DEEP, NF1),
/* NC */		PAD_CFG_NC(GPP_C12),
/* NC */		PAD_CFG_NC(GPP_C13),
/* NC */		PAD_CFG_NC(GPP_C14),
/* NC */		PAD_CFG_NC(GPP_C15),
/* I2C0_SDA */		PAD_CFG_NF(GPP_C16, NONE, DEEP, NF1),
/* I2C0_SCL */		PAD_CFG_NF(GPP_C17, NONE, DEEP, NF1),
/* NC */		PAD_CFG_NC(GPP_C18),
/* NC */		PAD_CFG_NC(GPP_C19),
/* NC */		PAD_CFG_NC(GPP_C20),
/* NC */		PAD_CFG_NC(GPP_C21),
/* EC_SCI# NOT USED */	PAD_CFG_NC(GPP_C22),
/* EC_SMI# NOT USED */	PAD_CFG_NC(GPP_C23),
/* TOUCH_SPI1_CS */	PAD_CFG_NC(GPP_D0),
/* TPM_PIRQ_N NOT USED */	PAD_CFG_NC(GPP_D1),
/* NC */		PAD_CFG_NC(GPP_D2),
/* NC */		PAD_CFG_NC(GPP_D3),
/* NC */		PAD_CFG_NC(GPP_D4),
/* NC */		PAD_CFG_NC(GPP_D5),
/* NC */		PAD_CFG_NC(GPP_D6),
/* NC */		PAD_CFG_NC(GPP_D7),
/* NC */		PAD_CFG_NC(GPP_D8),
/* NC */		PAD_CFG_NC(GPP_D9),
/* NC */		PAD_CFG_NC(GPP_D11),
/* NC */		PAD_CFG_NC(GPP_D12),
/* NC */		PAD_CFG_NC(GPP_D13),
/* NC */		PAD_CFG_NC(GPP_D14),
/* NC */		PAD_CFG_NC(GPP_D15),
/* NC */		PAD_CFG_NC(GPP_D16),
/* NC */		PAD_CFG_NC(GPP_D17),
/* NC */		PAD_CFG_NC(GPP_D18),
/* NC */		PAD_CFG_NC(GPP_D19),
/* NC */		PAD_CFG_NC(GPP_D20),
/* LID# NOT USED */	PAD_CFG_NC(GPP_D21),
/* NC */		PAD_CFG_NC(GPP_D22),
/* NC */		PAD_CFG_NC(GPP_D23),
/* NC */		PAD_CFG_NC(GPP_E0),
/* NC */		PAD_CFG_NC(GPP_E1),
/* NC */		PAD_CFG_NC(GPP_E2),
/* NC */		PAD_CFG_NC(GPP_E3),
/* DEVSLP0 TP */	PAD_CFG_NC(GPP_E4),
/* DEVSLP0 TP */	PAD_CFG_NC(GPP_E5),
/* DEVSLP1 TP */	PAD_CFG_NC(GPP_E6),
/* NC */		PAD_CFG_NC(GPP_E7),
/* SATA_LED_N */	PAD_CFG_NF(GPP_E8, NONE, DEEP, NF1),
/* USB2_OC0_1 */	PAD_CFG_NF(GPP_E9, NONE, DEEP, NF1),
/* USB2_OC2_3 */	PAD_CFG_NF(GPP_E10, NONE, DEEP, NF1),
/* USB2_OC4_5 */	PAD_CFG_NF(GPP_E11, NONE, DEEP, NF1),
/* USB2_OC6_7 */	PAD_CFG_NF(GPP_E11, NONE, DEEP, NF1),
/* DDPB_HPD0_C */	PAD_CFG_NF(GPP_E13, NONE, DEEP, NF1),
/* DDPC_HPD1_C */	PAD_CFG_NF(GPP_E14, NONE, DEEP, NF1),
/* DDPD_HPD2_C NC */	PAD_CFG_NC(GPP_E15),
/* DDPE_HPD3_C NC */	PAD_CFG_NC(GPP_E16),
/* EDP_HPD_C */		PAD_CFG_NF(GPP_E17, NONE, DEEP, NF1),
/* DDPB_CTRLCLK */	PAD_CFG_NF(GPP_E18, NONE, DEEP, NF1),
/* DDPB_CTRLDAT */	PAD_CFG_NF(GPP_E19, 20K_PD, DEEP, NF1),
/* DDI2_DDC_SCL_L */	PAD_CFG_NF(GPP_E20, NONE, DEEP, NF1),
/* DDI2_DDC_SDA_L */	PAD_CFG_NF(GPP_E21, 20K_PD, DEEP, NF1),
/* DDPD_CTRLCLK NC */	PAD_CFG_NC(GPP_E22),
/* DDPD_CTRLDAT NC */	PAD_CFG_NC(GPP_E23),
/* NC */		PAD_CFG_NC(GPP_F0),
/* NC */		PAD_CFG_NC(GPP_F1),
/* NC */		PAD_CFG_NC(GPP_F2),
/* NC */		PAD_CFG_NC(GPP_F3),
/* NC */		PAD_CFG_NC(GPP_F4),
/* NC */		PAD_CFG_NC(GPP_F5),
/* NC */		PAD_CFG_NC(GPP_F6),
/* NC */		PAD_CFG_NC(GPP_F7),
/* NC */		PAD_CFG_NC(GPP_F8),
/* NC */		PAD_CFG_NC(GPP_F9),
/* NC */		PAD_CFG_NC(GPP_F10),
/* NC */		PAD_CFG_NC(GPP_F11),
/* EMMC_CMD */		PAD_CFG_NF(GPP_F12, NONE, DEEP, NF1),
/* EMMC_DATA0 */	PAD_CFG_NF(GPP_F13, NONE, DEEP, NF1),
/* EMMC_DATA1 */	PAD_CFG_NF(GPP_F14, NONE, DEEP, NF1),
/* EMMC_DATA2 */	PAD_CFG_NF(GPP_F15, NONE, DEEP, NF1),
/* EMMC_DATA3 */	PAD_CFG_NF(GPP_F16, NONE, DEEP, NF1),
/* EMMC_DATA4 */	PAD_CFG_NF(GPP_F17, NONE, DEEP, NF1),
/* EMMC_DATA5 */	PAD_CFG_NF(GPP_F18, NONE, DEEP, NF1),
/* EMMC_DATA6 */	PAD_CFG_NF(GPP_F19, NONE, DEEP, NF1),
/* EMMC_DATA7 */	PAD_CFG_NF(GPP_F20, NONE, DEEP, NF1),
/* EMMC_STROBE */	PAD_CFG_NF(GPP_F21, NONE, DEEP, NF1),
/* EMMC_CLK */		PAD_CFG_NF(GPP_F22, NONE, DEEP, NF1),
/* GPP_F23 */		PAD_CFG_NC(GPP_F23),
/* SD_CMD */		PAD_CFG_NF(GPP_G0, NONE, DEEP, NF1),
/* SD_D0 */		PAD_CFG_NF(GPP_G1, NONE, DEEP, NF1),
/* SD_D1 */		PAD_CFG_NF(GPP_G2, NONE, DEEP, NF1),
/* SD_D2 */		PAD_CFG_NF(GPP_G3, NONE, DEEP, NF1),
/* SD_D3 */		PAD_CFG_NF(GPP_G4, NONE, DEEP, NF1),
/* SD_CD# */		PAD_CFG_NF(GPP_G5, NONE, DEEP, NF1),
/* SD_CLK */		PAD_CFG_NF(GPP_G6, NONE, DEEP, NF1),
/* SD_WP */		PAD_CFG_NF(GPP_G7, NONE, DEEP, NF1),
/* PCH_BATLOW */	PAD_CFG_NF(GPD0, NONE, DEEP, NF1),
/* KBC_ACPRESENT */	PAD_CFG_NF(GPD1, NONE, DEEP, NF1),
/* PCH_LAN_WAKE */	PAD_CFG_NF(GPD2, NONE, DEEP, NF1),
/* KBC_PWRBTN */	PAD_CFG_NF(GPD3, NONE, DEEP, NF1),
/* SLP_S3# */		PAD_CFG_NF(GPD4, NONE, DEEP, NF1),
/* SLP_S4# */		PAD_CFG_NF(GPD5, NONE, DEEP, NF1),
/* PM_SLP_M_N */	PAD_CFG_NF(GPD6, NONE, DEEP, NF1),
/* BIOS_RECOVERY NOT USED */	PAD_CFG_NC(GPD7),
/* CPU_SUSCLK */	PAD_CFG_NF(GPD8, NONE, DEEP, NF1),
/* SLP_WLAN# */		PAD_CFG_NF(GPD9, NONE, DEEP, NF1),
/* SLP_S5# */		PAD_CFG_NF(GPD10, NONE, DEEP, NF1),
/* PCH_LANPHYC */	PAD_CFG_NF(GPD11, NONE, DEEP, NF1),
};

#endif
#endif
