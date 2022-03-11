/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						02 MAR,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: WIFI Driver                                           							                     		 	  *
* ! File Name	: WIFI_program.c                                   		                   						                      *
* ! Description : This file has the implementation of Basic of WIFI functions  					   						              *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL	                  						                                         							  *
**************************************************************************************************************************************/

/**************************************************** Library Inclusions *************************************************************/
#include "../../include/LIB/STD_TYPES.h"
#include "../../include/LIB/BIT_MATH.h"
/************************************************** Lower Layer Inclusions ***********************************************************/
#include"../../include/MCAL/09-UART/UART_interface.h"
#include"../../include/MCAL/05-SYS_TICK/SYS_TICK_interface.h"
 
/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/
#include"../../include/HAL/06-WIFI/WIFI_intrface.h"  
#include"../../include/HAL/06-WIFI/WIFI_private.h"
#include"../../include/HAL/06-WIFI/WIFI_config.h"

/***************************************************** Global Variables **************************************************************/
uint8 volatile Global_uint8RecordDataBuffer[RECORD_CHAR_NUM] = {0};
uint8 volatile Global_uint8LoopCounter = 0;
uint8 volatile Global_uint8Validation_Flag = NOT_OK;


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: HWIFI_VoidInit																				                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
void HWIFI_voidInit()
{
	/*Set Receive CallBack Function*/
	MUSART1_VidSetCallBack(MUART_ReceiveCBK_Func);
	/*Send AT To Wifi Module for checking*/
	MUART_voidSendString((uint8*)"AT\r\n");
//	MUART_voidSendString((uint8*)"ATE0\r\n");
	while(HWIFI_CommandValidation() == NOT_OK)
	{
		HWIFI_CLearDataBuffer();
		MUART_voidSendString((uint8*)"AT\r\n");
	}

	HWIFI_CLearDataBuffer();
	MUART_voidSendString((uint8*)"AT+CWMODE=1\r\n");

	while(HWIFI_CommandValidation() == NOT_OK)
	{
		HWIFI_CLearDataBuffer();
		MUART_voidSendString((uint8*)"AT+CWMODE=1\r\n");
	}

	HWIFI_CLearDataBuffer();
}

/**************************************************************************************************************************************
* Function Name		: HWIFI_VoidInit																				                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
void HWIFI_voidConnectToWifi()
{
	HWIFI_CLearDataBuffer();
	
	MUART_voidSendString((uint8*)WIFI_CONNECT_CMD_P1);
	MUART_voidSendString((uint8*)SSID);
	MUART_voidSendString((uint8*)WIFI_CONNECT_CMD_P2);
	MUART_voidSendString((uint8*)WIFI_PASSWORD);
	MUART_voidSendString((uint8*)WIFI_CONNECT_CMD_P3);
	
	while(HWIFI_CommandValidation() == NOT_OK)
	{
		HWIFI_CLearDataBuffer();

		MUART_voidSendString((uint8*)WIFI_CONNECT_CMD_P1);
		MUART_voidSendString((uint8*)SSID);
		MUART_voidSendString((uint8*)WIFI_CONNECT_CMD_P2);
		MUART_voidSendString((uint8*)WIFI_PASSWORD);
		MUART_voidSendString((uint8*)WIFI_CONNECT_CMD_P3);
			
	}

	HWIFI_CLearDataBuffer();
}

/**************************************************************************************************************************************
* Function Name		: HWIFI_VoidInit																				                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
void HWIFI_voidConnectToServer()
{
	HWIFI_CLearDataBuffer();

	MUART_voidSendString((uint8*)SERVER_CONNECT_CMD_P1);
	MUART_voidSendString((uint8*)DOMAIN);
	MUART_voidSendString((uint8*)SERVER_CONNECT_CMD_P2);
	MUART_voidSendString((uint8*)PORT);
	MUART_voidSendString((uint8*)SERVER_CONNECT_CMD_P3);
	
//	if(HWIFI_CommandValidation() == NOT_OK)
//	{
//		HWIFI_CLearDataBuffer();
//
//		MUART_voidSendString((uint8*)SERVER_CONNECT_CMD_P1);
//		MUART_voidSendString((uint8*)DOMAIN);
//		MUART_voidSendString((uint8*)SERVER_CONNECT_CMD_P2);
//		MUART_voidSendString((uint8*)PORT);
//		MUART_voidSendString((uint8*)SERVER_CONNECT_CMD_P3);
//	}

	HWIFI_CLearDataBuffer();
	MSYS_TICK_voidSetBusyWait(1000000);
}

/**************************************************************************************************************************************
* Function Name		: HWIFI_VoidInit																				                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
void HWIFI_VoidSendHttpRequest(uint8 * Copy_uint8ServerLink, uint8 * Copy_uint8DataLenght)
{
	HWIFI_CLearDataBuffer();

	MUART_voidSendString((uint8*)HTTP_REQUEST_SEND_CMD_P1);
	MUART_voidSendString((uint8*)Copy_uint8DataLenght);
	MUART_voidSendString((uint8*)HTTP_REQUEST_SEND_CMD_P2);
	
//	while(HWIFI_CommandValidation() == NOT_OK)
//	{
//		HWIFI_CLearDataBuffer();
//
//		MUART_voidSendString((uint8*)HTTP_REQUEST_SEND_CMD_P1);
//		MUART_voidSendString((uint8*)Copy_uint8DataLenght);
//		MUART_voidSendString((uint8*)HTTP_REQUEST_SEND_CMD_P2);
//	}
	
	MSYS_TICK_voidSetBusyWait(200000);
	HWIFI_CLearDataBuffer();

	MUART_voidSendString((uint8*)"GET ");
	MUART_voidSendString((uint8*)Copy_uint8ServerLink);
	MUART_voidSendString((uint8*)"\r\n");
	MSYS_TICK_voidSetBusyWait(400000);
}

/**************************************************************************************************************************************
* Function Name		: HWIFI_VoidInit																				                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
void HWIFI_VoidReceiveRecord(uint8 Copy_uint8NetData[])
{
	uint8 Local_uint8LoopCounter = 0;
	uint8 Local_uint8FirstIndex = 0;

	while(Global_uint8RecordDataBuffer[Local_uint8LoopCounter] != ':')
	{
		Local_uint8LoopCounter++;
	}

	Local_uint8LoopCounter += 4;
	Local_uint8FirstIndex = Local_uint8LoopCounter;

	while((Global_uint8RecordDataBuffer[Local_uint8LoopCounter] != '\r') && (Global_uint8RecordDataBuffer[Local_uint8LoopCounter + 1] != '\n'))
	{
		Copy_uint8NetData[Local_uint8LoopCounter - Local_uint8FirstIndex] = Global_uint8RecordDataBuffer[Local_uint8LoopCounter];
		Local_uint8LoopCounter++;
	}
	
}

/**************************************************************************************************************************************
* Function Name		: HWIFI_VoidInit																				                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
static uint8 HWIFI_CommandValidation()
{


	uint8 Local_uint8LoopCounter = 0;
	
	while(Global_uint8Validation_Flag == NOT_OK)
	{
		for(Local_uint8LoopCounter = 0; Local_uint8LoopCounter < Global_uint8LoopCounter; Local_uint8LoopCounter++)
		{
			if (Global_uint8RecordDataBuffer[Local_uint8LoopCounter] == 'O' && Global_uint8RecordDataBuffer[(Local_uint8LoopCounter+1)] == 'K')
			{
				Global_uint8Validation_Flag = OK;
			}
		}
	}

		
	return Global_uint8Validation_Flag;
}

/**************************************************************************************************************************************
* Function Name		: HWIFI_CLearDataBuffer																			                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To 																				                      *
**************************************************************************************************************************************/
static void HWIFI_CLearDataBuffer()
{
	uint8 Local_uint8LoopCounter = 0;
	
	for(Local_uint8LoopCounter = 0; Local_uint8LoopCounter < RECORD_CHAR_NUM; Local_uint8LoopCounter++)
	{
		Global_uint8RecordDataBuffer[Local_uint8LoopCounter] = 0;
	}

	Global_uint8LoopCounter = 0;
	Global_uint8Validation_Flag = 0;
}

/**************************************************************************************************************************************
* Function Name		: HWIFI_CLearDataBuffer																			                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To 																				                      *
**************************************************************************************************************************************/
void MUART_ReceiveCBK_Func()
{

	Global_uint8RecordDataBuffer[ Global_uint8LoopCounter ] = MUART_voidReceiveByteAsync();

	Global_uint8LoopCounter++;
}

