/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						13 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: UART Driver                                                        							                      *
* ! File Name	: UART_program.c                                                       							                      *
* ! Description : This file has the implementation of Basic of UART functions        							                      *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/

/**************************************************** Library Inclusions *************************************************************/
#include "../../include/LIB/STD_TYPES.h"
#include "../../include/LIB/BIT_MATH.h"
/************************************************** Lower Layer Inclusions ***********************************************************/

/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/
/*Must be with that order maybe change Private with config only*/
#include"../../include/MCAL/09-UART/UART_interface.h"  
#include"../../include/MCAL/09-UART/UART_private.h"
#include"../../include/MCAL/09-UART/UART_config.h"

/***************************************************** Global Variables **************************************************************/
void (*MUSART1_CallBack)(void) = NULL;
/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MUART_voidInit																			                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Iniit UART Configrations	 					          					  						  *
**************************************************************************************************************************************/
void MUART_voidInit()
{ 
	    /*	baud rate = 115200  */
		UART1 -> USART_BRR = BRR_VALUE;

		SET_BIT((UART1 -> USART_CR1) , RXNEIE_BIT);		/*Enable Rx Interrupt*/
		SET_BIT((UART1 -> USART_CR1) , TE_BIT);			/* Enabling Transmitter */
		SET_BIT((UART1 -> USART_CR1) , RE_BIT);			/* Enabling Receiver */
		SET_BIT((UART1 -> USART_CR1) , UE_BIT);			/* Enabling USART */

		UART1 -> USART_SR = 0x00;
}

/**************************************************************************************************************************************
* Function Name		: MUART_voidSendByte																		                      *
* Parameters (in)	: uint8 Copy_uint8Data																			                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Send a Byte	 								          					  						  *
**************************************************************************************************************************************/
void MUART_voidSendByte(uint8 Copy_uint8Data)
{
	UART1 ->  USART_DR = Copy_uint8Data;
	
	while(GET_BIT(UART1 ->  USART_SR, USART_TC) == 0)
	{
		/*Busy Waiting For Sending Message*/
	}
	
	CLR_BIT(UART1 -> USART_SR, USART_TC);
}

/**************************************************************************************************************************************
* Function Name		: MUART_voidReceiveByte																		                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: uint8							  															    	              *
* Description		: Function To Receive a Byte	 							          					  						  *
**************************************************************************************************************************************/
uint8 MUART_voidReceiveByte()
{
	while(GET_BIT(UART1 ->  USART_SR, USART_RXNE) == 0)
	{
		/*Busy Waiting For Receiving Message*/
	}

	return UART1 -> USART_DR;
}

/**************************************************************************************************************************************
* Function Name		: MUART_voidReceiveByte																		                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: uint8							  															    	              *
* Description		: Function To Receive a Byte	 							          					  						  *
**************************************************************************************************************************************/
uint8 MUART_voidReceiveByteAsync()
{
	return  UART1 -> USART_DR;
}

/**************************************************************************************************************************************
* Function Name		: MUART_voidSendString																		                      *
* Parameters (in)	: char str[]																					                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Send a string				 					          					  						  *
**************************************************************************************************************************************/
void MUART_voidSendString(char Str[])
{
	uint8 Local_uint8LoopCounter = 0;

	while(Str[Local_uint8LoopCounter] != STRING_END)
	{
		UART1 ->  USART_DR = Str[Local_uint8LoopCounter];

		while((GET_BIT((UART1 ->  USART_SR), TC_BIT)) == 0);
		Local_uint8LoopCounter++;
	}

}

/**************************************************************************************************************************************
* Function Name		: MUART_voidSendString																		                      *
* Parameters (in)	: char str[]																					                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Receive a string				 				          					  						  *
**************************************************************************************************************************************/
void MUART_voidReceiveString(char str[])
{
	while(*str != STRING_END)
	{
		*str =MUART_voidReceiveByte();
		str++;
	}
}

/**************************************************************************************************************************************
* Function Name		: MUART_voidSendString																		                      *
* Parameters (in)	: char str[]																					                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Receive a string				 				          					  						  *
**************************************************************************************************************************************/
void MUSART1_VidSetCallBack( void (*ptr) (void) )
{

	MUSART1_CallBack = ptr ;

}
/*************************************************************************************************************************************/
/***************************************************** Interrupt Handler *************************************************************/
/*************************************************************************************************************************************/
void USART1_IRQHandler(void)
{
	MUSART1_CallBack();
	UART1 ->  USART_SR = 0;
}












