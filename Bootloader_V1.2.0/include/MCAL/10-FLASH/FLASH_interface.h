/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						02 MAR,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: FLASH Driver   			                                                 							              *
* ! File Name	: FLASH_intrface.h                        	                             							                  *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL	                  						                                         							  *
**************************************************************************************************************************************/

#ifndef MCAL_10_FLASH_FLASH_INTERFACE_H_
#define MCAL_10_FLASH_FLASH_INTERFACE_H_

/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: HWIFI_VoidInit																				                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
void MFLASH_voidAreaErase(void);
/**************************************************************************************************************************************
* Function Name		: HWIFI_VoidInit																				                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
void MFLASH_voidPageErase(uint8 Copy_uint8PageNum );
/**************************************************************************************************************************************
* Function Name		: HWIFI_VoidInit																				                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
void MFLASH_voidWrite(uint32 Copy_uint32Address, uint16 * Copy_uint16Data, uint8 Copy_uint8Length);


#endif /* MCAL_10_FLASH_FLASH_INTERFACE_H_ */
