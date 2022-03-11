/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						20 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Seven Segment Driver                                                 							                      *
* ! File Name	: SevenSeg_program.c                                                      						                      *
* ! Description : This file has the implementation of Basic of Seven Segment functions        							              *
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
#include"../../include/HAL/01-Seven_Segment/SevenSeg_intrface.h"  
#include"../../include/HAL/01-Seven_Segment/SevenSeg_private.h"
#include"../../include/HAL/01-Seven_Segment/SevenSeg_config.h"

/***************************************************** Global Variables **************************************************************/
static uint8 SevenSegmentArray[10] = SEVEN_SEG_ARRAY_VALUES;

/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: HSevenSegment_VoidInit																	                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Port Of The Seven Segment										                      *
**************************************************************************************************************************************/
void HSevenSegment_VoidInit()
{
	uint8 Local_uint8InitLoopCounter = 0;
	
	for(Local_uint8InitLoopCounter = SEVEN_SEGMENT_START_PIN; Local_uint8InitLoopCounter < (SEVEN_SEG_PINS_NUM + SEVEN_SEGMENT_START_PIN); Local_uint8InitLoopCounter++)
	{
		MGPIO_voidSetPinDirection(SEVEN_SEGMENT_PORT, Local_uint8InitLoopCounter, OUTPUT_MODE_MAX_SPEED_2_MHZ, GENERAL_PURPOSE_OUTPUT_PUSH_PULL);
	}
	
}

/**************************************************************************************************************************************
* Function Name		: HSevenSegment_VoidInit																	                      *
* Parameters (in)	: uint8 Copy_uint8Number																	                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Port Of The Seven Segment										                      *
**************************************************************************************************************************************/
void HSevenSegment_VoidDisplayNumber(uint8 Copy_uint8Number)
{
	#if(SEVEN_SEGMENT_TYPE == COMMON_ANODE)
		
			MGPIO_voidSetPortValue(SEVEN_SEGMENT_PORT, ~((SEVEN_SEG_MASK) << SEVEN_SEGMENT_START_PIN),\
									 (SevenSegmentArray[Copy_uint8Number] << SEVEN_SEGMENT_START_PIN));
			
	#elif(SEVEN_SEGMENT_TYPE == COMMON_CATHODE)
		
			MGPIO_voidSetPortValue(SEVEN_SEGMENT_PORT, ~((SEVEN_SEG_MASK) << SEVEN_SEGMENT_START_PIN),\
									(~SevenSegmentArray[Copy_uint8Number] << SEVEN_SEGMENT_START_PIN));
			
	#else
	
		#error"SEVEN_SEGMENT_TYPE Confogration Error"
	
	#endif	
}
