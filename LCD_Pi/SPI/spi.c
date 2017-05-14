#include "Gpio.h"

void SPI_Init(void)
{
	Gpio_init();
}

void SPI_CE_Set(unsigned char ce)
{
	Gpio_CE_Output(ce);
}

void SPI_DC_Set(unsigned char dc)
{
	Gpio_DC_Output(dc);
}

void SPI_Pin_Rest(unsigned char rest)
{
	Gpio_REST_Output(rest);
}

void SPI_WirteBus(unsigned char byte)
{
	int i;
	for(i=0;i<8;i++)
	{
		if(byte&0x80)
		{
			Gpio_MOSI_Output(1);
		}
		else
		{
			Gpio_MOSI_Output(0);
		}

		Gpio_SCK_Output(0);
		byte = byte << 1;
		Gpio_SCK_Output(1);
	}
}

void SPI_Delay(int ms)
{
	Delay(ms);
}

void SPI_Delay_us(int us)
{
	Delay_us(us);
}

