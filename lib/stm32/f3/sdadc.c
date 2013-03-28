
#include <libopencm3/stm32/f3/sdadc.h>

void sdadc_on(u32 sdadc)
{
	SDADC_CR2(sdadc) |= SDADC_CR2_ADON;
}

void sdadc_off(u32 sdadc)
{
	SDADC_CR2(sdadc) &= ~SDADC_CR2_ADON;
}

void sdadc_init_enable(u32 sdadc)
{
	SDADC_CR1(sdadc) |= SDADC_CR1_INIT;
}

void sdadc_init_disable(u32 sdadc)
{
	SDADC_CR1(sdadc) &= ~SDADC_CR1_INIT;
}

u32 sdadc_get_init_flag(u32 sdadc)
{
	return(SDADC_ISR(sdadc) & SDADC_ISR_INITRDY);
}

u32 sdadc_get_calib_flag(u32 sdadc)
{
	return(SDADC_ISR(sdadc) & SDADC_ISR_EOCALF);
}

/* The reference voltage is common to the all SDADCs (SDADC1, SDADC2 and SDADC3). */
void sdadc_set_vref(u32 sdadc, u32 vref)
{
	u32 reg32;
	
	reg32 = SDADC_CR1(sdadc);
	reg32 &= ~SDADC_CR1_REFV_MASK; /* clear bits */
	reg32 |= vref;
	SDADC_CR1(sdadc) = reg32;
}

void sdadc_start_conversion_regular(u32 sdadc)
{
	SDADC_CR2(sdadc) |= SDADC_CR2_RSWSTART;
}

s16 sdadc_read_regular(u32 sdadc)
{
	return (s16)SDADC_RDATAR(sdadc);
}

void sdadc_regular_channel_select(u32 sdadc, u32 sdadc_channel)
{
	u32 reg32;
	
	reg32 = SDADC_CR2(sdadc);
	reg32 &= ~SDADC_CR2_RCH_MASK; /* clear bits */
	reg32 |= (sdadc_channel << SDADC_CR2_RCH_SHIFT);
	SDADC_CR2(sdadc) = reg32;
}

void sdadc_injected_sequence(u32 sdadc, u32 sdadc_channel_sequence)
{
	SDADC_JCHGR(sdadc) = sdadc_channel_sequence;
}

void sdadc_set_channel_config(u32 sdadc, u32 sdadc_channel, u32 sdadc_config)
{
	u32 reg32;
	u32 sdadc_channel_shift;
	
	if(sdadc_channel != 8)
	{
		sdadc_channel_shift = sdadc_channel * 4;
		reg32 = SDADC_CONFCHR1(sdadc);
		reg32 &= ~(3 << sdadc_channel_shift); /* clear bits */
		SDADC_CONFCHR1(sdadc) |= (sdadc_config << sdadc_channel_shift);
	}
	else
	{
		reg32 &= ~SDADC_CONFCHR2_CONFCH8; /* clear bits */
		SDADC_CONFCHR2(sdadc) |=  sdadc_config;
	}
}

void sdadc_start_calibration(u32 sdadc)
{
	SDADC_CR2(sdadc) |= SDADC_CR2_STARTCALIB;
}
