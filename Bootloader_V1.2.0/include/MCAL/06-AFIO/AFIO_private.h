/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						01 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: AFIO Driver                                                        							                      *
* ! File Name	: AFIO_private.h                                                     							                      *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

//************************************************************************************************************************************/
/***************************************************** Registers Memory Map **********************************************************/
/*************************************************************************************************************************************/

/******************************************************** AFIO Registers **************************************************************/
#define AFIOA_BASE_ADRRESS				0x40010000										//AFIOA Base Address

#define AFIO						 	((volatile AFIOx_t *) AFIOA_BASE_ADRRESS)		//AFIOA Base Address

typedef struct 
{
	volatile uint32 AFIO_EVCR;															//Event control register
	volatile uint32 AFIO_MAPR;															//AF remap and debug I/O configuration register
	volatile uint32 AFIO_EXTICR[4];														//External interrupt configuration register Array
	volatile uint32 AFIO_MAPR2;															//AF remap and debug I/O configuration register2
  
	
}AFIOx_t;

#define AFIO_EVOE						7												//Event output enable Bit

#define AFIO_EXTI_REGS_NUM				4
#define AFIO_EXTI_NUM_IN_REG			4
#define AFIO_BITS_NUM_IN_EXTI			4


#define AFIO_MAPR_1						32
#define AFIO_MAPR_2						64

#endif /*AFIO_PRIVATE_H*/








