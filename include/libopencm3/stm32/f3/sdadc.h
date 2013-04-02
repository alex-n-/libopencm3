/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Alex Niebling <aniebling@microdevelopment.de>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#include <libopencm3/cm3/common.h>

#define SDADC1				SDADC1_BASE
#define SDADC2				SDADC2_BASE
#define SDADC3				SDADC3_BASE

/* Control register 1 (SDADC_CR1) */
#define SDADC_CR1(sdadc_base)		MMIO32(sdadc_base + 0x00)
#define SDADC1_CR1			SDADC_CR1(SDADC1)
#define SDADC2_CR1			SDADC_CR1(SDADC2)
#define SDADC3_CR1			SDADC_CR1(SDADC3)

/* Control register 2 (SDADC_CR2) */
#define SDADC_CR2(sdadc_base)		MMIO32(sdadc_base + 0x04)
#define SDADC1_CR2			SDADC_CR2(SDADC1)
#define SDADC2_CR2			SDADC_CR2(SDADC2)
#define SDADC3_CR2			SDADC_CR2(SDADC3)

/* interrupt and status register (SDADC_ISR) */
#define SDADC_ISR(sdadc_base)		MMIO32(sdadc_base + 0x08)
#define SDADC1_ISR			SDADC_ISR(SDADC1)
#define SDADC2_ISR			SDADC_ISR(SDADC2)
#define SDADC3_ISR			SDADC_ISR(SDADC3)

/* clear interrupt and status register (SDADC_CLRISR) */
#define SDADC_CLRISR(sdadc_base)		MMIO32(sdadc_base + 0x0C)
#define SDADC1_CLRISR			SDADC_CLRISR(SDADC1)
#define SDADC2_CLRISR			SDADC_CLRISR(SDADC2)
#define SDADC3_CLRISR			SDADC_CLRISR(SDADC3)

/* RESERVED 0x10 */

/* injected channel group selection register (SDADC_JCHGR) */
#define SDADC_JCHGR(sdadc_base)		MMIO32(sdadc_base + 0x14)
#define SDADC1_JCHGR			SDADC_JCHGR(SDADC1)
#define SDADC2_JCHGR			SDADC_JCHGR(SDADC2)
#define SDADC3_JCHGR			SDADC_JCHGR(SDADC3)

/* RESERVED 0x18 */
/* RESERVED 0x1C */

/* configuration 0 register (SDADC_CONF0R) */
#define SDADC_CONF0R(sdadc_base)		MMIO32(sdadc_base + 0x20)
#define SDADC1_CONF0R			SDADC_CONF0R(SDADC1)
#define SDADC2_CONF0R			SDADC_CONF0R(SDADC2)
#define SDADC3_CONF0R			SDADC_CONF0R(SDADC3)

/* configuration 0 register (SDADC_CONF1R) */
#define SDADC_CONF1R(sdadc_base)		MMIO32(sdadc_base + 0x24)
#define SDADC1_CONF1R			SDADC_CONF1R(SDADC1)
#define SDADC2_CONF1R			SDADC_CONF1R(SDADC2)
#define SDADC3_CONF1R			SDADC_CONF1R(SDADC3)

/* configuration 0 register (SDADC_CONF2R) */
#define SDADC_CONF2R(sdadc_base)		MMIO32(sdadc_base + 0x28)
#define SDADC1_CONF2R			SDADC_CONF2R(SDADC1)
#define SDADC2_CONF2R			SDADC_CONF2R(SDADC2)
#define SDADC3_CONF2R			SDADC_CONF2R(SDADC3)

/* RESERVED 0x2C - 0x3C */

/* channel configuration register 1 (SDADC_CONFCHR1) */
#define SDADC_CONFCHR1(sdadc_base)		MMIO32(sdadc_base + 0x40)
#define SDADC1_CONFCHR1			SDADC_CONFCHR1(SDADC1)
#define SDADC2_CONFCHR1			SDADC_CONFCHR1(SDADC2)
#define SDADC3_CONFCHR1			SDADC_CONFCHR1(SDADC3)

/* channel configuration register 2 (SDADC_CONFCHR2) */
#define SDADC_CONFCHR2(sdadc_base)		MMIO32(sdadc_base + 0x44)
#define SDADC1_CONFCHR2			SDADC_CONFCHR2(SDADC1)
#define SDADC2_CONFCHR2			SDADC_CONFCHR2(SDADC2)
#define SDADC3_CONFCHR2			SDADC_CONFCHR2(SDADC3)

/* RESERVED 0x48 - 0x5C */

/* data register for injected group (SDADC_JDATAR) */
#define SDADC_JDATAR(sdadc_base)		MMIO32(sdadc_base + 0x60)
#define SDADC1_JDATAR			SDADC_JDATAR(SDADC1)
#define SDADC2_JDATAR			SDADC_JDATAR(SDADC2)
#define SDADC3_JDATAR			SDADC_JDATAR(SDADC3)

/* data register for the regular channel (SDADC_RDATAR) */
#define SDADC_RDATAR(sdadc_base)		MMIO32(sdadc_base + 0x64)
#define SDADC1_RDATAR			SDADC_RDATAR(SDADC1)
#define SDADC2_RDATAR			SDADC_RDATAR(SDADC2)
#define SDADC3_RDATAR			SDADC_RDATAR(SDADC3)

/* RESERVED 0x68 - 0x6C */

/* SDADC1 and SDADC2 injected data register (SDADC_JDATA12R) */
#define SDADC_JDATA12R(sdadc_base)		MMIO32(sdadc_base + 0x70)
#define SDADC1_JDATA12R			SDADC_JDATA12R(SDADC1)
#define SDADC2_JDATA12R			SDADC_JDATA12R(SDADC2)
#define SDADC3_JDATA12R			SDADC_JDATA12R(SDADC3)

/* SDADC1 and SDADC2 regular data register (SDADC_RDATA12R) */
#define SDADC_RDATA12R(sdadc_base)		MMIO32(sdadc_base + 0x74)
#define SDADC1_RDATA12R			SDADC_RDATA12R(SDADC1)
#define SDADC2_RDATA12R			SDADC_RDATA12R(SDADC2)
#define SDADC3_RDATA12R			SDADC_RDATA12R(SDADC3)

/* SDADC1 and SDADC3 injected data register (SDADC_JDATA13R) */
#define SDADC_JDATA13R(sdadc_base)		MMIO32(sdadc_base + 0x78)
#define SDADC1_JDATA13R			SDADC_JDATA13R(SDADC1)
#define SDADC2_JDATA13R			SDADC_JDATA13R(SDADC2)
#define SDADC3_JDATA13R			SDADC_JDATA13R(SDADC3)

/* SDADC1 and SDADC3 regular data register (SDADC_RDATA13R) */
#define SDADC_RDATA13R(sdadc_base)		MMIO32(sdadc_base + 0x7C)
#define SDADC1_RDATA13R			SDADC_RDATA13R(SDADC1)
#define SDADC2_RDATA13R			SDADC_RDATA13R(SDADC2)
#define SDADC3_RDATA13R			SDADC_RDATA13R(SDADC3)

/* RESERVED 0x80 - 0xBC */

/* --- SDADC_CR1 values ---------------------------------------------------- */

/* EOCALIE : End of calibration interrupt enable */
#define  SDADC_CR1_EOCALIE		(1 << 0)
/* JEOCIE : Injected end of conversion interrupt enable */
#define  SDADC_CR1_JEOCIE		(1 << 1)
/* JOVRIE : Injected data overrun interrupt enable */
#define  SDADC_CR1_JOVRIE		(1 << 2)
/* REOCIE : Regular end of conversion interrupt enable */
#define  SDADC_CR1_REOCIE		(1 << 3)
/* ROVRIE : Regular data overrun interrupt enable */
#define  SDADC_CR1_ROVRIE		(1 << 4)
/* REFV : Reference voltage selection */
#define  SDADC_CR1_REFV_MASK	(3 << 8)
/* REFV_0 : Reference voltage selection bit 0 */
#define  SDADC_CR1_REFV_0		(1 << 8)
/* REFV_1 : Reference voltage selection bit 1 */
#define  SDADC_CR1_REFV_1		(1 << 9)
/* SLOWCK : Slow clock mode enable */
#define  SDADC_CR1_SLOWCK		(1 << 10)
/* SBI : Enter standby mode when idle */
#define  SDADC_CR1_SBI			(1 << 11)
/* PDI : Enter power down mode when idle */
#define  SDADC_CR1_PDI			(1 << 12) 	/* !!! NOT DOCUMENTED IN MANUAL !!! */
/* JSYNC : Launch a injected conversion synchronously with SDADC1 */
#define  SDADC_CR1_JSYNC		(1 << 14)
/* RSYNC : Launch regular conversion synchronously with SDADC1 */
#define  SDADC_CR1_RSYNC		(1 << 15)
/* JDMAEN : DMA channel enabled to read data for the injected channel group */
#define  SDADC_CR1_JDMAEN		(1 << 16)
/* RDMAEN : DMA channel enabled to read data for the regular channel */
#define  SDADC_CR1_RDMAEN		(1 << 17)
/* INT : Initialization mode request */
#define  SDADC_CR1_INIT			(1 << 31)

/* --- SDADC_CR2 values ---------------------------------------------------- */

/* ADON : SDADC enable */
#define  SDADC_CR2_ADON				(1 << 0)
/* CALIB : Number of calibration sequences to be performed */
#define  SDADC_CR2_CALIBCNT_MASK	(3 << 1)
/* CALIB_0 : Number of calibration sequences to be performed bit 0 */
#define  SDADC_CR2_CALIBCNT_0		(1 << 2)
/* CALIB_1 : Number of calibration sequences to be performed bit 1 */
#define  SDADC_CR2_CALIBCNT_1		(1 << 3)
/* STARTCALIB : Start calibration */
#define  SDADC_CR2_STARTCALIB		(1 << 4)
/* JCONT : Continuous mode selection for injected conversions */
#define  SDADC_CR2_JCONT			(1 << 5)
/* JDS : Delay start of injected conversions */
#define  SDADC_CR2_JDS				(1 << 6)
/* JEXTSEL : Trigger signal selection for launching injected conversions */
#define  SDADC_CR2_JEXTSEL_MASK		(15 << 8)
/* JEXTSEL_0 : Trigger signal selection for launching injected conversions bit 0 */
#define  SDADC_CR2_JEXTSEL_0		(1 << 8)
/* JEXTSEL_1 : Trigger signal selection for launching injected conversions bit 1 */
#define  SDADC_CR2_JEXTSEL_1		(1 << 9)
/* JEXTSEL_2 : Trigger signal selection for launching injected conversions bit 2 */
#define  SDADC_CR2_JEXTSEL_2		(1 << 10)
/* JEXTSEL_3 : Trigger signal selection for launching injected conversions bit 3 */
#define  SDADC_CR2_JEXTSEL_3		(1 << 11)
/* JEXTEN Trigger enable and trigger edge selection for injected conversions */
#define  SDADC_CR2_JEXTEN_MASK		(3 << 13)
/* JEXTEN_0 : Trigger enable and trigger edge selection for injected conversions bit 0 */
#define  SDADC_CR2_JEXTEN_0			(1 << 13)
/* JEXTEN_1 : Trigger enable and trigger edge selection for injected conversions bit 1 */
#define  SDADC_CR2_JEXTEN_1			(1 << 14)
/* JSWSTART : Start a conversion of the injected group of channels */
#define  SDADC_CR2_JSWSTART			(1 << 15)
/* RCH : Regular channel selection */
#define  SDADC_CR2_RCH_SHIFT		16
#define  SDADC_CR2_RCH_MASK			(15 << 16)
/* RCH_0 : Regular channel selection bit 0 */
#define  SDADC_CR2_RCH_0			(1 << 16)
/* RCH_1 : Regular channel selection bit 1 */
#define  SDADC_CR2_RCH_1			(1 << 17)
/* RCH_2 : Regular channel selection bit 2 */
#define  SDADC_CR2_RCH_2			(1 << 18)
/* RCH_3 : Regular channel selection bit 3 */
#define  SDADC_CR2_RCH_3			(1 << 19)
/* RCONT : Continuous mode selection for regular conversions */
#define  SDADC_CR2_RCONT			(1 << 22)
/* RSWSTART : Software start of a conversion on the regular channel */
#define  SDADC_CR2_RSWSTART			(1 << 23)
/* FAST : Fast conversion mode selection */
#define  SDADC_CR2_FAST				(1 << 24)

/* --- SDADC_ISR values ---------------------------------------------------- */

/* EOCALF : End of calibration flag */
#define  SDADC_ISR_EOCALF		(1 << 0)
/* JEOCF : End of injected conversion flag */
#define  SDADC_ISR_JEOCF		(1 << 1)
/* JOVRF : Injected conversion overrun flag */
#define  SDADC_ISR_JOVRF		(1 << 2)
/* REOCF : End of regular conversion flag */
#define  SDADC_ISR_REOCF		(1 << 3)
/* ROVRF : Regular conversion overrun flag */
#define  SDADC_ISR_ROVRF		(1 << 4)
/* CALIBIP : Calibration in progress status */
#define  SDADC_ISR_CALIBIP		(1 << 12)
/* JCIP : Injected conversion in progress status */
#define  SDADC_ISR_JCIP			(1 << 13)
/* RCIP : Regular conversion in progress status */
#define  SDADC_ISR_RCIP			(1 << 14)
/* STABIP : Stabilization in progress status */
#define  SDADC_ISR_STABIP		(1 << 15)
/* INITRDY : Initialization mode is ready */
#define  SDADC_ISR_INITRDY		(1 << 31)

/* --- SDADC_CLRISR values ------------------------------------------------- */

/* CLREOCALF : Clear the end of calibration flag */
#define  SDADC_CLRISR_CLREOCALF		(1 << 0)
/* CLRJOVRF : Clear the injected conversion overrun flag */
#define  SDADC_CLRISR_CLRJOVRF		(1 << 1)
/* CLRROVRF : Clear the regular conversion overrun flag */
#define  SDADC_CLRISR_CLRROVRF		(1 << 2)

/* --- SDADC_JCHGR values -------------------------------------------------- */

/* JCHG : Injected channel group selection */
#define  SDADC_JCHGR_JCHG_MASK		(0x1FFF < 0)
/* JCHG_0 : Injected channel 0 selection */
#define  SDADC_JCHGR_JCHG_0			(1 << 0)
/* JCHG_1 : Injected channel 1 selection */
#define  SDADC_JCHGR_JCHG_1			(1 << 1)
/* JCHG_2 : Injected channel 2 selection */
#define  SDADC_JCHGR_JCHG_2			(1 << 2)
/* JCHG_3 : Injected channel 3 selection */
#define  SDADC_JCHGR_JCHG_3			(1 << 3)
/* JCHG_4 : Injected channel 4 selection */
#define  SDADC_JCHGR_JCHG_4			(1 << 4)
/* JCHG_5 : Injected channel 5 selection */
#define  SDADC_JCHGR_JCHG_5			(1 << 5)
/* JCHG_6 : Injected channel 6 selection */
#define  SDADC_JCHGR_JCHG_6			(1 << 6)
/* JCHG_7 : Injected channel 7 selection */
#define  SDADC_JCHGR_JCHG_7			(1 << 7)
/* JCHG_8 : Injected channel 8 selection */
#define  SDADC_JCHGR_JCHG_8			(1 << 8)

/* --- SDADC_CONF0R values ------------------------------------------------- */

/* OFFSET0 : 12-bit calibration offset for configuration 0 */
#define  SDADC_CONF0R_OFFSET0_MASK		(0xFFF << 0)
/* GAIN0 : Gain setting for configuration 0 */
#define  SDADC_CONF0R_GAIN0_MASK		(7 << 20)
/* GAIN0_0 : Gain setting for configuration 0 Bit 0*/
#define  SDADC_CONF0R_GAIN0_0			(1 << 20)
/* GAIN0_1 : Gain setting for configuration 0 Bit 1 */
#define  SDADC_CONF0R_GAIN0_1			(1 << 21)
/* GAIN0_2 : Gain setting for configuration 0 Bit 2 */
#define  SDADC_CONF0R_GAIN0_2			(1 << 22)
/* SE0 : Single ended mode for configuration 0 */
#define  SDADC_CONF0R_SE0_MASK			(3 << 26)
/* SE0_0 : Single ended mode for configuration 0 Bit 0 */
#define  SDADC_CONF0R_SE0_0				(1 << 26)
/* SE0_1 : Single ended mode for configuration 0 Bit 1 */
#define  SDADC_CONF0R_SE0_1				(1 << 27)
/* COMMON0 : Common mode for configuration 0 */
#define  SDADC_CONF0R_COMMON0_MASK		(3 << 30)
/* COMMON0_0 : Common mode for configuration 0 Bit 0 */
#define  SDADC_CONF0R_COMMON0_0			(1 << 30)
/* COMMON0_1 : Common mode for configuration 0 Bit 1 */
#define  SDADC_CONF0R_COMMON0_1			(1 << 31)

/* --- SDADC_CONF1R values ------------------------------------------------- */

/* OFFSET1 : 12-bit calibration offset for configuration 1 */
#define  SDADC_CONF1R_OFFSET1_MASK		(0xFFF << 0)
/* GAIN1 : Gain setting for configuration 1 */
#define  SDADC_CONF1R_GAIN1_MASK		(7 << 20)
/* GAIN1_0 : Gain setting for configuration 1 Bit 0*/
#define  SDADC_CONF1R_GAIN1_0			(1 << 20)
/* GAIN1_1 : Gain setting for configuration 1 Bit 1 */
#define  SDADC_CONF1R_GAIN1_1			(1 << 21)
/* GAIN1_2 : Gain setting for configuration 1 Bit 2 */
#define  SDADC_CONF1R_GAIN1_2			(1 << 22)
/* SE1 : Single ended mode for configuration 1 */
#define  SDADC_CONF1R_SE1_MASK			(3 << 26)
/* SE1_0 : Single ended mode for configuration 1 Bit 0 */
#define  SDADC_CONF1R_SE1_0				(1 << 26)
/* SE1_1 : Single ended mode for configuration 1 Bit 1 */
#define  SDADC_CONF1R_SE1_1				(1 << 27)
/* COMMON1 : Common mode for configuration 1 */
#define  SDADC_CONF1R_COMMON1_MASK		(3 << 30)
/* COMMON1_0 : Common mode for configuration 1 Bit 0 */
#define  SDADC_CONF1R_COMMON1_0			(1 << 30)
/* COMMON1_1 : Common mode for configuration 1 Bit 1 */
#define  SDADC_CONF1R_COMMON1_1			(1 << 31)

/* --- SDADC_CONF2R values ------------------------------------------------- */

/* OFFSET2 : 12-bit calibration offset for configuration 2 */
#define  SDADC_CONF2R_OFFSET2_MASK		(0xFFF << 0)
/* GAIN2 : Gain setting for configuration 2 */
#define  SDADC_CONF2R_GAIN2_MASK		(7 << 20)
/* GAIN2_0 : Gain setting for configuration 2 Bit 0*/
#define  SDADC_CONF2R_GAIN2_0			(1 << 20)
/* GAIN2_1 : Gain setting for configuration 2 Bit 1 */
#define  SDADC_CONF2R_GAIN2_1			(1 << 21)
/* GAIN2_2 : Gain setting for configuration 2 Bit 2 */
#define  SDADC_CONF2R_GAIN2_2			(1 << 22)
/* SE2 : Single ended mode for configuration 2 */
#define  SDADC_CONF2R_SE2_MASK			(3 << 26)
/* SE2_0 : Single ended mode for configuration 2 Bit 0 */
#define  SDADC_CONF2R_SE2_0				(1 << 26)
/* SE2_1 : Single ended mode for configuration 2 Bit 1 */
#define  SDADC_CONF2R_SE2_1				(1 << 27)
/* COMMON2 : Common mode for configuration 2 */
#define  SDADC_CONF2R_COMMON2_MASK		(3 << 30)
/* COMMON2_0 : Common mode for configuration 2 Bit 0 */
#define  SDADC_CONF2R_COMMON2_0			(1 << 30)
/* COMMON2_1 : Common mode for configuration 2 Bit 1 */
#define  SDADC_CONF2R_COMMON2_1			(1 << 31)

/* --- SDADC_CONFCHR1 values ----------------------------------------------- */

/* CONFCH0 : Channel 0 configuration */
#define  SDADC_CONFCHR1_CONFCH0_MASK	(3 << 0)
/* CONFCH1 : Channel 1 configuration */
#define  SDADC_CONFCHR1_CONFCH1_MASK	(3 << 4)
/* CONFCH2 : Channel 2 configuration */
#define  SDADC_CONFCHR1_CONFCH2_MASK	(3 << 8)
/* CONFCH3 : Channel 3 configuration */
#define  SDADC_CONFCHR1_CONFCH3_MASK	(3 << 12)
/* CONFCH4 : Channel 4 configuration */
#define  SDADC_CONFCHR1_CONFCH4_MASK	(3 << 16)
/* CONFCH5 : Channel 5 configuration */
#define  SDADC_CONFCHR1_CONFCH5_MASK	(3 << 20)
/* CONFCH6 : Channel 6 configuration */
#define  SDADC_CONFCHR1_CONFCH6_MASK	(3 << 24)
/* CONFCH7 : Channel 7 configuration */
#define  SDADC_CONFCHR1_CONFCH7_MASK	(3 << 28)

/* --- SDADC_CONFCHR2 values ----------------------------------------------- */

/* CONFCH8 : Channel 8 configuration */
#define  SDADC_CONFCHR2_CONFCH8			(3 << 0)

/* --- SDADC_JDATAR values ------------------------------------------------- */

/* JDATA : Injected group conversion data */
#define  SDADC_JDATAR_JDATA_MASK	(0xFFFF << 0)
/* JDATACH : Injected channel most recently converted */
#define  SDADC_JDATAR_JDATACH_MASK	(0xF << 25)
/* JDATACH_0 : Injected channel most recently converted bit 0 */
#define  SDADC_JDATAR_JDATACH_0		(1 << 25)
/* JDATACH_1 : Injected channel most recently converted bit 1 */
#define  SDADC_JDATAR_JDATACH_1		(1 << 26)
/* JDATACH_2 : Injected channel most recently converted bit 2 */
#define  SDADC_JDATAR_JDATACH_2		(1 << 27)
/* JDATACH_3 : Injected channel most recently converted bit 3 */
#define  SDADC_JDATAR_JDATACH_3		(1 << 28)

/* --- SDADC_RDATAR values ------------------------------------------------- */

/* RDATA : Injected group conversion data */
#define  SDADC_RDATAR_RDATA		(0xFFFF << 0)

/* --- SDADC_JDATA12R values ----------------------------------------------- */

/* JDATA1 : Injected group conversion data for SDADC2 */
#define  SDADC_JDATA12R_JDATA2	(0xFFFF0000 << 0)
/* JDATA2 : Injected group conversion data for SDADC1 */
#define  SDADC_JDATA12R_JDATA1	(0x0000FFFF << 0)

/* --- SDADC_RDATA12R values ----------------------------------------------- */

/* RDATA2 : Regular conversion data for SDADC2 */
#define  SDADC_RDATA12R_RDATA2	(0xFFFF0000 << 0)
/* RDATA1 : Regular conversion data for SDADC1 */
#define  SDADC_RDATA12R_RDATA1	(0x0000FFFF << 0)

/* --- SDADC_JDATA13R values ----------------------------------------------- */

/* JDATA3 : Injected group conversion data for SDADC3 */
#define  SDADC_JDATA13R_JDATA3	(0xFFFF0000 << 0)
/* JDATA1 : Injected group conversion data for SDADC1 */
#define  SDADC_JDATA13R_JDATA1	(0x0000FFFF << 0)

/* --- SDADC_RDATA13R values ----------------------------------------------- */

/* RDATA3 : Regular conversion data for SDADC3 */
#define  SDADC_RDATA13R_RDATA3	(0xFFFF0000 << 0)
/* RDATA1 : Regular conversion data for SDADC1 */
#define  SDADC_RDATA13R_RDATA1	(0x0000FFFF << 0)

/* --- Convenience defines ------------------------------------------------- */

/* The reference voltage is forced externally using VREF pin */
#define SDADC_VREF_EXT			0
/* The reference voltage is forced internally to 1.22V VREFINT */
#define SDADC_VREF_INT_1_22V	(SDADC_CR1_REFV_0)
/* The reference voltage is forced internally to 1.8V VREFINT */
#define SDADC_VREF_INT_1_8V		(SDADC_CR1_REFV_1)
/* The reference voltage is forced internally to VDDA */
#define SDADC_VREF_INT_VDD		(SDADC_CR1_REFV_0 | SDADC_CR1_REFV_1)

/* Gain equal to 1 */
#define SDADC_GAIN_1		0
/* Gain equal to 2 */
#define SDADC_GAIN_2		SDADC_CONF0R_GAIN0_0
 /* Gain equal to 4 */
#define SDADC_GAIN_4		SDADC_CONF0R_GAIN0_1
/* Gain equal to 8 */
#define SDADC_GAIN_8		(SDADC_CONF0R_GAIN0_1 | SDADC_CONF0R_GAIN0_0)
/* Gain equal to 16 */
#define SDADC_GAIN_16		SDADC_CONF0R_GAIN0_2
 /* Gain equal to 32 */ 
#define SDADC_GAIN_32		(SDADC_CONF0R_GAIN0_2 | SDADC_CONF0R_GAIN0_0)
/* Gain equal to 1/2 */
#define SDADC_GAIN_1_2		(SDADC_CONF0R_GAIN0_2 | SDADC_CONF0R_GAIN0_1 | SDADC_CONF0R_GAIN0_0)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void sdadc_enable(u32 sdadc);
void sdadc_disable(u32 sdadc);

END_DECLS

















