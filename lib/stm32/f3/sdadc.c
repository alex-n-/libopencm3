
#include <libopencm3/stm32/f3/sdadc.h>

void sdadc_enable(u32 sdadc)
{
	SDADC_CR2(sdadc) |= SDADC_CR2_ADON;
}

void sdadc_disable(u32 sdadc)
{
	SDADC_CR2(sdadc) &= ~SDADC_CR2_ADON;
}
