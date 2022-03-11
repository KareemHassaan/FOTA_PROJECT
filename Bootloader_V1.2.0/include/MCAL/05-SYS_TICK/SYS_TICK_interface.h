/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						28 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: SYS_TICK Driver                                                        							                  *                     
* ! File Name	: SYS_TICK_intrface.h                                                     							                  *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef SYS_TICK_INTERFACE_H
#define SYS_TICK_INTERFACE_H


/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MSYS_TICK_voidInit																			                  *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize all the Configration To the SysTick							          				  *
**************************************************************************************************************************************/
void MSYS_TICK_voidInit();
/**************************************************************************************************************************************
* Function Name		: SYS_TICK_voidSetBusyWait																			              *
* Parameters (in)	: uint32 Copy_TickCount																			                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Set Busy Wait By Polling													          				  *
**************************************************************************************************************************************/
void MSYS_TICK_voidSetBusyWait(uint32 Copy_TickCount);
/**************************************************************************************************************************************
* Function Name		: MSYS_TICK_voidSetIntervalSingle															                      *
* Parameters (in)	: uint32 Copy_TickCount, void (*CBK_Func)()														                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Make An Action For A single Time				 							          				  *
**************************************************************************************************************************************/
void MSYS_TICK_voidSetIntervalSingle(uint32 Copy_TickCount, void (*CBK_Func)());
/**************************************************************************************************************************************
* Function Name		: MSYS_TICK_voidSetIntervalPeriodic															                      *
* Parameters (in)	: uint32 Copy_TickCount, void (*CBK_Func)()														                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Make An Action Periodic*						 							          				  *
**************************************************************************************************************************************/
void MSYS_TICK_voidSetIntervalPeriodic(uint32 Copy_TickCount, void (*CBK_Func)());
/**************************************************************************************************************************************
* Function Name		: MSYS_TICK_voidGetRemainingTime															                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: uint32 Remaining Time					  													    	              *
* Description		: Function To Get the Remaining Time													          				  *
**************************************************************************************************************************************/
uint32 MSYS_TICK_voidGetRemainingTime();
/**************************************************************************************************************************************
* Function Name		: MSYS_TICK_voidGetElapsedTime																                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: uint32 Elapsed Time					  													    	              *
* Description		: Function To Get the Elapsed Time														          				  *
**************************************************************************************************************************************/
uint32 MSYS_TICK_voidGetElapsedTime();
/**************************************************************************************************************************************
* Function Name		: MSYS_TICK_voidEnableInterrupt																                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Enable Interrupt					 										          				  *
**************************************************************************************************************************************/
void MSYS_TICK_voidEnableInterrupt();
/**************************************************************************************************************************************
* Function Name		: MSYS_TICK_voidDisableInterrupt															                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Disable Interrupt					 										          				  *
**************************************************************************************************************************************/
void MSYS_TICK_voidDisableInterrupt();
/**************************************************************************************************************************************
* Function Name		: MSYS_TICK_voidStopTimer																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Disable The Timer															          				  *
**************************************************************************************************************************************/
void MSYS_TICK_voidStopTimer();

#endif /*SYS_TICK_INTERFACE_H*/