/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						26 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: EXTI Driver                                                        							                      *
* ! File Name	: EXTI_private.h                                                     							                      *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

//************************************************************************************************************************************/
/***************************************************** Registers Memory Map **********************************************************/
/*************************************************************************************************************************************/

/******************************************************** EXTI Registers **************************************************************/	
#define EXTI_BASE_ADDRESS		(0x40010400)												//EXTI Base Address
#define EXTI					((volatile EXTI_t *) EXTI_BASE_ADDRESS )					//EXTI Resgister Structure Address


typedef struct
{
	volatile uint32 EXTI_IMR;																//Interrupt mask register
	volatile uint32 EXTI_EMR;																//Event mask register
	volatile uint32 EXTI_RTSR;																//Rising trigger selection register
	volatile uint32 EXTI_FTSR;																//Falling trigger selection register
	volatile uint32 EXTI_SWIER;																//Software interrupt event register
	volatile uint32 EXTI_PR;																//Pending register
	
}EXTI_t;

#define ENABLE  				1
#define DISABLE 				0


#endif /*EXTI_PRIVATE_H*/








