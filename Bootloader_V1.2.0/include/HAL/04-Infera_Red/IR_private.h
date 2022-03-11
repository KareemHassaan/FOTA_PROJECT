/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						02 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Infera Red Driver    		                                                							              *
* ! File Name	: IR_private.h                                   		                  							                  *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL                  						                                         							      *
**************************************************************************************************************************************/
#ifndef IR_PRIVATE_H
#define IR_PRIVATE_H

#define INT_NUM				 16
#define FRAME_LENGHT		 50
#define Timer_Ticks			 500000
#define HIGH_MIN_VALUE		 2200
#define HIGH_MAX_VALUE		 2500
#define DATA_START		     17


uint8 InterruptNumArray[INT_NUM] = {NVIC_EN_EXTI0,
	                                NVIC_EN_EXTI1,
	                                NVIC_EN_EXTI2,
	                                NVIC_EN_EXTI3,
	                                NVIC_EN_EXTI4,
	                                NVIC_EN_EXTI9_5,
	                                NVIC_EN_EXTI9_5,
	                                NVIC_EN_EXTI9_5,
	                                NVIC_EN_EXTI9_5,
	                                NVIC_EN_EXTI9_5,
	                                NVIC_EN_EXTI15_10,
	                                NVIC_EN_EXTI15_10,
	                                NVIC_EN_EXTI15_10,
	                                NVIC_EN_EXTI15_10,
	                                NVIC_EN_EXTI15_10,
	                                NVIC_EN_EXTI15_10};
									
/*************************************************************************************************************************************/
/********************************************** Static Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: HIR_GetFrame																				                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Get A Single Frame															                      *
**************************************************************************************************************************************/
static void HIR_GetFrame();
/**************************************************************************************************************************************
* Function Name		: HIR_ReadFrame																				                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Get The Data From The Frame													                      *
**************************************************************************************************************************************/
static void HIR_ReadFrame();

#endif /*IR_PRIVATE_H*/