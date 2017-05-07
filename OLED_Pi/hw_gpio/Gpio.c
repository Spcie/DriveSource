#include <wiringPi.h>
#include "Gpio.h"

#define PIN_1	2		//SCL
#define PIN_2	0		//SDA


int Gpio_init(void)
{
	wiringPiSetup();
	return 0;
}

int SDA_OUT(unsigned char lev)
{
	pinMode(PIN_2,OUTPUT);
	if(lev&0x01)
	{
		digitalWrite(PIN_2, HIGH);
	}else
	{
		digitalWrite(PIN_2, LOW);
	}	
	return 0;	
}

unsigned char SDA_IN(void)
{
	return 0;
}

int SCL_OUT(unsigned char lev)
{
	pinMode(PIN_1,OUTPUT);
	if(lev&0x01)
	{
		digitalWrite(PIN_1, HIGH);
	}else
	{
		digitalWrite(PIN_1, LOW);
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




