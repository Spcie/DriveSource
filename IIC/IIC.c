#include "IIC.h"


IIC_FunationDef IIC_Funation;

void IIC_Init(IIC_FunationDef IIC_FunationList)
{
	IIC_Funation.SCL = IIC_FunationList.SCL;
	IIC_Funation.SDA_w = IIC_FunationList.SDA_w;
	IIC_Funation.SDA_r = IIC_FunationList.SDA_r;
	IIC_Funation.Delay_us = IIC_FunationList.Delay_us;
}

void IIC_Start(void)
{
	IIC_Funation.SDA_w(1);
	IIC_Funation.SCL(1);
	IIC_Funation.Delay_us(4);
	IIC_Funation.SDA_w(0);//START:when CLK is high,DATA change form high to low 
	IIC_Funation.Delay_us(4);
	IIC_Funation.SCL(0);//钳住I2C总线，准备发送或接收数据 
}	  
void IIC_Stop(void)
{
	IIC_Funation.SCL(0);
	IIC_Funation.SDA_w(0);
	IIC_Funation.Delay_us(4);
	IIC_Funation.SCL(1);
	IIC_Funation.SDA_w(1);//发送I2C总线结束信号
	IIC_Funation.Delay_us(4);
}
unsigned char IIC_Wait_Ack(void)
{
	unsigned char ucErrTime = 0; 

	IIC_Funation.SDA_w(1);
	IIC_Funation.Delay_us(1);
	IIC_Funation.SCL(1);
	IIC_Funation.Delay_us(1);

	while (IIC_Funation.SDA_r())
	{
		ucErrTime++;
		if (ucErrTime>250)
		{
			IIC_Stop();
			return 1;
		}
	}
	IIC_Funation.SCL(0);
	return 0;
}
void IIC_Ack(void)
{
	IIC_Funation.SCL(0);
	IIC_Funation.SDA_w(0);
	IIC_Funation.Delay_us(2);
	IIC_Funation.SCL(1);
	IIC_Funation.Delay_us(2);
	IIC_Funation.SCL(0);
}
//不产生ACK应答		    
void IIC_NAck(void)
{
	IIC_Funation.SCL(0);
	IIC_Funation.SDA_w(1);
	IIC_Funation.Delay_us(2);
	IIC_Funation.SCL(1);
	IIC_Funation.Delay_us(2);
	IIC_Funation.SCL(0);
}

//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答			  
void IIC_Send_Byte(unsigned char txd)
{
	unsigned char t;
	IIC_Funation.SCL(0);//拉低时钟开始数据传输
	for (t = 0; t<8; t++)
	{
		IIC_Funation.SDA_w((txd & 0x80) >> 7);
		txd <<= 1;
		IIC_Funation.Delay_us(2);   //对TEA5767这三个延时都是必须的
		IIC_Funation.SCL(1);
		IIC_Funation.Delay_us(2);
		IIC_Funation.SCL(0);
		IIC_Funation.Delay_us(2);
	}
}
//读1个字节，ack=1时，发送ACK，ack=0，发送nACK   
unsigned char IIC_Read_Byte(unsigned char ack)
{
	unsigned char i, receive = 0;
	SDA_IN();//SDA设置为输入
	for (i = 0; i<8; i++)
	{
		IIC_Funation.SCL(0);
		IIC_Funation.Delay_us(2);
		IIC_Funation.SCL(1);
		receive <<= 1;
		if (IIC_Funation.SDA_r()) receive++;
		IIC_Funation.Delay_us(1);
	}
	if (!ack)
		IIC_NAck();//发送nACK
	else
		IIC_Ack(); //发送ACK   
	return receive;
}