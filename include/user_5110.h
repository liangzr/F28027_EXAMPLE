// TI File $Revision: /main/3 $
// Checkin $Date: October 6, 2010   15:08:36 $
//###########################################################################
//
// FILE:   user_5110.h
//
// TITLE:  DSP2802x Inter-Integrated Circuit (I2C) Module
//         Register Bit Definitions.
//
//###########################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//###########################################################################

#ifndef	USER_5110_H
#define USER_5110_H

#define LCD_RST_H	GpioDataRegs.GPASET.bit.GPIO3 	= 1;
#define LCD_RST_L	GpioDataRegs.GPACLEAR.bit.GPIO3 = 1;
#define LCD_CE_H    GpioDataRegs.GPASET.bit.GPIO4   = 1;
#define LCD_CE_L    GpioDataRegs.GPACLEAR.bit.GPIO4 = 1;
#define	LCD_DC_H    GpioDataRegs.GPASET.bit.GPIO5  	= 1;
#define LCD_DC_L    GpioDataRegs.GPACLEAR.bit.GPIO5 = 1;
#define LCD_SDIN_H  GpioDataRegs.GPASET.bit.GPIO6   = 1;
#define LCD_SDIN_L  GpioDataRegs.GPACLEAR.bit.GPIO6 = 1;
#define LCD_SCLK_H  GpioDataRegs.GPASET.bit.GPIO7  	= 1;
#define LCD_SCLK_L  GpioDataRegs.GPACLEAR.bit.GPIO7 = 1;

void LCD_init(void);
void LCD_clear(void);
void LCD_set_XY(unsigned char x,unsigned char y);
void LCD_char(unsigned char c);
void LCD_string(unsigned char X,unsigned char Y,unsigned char *s);
void LCD_string2(unsigned char *s);
void LCD_write_chinese_string(unsigned char X, unsigned char Y,unsigned char ch_with,unsigned char num,unsigned char line,unsigned char row);
//void LCD_draw_bmp_pixel(unsigned char X,unsigned char Y,unsigned char *map,unsigned char Pix_x,unsigned char Pix_y);
void LCD_write_byte(unsigned char dat, unsigned char command);

// 6 x 8 font
// 1 pixel space at left and bottom
// index = ASCII - 32
extern const unsigned char font6x8[][6];
extern const unsigned char HZK[][24];
extern unsigned char AVR_bmp[];


#endif	//USER_5110_H
