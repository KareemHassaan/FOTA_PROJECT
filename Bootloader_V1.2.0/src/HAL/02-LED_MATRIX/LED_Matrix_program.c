/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						02 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: LED Matrix Driver                                                 							                      *
* ! File Name	: LED_MATRIX_program.c                                                      						                  *
* ! Description : This file has the implementation of Basic of LED Matrix functions using S2P    						              *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL	                  						                                         							  *
**************************************************************************************************************************************/

/**************************************************** Library Inclusions *************************************************************/
#include "../../include/LIB/STD_TYPES.h"
#include "../../include/LIB/BIT_MATH.h"
/************************************************** Lower Layer Inclusions ***********************************************************/
#include"../../include/MCAL/02-GPIO/GPIO_interface.h"
/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/
#include"../../include/HAL/02-LED_MATRIX/LED_Matrix_intrface.h"  
#include"../../include/HAL/02-LED_MATRIX/LED_Matrix_private.h"
#include"../../include/HAL/02-LED_MATRIX/LED_Matrix_config.h"

/***************************************************** Global Variables **************************************************************/


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: HLED_MATRIX_VoidInit																		                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize The LED Matrix Driver												                      *
**************************************************************************************************************************************/
void HLED_MATRIX_VoidInit()
{
	HS2P_VoidInit();
}

/**************************************************************************************************************************************
* Function Name		: HLED_MATRIX_VoidDisplayFrame																                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Display One Frame at a time													                      *
**************************************************************************************************************************************/
void HLED_MATRIX_VoidDisplayFrame(uint8 * Frame, uint8 Copy_uint8Frame_Size)
{
	uint32 Local_uint32LoopCounter = 0;
	
	for(Local_uint32LoopCounter = 0; Local_uint32LoopCounter < Copy_uint8Frame_Size; Local_uint32LoopCounter++)
	{
		
		/*Disable All Columns*/
		 Clear_All();
		
		/*Sending The Rows And Cols Data*/
		Set_Rows_Cols_Values(Frame[Local_uint32LoopCounter], Local_uint32LoopCounter);
		
		/*
			Delay For Frame Time 2.5 msec
			RCC -> HSE -> FCPU = 8 MHz
			Freq_AHB = 8 MHz -> /8 -> 1 MHz
			Tick_Time = 12.5 us , Tick_Time = 1 us
			
		*/
			MSYS_TICK_voidSetBusyWait(2500);
	}
}

/**************************************************************************************************************************************
* Function Name		: Clear_All																					                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Clear The Display (Registers)													                      *
**************************************************************************************************************************************/
static void Clear_All()
{
	HS2P_VoidSendData(0);
}

/**************************************************************************************************************************************
* Function Name		: Set_Rows_Cols_Values																		                      *
* Parameters (in)	: uint8 Copy_uint8Frame, uint8 Copy_uint8ColumnNum											                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Send The Rows Adn Cols Values To The S2P										                      *
**************************************************************************************************************************************/
static void Set_Rows_Cols_Values(uint8 Copy_uint8Frame, uint8 Copy_uint8ColumnNum)
{
	uint32 Local_uint32_S2P_Data = 0;
	
	Local_uint32_S2P_Data = Copy_uint8Frame;
	Local_uint32_S2P_Data = Local_uint32_S2P_Data << 8;
	
	SET_BIT(Local_uint32_S2P_Data, Copy_uint8ColumnNum);
	
	/*Send Data To S2P The Lowest Byte Is The Cols and The Most Byte Is Rows*/
	HS2P_VoidSendData(Local_uint32_S2P_Data);
}
