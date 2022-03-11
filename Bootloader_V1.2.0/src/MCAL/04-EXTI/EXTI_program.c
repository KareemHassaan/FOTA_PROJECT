/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						26 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: EXTI Driver                                                        							                      *
* ! File Name	: EXTI_program.c                                                       							                      *
* ! Description : This file has the implementation of Basic of EXTI functions        							                      *
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
#include"../../include/MCAL/04-EXTI/EXTI_interface.h"  
#include"../../include/MCAL/04-EXTI/EXTI_private.h"
#include"../../include/MCAL/04-EXTI/EXTI_config.h"

/***************************************************** Global Variables **************************************************************/
static void (* CBK_PtrFunctionsArray[EXTI_NUM])();

/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MEXTI_voidInit																			                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To 									 										          				  *
**************************************************************************************************************************************/
void MEXTI_VoidInit()
{
	EXTI -> EXTI_IMR |= ((EXTI_LINE0_EN << EXTI0)   | (EXTI_LINE1_EN << EXTI1)   | (EXTI_LINE2_EN << EXTI2)   | (EXTI_LINE3_EN << EXTI3)   |\
				  	     (EXTI_LINE4_EN << EXTI4)   | (EXTI_LINE5_EN << EXTI5)   | (EXTI_LINE6_EN << EXTI6)   | (EXTI_LINE7_EN << EXTI7)   |\
						 (EXTI_LINE8_EN << EXTI8)   | (EXTI_LINE9_EN << EXTI9)   | (EXTI_LINE10_EN << EXTI10) | (EXTI_LINE11_EN << EXTI11) |\
						 (EXTI_LINE12_EN << EXTI12) | (EXTI_LINE13_EN << EXTI13) | (EXTI_LINE14_EN << EXTI14) | (EXTI_LINE15_EN << EXTI15) );
				  
	/* clear Pending flag registers
	 * before any execution */
	 
		EXTI -> EXTI_PR = 0xFFFFFFFF;
}
/**************************************************************************************************************************************
* Function Name		: MEXTI_VoidEnableLine																		                      *
* Parameters (in)	: EXTI_line Copy_LineNum																		                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Enable EXTI Bit					 										          				  *
**************************************************************************************************************************************/
void MEXTI_VoidEnableLine(EXTI_line Copy_LineNum)
{
	SET_BIT(EXTI -> EXTI_IMR, Copy_LineNum);	
}
/**************************************************************************************************************************************
* Function Name		: MEXTI_VoidDisableLine																		                      *
* Parameters (in)	: EXTI_line Copy_LineNum																		                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Disable EXTI Bit					 										          				  *
**************************************************************************************************************************************/
void MEXTI_VoidDisableLine(EXTI_line Copy_LineNum)
{
	CLR_BIT(EXTI -> EXTI_IMR, Copy_LineNum);
}
/**************************************************************************************************************************************
* Function Name		: MEXTI_VoidSetLineTrigger																	                      *
* Parameters (in)	: EXTI_line Copy_LineNum,EXTI_trigger Copy_Trigger												                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Set the trigger Of the EXTI									 			          				  *
**************************************************************************************************************************************/
void MEXTI_VoidSetLineTrigger(EXTI_line Copy_LineNum,EXTI_trigger Copy_Trigger)
{
	switch(Copy_Trigger)
	{
		case EXTI_RISING:
		
				SET_BIT(EXTI -> EXTI_RTSR, Copy_LineNum);
				CLR_BIT(EXTI -> EXTI_FTSR, Copy_LineNum);	
		break;
		
		case EXTI_FALLING:
		
				CLR_BIT(EXTI -> EXTI_RTSR, Copy_LineNum);
				SET_BIT(EXTI -> EXTI_FTSR, Copy_LineNum);					
		break;
		
		case EXTI_ONCHANGE:
		
				SET_BIT(EXTI -> EXTI_RTSR, Copy_LineNum);
				SET_BIT(EXTI -> EXTI_FTSR, Copy_LineNum);		
		break;
		
		default:
		
				/*ERROR*/
		break;
	}
}
/**************************************************************************************************************************************
* Function Name		: MEXTI_VoidSetSWInterrupt																	                      *
* Parameters (in)	: EXTI_line Copy_LineNum																		                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Set Software Interrupt									 				          				  *
**************************************************************************************************************************************/
void MEXTI_VoidSetSWInterrupt(EXTI_line Copy_LineNum)
{
	SET_BIT(EXTI -> EXTI_SWIER, Copy_LineNum);	
}
/**************************************************************************************************************************************
* Function Name		: MEXTI_voidInit																			                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Set the Call Back Function to each EXTI									          				  *
**************************************************************************************************************************************/ 
void EXTI_vidsetCallBack(EXTI_line Copy_LineNum, void (*CBKPtrFunc)())
{
	switch(Copy_LineNum)
	{
		case EXTI0  : CBK_PtrFunctionsArray[EXTI0]  = CBKPtrFunc; break;
		case EXTI1  : CBK_PtrFunctionsArray[EXTI1]  = CBKPtrFunc; break;
		case EXTI2  : CBK_PtrFunctionsArray[EXTI2]  = CBKPtrFunc; break;
		case EXTI3  : CBK_PtrFunctionsArray[EXTI3]  = CBKPtrFunc; break;
		case EXTI4  : CBK_PtrFunctionsArray[EXTI4]  = CBKPtrFunc; break;
		case EXTI5  : CBK_PtrFunctionsArray[EXTI5]  = CBKPtrFunc; break;
		case EXTI6  : CBK_PtrFunctionsArray[EXTI6]  = CBKPtrFunc; break;
		case EXTI7  : CBK_PtrFunctionsArray[EXTI7]  = CBKPtrFunc; break;
		case EXTI8  : CBK_PtrFunctionsArray[EXTI8]  = CBKPtrFunc; break;
		case EXTI9  : CBK_PtrFunctionsArray[EXTI9]  = CBKPtrFunc; break;
		case EXTI10 : CBK_PtrFunctionsArray[EXTI10] = CBKPtrFunc; break;
		case EXTI11 : CBK_PtrFunctionsArray[EXTI11] = CBKPtrFunc; break;
		case EXTI12 : CBK_PtrFunctionsArray[EXTI12] = CBKPtrFunc; break;
		case EXTI13 : CBK_PtrFunctionsArray[EXTI13] = CBKPtrFunc; break;
		case EXTI14 : CBK_PtrFunctionsArray[EXTI14] = CBKPtrFunc; break;
		case EXTI15 : CBK_PtrFunctionsArray[EXTI15] = CBKPtrFunc; break;
		default		: /*ERROR*/									  break;
	}
}

/*************************************************************************************************************************************/
/******************************************************** EXTI 0 HANDLER *************************************************************/
/*************************************************************************************************************************************/
void EXTI0_IRQHandler()
{
	if(CBK_PtrFunctionsArray[EXTI0] != NULL)
	{
		(CBK_PtrFunctionsArray[EXTI0])();
	}

	SET_BIT(EXTI -> EXTI_PR, EXTI0);
}

/*************************************************************************************************************************************/
/******************************************************** EXTI 1 HANDLER *************************************************************/
/*************************************************************************************************************************************/
void EXTI1_IRQHandler()
{
	if(CBK_PtrFunctionsArray[EXTI1] != NULL)
	{
		(CBK_PtrFunctionsArray[EXTI1])();
	}

	SET_BIT(EXTI -> EXTI_PR, EXTI1);
}

/*************************************************************************************************************************************/
/******************************************************** EXTI 2 HANDLER *************************************************************/
/*************************************************************************************************************************************/
void EXTI2_IRQHandler()
{
	if(CBK_PtrFunctionsArray[EXTI2] != NULL)
	{
		(CBK_PtrFunctionsArray[EXTI2])();
	}

	SET_BIT(EXTI -> EXTI_PR, EXTI2);
}

/*************************************************************************************************************************************/
/******************************************************** EXTI 3 HANDLER *************************************************************/
/*************************************************************************************************************************************/
void EXTI3_IRQHandler()
{
	if(CBK_PtrFunctionsArray[EXTI3] != NULL)
	{
		(CBK_PtrFunctionsArray[EXTI3])();
	}

	SET_BIT(EXTI -> EXTI_PR, EXTI3);
}

/*************************************************************************************************************************************/
/******************************************************** EXTI 4 HANDLER *************************************************************/
/*************************************************************************************************************************************/
void EXTI4_IRQHandler()
{
	if(CBK_PtrFunctionsArray[EXTI4] != NULL)
	{
		(CBK_PtrFunctionsArray[EXTI4])();
	}

	SET_BIT(EXTI-> EXTI_PR, EXTI4);
}

/*************************************************************************************************************************************/
/******************************************************** EXTI 5_9 HANDLER ***********************************************************/
/*************************************************************************************************************************************/
void EXTI9_5_IRQHandler()
{
	/*EXTI 5 Handler*/
	if(GET_BIT(EXTI -> EXTI_PR, EXTI5))
	{
		if(CBK_PtrFunctionsArray[EXTI5] != NULL)
		{
			(CBK_PtrFunctionsArray[EXTI5])();
		}

		SET_BIT(EXTI -> EXTI_PR, EXTI5);	
	}
	
	/*EXTI 6 Handler*/
	if(GET_BIT(EXTI -> EXTI_PR, EXTI6))
	{
		if(CBK_PtrFunctionsArray[EXTI6] != NULL)
		{
			(CBK_PtrFunctionsArray[EXTI6])();
		}

		SET_BIT(EXTI -> EXTI_PR, EXTI6);	
	}
	
	/*EXTI 7 Handler*/
	if(GET_BIT(EXTI -> EXTI_PR, EXTI7))
	{
		if(CBK_PtrFunctionsArray[EXTI7] != NULL)
		{
			(CBK_PtrFunctionsArray[EXTI7])();
		}

		SET_BIT(EXTI -> EXTI_PR, EXTI7);	
	}
	
	/*EXTI 8 Handler*/
	if(GET_BIT(EXTI -> EXTI_PR, EXTI8))
	{
		if(CBK_PtrFunctionsArray[EXTI8] != NULL)
		{
			(CBK_PtrFunctionsArray[EXTI8])();
		}

		SET_BIT(EXTI -> EXTI_PR, EXTI8);	
	}
	
	/*EXTI 9 Handler*/
	if(GET_BIT(EXTI -> EXTI_PR, EXTI9))
	{
		if(CBK_PtrFunctionsArray[EXTI9] != NULL)
		{
			(CBK_PtrFunctionsArray[EXTI9])();
		}

		SET_BIT(EXTI -> EXTI_PR, EXTI9);	
	}
	
}

/*************************************************************************************************************************************/
/******************************************************* EXTI 10_15 HANDLER **********************************************************/
/*************************************************************************************************************************************/
void EXTI15_10_IRQHandler()
{
	/*EXTI 10 Handler*/
	if(GET_BIT(EXTI -> EXTI_PR, EXTI10))
	{
		if(CBK_PtrFunctionsArray[EXTI10] != NULL)
		{
			(CBK_PtrFunctionsArray[EXTI10])();
		}

		SET_BIT(EXTI -> EXTI_PR, EXTI10);	
	}
	
	/*EXTI 11 Handler*/
	if(GET_BIT(EXTI -> EXTI_PR, EXTI11))
	{
		if(CBK_PtrFunctionsArray[EXTI11] != NULL)
		{
			(CBK_PtrFunctionsArray[EXTI11])();
		}

		SET_BIT(EXTI -> EXTI_PR, EXTI11);	
	}
	
	/*EXTI 12 Handler*/
	if(GET_BIT(EXTI -> EXTI_PR, EXTI12))
	{
		if(CBK_PtrFunctionsArray[EXTI12] != NULL)
		{
			(CBK_PtrFunctionsArray[EXTI12])();
		}

		SET_BIT(EXTI -> EXTI_PR, EXTI12);	
	}
	
	/*EXTI 13 Handler*/
	if(GET_BIT(EXTI -> EXTI_PR, EXTI13))
	{
		if(CBK_PtrFunctionsArray[EXTI13] != NULL)
		{
			(CBK_PtrFunctionsArray[EXTI13])();
		}

		SET_BIT(EXTI -> EXTI_PR, EXTI13);	
	}
	
	/*EXTI 14 Handler*/
	if(GET_BIT(EXTI -> EXTI_PR, EXTI14))
	{
		if(CBK_PtrFunctionsArray[EXTI14] != NULL)
		{
			(CBK_PtrFunctionsArray[EXTI14])();
		}

		SET_BIT(EXTI -> EXTI_PR, EXTI14);	
	}
	
	/*EXTI 15 Handler*/
	if(GET_BIT(EXTI -> EXTI_PR, EXTI15))
	{
		if(CBK_PtrFunctionsArray[EXTI15] != NULL)
		{
			(CBK_PtrFunctionsArray[EXTI15])();
		}

		SET_BIT(EXTI -> EXTI_PR, EXTI15);	
	}
}
