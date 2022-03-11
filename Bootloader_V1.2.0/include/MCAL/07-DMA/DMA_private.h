/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						11 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: DMA Driver                                                        							                      *
* ! File Name	: DMA_private.h                                                     							                      *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

//************************************************************************************************************************************/
/***************************************************** Registers Memory Map **********************************************************/
/*************************************************************************************************************************************/

/******************************************************** DMA Registers **************************************************************/
#define DMA1_BASE_ADRRESS				0x40020000										//DMA1 Base Address
#define DMA2_BASE_ADRRESS				0x40020400										//DMA2 Base Address

#define DMA1						 	((volatile DMAx_t *) DMA1_BASE_ADRRESS)			//DMA1 Base Address
#define DMA2					 		((volatile DMAx_t *) DMA2_BASE_ADRRESS)			//DMA1 Base Address

typedef struct
{
	uint32 CCR;																			//DMA channel x configuration register
	uint32 CNDTR;																		//DMA channel x number of data register
	uint32 CPAR;																		//DMA channel x peripheral address register
	uint32 CMAR;																		//DMA channel x memory address register
	uint32 Reserved;																	//Reserved
	
}DMA_Channel_t;

typedef struct
{
	uint32 DMA_ISR;																		//DMA interrupt status register
	uint32 DMA_IFCR;																	//DMA interrupt flag clear register
	DMA_Channel_t DMA_Channel[7];														//DMA channels registers	
	
}DMAx_t;

#define PIN14							14
#define PIN6                            6
#define PIN7                            7
#define PIN12                           12
#define PIN10                           10
#define PIN8                            8
#define PIN4                            4
#define PIN5                            5
#define PIN2                            2
#define PIN1                            1
#define PIN3                            3

#define DISABLE                         0
#define ENABLE                          1



#endif /*DMA_PRIVATE_H*/








