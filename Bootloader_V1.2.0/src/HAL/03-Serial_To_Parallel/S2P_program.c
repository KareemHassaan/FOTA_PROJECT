/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						02 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Serial To Parallel Driver                                           							                      *
* ! File Name	: S2P_program.c                                   		                   						                      *
* ! Description : This file has the implementation of Basic of Serial To Parallel functions     						              *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL	                  						                                         							  *
**************************************************************************************************************************************/

/**************************************************** Library Inclusions *************************************************************/
#include "../../include/LIB/STD_TYPES.h"
#include "../../include/LIB/BIT_MATH.h"
/************************************************** Lower Layer Inclusions ***********************************************************/
#include"../../include/MCAL/02-GPIO/GPIO_interface.h"
#include"../../include/MCAL/05-SYS_TICK/SYS_TICK_interface.h"  
/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/
#include"../../include/HAL/03-Serial_To_Parallel/S2P_intrface.h"  
#include"../../include/HAL/03-Serial_To_Parallel/S2P_private.h"
#include"../../include/HAL/03-Serial_To_Parallel/S2P_config.h"

/***************************************************** Global Variables **************************************************************/


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: HS2P_VoidInit																				                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Serial To Parallel	Module							                      *
**************************************************************************************************************************************/
void HS2P_VoidInit()
{
	/*Initialize all The S2P Pins To Be Output*/
	MGPIO_voidSetPinDirection(S2P_PORT, S2P_SERIAL_OUTPUT_PIN, OUTPUT_MODE_MAX_SPEED_2_MHZ, GENERAL_PURPOSE_OUTPUT_PUSH_PULL);
	MGPIO_voidSetPinDirection(S2P_PORT, S2P_CLK_OUTPUT_PIN   , OUTPUT_MODE_MAX_SPEED_2_MHZ, GENERAL_PURPOSE_OUTPUT_PUSH_PULL);
	MGPIO_voidSetPinDirection(S2P_PORT, S2P_LATCH_OUTPUT_PIN , OUTPUT_MODE_MAX_SPEED_2_MHZ, GENERAL_PURPOSE_OUTPUT_PUSH_PULL);

	/*Initialize SYS_TICK*/
	MSYS_TICK_voidInit();
}

/**************************************************************************************************************************************
* Function Name		: HS2P_VoidSendData																			                      *
* Parameters (in)	: uint32 Copy_uint32Data																	                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Port Of The Serial To Parallel	Module							                      *
**************************************************************************************************************************************/
void HS2P_VoidSendData(uint32 Copy_uint32Data)
{
	uint8 Local_uint8LoopCounter = 0;
	
	/*make sure that SHIFT and LATCH are LOW */
	MGPIO_voidSetPinValue(S2P_PORT, S2P_CLK_OUTPUT_PIN, GPIO_LOW);
	MGPIO_voidSetPinValue(S2P_PORT, S2P_LATCH_OUTPUT_PIN, GPIO_LOW);
	
	/* 2- loop on all bits of data
	 * NOTE: 8 * NO_REGS
	 * */
	for(Local_uint8LoopCounter = 0; Local_uint8LoopCounter < (S2P_REGS_SIZE*S2P_REGS_NUM); Local_uint8LoopCounter++)
	{
		/*Get the i th bit and output the value of this bit on the SERIAL pin */
		MGPIO_voidSetPinValue(S2P_PORT, S2P_SERIAL_OUTPUT_PIN, GET_BIT(Copy_uint32Data,Local_uint8LoopCounter));
		/*send a clock pulse on SHIFT pin */
		ShiftData();
	}
	
	/*send a Latch pulse To Represent the Data On S2P Port*/
	LatchData();
}

/**************************************************************************************************************************************
* Function Name		: ShiftData																					                      *
* Parameters (in)	: uint32 Copy_uint32Data																	                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Set a Pulse On Clock Pin To Shift the Data To The S2P Port					                      *
**************************************************************************************************************************************/
static void ShiftData()
{
	/*Set the Clock Pin To Be High To Shift The Data*/
	MGPIO_voidSetPinValue(S2P_PORT, S2P_CLK_OUTPUT_PIN , GPIO_HIGH);
	
	/*Set Busy Wait*/
	MSYS_TICK_voidSetBusyWait(S2P_PULSE_TIME);
	
	/*Clear the Clock Pin To Be Low*/
	MGPIO_voidSetPinValue(S2P_PORT, S2P_CLK_OUTPUT_PIN , GPIO_LOW);
	
	/*Set Busy Wait*/
	MSYS_TICK_voidSetBusyWait(S2P_PULSE_TIME);
}

/**************************************************************************************************************************************
* Function Name		: LatchData																					                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Set a Pulse On Latch Pin To Represent the Data On S2P Port					                      *
**************************************************************************************************************************************/
static void LatchData()
{
	/*Set the Latch Pin To Be High To Shift The Data*/
	MGPIO_voidSetPinValue(S2P_PORT, S2P_CLK_OUTPUT_PIN , GPIO_HIGH);
	
	/*Set Busy Wait*/
	MSYS_TICK_voidSetBusyWait(S2P_PULSE_TIME);
	
	/*Clear the Latch Pin To Be Low*/
	MGPIO_voidSetPinValue(S2P_PORT, S2P_CLK_OUTPUT_PIN , GPIO_LOW);
	
	/*Set Busy Wait*/
	MSYS_TICK_voidSetBusyWait(S2P_PULSE_TIME);
}


