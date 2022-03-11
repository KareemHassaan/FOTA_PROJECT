/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#ifndef TFT_INTERFACE_H_
#define TFT_INTERFACE_H_

// ST7735 ROUTINES
#define SWRESET 0x01 // software reset
#define SLPOUT 0x11 // sleep out
#define DISPOFF 0x28 // display off
#define DISPON 0x29 // display on
#define CASET 0x2A // column address set
#define RASET 0x2B // row address set
#define RAMWR 0x2C // RAM write
#define MADCTL 0x36 // axis control
#define COLMOD 0x3A // color mode
// 1.8" TFT display constants
#define XSIZE 128
#define YSIZE 160
#define XMAX XSIZE-1
#define YMAX YSIZE-1
// Color constants
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x0400
#define LIME 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF




void TFT_VidInit           ( void                      ) ;
void TFT_VidFillColor      (u16 Copy_u16Color, u8 Copy_u8LenghtStart, u8 Copy_u8Lenght, u8 Copy_u8WidthStart, u8 Copy_u8Width) ;
void TFT_VidFillImage      ( const u16 * Copy_ptrImage ) ;


void TFT_VidDrawHLine      ( u8 Xaxis , u8 Yaxis , u8 Copy_u8Length , u16 Copy_u8Color ) ;
void TFT_VidDrawVLine      ( u8 Xaxis , u8 Yaxis , u8 Copy_u8Length , u16 Copy_u8Color ) ;

void TFT_VidDrawRectangle ( u8 Copy_u8Height , u8 Copy_u8Width , u8 Xaxis , u8 Yaxis , u16 Copy_u8Color ) ;

void TFT_VidWriteChar      ( u8 * Cop_u8Char , u8 Xaxis , u8 Yaxis , u16 Copy_u8Color                    ) ;

#endif /* TFT_INTERFACE_H_ */
