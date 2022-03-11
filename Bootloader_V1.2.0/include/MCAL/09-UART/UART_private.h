/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						13 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: UART Driver                                                        							                      *
* ! File Name	: UART_private.h                                                     							                      *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

//************************************************************************************************************************************/
/***************************************************** Registers Memory Map **********************************************************/
/*************************************************************************************************************************************/

/******************************************************** UART Registers **************************************************************/
#define UART1_BASE_ADRRESS							0x40013800											//UART1 Base Address


#define UART1						 				((volatile UARTx_t *) UART1_BASE_ADRRESS)			//UART1 Base Address



typedef struct
{
	uint32 USART_SR;
	uint32 USART_DR;
	uint32 USART_BRR;
	uint32 USART_CR1;
	uint32 USART_CR2;
	uint32 USART_CR3;
	uint32 USART_GTPR;
	
	
}UARTx_t;

#define STRING_END									'\0'

#define USART_TC									6
#define USART_RXNE									5

#define TC_BIT										6

#define UE_BIT 										13
#define M_BIT										12 
#define WAKE_BIT 									11
#define PCE_BIT										10 
#define PS_BIT 										9
#define PEIE_BIT	 								8
#define TXEIE_BIT									7 
#define TCIE_BIT 									6
#define RXNEIE_BIT 									5
#define IDLEIE_BIT 									4
#define TE_BIT										3	 
#define RE_BIT 										2
#define RWU_BIT										1	 
#define SBK_BIT 									0

#define IDLE_LINE									0
#define ADDRESS_MARK								1	
	
#define D8_DATA_BITS								0
#define D9_DATA_BITS								1
	
#define EVEN_PARITY									0
#define ODD_PARITY									1
	
#define ACTIVE_MODE									0
#define MUTE_MODE									1
	
#define DISABLE										0
#define ENABLE										1
	
	
	
	
#define STOP_BIT 									12 
#define CLKEN_BIT									11 
#define CPOL_BIT									10 
#define CPHA_BIT  									9 
	
#define STOP_BIT_1									0b00
#define STOP_BIT0_5              					0b01
#define STOP_BITS_2              					0b10
#define STOP_BIT_1_5              					0b11

#define STEADY_LOW_VALUE_ON_CK_PIN_OUTSIDE_TRANSMISSION_WINDOW				0
#define STEADY_HIGH_VALUE_ON_CK_PIN_OUTSIDE_TRANSMISSION_WINDOW				1

#define THE_FIRST_CLOCK_TRANSITION_IS_THE_FIRST_DATA_CAPTURE_EDGE			0
#define THE_SECOND_CLOCK_TRANSITION_IS_THE_FIRST_DATA_CAPTURE_EDGE			1



#endif /*UART_PRIVATE_H*/








