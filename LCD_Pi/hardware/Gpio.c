#include <wiringPi.h>
#include "Gpio.h"

#define PIN_CE	0
#define PIN_DC	2
#define PIN_REST	3
#define PIN_SCK		25
#define PIN_MOSI	7

int Gpio_init(void)
{
	wiringPiSetup();
	return 0;
}

int Gpio_REST_Output(unsigned char lev)
{
	pinMode(PIN_REST,OUTPUT);
	if(lev&0x01)
	{
		digitalWrite(PIN_REST, HIGH);
	}else
	{
		digitalWrite(PIN_REST, LOW);
	}	
	return 0;
}

int Gpio_CE_Output(unsigned char lev)
{
	pinMode(PIN_CE,OUTPUT);
	if(lev&0x01)
	{
		digitalWrite(PIN_CE, HIGH);
	}else
	{
		digitalWrite(PIN_CE, LOW);
	}	
	return 0;
}

int Gpio_DC_Output(unsigned char lev)
{
	pinMode(PIN_DC,OUTPUT);
	if(lev&0x01)
	{
		digitalWrite(PIN_DC, HIGH);
	}else
	{
		digitalWrite(PIN_DC, LOW);
	}	
	return 0;
}

int Gpio_SCK_Output(unsigned char lev)
{
	pinMode(PIN_SCK,OUTPUT);
	if(lev&0x01)
	{
		digitalWrite(PIN_SCK, HIGH);
	}else
	{
		digitalWrite(PIN_SCK, LOW);
	}	
	return 0;
}

int Gpio_MOSI_Output(unsigned char lev)
{
	pinMode(PIN_MOSI,OUTPUT);
	if(lev&0x01)
	{
		digitalWrite(PIN_MOSI, HIGH);
	}else
	{
		digitalWrite(PIN_MOSI, LOW);
	}	
	return 0;
}

int Delay(int ms)
{
	delay(ms);
	return 0;
}


int Delay_us(int us)
{
	delayMicroseconds(us);
	return 0;
}




