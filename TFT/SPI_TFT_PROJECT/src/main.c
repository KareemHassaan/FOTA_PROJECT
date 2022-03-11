/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#include "TYPES.h"

#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "SPI_INTERFACE.h"

#include "TFT_INTERFACE.h"

#include "Images.h"

int main ( void ){

	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock( APB2_BUS , GPIOA_RCC );
	MRCC_VidEnablePeripheralClock( APB2_BUS , SPI1_RCC  );

	MGPIO_VidSetPinDirection( GPIOA , PIN7 , OUTPUT_SPEED_10MHZ_AFPP );//MOSI
	MGPIO_VidSetPinDirection( GPIOA , PIN5 , OUTPUT_SPEED_10MHZ_AFPP );//CLOCK

	MGPIO_VidSetPinDirection( GPIOA , PIN1 , OUTPUT_SPEED_10MHZ_PP   );//RST
	MGPIO_VidSetPinDirection( GPIOA , PIN2 , OUTPUT_SPEED_10MHZ_PP   );//A0(D/C)

	MSPI_VidInit();

	TFT_VidInit();

	/* Drawing Egypt Flag */
	TFT_VidFillColor( BLACK ,0,160,0,128 );
//	TFT_VidFillColor( RED ,0,160,0,128 );
//	TFT_VidFillColor( WHITE ,0,160,0,86);
//	TFT_VidFillColor( BLACK ,0,160,0,43 );

	/*Drawing Ukraine Flag*/
	TFT_VidFillColor( BLUE ,0,160,0,128 );
	TFT_VidFillColor( YELLOW ,0,160,0,64);




	while(1);

	return 0 ;
}
