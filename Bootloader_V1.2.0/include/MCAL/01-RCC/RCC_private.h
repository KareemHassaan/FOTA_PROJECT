/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						19 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: RCC Driver                                                        							                      *
* ! File Name	: RCC_private.h                                                     							                      *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

//************************************************************************************************************************************/
/***************************************************** Registers Memory Map **********************************************************/
/*************************************************************************************************************************************/

/******************************************************** RCC Registers **************************************************************/
#define RCC_BASE_ADRRESS						0x40021000								//Base Address Of RCC Perephiral
					
#define RCC 									((volatile RCC_t *)RCC_BASE_ADRRESS)	//Pointer To The Structure Of Register

typedef struct 																			
{
	volatile uint32 RCC_CR;																//Clock control register			
	volatile uint32 RCC_CFGR;															//Clock configuration register			     
	volatile uint32 RCC_CIR;															//Clock interrupt register			     
	volatile uint32 RCC_APB2RSTR;														//APB2 peripheral reset register					  
	volatile uint32 RCC_APB1RSTR;														//APB1 peripheral reset register				  
	volatile uint32 RCC_AHBENR;															//AHB peripheral clock enable register			     
	volatile uint32 RCC_APB2ENR;														//APB2 peripheral clock enable register			  
	volatile uint32 RCC_APB1ENR;														//APB1 peripheral clock enable register	
	volatile uint32 RCC_BDCR;															//Backup domain control register			     
	volatile uint32 RCC_CSR;														    //Control/status register
	
}RCC_t;



#define RCC_CR_HSI_ON_BIT						0
#define RCC_CR_HSE_ON_BIT						16
#define RCC_CR_PLL_ON_BIT						24
		
#define CLK_SOURCE_NOT_READY    				0
#define CLK_SOURCE_READY    					1

#define RCC_CFGR_AHB_PRESCALER_START_BIT  		4
#define RCC_CFGR_APB1_PRESCALER_START_BIT 		8
#define RCC_CFGR_APB2_PRESCALER_START_BIT 		11

#define RCC_CFGR_PLL_SOURCE_BIT  				16
#define RCC_CFGR_HSE_DIVIDER_BIT 				17
#define RCC_CFGR_PLL_MUL_BIT 	 				18
	
	
#define RCC_CFGR_SW_BITS_MASK					0xFFFFFFFC
#define RCC_CFGR_Prescaller_BITS_MASK			0xFFFFC00F
#define RCC_CFGR_PLL_CONFIG_MASK 				0xFF80FFFF



#endif /*RCC_PRIVATE_H*/








