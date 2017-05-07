#include "IIC.h"
#include "Gpio.h"

static int IIC_GpioInit(void);
static int IIC_SDA_Output(unsigned char lev);
static int IIC_SCL_Output(unsigned char lev);
static unsigned char IIC_SDA_Input(void);
static int IIC_Delay(int ms);
static int IIC_Delay_us(int us);

static int IIC_GpioInit(void)
{
	return Gpio_init();
}
static int IIC_SDA_Output(unsigned char lev)
{
	return SDA_OUT(lev); 
}

static int IIC_SCL_Output(unsigned char lev)
{
	return SCL_OUT(lev);
}

static unsigned char IIC_SDA_Input(void)
{
	return	SDA_IN();
}
static int IIC_Delay(int ms)
{
	return Delay(ms);
}

static int IIC_Delay_us(int us)
{
	return Delay_us(us);
}



void IIC_Init(void)
{
	IIC_GpioInit();
}

void IIC_Start(void)
{
	IIC_SCL_Output(1);
	IIC_SDA_Output(1);
	IIC_Delay_us(4);
	IIC_SDA_Output(0); 
	IIC_Delay_us(4);
	IIC_SCL_Output(0);
}
	  
void IIC_Stop(void)
{
	IIC_SCL_Output(0);
	IIC_SDA_Output(0);
	IIC_Delay_us(4);
	IIC_SCL_Output(1);
	IIC_SDA_Output(1);
	IIC_Delay_us(4);
}

unsigned char IIC_Wait_Ack(void)
{
	unsigned char ucErrTime = 0;

	IIC_SDA_Output(1);
	IIC_Delay_us(1);
	IIC_SCL_Output(1);
	IIC_Delay_us(1);

	while (IIC_SDA_Input())
	{
		ucErrTime++;
		if (ucErrTime>250)
		{
			IIC_Stop();
			return 1;
		}
	}
	IIC_SCL_Output(0);
	return 0;
}
void IIC_Ack(void)
{
	IIC_SCL_Output(0);
	IIC_SDA_Output(0);
	IIC_Delay_us(2);
	IIC_SCL_Output(1);
	IIC_Delay_us(2);
	IIC_SCL_Output(0);
}
  
void IIC_NAck(void)
{
	IIC_SCL_Output(0);
	IIC_SDA_Output(1);
	IIC_Delay_us(2);
	IIC_SCL_Output(1);
	IIC_Delay_us(2);
	IIC_SCL_Output(0);
}

void IIC_Send_Byte(unsigned char txd)
{
	unsigned char t;
	IIC_SCL_Output(0);//拉低时钟开始数据传输
	for (t = 0; t<8; t++)
	{
		IIC_SDA_Output((txd & 0x80) >> 7);
		txd <<= 1;
		IIC_Delay_us(2);   //对TEA5767这三个延时都是必须的
		IIC_SCL_Output(1);
		IIC_Delay_us(2);
		IIC_SCL_Output(0);
		IIC_Delay_us(2);
	}
	IIC_SDA_Output(1);
	IIC_SCL_Output(1);
	IIC_SCL_Output(0);

}

unsigned char IIC_Read_Byte(unsigned char ack)
{
	unsigned char i, receive = 0;

	for (i = 0; i<8; i++)
	{
		IIC_SCL_Output(0);
		IIC_Delay_us(2);
		IIC_SCL_Output(1);
		receive <<= 1;
		if (IIC_SDA_Input()) receive++;
		IIC_Delay_us(1);
	}
	if (!ack)
		IIC_NAck();//发送nACK
	else
		IIC_Ack(); //发送ACK   
	return receive;
}
