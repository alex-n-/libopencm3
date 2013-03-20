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
