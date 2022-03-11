/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						26 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: EXTI Driver                                     							                                          *
* ! File Name	: EXTI_config.h                                                      							                      *
* ! Description : This file has the Configrations needed		     		        	 						                      *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

/**************************************************************************************************************************************
* MACRO		: 	To Adjust EXTI Numbers																				         		  *
* options	:	Int Num											  																	  *
**************************************************************************************************************************************/
#define EXTI_NUM						16

/**************************************************************************************************************************************
* MACRO		: 	To Turn EXTI ON OR OFF																				         		  *
* options	:	ENABLE 		/		DISABLE			/																				  *
**************************************************************************************************************************************/
#define EXTI_LINE0_EN					ENABLE
#define EXTI_LINE1_EN					DISABLE
#define EXTI_LINE2_EN					DISABLE
#define EXTI_LINE3_EN					DISABLE
#define EXTI_LINE4_EN					DISABLE
#define EXTI_LINE5_EN					DISABLE
#define EXTI_LINE6_EN					DISABLE
#define EXTI_LINE7_EN					DISABLE
#define EXTI_LINE8_EN					DISABLE
#define EXTI_LINE9_EN					DISABLE
#define EXTI_LINE10_EN					DISABLE
#define EXTI_LINE11_EN					DISABLE
#define EXTI_LINE12_EN					DISABLE
#define EXTI_LINE13_EN					DISABLE
#define EXTI_LINE14_EN					DISABLE
#define EXTI_LINE15_EN					DISABLE



#endif /*EXTI_CONFIG_H*/  
