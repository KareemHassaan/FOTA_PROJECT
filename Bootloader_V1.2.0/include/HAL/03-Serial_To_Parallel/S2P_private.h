/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						02 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Serial To Parallel Driver                                                    							              *
* ! File Name	: S2P_private.h                                   		                  							                  *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL                  						                                         							      *
**************************************************************************************************************************************/
#ifndef S2P_PRIVATE_H
#define S2P_PRIVATE_H

/*************************************************************************************************************************************/
/********************************************** Static Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: ShiftData																					                      *
* Parameters (in)	: uint32 Copy_uint32Data																	                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Set a Pulse On Clock Pin To Shift the Data To The S2P Port					                      *
**************************************************************************************************************************************/
static void ShiftData();
/**************************************************************************************************************************************
* Function Name		: LatchData																					                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Set a Pulse On Latch Pin To Represent the Data On S2P Port					                      *
**************************************************************************************************************************************/
static void LatchData();


#endif /*S2P_PRIVATE_H*/