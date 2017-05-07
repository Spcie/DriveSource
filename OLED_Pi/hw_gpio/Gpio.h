#ifndef __GPIO_H
#define __GPIO_H

int Gpio_init(void);
int SDA_OUT(unsigned char lev);
unsigned char SDA_IN(void);
int SCL_OUT(unsigned char lev);
int Delay(int ms);
int Delay_us(int us);
#endif 
