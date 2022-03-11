/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						12 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: SPI Driver                                                        							                      *
* ! File Name	: SPI_private.h                                                     							                      *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

//************************************************************************************************************************************/
/***************************************************** Registers Memory Map **********************************************************/
/*************************************************************************************************************************************/

/******************************************************** SPI Registers **************************************************************/
#define SPI1_BASE_ADRRESS				0x40013000										//SPI1 Base Address


#define SPI1						 	((volatile SPIx_t *) SPI1_BASE_ADRRESS)			//SPI1 Base Address



typedef struct
{
	uint32 SPI_CR1;
	uint32 SPI_CR2;
	uint32 SPI_SR;
	uint32 SPI_DR;
	uint32 SPI_CRCPR;
	uint32 SPI_RXCRCR;
	uint32 SPI_TXCRCR;
	uint32 SPI_I2SCFGR;
	uint32 SPI_I2SPR;
	
}SPIx_t;

#define BSY_BIT							7

#define CPHA_BIT						0 
#define CPOL_BIT						1 
#define MSTR_BIT   						2
#define BR_BIT  						3
#define SPE_BIT   						6 
#define LSBFIRST_BIT   					7 
#define SSI_BIT   						8
#define SSM_BIT  						9
#define RXONLY_BIT  					10
#define DFF_BIT  						11
#define CRCNEXT_BIT 					12
#define CRCEN_BIT 						13
#define BIDIOE_BIT						14
#define BIDIMODE_BIT					15
	
#define LINE_UNIDIRECTIONAL 			0
#define LINE_BIDIRECTIONAL 				1
	
#define OUTPUT_DISABLED 				0
#define OUTPUT_ENABLED 					1
	
#define CRC_DISABLED					0
#define CRC_ENABLED						1 
	
#define DATA_PHASE 						0
#define NEXT_TRANSFER_CRC 				1
	
#define D8_BIT_DATA_FRAME 				0
#define D16_BIT_DATA_FRAME 				1

#define FULL_DUPLEX 					0
#define RX_OUTPUT_DISABLED 				1

#define SW_SLAVE_DISABLED				0
#define SW_SLAVE_ENABLED				1
 
#define SLAVE_SELECT_DISABLED			0
#define SLAVE_SELECT_ENABLED			1
 
#define MSB_FIRST						0
#define LSB_FIRST						1
 
#define PERIPHERAL_DISABLED				0
#define PERIPHERAL_ENABLED				1

#define FPCLK_2					  		0b000
#define FPCLK_4                   		0b001
#define FPCLK_8                   		0b010
#define FPCLK_16                  		0b011
#define FPCLK_32                  		0b100
#define FPCLK_64                  		0b101
#define FPCLK_128                 		0b110
#define FPCLK_256                 		0b111

#define SLAVE_CONFIGURATION				0
#define MASTER_CONFIGURATION			1

#define CK_TO_0_WHEN_IDLE				0
#define CK_TO_1_WHEN_IDLE				1

#define FIRST_ CLOCK_TRANSITION_IS_THE_FIRST_DATA_CAPTURE_EDGE		0
#define SECOND_CLOCK_TRANSITION_IS_THE_FIRST_DATA_CAPTURE_EDGE		1


#define TXEIE_BIT													7
#define RXNEIE_BIT													6
#define ERRIE_BIT													5 
#define SSOE_BIT													2 
#define TXDMAEN_BIT 												1
#define RXDMAEN_BIT 												0




#endif /*SPI_PRIVATE_H*/








