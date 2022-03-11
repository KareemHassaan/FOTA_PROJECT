/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						19 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: RCC Driver                                     							                                          *
* ! File Name	: RCC_config.h                                                      							                      *
* ! Description : This file has the Configrations needed		     		        	 						                      *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/**************************************************************************************************************************************
* MACRO		: 	To Configure The Clock Source Ready Loop Time Out													         		  *
* options	:	Any Number In Range uint32						  																	  *
**************************************************************************************************************************************/
#define CLK_SOURCE_READY_TIME_OUT 										50000

/**************************************************************************************************************************************
* MACRO		: 	To Select The Clock Source To The System															         		  *
* options	:	HSE		/	 HSI	/	 PLL	/					  																  *
**************************************************************************************************************************************/
#define CLK_SOURCE 														PLL
/**************************************************************************************************************************************
* MACRO		: 	To Select The Clock Source To The PLL																         		  *
* options	:	HSE_SOURCE		/	 HSI_SOURCE		/				 																  *
**************************************************************************************************************************************/
#define PLL_SOURCE 														HSI_SOURCE
/**************************************************************************************************************************************
* MACRO		: 	To Select HSE Division Factor																		         		  *
* options	:	HSE_NOT_DIVIDED		/	 HSE_DIVIDED_BY_2		/				 													  *
**************************************************************************************************************************************/
#define HSE_DIVISION_FACTOR 											HSE_NOT_DIVIDED
/**************************************************************************************************************************************
* MACRO		: 	To Select PLL Input Multplication Factor															         		  *
* options	:	PLL_INPUT_MUL_2		/	 PLL_INPUT_MUL_3		/		PLL_INPUT_MUL_4			/		PLL_INPUT_MUL_5			/	  *
*				PLL_INPUT_MUL_6		/	 PLL_INPUT_MUL_7		/		PLL_INPUT_MUL_8			/		PLL_INPUT_MUL_9			/	  *
*				PLL_INPUT_MUL_10	/	 PLL_INPUT_MUL_11		/		PLL_INPUT_MUL_12		/		PLL_INPUT_MUL_13		/	  *
*				PLL_INPUT_MUL_14	/	 PLL_INPUT_MUL_15		/		PLL_INPUT_MUL_16		/									  *
**************************************************************************************************************************************/
#define PLL_MULTIPLICATION_FACTOR 										PLL_INPUT_MUL_7

/**************************************************************************************************************************************
* MACRO		: 	To Adjust AHB Prescaller																			         		  *
* options	:	AHB_SYSCLK_NOT_DIVIDED		/	 AHB_SYSCLK_DIVIDED_BY_2		/		AHB_SYSCLK_DIVIDED_BY_4			/			  *
* 				AHB_SYSCLK_DIVIDED_BY_8		/	 AHB_SYSCLK_DIVIDED_BY_16		/		AHB_SYSCLK_DIVIDED_BY_64		/			  *
* 				AHB_SYSCLK_DIVIDED_BY_128	/	 AHB_SYSCLK_DIVIDED_BY_256		/		AHB_SYSCLK_DIVIDED_BY_512		/			  *
**************************************************************************************************************************************/
#define AHB_PRESCALER 													AHB_SYSCLK_NOT_DIVIDED
/**************************************************************************************************************************************
* MACRO		: 	To Adjust ABP1 Prescaller																			         		  *
* options	:	APB1_HCLK_NOT_DIVIDED		/	 APB1_HCLK_DIVIDED_BY_2			/		APB1_HCLK_DIVIDED_BY_4			/			  *
* 				APB1_HCLK_DIVIDED_BY_8		/	 APB1_HCLK_DIVIDED_BY_16		/				  									  *
**************************************************************************************************************************************/ 
#define APB1_PRESCALER 													APB1_HCLK_DIVIDED_BY_2
/**************************************************************************************************************************************
* MACRO		: 	To Adjust ABP2 Prescaller																			         		  *
* options	:	APB2_HCLK_NOT_DIVIDED		/	 APB2_HCLK_DIVIDED_BY_2			/		APB2_HCLK_DIVIDED_BY_4			/			  *
* 				APB2_HCLK_DIVIDED_BY_8		/	 APB2_HCLK_DIVIDED_BY_16		/				  									  *
**************************************************************************************************************************************/ 
#define APB2_PRESCALER 													APB2_HCLK_NOT_DIVIDED


#endif /*RCC_CONFIG_H*/  
