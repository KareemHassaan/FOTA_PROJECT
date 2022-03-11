/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						28 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: SYS_TICK Driver                                                        							                  *
* ! File Name	: SYS_TICK_private.h                                                     							                  *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef SYS_TICK_PRIVATE_H
#define SYS_TICK_PRIVATE_H

//************************************************************************************************************************************/
/***************************************************** Registers Memory Map **********************************************************/
/*************************************************************************************************************************************/

/****************************************************** SYS_TICK Registers ***********************************************************/
#define SYS_TICK_BASE_ADDRESS		0xE000E010														//SYS_TICK Base Address
#define SYS_TICK					((volatile SYS_TICK_t *) SYS_TICK_BASE_ADDRESS)					//SYS_TICK Base Address PTR


typedef struct
{
	volatile uint32 STK_CTRL;																		//SysTick control and status register
	volatile uint32 STK_LOAD;																		//SysTick reload value register
	volatile uint32 STK_VAL;																		//SysTick current value register
	volatile uint32 STK_CALIB;																		//SysTick calibration value register

	
}SYS_TICK_t;



#define SYS_TICK_ENABLE 			0
#define SYS_TICK_INT_BIT	 		1
#define SYS_TICK_CLK_SOURCE 		2
#define SYS_TICK_COUNT_FLAG 		16

#define ENABLE 						0
#define DISABLE						1

#define CLK_AHB_DIVIDE_8			0
#define CLK_AHB 					1

#define SINGLE 						0
#define PERIODIC					1

#endif /*SYS_TICK_PRIVATE_H*/








