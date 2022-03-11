/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						03 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Infera Red Driver                                           							                     		  *
* ! File Name	: IR_program.c                                   		                   						                      *
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
/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/
#include"../../include/HAL/04-Infera_Red/IR_intrface.h"  
#include"../../include/HAL/04-Infera_Red/IR_private.h"
#include"../../include/HAL/04-Infera_Red/IR_config.h"

/***************************************************** Global Variables **************************************************************/
static volatile  uint16 Global_uint16FrameArray[FRAME_LENGHT] = {0};
static volatile  uint8  Global_uint8StartFlag = 0;
static volatile  uint8  Global_uint8EdgeCounter = 0;
uint8  HIR_uint8DataRecieved = 0;

/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: HIR_VoidInit																				                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
void HIR_VoidInit()
{
	/*	
		- Initialize The RCC Module
		- Enable The Clock To The GPIO Peripheral
	*/
		MRCC_voidInit();
		MRCC_voidSetPeripheralClock(APB2, AFIOEN, CLK_ENABLE);
	
	/*
		- Check Which Port Selected To The IR
		- Enable The Clock To The AFIO Of That Port 
		- Enable The AFIO For The Selected Pin in That Port
	*/
		#if(IR_PORT == GPIO_PORTA)
			
			MRCC_voidSetPeripheralClock(APB2, IOPA, CLK_ENABLE);
			MAFIO_voidAFExternalInterruptEnable(AFIO_PORTA, IR_PIN);
			
		#elif(IR_PORT == GPIO_PORTB)
			
			MRCC_voidSetPeripheralClock(ABP2, IOPB, CLK_ENABLE);
			MAFIO_voidAFExternalInterruptEnable(AFIO_PORTB, IR_PIN);
			
		#elif(IR_PORT == GPIO_PORTC)
			
			MRCC_voidSetPeripheralClock(ABP2, IOBC, CLK_ENABLE);
			MAFIO_voidAFExternalInterruptEnable(AFIO_PORTC, IR_PIN);
			
		#else
			
			#error" IR_PORT Configration Error"
		#endif
	
	/*Configure the Selected Pin For The IR To Be Input Pulled Up*/
	 MGPIO_voidSetPinDirection(IR_PORT, IR_PIN, INPUT_MODE, INPUT_PULL_UP_PULL_DOWN);
	 MGPIO_voidSetPinValue(IR_PORT, IR_PIN, GPIO_HIGH);
	
	/*
		- Initialize The EXTI
		- Enable The EXTI For The Selected Pin
		- Set the Trigger to Falling Edge
		- Set the CallBack Function To The Selected EXTI\
	*/
		MEXTI_VoidInit();
		MEXTI_VoidEnableLine(IR_PIN);
		MEXTI_VoidSetLineTrigger(IR_PIN, EXTI_FALLING);
		EXTI_vidsetCallBack(IR_PIN, HIR_GetFrame);
	
	/*Enable The Selected Interrupt In the NVIC*/
	 MNVIC_voidEnableInterrupt(InterruptNumArray[IR_PIN]);
	

	/*Initialize SYS_TICK*/
	MSYS_TICK_voidInit();
}

/**************************************************************************************************************************************
* Function Name		: HIR_GetFrame																				                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Get A Single Frame															                      *
**************************************************************************************************************************************/
static void HIR_GetFrame()
{
	/*Check If this Falling Edge Is the Start Of the Frame or Not*/
	 if(Global_uint8StartFlag == 0)
	 {
		/*Start The Timer To Count From The Start Edge*/
		 MSYS_TICK_voidSetIntervalPeriodic(Timer_Ticks, HIR_ReadFrame);
		/*Fire the Start of Frame Flag*/
		 Global_uint8StartFlag = 1;
	 }
	else
	{
		/*Store the Timer Value as it is the Time Of the Current Bit 0 -> 1125, 1 -> 2250*/
		 Global_uint16FrameArray[Global_uint8EdgeCounter] = MSYS_TICK_voidGetElapsedTime();
		/*Start the Timer Again To Count the time of Another Bit*/
		 MSYS_TICK_voidSetIntervalPeriodic(Timer_Ticks, HIR_ReadFrame);
		/*Increment The Counter of The Falling Edges or Bits*/
		 Global_uint8EdgeCounter++;
	}
}

/**************************************************************************************************************************************
* Function Name		: HIR_ReadFrame																				                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Get The Data From The Frame													                      *
**************************************************************************************************************************************/
static void HIR_ReadFrame()
{
	uint32 Local_uint32LoopCounter = 0;
	
	/*Looping in the Fram From Bit 17 To Bit 25 to Get the Data only From the Frame*/
	 for(Local_uint32LoopCounter = 0; Local_uint32LoopCounter < 8; Local_uint32LoopCounter++ )
	 {
		/*
			- Checking if the Bit HIGH Or LOW
			- If 1125 Then it is LOW
			- If 2250 Then it is HIGH
			- With margin of Error
		
		*/
		 if( (HIGH_MIN_VALUE < Global_uint16FrameArray[DATA_START + Local_uint32LoopCounter]) && (Global_uint16FrameArray[DATA_START + Local_uint32LoopCounter] < HIGH_MAX_VALUE))
		 {
			 SET_BIT(HIR_uint8DataRecieved, Local_uint32LoopCounter);
		 }
		 else
		 {
			 CLR_BIT(HIR_uint8DataRecieved,Local_uint32LoopCounter);
		 }
	 } 
	
	/*Clear Start Flage And Edge or Bit Counter To Recieve a New Frame*/
	 Global_uint8StartFlag = 0;
	 Global_uint8EdgeCounter = 0;
	
}
