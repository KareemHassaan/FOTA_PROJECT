/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						28 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: SYS_TICK Driver                                                        							                  *
* ! File Name	: SYS_TICK_program.c                                                       							                  *
* ! Description : This file has the implementation of Basic of SYS_TICK functions        							                  *
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
#include"../../include/MCAL/05-SYS_TICK/SYS_TICK_interface.h"  
#include"../../include/MCAL/05-SYS_TICK/SYS_TICK_private.h"
#include"../../include/MCAL/05-SYS_TICK/SYS_TICK_config.h"

/***************************************************** Global Variables **************************************************************/
static void(*Sys_TickHandler)();												//Pointer To Function To Store the callback function
uint8 SinglePeriodicFlag = SINGLE;												//Flag to indicate single or periodic counter

/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MSYS_TICK_voidInit																			                  *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize all the Configration To the SysTick							          				  *
**************************************************************************************************************************************/
void MSYS_TICK_voidInit()
{
	/*Enable Or Disable Interrupts*/
	#if(SYS_TICK_INT_ENABLE == ENABLE)
		
		/*Enable The Interrupts*/
		SET_BIT(SYS_TICK -> STK_CTRL, SYS_TICK_INT_BIT);
		
	#elif(SYS_TICK_INT_ENABLE == DISABLE)
		
		/*Disable The Interrupts*/
		CLR_BIT(SYS_TICK -> STK_CTRL, SYS_TICK_INT_BIT);

	#else

		#error"SYS_TICK_INT_ENABLE Configration Error"

	#endif
	
	/*Configure The Prescaller*/
	#if(SYS_TICK_PRESCALLER	== CLK_AHB)
		
		/*Configure The Prescaller to be AHB CLK*/
		SET_BIT(SYS_TICK -> STK_CTRL, SYS_TICK_CLK_SOURCE);
		
	#elif(SYS_TICK_PRESCALLER	== CLK_AHB_DIVIDE_8)
		
		/*Configure The Prescaller to be AHB CLK / 8*/
		CLR_BIT(SYS_TICK -> STK_CTRL, SYS_TICK_CLK_SOURCE);
	#else

		#error"SYS_TICK_PRESCALLER Configration Error"

	#endif
}

/**************************************************************************************************************************************
* Function Name		: SYS_TICK_voidSetBusyWait																			              *
* Parameters (in)	: uint32 Copy_TickCount																			                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Set Busy Wait By Polling													          				  *
**************************************************************************************************************************************/
void MSYS_TICK_voidSetBusyWait(uint32 Copy_TickCount)
{
	/*Ensure That Previous Flage is Cleared*/
	SYS_TICK -> STK_VAL = 0;
	
	/*Set Load Register*/
	SYS_TICK -> STK_LOAD = Copy_TickCount;
	/*Enable Timer*/
	SET_BIT(SYS_TICK -> STK_CTRL, SYS_TICK_ENABLE);
	/*Busy Waiting Till Reaching the Tick Count*/
	while(GET_BIT(SYS_TICK -> STK_CTRL, SYS_TICK_COUNT_FLAG) == 0)
	{
		/*Busy Waiting*/
	}
	
	/*Set Value Register to Clear Flag*/
	SYS_TICK -> STK_VAL = 0;
	/*Set Load Register*/
	SYS_TICK -> STK_LOAD = 0;
	/*Disable Timer*/
	CLR_BIT(SYS_TICK -> STK_CTRL, SYS_TICK_ENABLE);
}

/**************************************************************************************************************************************
* Function Name		: MSYS_TICK_voidSetIntervalSingle															                      *
* Parameters (in)	: uint32 Copy_TickCount, void (*CBK_Func)()														                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Make An Action For A single Time				 							          				  *
**************************************************************************************************************************************/
void MSYS_TICK_voidSetIntervalSingle(uint32 Copy_TickCount, void (*CBK_Func)())
{
	/*Set Call Back Function*/
	Sys_TickHandler = CBK_Func;
	/*Ensure That Previous Flage is Cleared*/
	SYS_TICK -> STK_VAL = 0;
	
	/*Set Load Register*/
	SYS_TICK -> STK_LOAD = Copy_TickCount;
	/*Enable Timer*/
	SET_BIT(SYS_TICK -> STK_CTRL, SYS_TICK_ENABLE);
	
	/*Set the Flag To Be Single*/
	SinglePeriodicFlag = SINGLE;	
}

/**************************************************************************************************************************************
* Function Name		: MSYS_TICK_voidSetIntervalPeriodic															                      *
* Parameters (in)	: uint32 Copy_TickCount, void (*CBK_Func)()														                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Make An Action Periodic*						 							          				  *
**************************************************************************************************************************************/
void MSYS_TICK_voidSetIntervalPeriodic(uint32 Copy_TickCount, void (*CBK_Func)())
{
	/*Set Call Back Function*/
	Sys_TickHandler = CBK_Func;
	/*Ensure That Previous Flage is Cleared*/
	SYS_TICK -> STK_VAL = 0;
	
	/*Set Load Register*/
	SYS_TICK -> STK_LOAD = Copy_TickCount;
	/*Enable Timer*/
	SET_BIT(SYS_TICK -> STK_CTRL, SYS_TICK_ENABLE);
	
	/*Set the Flag To Be Periodic*/
	SinglePeriodicFlag = PERIODIC;
}

/**************************************************************************************************************************************
* Function Name		: MSYS_TICK_voidGetRemainingTime															                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: uint32 Remaining Time					  													    	              *
* Description		: Function To Get the Remaining Time													          				  *
**************************************************************************************************************************************/
uint32 MSYS_TICK_voidGetRemainingTime()
{
	/*Return Value Register*/
	return SYS_TICK -> STK_VAL;
}

/**************************************************************************************************************************************
* Function Name		: MSYS_TICK_voidGetElapsedTime																                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: uint32 Elapsed Time					  													    	              *
* Description		: Function To Get the Elapsed Time														          				  *
**************************************************************************************************************************************/
uint32 MSYS_TICK_voidGetElapsedTime()
{
	/*Return Value Register - Load Register*/
	return ((SYS_TICK -> STK_LOAD) - (SYS_TICK -> STK_VAL));
}

/**************************************************************************************************************************************
* Function Name		: MSYS_TICK_voidEnableInterrupt																                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Enable Interrupt					 										          				  *
**************************************************************************************************************************************/
void MSYS_TICK_voidEnableInterrupt()
{
	SET_BIT(SYS_TICK -> STK_CTRL, SYS_TICK_INT_ENABLE);
}

/**************************************************************************************************************************************
* Function Name		: MSYS_TICK_voidDisableInterrupt															                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Disable Interrupt					 										          				  *
**************************************************************************************************************************************/
void MSYS_TICK_voidDisableInterrupt()
{
	CLR_BIT(SYS_TICK -> STK_CTRL, SYS_TICK_INT_ENABLE);
}

/**************************************************************************************************************************************
* Function Name		: MSYS_TICK_voidStopTimer																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Disable The Timer															          				  *
**************************************************************************************************************************************/
void MSYS_TICK_voidStopTimer()
{
	/*Disable Timer*/
	CLR_BIT(SYS_TICK -> STK_CTRL, SYS_TICK_ENABLE);
	/*Reset Value Register to Clear Flag*/
	SYS_TICK -> STK_VAL = 0;
	/*Reset Load Register*/
	SYS_TICK -> STK_LOAD = 0;
}

/*************************************************************************************************************************************/
/******************************************************* SysTick Handler *************************************************************/
/*************************************************************************************************************************************/
void SysTick_Handler()
{
	if(Sys_TickHandler != NULL)
	{
		Sys_TickHandler();
	}
	
	if(SinglePeriodicFlag == SINGLE)
	{
		/*Disable Timer*/
		CLR_BIT(SYS_TICK -> STK_CTRL, SYS_TICK_ENABLE);
	}
	else
	{
		/*Periodic*/
	}
	
	/*Set Value Register to Clear Flag*/
	SYS_TICK -> STK_VAL = 0;
}










