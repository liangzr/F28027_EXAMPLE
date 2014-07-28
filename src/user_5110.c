// TI File $Revision: /main/1 $
// Checkin $Date: August 14, 2008   16:58:46 $
//###########################################################################
//
// FILE:    user_5110.c
//
// TITLE:    DSP2802x SCI Initialization & Support Functions.
//
//###########################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//###########################################################################

#include "F2802x_Device.h"     // Headerfile Include File
#include "F2802x_Examples.h"   // Examples Include File


void LCD_init(void)
{
    //SETBIT(LCD_DIR,LCD_RST);

    // 产生一个让LCD复位的低电平脉冲
	LCD_RST_H;
	LCD_RST_L;
	LCD_RST_H;
	//CLEARBIT(LCD_PORT,LCD_RST);//LCD_RST = 0;
    //delay_1us();
	//SETBIT(LCD_PORT,LCD_RST);//LCD_RST = 1;

	// 关闭LCD
	LCD_CE_L;

	// 使能LCD
	LCD_CE_H;

    LCD_write_byte(0x21, 0);	// 使用扩展命令设置LCD模式
    LCD_write_byte(0xc8, 0);	// 设置偏置电压
    LCD_write_byte(0x06, 0);	// 温度校正
    LCD_write_byte(0x13, 0);	// 1:48
    LCD_write_byte(0x20, 0);	// 使用基本命令
    LCD_clear();	            // 清屏
    LCD_write_byte(0x0c, 0);	// 设定显示模式，正常显示


    LCD_CE_L;

}
/********************************************************************************************************************/
void LCD_clear(void)
{
    unsigned int i;

    LCD_write_byte(0x0c, 0);
    LCD_write_byte(0x80, 0);

    for (i=0; i<504; i++)
	{
        LCD_write_byte(0, 1);
	}
}

/********************************************************************************************************************/
void LCD_set_XY(unsigned char X, unsigned char Y)
{
    LCD_write_byte(0x40 | Y, 0);// column
    LCD_write_byte(0x80 | X, 0);// row
}
/********************************************************************************************************************/
void LCD_char(unsigned char c)
{
	unsigned char line;

    c -= 32;
    for (line=0; line<6; line++)
	{
        LCD_write_byte(font6x8[c][line], 1);
	}
}
/********************************************************************************************************************/
/*-----------------------------------------------------------------------
LCD_write_english_String  : 英文字符串显示函数

输入参数：*s      ：英文字符串指针；
          X、Y    : 显示字符串的位置,x 0-83 ,y 0-5
-----------------------------------------------------------------------*/
void LCD_string(unsigned char X,unsigned char Y,unsigned char *s)
{
    LCD_set_XY(X,Y);
    while (*s)
    {
    	LCD_char(*s);
	    s++;
    }
}
void LCD_string2(unsigned char *s)
{

    while (*s)
    {
    	LCD_char(*s);
	    s++;
    }
}
/*
void LCD_int(unsigned char X,unsigned char Y, float data)
{
    unsigned char str[10];
    sprintf (str, "__%5.3d__/", data);
    LCD_string(X, Y, str);
}

*******************************************************************************************************************/
/*-----------------------------------------------------------------------
LCD_write_chinese_string: 在LCD上显示汉字

输入参数：X、Y    ：显示汉字的起始X、Y坐标；
          ch_with ：汉字点阵的宽度
          num     ：显示汉字的个数；
          line    ：汉字点阵数组中的起始行数
          row     ：汉字显示的行间距
-----------------------------------------------------------------------*/
void LCD_write_chinese_string(unsigned char X, unsigned char Y,unsigned char ch_with,unsigned char num,unsigned char line,unsigned char row)
{
    unsigned char i,n;

    LCD_set_XY(X,Y);                             //设置初始位置

    for (i=0;i<num;)
    {
      	for (n=0; n<ch_with*2; n++)              //写一个汉字
      	{
      	    if (n==ch_with)                      //写汉字的下半部分
      	    {
      	        if (i==0) LCD_set_XY(X,Y+1);
      	        else
				{
      	           LCD_set_XY((X+(ch_with+row)*i),Y+1);
				}
            }
      	    LCD_write_byte(HZK[line+i][n],1);
      	}
      	i++;
      	LCD_set_XY((X+(ch_with+row)*i),Y);
    }
}
/********************************************************************************************************************/
/*-----------------------------------------------------------------------
LCD_draw_map      : 位图绘制函数

输入参数：X、Y    ：位图绘制的起始X、Y坐标；
          *map    ：位图点阵数据；
          Pix_x   ：位图像素（长）
          Pix_y   ：位图像素（宽）
-----------------------------------------------------------------------*/
void LCD_draw_bmp_pixel(unsigned char X,unsigned char Y,unsigned char *map,unsigned char Pix_x,unsigned char Pix_y)
{
    unsigned int i,n;
    unsigned char row;

    if (Pix_y%8==0)
	{
	    row=Pix_y/8;      //计算位图所占行数
    }
    else
	{
        row=Pix_y/8+1;
    }
    for (n=0;n<row;n++)
    {
      	LCD_set_XY(X,Y);
        for(i=0; i<Pix_x; i++)
          {
            LCD_write_byte(map[i+n*Pix_x], 1);
          }
        Y++;                         //换行
    }
}
/********************************************************************************************************************/
/*-----------------------------------------------------------------------
LCD_write_byte    : 写数据到LCD

输入参数：data    ：写入的数据；
          command ：写数据/命令选择；
----------------------------------------------------------------------
void LCD_write_byte(unsigned char dat, unsigned char command)
{

    if (command == 0)
	{
	    LCD_DC_L;
	}
    else
	{
    	LCD_DC_H;
	}
    SpiaRegs.SPITXBUF = dat;
}-*/
/*-----------------------------------------------------------------------
LCD_write_byte    : 写数据到LCD

输入参数：data    ：写入的数据；
          command ：写数据/命令选择；
-----------------------------------------------------------------------*/
void LCD_write_byte(unsigned char dat, unsigned char command)
{
    unsigned char i;

	LCD_CE_L;

    if (command == 0)
	{
	    LCD_DC_L;
	}
    else
	{
	    LCD_DC_H;
	}

	for(i=0;i<8;i++)
	{
		if(dat&0x80)
		{
			LCD_SDIN_H;//SDIN = 1;
		}
		else
		{
			LCD_SDIN_L;//SDIN = 0;
		}
		LCD_SCLK_L;//SCLK = 0;
		dat = dat << 1;
		LCD_SCLK_H;//SCLK = 1;
	}
 //   SpiaRegs.SPITXBUF = dat;

    LCD_CE_H;//LCD_CE = 1;
}

