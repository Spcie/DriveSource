#ifndef __SPI_H
#define __SPI_H

#define SPI_MOD_COMMAND	(0x00)
#define SPI_MOD_DATA	(0x01)

void SPI_Init(void);
void SPI_CE_Set(unsigned char ce);
void SPI_DC_Set(unsigned char dc);
void SPI_Pin_Rest(unsigned char rest);
void SPI_WirteBus(unsigned char byte);
void SPI_Delay(int ms);
void SPI_Delay_us(int us);

#endif