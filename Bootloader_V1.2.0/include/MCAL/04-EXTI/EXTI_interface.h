/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						26 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: EXTI Driver                                                        							                      *                     
* ! File Name	: EXTI_intrface.h                                                     							                      *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

typedef enum 
{
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	EXTI5,
	EXTI6,
	EXTI7,
	EXTI8,
	EXTI9,
	EXTI10,
	EXTI11,
	EXTI12,
	EXTI13,
	EXTI14,
	EXTI15
}EXTI_line;

typedef enum
{
	EXTI_RISING,
	EXTI_FALLING,
	EXTI_ONCHANGE
	
}EXTI_trigger;


/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MEXTI_voidInit																			                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To 									 										          				  *
**************************************************************************************************************************************/
void MEXTI_VoidInit();
/**************************************************************************************************************************************
* Function Name		: MEXTI_VoidEnableLine																		                      *
* Parameters (in)	: EXTI_line Copy_LineNum																		                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Enable EXTI Bit					 										          				  *
**************************************************************************************************************************************/
void MEXTI_VoidEnableLine(EXTI_line Copy_LineNum);
/**************************************************************************************************************************************
* Function Name		: MEXTI_VoidDisableLine																		                      *
* Parameters (in)	: EXTI_line Copy_LineNum																		                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Disable EXTI Bit					 										          				  *
**************************************************************************************************************************************/
void MEXTI_VoidDisableLine(EXTI_line Copy_LineNum);
/**************************************************************************************************************************************
* Function Name		: MEXTI_VoidSetLineTrigger																	                      *
* Parameters (in)	: EXTI_line Copy_LineNum,EXTI_trigger Copy_Trigger												                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Set the trigger Of the EXTI									 			          				  *
**************************************************************************************************************************************/
void MEXTI_VoidSetLineTrigger(EXTI_line Copy_LineNum,EXTI_trigger Copy_Trigger);
/**************************************************************************************************************************************
* Function Name		: MEXTI_VoidSetSWInterrupt																	                      *
* Parameters (in)	: EXTI_line Copy_LineNum																		                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Set Software Interrupt									 				          				  *
**************************************************************************************************************************************/
void MEXTI_VoidSetSWInterrupt(EXTI_line Copy_LineNum);
/**************************************************************************************************************************************
* Function Name		: MEXTI_voidInit																			                      *
* Parameters (in)	: EXTI_line Copy_LineNum, void (*CBKPtrFunc)()													                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Set the Call Back Function to each EXTI									          				  *
**************************************************************************************************************************************/ 
void EXTI_vidsetCallBack(EXTI_line Copy_LineNum, void (*CBKPtrFunc)());

#endif /*EXTI_INTERFACE_H*/