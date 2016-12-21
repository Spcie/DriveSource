#ifndef __IIC_H
#define __IIC_H

typedef void(*IIC_Delay)(unsigned char);
typedef void (*IIC_Pin_Funa_Set)(unsigned char);
typedef unsigned char (*IIC_Pin_Funa_Read)(void);

typedef struct IIC_FunationDef
{
	IIC_Pin_Funa_Set SCL;
	IIC_Pin_Funa_Set SDA_w;
	IIC_Pin_Funa_Read SDA_r;
	IIC_Delay Delay_us;
}IIC_FunationDef;

#endif