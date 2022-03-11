/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						13 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Infera Red Driver                                           							                     		  *
* ! File Name	: TFT_program.c                                   		                   						                      *
* ! Description : This file has the implementation of Basic of Infera Red functions  			   						              *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL	                  						                                         							  *
**************************************************************************************************************************************/

/**************************************************** Library Inclusions *************************************************************/
#include "../../include/LIB/STD_TYPES.h"
#include "../../include/LIB/BIT_MATH.h"
/************************************************** Lower Layer Inclusions ***********************************************************/
#include"../../include/MCAL/01-RCC/RCC_interface.h"
#include"../../include/MCAL/02-GPIO/GPIO_interface.h"
#include"../../include/MCAL/03-NVIC/NVIC_interface.h"
#include"../../include/MCAL/04-EXTI/EXTI_interface.h"
#include"../../include/MCAL/05-SYS_TICK/SYS_TICK_interface.h"  
#include"../../include/MCAL/06-AFIO/AFIO_interface.h"  
#include"../../include/MCAL/08-SPI/SPI_interface.h"  
/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/
#include"../../include/HAL/05-TFT/TFT_intrface.h"  
#include"../../include/HAL/05-TFT/TFT_private.h"
#include"../../include/HAL/05-TFT/TFT_config.h"

/***************************************************** Global Variables **************************************************************/


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: HTFT_VoidInit																				                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
void HTFT_voidInit()
{
	/*Init All GPIO Pins*/
	MGPIO_voidSetPinDirection(TFT_PORT, TFT_A0_PIN, OUTPUT_MODE_MAX_SPEED_2_MHZ, GENERAL_PURPOSE_OUTPUT_PUSH_PULL);
	MGPIO_voidSetPinDirection(TFT_PORT, TFT_RST_PIN,OUTPUT_MODE_MAX_SPEED_2_MHZ, GENERAL_PURPOSE_OUTPUT_PUSH_PULL);

	/*Init SPI*/
	MSPI_voidInit();
	/*Init SysTick*/
	 MSYS_TICK_voidInit();
	 
	/*Init TFT Itself*/
	HTFT_voidSendResetPulse();
	/*Send Sleep Out command */
	HTFT_voidWriteCMD(0x11);
	/*Delay for 15 ms to wakeup*/
	MSYS_TICK_voidSetBusyWait(15000);
	/*Set Color mode : RGB565 */
	HTFT_voidWriteCMD(0x3A);
	HTFT_voidWriteCMD(0x05);
	/*Send Display ON command */
	HTFT_voidWriteCMD(0x29);
	
}

/**************************************************************************************************************************************
* Function Name		: HTFT_VoidInit																				                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
void HTFT_voidShowImage(uint16 Copy_uint16Image[], uint32 Copy_uint32ImageSize)
{
	uint32 Local_uint32LoopCounter = 0;
	
	/*Set X Boundries*/
	HTFT_voidWriteCMD(0x2A);					// set column address

	HTFT_voidWriteDATA(0);				        // MSB->x start
	HTFT_voidWriteDATA(0);      		        // LSB->x start
	HTFT_voidWriteDATA(0);      		        // MSB->x end
	HTFT_voidWriteDATA(127);    		        // LSB->x end
	/*Set Y Boundries*/         		
	HTFT_voidWriteCMD(0x2B);					// set row address

	HTFT_voidWriteDATA(0);                      // MSB->y start
	HTFT_voidWriteDATA(0);                      // LSB->y start
	HTFT_voidWriteDATA(0);                      // MSB->y end
	HTFT_voidWriteDATA(159);                    // LSB->y end
	
	/*Send Pixel Color Data*/
	HTFT_voidWriteCMD(0x2C);
	
	for(Local_uint32LoopCounter = 0; Local_uint32LoopCounter < Copy_uint32ImageSize; Local_uint32LoopCounter++)
	{
		HTFT_voidWriteDATA((Copy_uint16Image[Local_uint32LoopCounter] >> 8));
		HTFT_voidWriteDATA((Copy_uint16Image[Local_uint32LoopCounter] & 0x00FF));
	}
}

/**************************************************************************************************************************************
* Function Name		: HTFT_VoidInit																				                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
void HTFT_voidDrawRectangle()
{
	
}

/**************************************************************************************************************************************
* Function Name		: HTFT_VoidInit																				                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
static void HTFT_voidWriteCMD(uint8 Copy_uint8CMD)
{
	/*Set Pin A0 To Low to Write Command*/
	MGPIO_voidSetPinValue(TFT_PORT, TFT_A0_PIN, GPIO_LOW);
	/*Send CMD With SPI*/
	MSPI_voidTranscieve(Copy_uint8CMD);
}

/**************************************************************************************************************************************
* Function Name		: HTFT_VoidInit																				                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
static void HTFT_voidWriteDATA(uint8 Copy_uint8DATA)
{
	/*Set Pin A0 To High to Write Data*/
	MGPIO_voidSetPinValue(TFT_PORT, TFT_A0_PIN, GPIO_HIGH);
	/*Send CMD With SPI*/
	MSPI_voidTranscieve(Copy_uint8DATA);
}

/**************************************************************************************************************************************
* Function Name		: HTFT_VoidInit																				                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
static void HTFT_voidSendResetPulse()
{
	/*
	 * Reset Sequence 
	 * HIGH -> 100 us
	 * LOW  ->   1 us
	 * HIGH -> 100 us
	 * LOW  -> 100 us
	 * HIGH -> 120 ms
	*/
	MGPIO_voidSetPinValue(TFT_PORT, TFT_RST_PIN, GPIO_HIGH);
	MSYS_TICK_voidSetBusyWait(100);
	
	MGPIO_voidSetPinValue(TFT_PORT, TFT_RST_PIN, GPIO_LOW);
	MSYS_TICK_voidSetBusyWait(1);
	
	MGPIO_voidSetPinValue(TFT_PORT, TFT_RST_PIN, GPIO_HIGH);
	MSYS_TICK_voidSetBusyWait(100);
	
	MGPIO_voidSetPinValue(TFT_PORT, TFT_RST_PIN, GPIO_LOW);
	MSYS_TICK_voidSetBusyWait(100);
	
	MGPIO_voidSetPinValue(TFT_PORT, TFT_RST_PIN, GPIO_HIGH);
	MSYS_TICK_voidSetBusyWait(120000);	
}



