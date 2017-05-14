#ifndef __GPIO_H
#define __GPIO_H

int Gpio_init(void);
int Gpio_REST_Output(unsigned char lev);
int Gpio_CE_Output(unsigned char lev);
int Gpio_DC_Output(unsigned char lev);
int Gpio_SCK_Output(unsigned char lev);
int Gpio_MOSI_Output(unsigned char lev);
int Delay(int ms);
int Delay_us(int us);

#endif 
