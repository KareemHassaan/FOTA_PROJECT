/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						21 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: NVIC Driver                                                        							                      *
* ! File Name	: NVIC_private.h                                                     							                      *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

//************************************************************************************************************************************/
/***************************************************** Registers Memory Map **********************************************************/
/*************************************************************************************************************************************/

/******************************************************** NVIC Registers **************************************************************/	
#define NVIC						((volatile NVIC_t * ) 0xE000E100)						//NVIC Base Address
#define SCB_AIRCR  					*((volatile u32*)(0xE000ED00 + 0x0C))

typedef struct
{
	volatile uint32 ISER [32];																//Interrupt set-enable registers
	volatile uint32 ICER [32];																//Interrupt clear-enable registers
	volatile uint32 ISPR [32];																//Interrupt set-pending registers
	volatile uint32 ICPR [32];																//Interrupt clear-pending registers
	volatile uint32 IABR [32];																//Interrupt active bit registers
	volatile uint32 Reserved [32];															//Reserved Bytes
	volatile uint8 IPR [128];																//Interrupt priority registers
	
}NVIC_t;

/****************************************************** GROUP POlicy options **********************************************************/	
#define NVIC_G16_S0					(0x05FA0300)  
#define NVIC_G8_S2  				(0x05FA0400) 
#define NVIC_G4_S4  				(0x05FA0500) 
#define NVIC_G2_S8  				(0x05FA0600) 
#define NVIC_G0_S16  				(0x05FA0700) 


#endif /*NVIC_PRIVATE_H*/








