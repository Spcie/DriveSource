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
	IIC_Funation.SCL(0);//ǯסI2C���ߣ�׼�����ͻ�������� 
}	  
void IIC_Stop(void)
{
	IIC_Funation.SCL(0);
	IIC_Funation.SDA_w(0);
	IIC_Funation.Delay_us(4);
	IIC_Funation.SCL(1);
	IIC_Funation.SDA_w(1);//����I2C���߽����ź�
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
//������ACKӦ��		    
void IIC_NAck(void)
{
	IIC_Funation.SCL(0);
	IIC_Funation.SDA_w(1);
	IIC_Funation.Delay_us(2);
	IIC_Funation.SCL(1);
	IIC_Funation.Delay_us(2);
	IIC_Funation.SCL(0);
}

//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void IIC_Send_Byte(unsigned char txd)
{
	unsigned char t;
	IIC_Funation.SCL(0);//����ʱ�ӿ�ʼ���ݴ���
	for (t = 0; t<8; t++)
	{
		IIC_Funation.SDA_w((txd & 0x80) >> 7);
		txd <<= 1;
		IIC_Funation.Delay_us(2);   //��TEA5767��������ʱ���Ǳ����
		IIC_Funation.SCL(1);
		IIC_Funation.Delay_us(2);
		IIC_Funation.SCL(0);
		IIC_Funation.Delay_us(2);
	}
}
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
unsigned char IIC_Read_Byte(unsigned char ack)
{
	unsigned char i, receive = 0;
	SDA_IN();//SDA����Ϊ����
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
		IIC_NAck();//����nACK
	else
		IIC_Ack(); //����ACK   
	return receive;
}