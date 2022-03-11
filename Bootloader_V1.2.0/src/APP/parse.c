/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					FOTA team    						02 MAR,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Parse SWC                                           							                     		 	      *
* ! File Name	: parse.c                                   		                   						                      	  *
* ! Description : This file has the implementation of Basic of Tokenizer functions  			  						              *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL	                  						                                         							  *
**************************************************************************************************************************************/

#define FLASH_START_ADDRESS				0x08000000
#define BUFFER_SIZE						100

/**************************************************** Library Inclusions *************************************************************/
#include "../../include/LIB/BIT_MATH.h"
#include "../../include/LIB/STD_TYPES.h"
/************************************************** Lower Layer Inclusions ***********************************************************/
#include "../../include/MCAL/10-FLASH/FLASH_interface.h"
#include"../../include/MCAL/04-EXTI/EXTI_interface.h"
#include"../../include/MCAL/05-SYS_TICK/SYS_TICK_interface.h"
#include"../../include/HAL/06-WIFI/WIFI_intrface.h"
/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/

/***************************************************** Global Variables **************************************************************/
uint16 DataBuffer[BUFFER_SIZE] = {0};
uint32 Address = FLASH_START_ADDRESS;
uint8 Global_uint8HexStartFlag = 0;

/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: ASCIIToHex																				                      *
* Parameters (in)	: Copy_uint8Char																					              *
* Parameters (out)	: None																						                      *
* Return value		: uint8																						                      *
* Description		: Function To convert ASCII to Hex									                      						  *
**************************************************************************************************************************************/
uint8 ASCIIToHex(uint8 Copy_uint8Char)
{
	uint8 Result;
	if(Copy_uint8Char >= '0' && Copy_uint8Char <= '9')
	{
		Result = Copy_uint8Char - '0';
	}
	else
	{
		Result = Copy_uint8Char - '7';
	}
	return Result;
}

/**************************************************************************************************************************************
* Function Name		: ParseData																				                          *
* Parameters (in)	: None																						                      *
* Parameters (out)	: Copy_uint8RecordBuffer																	                      *
* Return value		: None																						                      *
* Description		: Function To parse data									                                                      *
**************************************************************************************************************************************/
void ParseData(uint8 * Copy_uint8RecordBuffer)
{
	uint8  Local_uint8CharCount   = 0;
	uint8  Local_uint8LoopCounter = 0;
	uint16 Local_uint16Data       = 0;

	/* Extracting the Character Count of Record*/
	 Local_uint8CharCount = (ASCIIToHex(Copy_uint8RecordBuffer[1]) * 16) + (ASCIIToHex(Copy_uint8RecordBuffer[2]));

	/* Make Sure the Lower Address are Cleared*/
	 Address = Address & 0xFFFF0000;
	 
	/* Extracting the Address  of Record*/
	 Address = Address |(ASCIIToHex(Copy_uint8RecordBuffer[3]) << 12)|
						(ASCIIToHex(Copy_uint8RecordBuffer[4]) << 8) |
						(ASCIIToHex(Copy_uint8RecordBuffer[5]) << 4) |
						(ASCIIToHex(Copy_uint8RecordBuffer[6]));

	/* Extracting the Data of Record*/
	for (Local_uint8LoopCounter = 0; Local_uint8LoopCounter < ((Local_uint8CharCount/2)); Local_uint8LoopCounter++)
	{
		Local_uint16Data = 	(ASCIIToHex(Copy_uint8RecordBuffer[(Local_uint8LoopCounter * 4) + 9]) << 4) |
							(ASCIIToHex(Copy_uint8RecordBuffer[(Local_uint8LoopCounter * 4) +10])) 		|
							(ASCIIToHex(Copy_uint8RecordBuffer[(Local_uint8LoopCounter * 4) +11]) << 12)|
							(ASCIIToHex(Copy_uint8RecordBuffer[(Local_uint8LoopCounter * 4) +12]) << 8);

		/* Assigning the Data int the Data Array*/
		DataBuffer[Local_uint8LoopCounter] =  Local_uint16Data;
	}
	
	/* Flashing the Data into the Application Section */
	MFLASH_voidWrite(Address, DataBuffer, (Local_uint8CharCount/2) );
}

/**************************************************************************************************************************************
* Function Name		: Parser_voidParseRecord																				          *
* Parameters (in)	: Copy_uint8RecordBuffer																                          *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To parse record								                                                          *
**************************************************************************************************************************************/
void Parser_voidParseRecord(uint8 * Copy_uint8RecordBuffer)
{

	switch(Copy_uint8RecordBuffer[8])
	{
		case '0' :

				if(Global_uint8HexStartFlag == 1)
				{
					ParseData(Copy_uint8RecordBuffer);
				}
				else
				{
					MSYS_TICK_voidSetBusyWait(2000000);
					HWIFI_voidConnectToServer();
					HWIFI_VoidSendHttpRequest((uint8*)"http://iti-nc.freevar.com/Recive.php?response=Reload", (uint8*)"58");
				}
		break;

		case '1' :

				MEXTI_VoidSetSWInterrupt(EXTI0);
		break;

		case '4' :

				Global_uint8HexStartFlag = 1;
		break;
	}
}
