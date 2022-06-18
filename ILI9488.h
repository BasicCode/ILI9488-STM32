/*
 * Driver for the ILI9488 Micro written for STM32L micros
 *
 * File:   ILI9488.h
 * Author: tommy
 *
 * Created on 15th May 2022
 */

#ifndef ILI9488_H
#define	ILI9488_H

//Set up any ports in your main.c file.
#include "main.h"

#define SPI_MODE 1 //Set mode 1 for serial / SPI mode, or 0 for parallel mode.
extern SPI_HandleTypeDef hspi2;

//Hard-coded dimensions of the display
#define WIDTH 480 //480
#define HEIGHT 320 //320
#define LANDSCAPE   1 //Portrait or Landscape orientation. Update WIDTH and HEIGHT above.

//ILI9488 registers found at
//https://github.com/jaretburkett/ILI9488/blob/master/ILI9488.cpp
//Thanks!
#define ILI9488_NOP     0x00
#define ILI9488_SWRESET 0x01
#define ILI9488_RDDID   0x04
#define ILI9488_RDDST   0x09

#define ILI9488_SLPIN   0x10
#define ILI9488_SLPOUT  0x11
#define ILI9488_PTLON   0x12
#define ILI9488_NORON   0x13

#define ILI9488_RDMODE  0x0A
#define ILI9488_RDMADCTL  0x0B
#define ILI9488_RDPIXFMT  0x0C
#define ILI9488_RDIMGFMT  0x0D
#define ILI9488_RDSELFDIAG  0x0F

#define ILI9488_INVOFF  0x20
#define ILI9488_INVON   0x21
#define ILI9488_GAMMASET 0x26
#define ILI9488_DISPOFF 0x28
#define ILI9488_DISPON  0x29

#define ILI9488_CASET   0x2A
#define ILI9488_PASET   0x2B
#define ILI9488_RAMWR   0x2C
#define ILI9488_RAMRD   0x2E

#define ILI9488_PTLAR   0x30
#define ILI9488_MADCTL  0x36
#define ILI9488_PIXFMT  0x3A

#define ILI9488_FRMCTR1 0xB1
#define ILI9488_FRMCTR2 0xB2
#define ILI9488_FRMCTR3 0xB3
#define ILI9488_INVCTR  0xB4
#define ILI9488_DFUNCTR 0xB6

#define ILI9488_PWCTR1  0xC0
#define ILI9488_PWCTR2  0xC1
#define ILI9488_PWCTR3  0xC2
#define ILI9488_PWCTR4  0xC3
#define ILI9488_PWCTR5  0xC4
#define ILI9488_VMCTR1  0xC5
#define ILI9488_VMCTR2  0xC7

#define ILI9488_RDID1   0xDA
#define ILI9488_RDID2   0xDB
#define ILI9488_RDID3   0xDC
#define ILI9488_RDID4   0xDD

#define ILI9488_GMCTRP1 0xE0
#define ILI9488_GMCTRN1 0xE1

/* RGB 16-bit color table definition (RG565) */
#define COLOR_BLACK          0x0000      /*   0,   0,   0 */
#define COLOR_WHITE          0xFFFF      /* 255, 255, 255 */
#define COLOR_BLUE           0x001F      /*   0,   0, 255 */
#define COLOR_GREEN          0x07E0      /*   0, 255,   0 */
#define COLOR_RED            0xF800      /* 255,   0,   0 */
#define COLOR_NAVY           0x000F      /*   0,   0, 128 */
#define COLOR_DARKBLUE       0x0011      /*   0,   0, 139 */
#define COLOR_DARKGREEN      0x03E0      /*   0, 128,   0 */
#define COLOR_DARKCYAN       0x03EF      /*   0, 128, 128 */
#define COLOR_CYAN           0x07FF      /*   0, 255, 255 */
#define COLOR_TURQUOISE      0x471A      /*  64, 224, 208 */
#define COLOR_INDIGO         0x4810      /*  75,   0, 130 */
#define COLOR_DARKRED        0x8000      /* 128,   0,   0 */
#define COLOR_OLIVE          0x7BE0      /* 128, 128,   0 */
#define COLOR_GRAY           0x8410      /* 128, 128, 128 */
#define COLOR_GREY           0x8410      /* 128, 128, 128 */
#define COLOR_SKYBLUE        0x867D      /* 135, 206, 235 */
#define COLOR_BLUEVIOLET     0x895C      /* 138,  43, 226 */
#define COLOR_LIGHTGREEN     0x9772      /* 144, 238, 144 */
#define COLOR_DARKVIOLET     0x901A      /* 148,   0, 211 */
#define COLOR_YELLOWGREEN    0x9E66      /* 154, 205,  50 */
#define COLOR_BROWN          0xA145      /* 165,  42,  42 */
#define COLOR_DARKGRAY       0x7BEF      /* 128, 128, 128 */
#define COLOR_DARKGREY       0x7BEF      /* 128, 128, 128 */
#define COLOR_SIENNA         0xA285      /* 160,  82,  45 */
#define COLOR_LIGHTBLUE      0xAEDC      /* 172, 216, 230 */
#define COLOR_GREENYELLOW    0xAFE5      /* 173, 255,  47 */
#define COLOR_SILVER         0xC618      /* 192, 192, 192 */
#define COLOR_LIGHTGRAY      0xC618      /* 192, 192, 192 */
#define COLOR_LIGHTGREY      0xC618      /* 192, 192, 192 */
#define COLOR_LIGHTCYAN      0xE7FF      /* 224, 255, 255 */
#define COLOR_VIOLET         0xEC1D      /* 238, 130, 238 */
#define COLOR_AZUR           0xF7FF      /* 240, 255, 255 */
#define COLOR_BEIGE          0xF7BB      /* 245, 245, 220 */
#define COLOR_MAGENTA        0xF81F      /* 255,   0, 255 */
#define COLOR_TOMATO         0xFB08      /* 255,  99,  71 */
#define COLOR_GOLD           0xFEA0      /* 255, 215,   0 */
#define COLOR_ORANGE         0xFD20      /* 255, 165,   0 */
#define COLOR_SNOW           0xFFDF      /* 255, 250, 250 */
#define COLOR_YELLOW         0xFFE0      /* 255, 255,   0 */

//Pin definitions - change as required
#define	CS_PORT		GPIOB
#define CS_PIN		GPIO_PIN_13 //Chip select
#define RESX_PORT	GPIOB
#define RESX_PIN	GPIO_PIN_14 //Reset pin
#define	DC_PORT		GPIOB
#define DC_PIN		GPIO_PIN_15 //DATA / Command select
#define WR_PORT		GPIOB
#define	WR_PIN		GPIO_PIN_4 //Write pin
#define RD_PORT		GPIOB
#define	RD_PIN		GPIO_PIN_3 //Read pin
#define LCD0_Pin GPIO_PIN_5
#define LCD0_GPIO_Port GPIOA
#define LCD1_Pin GPIO_PIN_6
#define LCD1_GPIO_Port GPIOA
#define LCD2_Pin GPIO_PIN_7
#define LCD2_GPIO_Port GPIOA
#define LCD3_Pin GPIO_PIN_8
#define LCD3_GPIO_Port GPIOA
#define LCD4_Pin GPIO_PIN_9
#define LCD4_GPIO_Port GPIOA
#define LCD5_Pin GPIO_PIN_10
#define LCD5_GPIO_Port GPIOA
#define LCD6_Pin GPIO_PIN_11
#define LCD6_GPIO_Port GPIOA
#define LCD7_Pin GPIO_PIN_12
#define LCD7_GPIO_Port GPIOA

void spi_write(unsigned char data);
void write_buffer();
void parallel_write(unsigned char data);
void lcd_write_command(unsigned char data);
void lcd_write_data(unsigned char data);
void lcd_write_reg(unsigned int data);
void lcd_read_bytes(int byteCount);
void lcd_init_parallel(void);
void lcd_init_spi();
void swap_int(unsigned int *num1, unsigned int *num2);
void swap_char(char *num1, char *num2);
void delay_ms(double millis);
void delay_us(long int cycles);
void lcd_init_command_list(void);
void draw_pixel(unsigned int x, unsigned int y, unsigned int colour);
void set_draw_window(unsigned int row_start, unsigned int row_end, unsigned int col_start, unsigned int col_end);
void fill_rectangle(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int colour);
void draw_char(unsigned int x, unsigned int y, char c, unsigned int colour, char size);
void draw_fast_char(unsigned int x, unsigned int y, char c, unsigned int colour, unsigned int bg_colour);
void draw_string(unsigned int x, unsigned int y, unsigned int colour, char size, char *str);
void draw_fast_string(unsigned int x, unsigned int y, unsigned int colour, unsigned int bg_colour, char *str);
void draw_line(unsigned int x1, unsigned int y1, char x2, char y2, unsigned int colour);
void draw_bitmap(unsigned int x, unsigned int y, int scale, const unsigned int *bmp);
void fill_fast_rectangle(unsigned int x1, unsigned int y1, unsigned int colour);
void clear_screen(int white);

#endif	/* ILI9488_H */


