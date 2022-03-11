/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						20 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: GPIO Driver                                                        							                      *
* ! File Name	: GPIO_private.h                                                     							                      *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

//************************************************************************************************************************************/
/***************************************************** Registers Memory Map **********************************************************/
/*************************************************************************************************************************************/

/******************************************************** GPIO Registers **************************************************************/
#define GPIOA_BASE_ADRRESS				0x40010800													//GPIOA Base Address
#define GPIOB_BASE_ADRRESS				0x40010C00													//GPIOB Base Address
#define GPIOC_BASE_ADRRESS				0x40011000													//GPIOC Base Address
	
#define GPIOA 							((volatile GPIOx_t *)GPIOA_BASE_ADRRESS)					//Pointer To GPIO Register Structure
#define GPIOB 							((volatile GPIOx_t *)GPIOB_BASE_ADRRESS)					//Pointer To GPIO Register Structure
#define GPIOC 							((volatile GPIOx_t *)GPIOC_BASE_ADRRESS)					//Pointer To GPIO Register Structure
	
typedef struct 
{
	volatile uint32 GPIO_CRL;																		//Port configuration register low
    volatile uint32 GPIO_CRH;																		//Port configuration register high
    volatile uint32 GPIO_IDR;																		//Port Input data register
    volatile uint32 GPIO_ODR;																		//Port output data register
    volatile uint32 GPIO_BSRR;																		//Port bit set/reset register
    volatile uint32 GPIO_BRR;																		//Port bit reset register
    volatile uint32 GPIO_LCKR;																		//Port configuration lock register
	
}GPIOx_t;

#define GPIO_CRX_MASK					0x0000000F

#define GPIO_LCKK_BIT					16



#endif /*GPIO_PRIVATE_H*/








