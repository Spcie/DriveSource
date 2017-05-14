#include "stdio.h"
#include "lcd.h"
#include "font.h"


int main(void)
{
	LCD_Init();
	
	LCD_Clear(0xFFFF);
	LCD_SetPointColor(0x0000);
	LCD_DrawRectangle(2,4,8,10,0x0000);
	LCD_DrawLine(0,0,100,100,0x0000);
	LCD_ShowChar(20,20,0,12,1);
	LCD_ShowString(40,40,100,100,16,"hello world");
	number(100,100,10);
	return 0;
}