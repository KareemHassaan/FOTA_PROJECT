/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#include "TYPES.h"
#include "MACROS.h"

#include "GPIO_INTERFACE.h"
#include "DELAY_INTERFACE.h"
#include "SPI_INTERFACE.h"

#include "TFT_INTERFACE.h"
#include "TFT_PRIVATE.h"
#include "TFT_CONFIG.h"


void TFT_VidInit ( void ) {

	/* Reset Puls To Initializing All registers*/
	MGPIO_VidSetPinValue( TFT_RST_PORT , TFT_RST_PIN , LOW );
	_delay_us( 1000 );
	MGPIO_VidSetPinValue( TFT_RST_PORT , TFT_RST_PIN , HIGH );
	_delay_us( 150000 );

	WriteCommand( SLPOUT ) ;   // take display out of sleep mode
	_delay_us   ( 150000 ) ;   // wait 150mS for TFT driver circuits

	WriteCommand( COLMOD ) ;   // select color mode:
	WriteData   ( 0x05   ) ;   // mode 5 = 16bit pixels (RGB565)

	WriteCommand( DISPON ) ;   // turn display on!
	_delay_us   ( 1000 );

	/* Remap TFT addresses ( x = 0 , y = 0 Start From The Left Top Of The TFT ) */
	WriteCommand( MADCTL );
	WriteData   ( 0xC0 );
}


void TFT_VidFillImage ( const u16 * Copy_ptrImage ){

	u8 LOC_u8CountX ;
	u8 LOC_u8CountY ;
	u16 LOC_u8Data  ;

	for( LOC_u8CountY  = 0 ; LOC_u8CountY  < 160 ; LOC_u8CountY ++ )
	{
		WriteCommand( CASET         ) ; // set column range (x0,x1)
		WriteData   ( 0             ) ;
		WriteData   ( 0             ) ;
		WriteCommand( RASET         ) ; // set row range (y0,y1)
		WriteData   ( 0             ) ;
		WriteData   ( LOC_u8CountY  ) ;

		WriteCommand( RAMWR         ) ; // memory write

		for ( LOC_u8CountX = 0 ; LOC_u8CountX < 128 ; LOC_u8CountX++ )
		{
			/* Get Pixel To Send */
			LOC_u8Data = *Copy_ptrImage ;

			WriteData ( LOC_u8Data >> 8   ); // write hi byte
			WriteData ( LOC_u8Data & 0xFF ); // write lo byte

			/* Mode to next Pixel */
			Copy_ptrImage ++;

		}
	}

}



void TFT_VidFillColor ( u16 Copy_u16Color, u8 Copy_u8LenghtStart, u8 Copy_u8Lenght, u8 Copy_u8WidthStart, u8 Copy_u8Width ) {

	u8 LOC_u8CountX ;
	u8 LOC_u8CountY ;

	for( LOC_u8CountY = Copy_u8LenghtStart ; LOC_u8CountY < Copy_u8Lenght ; LOC_u8CountY++ )
	{
		WriteCommand( CASET        ) ; // set column range (x0,x1)
		WriteData   ( 0            ) ;
		WriteData   ( 0            ) ;
		WriteCommand( RASET        ) ; // set row range (y0,y1)
		WriteData   ( 0            ) ;
		WriteData   ( LOC_u8CountY ) ;

		WriteCommand( RAMWR        ); // memory write

		for ( LOC_u8CountX = Copy_u8WidthStart ; LOC_u8CountX < Copy_u8Width ; LOC_u8CountX++ )
		{
			WriteData ( Copy_u16Color >> 8   ) ; // write hi byte
			WriteData ( Copy_u16Color & 0xFF ) ; // write lo byte

		}
	}

}

static void WriteData   ( u8 Copy_u8Data ) {

	/* DC is 1 for data */
	MGPIO_VidSetPinValue( TFT_DC_PORT , TFT_DC_PIN , HIGH );

	/* Send Data */
	MSPI1_VidSendDataU8( Copy_u8Data ) ;
}

static void WriteCommand( u8 Copy_u8Commend ) {

	/* DC is 0 for data */
	MGPIO_VidSetPinValue( TFT_DC_PORT , TFT_DC_PIN , LOW );

	/* Send Command */
	MSPI1_VidSendDataU8( Copy_u8Commend ) ;
}

void TFT_VidDrawHLine ( u8 Xaxis , u8 Yaxis , u8 Copy_u8Length , u16 Copy_u8Color ) {

	for ( ; Copy_u8Length > 0 ; Copy_u8Length-- ){

		WriteCommand( CASET ); // set column range (x0,x1)

		WriteData   ( Xaxis );
		WriteData   ( Xaxis );

		WriteCommand( RASET ); // set row range (y0,y1)

		WriteData   ( Yaxis );
		WriteData   ( Yaxis );

		WriteCommand( RAMWR ); // memory write

		WriteData ( Copy_u8Color >> 8   ); // write hi byte
		WriteData ( Copy_u8Color & 0xFF ); // write lo byte

		Xaxis++;

	}

}

void TFT_VidDrawVLine ( u8 Xaxis , u8 Yaxis , u8 Copy_u8Length , u16 Copy_u8Color ) {

	for ( ; Copy_u8Length > 0 ; Copy_u8Length-- ){

		WriteCommand( CASET ); // set column range (x0,x1)

		WriteData   ( Xaxis );
		WriteData   ( Xaxis );

		WriteCommand( RASET ); // set row range (y0,y1)

		WriteData   ( Yaxis );
		WriteData   ( Yaxis );

		WriteCommand( RAMWR ); // memory write

		WriteData ( Copy_u8Color >> 8   ); // write hi byte
		WriteData ( Copy_u8Color & 0xFF ); // write lo byte

		Yaxis++;

	}

}

void TFT_VidDrawRectangle ( u8 Copy_u8Height , u8 Copy_u8Width , u8 Xaxis , u8 Yaxis , u16 Copy_u8Color ) {

	TFT_VidDrawHLine ( Xaxis , Yaxis , Copy_u8Width  , Copy_u8Color                 );
	TFT_VidDrawVLine ( Xaxis , Yaxis , Copy_u8Height , Copy_u8Color                 );
	TFT_VidDrawHLine ( Xaxis , Copy_u8Height + Yaxis , Copy_u8Width  , Copy_u8Color );
	TFT_VidDrawVLine ( Copy_u8Width + Xaxis , Yaxis , Copy_u8Height , Copy_u8Color  );

}

void TFT_VidWriteChar( u8 * Cop_u8Char , u8 Xaxis , u8 Yaxis , u16 Copy_u8Color ){

	u8  LOC_u8Mask = 0x01 ;
	u8  LOC_u8DataMasked  ;
	u16 LOC_u8Pixel       ;

	for( u8 LOC_u8Iterator1 = 0 ; LOC_u8Iterator1 < 5 ; LOC_u8Iterator1++ ){

		for( u8 LOC_u8Iterator2 = 0 ; LOC_u8Iterator2 < 7 ; LOC_u8Iterator2++ ){

			/* Set The Position Of 5x7 Character */
			WriteCommand( CASET ); // set column range (x0,x1)

			WriteData( Xaxis +  LOC_u8Iterator1 );
			WriteData( Xaxis +  LOC_u8Iterator1 );

			WriteCommand( RASET ); // set row range (y0,y1)

			WriteData( Yaxis +  LOC_u8Iterator2 );
			WriteData( Yaxis +  LOC_u8Iterator2 );

			WriteCommand( RAMWR ); // memory write

			LOC_u8DataMasked = Cop_u8Char[ LOC_u8Iterator1 ] & LOC_u8Mask ;

			if( LOC_u8DataMasked == 0  ) { LOC_u8Pixel = 0x0000       ; }
			else                         { LOC_u8Pixel = Copy_u8Color ; }

			WriteData ( LOC_u8Pixel >> 8   ); // write hi byte
			WriteData ( LOC_u8Pixel & 0xFF ); // write lo byte

			LOC_u8Mask <<= 1 ;

		}

		LOC_u8Mask = 0x01 ;

	}

}
