/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						01 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: AFIO Driver                                                        							                      *
* ! File Name	: AFIO_program.c                                                       							                      *
* ! Description : This file has the implementation of Basic of AFIO functions        							                      *
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
#include"../../include/MCAL/06-AFIO/AFIO_interface.h"  
#include"../../include/MCAL/06-AFIO/AFIO_private.h"
#include"../../include/MCAL/06-AFIO/AFIO_config.h"

/***************************************************** Global Variables **************************************************************/


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MAFIO_voidEventEnable																	                      	  *
* Parameters (in)	: uint8 Copy_uint8PortNum, uint8 Copy_uint8PinNum												                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Enable AFIO For Event Out		 										          					  *
**************************************************************************************************************************************/
void MAFIO_voidEventEnable(uint8 Copy_uint8PortNum, uint8 Copy_uint8PinNum)
{
	/*
		Set the EVENTOUT Cortex® output is connected to the I/O selected by the PORT[2:0] and PIN[3:0] bits.
		and Choosing the Port and Pin Needed
	*/
		AFIO -> AFIO_EVCR = ((1 << AFIO_EVOE)|(Copy_uint8PortNum << AFIO_PIN4)|(Copy_uint8PinNum));
	
	
}

/**************************************************************************************************************************************
* Function Name		: MAFIO_voidAFExternalInterruptEnable																	          *
* Parameters (in)	: uint8 Copy_uint8PortNum, uint8 Copy_uint8_EXTI_Num											                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Enable AFIO For EXTI 			 										          					  *
**************************************************************************************************************************************/
void MAFIO_voidAFExternalInterruptEnable(uint8 Copy_uint8PortNum, uint8 Copy_uint8_EXTI_Num)
{
	/*
		Picking the Wanted Register by Divide the EXTI Num by REGS Num (4) and then assign to
		Port Num Wanted Shifted by the Number of the bits of the EXTI (Each Reg 4 EXTI and Each EXTI 4 Bits)
	*/
	AFIO -> AFIO_EXTICR[Copy_uint8_EXTI_Num / AFIO_EXTI_REGS_NUM] =\
						(Copy_uint8PortNum << (Copy_uint8_EXTI_Num % AFIO_EXTI_NUM_IN_REG) * AFIO_BITS_NUM_IN_EXTI);
}

/**************************************************************************************************************************************
* Function Name		: MAFIO_voidAFExternalInterruptEnable																	          *
* Parameters (in)	: uint8 Copy_uint8PeripheralName, uint8 Copy_uint8Status										                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Enable AFIO For Peripherals 	 										          					  *
**************************************************************************************************************************************/
void MAFIO_voidAFPeripheralsEnable(uint8 Copy_uint8PeripheralName, uint8 Copy_uint8Status)
{
	/*Checking if the Peripheral is in MAPR1*/
	if(Copy_uint8PeripheralName < AFIO_MAPR_1)
	{
		switch(Copy_uint8PeripheralName)
		{
			case AFIO_USART3:
					
					switch(Copy_uint8Status)
					{
						case NO_REMAP:
						
								/*Making the Pins To be Normal Input/Output by setting the bits to (00)*/
								CLR_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								CLR_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
						break;
						
						case REMAP:
							
								/*Making the Pins To be Alternative Function Input/Output by setting the bits to (11)*/
								SET_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								SET_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
						break;
						
						case PARTIAL_REMAP:
							
								/*Making the Pins To be Partial Alternative Function Input/Output by setting the bits to (01)*/
								SET_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								CLR_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
						break;
						
						default :
						
								/*ERROR*/
						break;
					}
			break;
			
			case AFIO_TIM1:
			
					switch(Copy_uint8Status)
					{
						case NO_REMAP:
						
								/*Making the Pins To be Normal Input/Output by setting the bits to (00)*/
								CLR_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								CLR_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
						break;
						
						case REMAP:
								
								/*Making the Pins To be Alternative Function Input/Output by setting the bits to (11)*/
								SET_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								SET_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
						break;
						
						case PARTIAL_REMAP:
						
								/*Making the Pins To be Partial Alternative Function Input/Output by setting the bits to (01)*/
								SET_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								CLR_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
						break;
						
						default :
						
								/*ERROR*/
						break;
					}
			break;
			
			case AFIO_TIM2:
			
					switch(Copy_uint8Status)
					{
						case NO_REMAP:
						
								/*Making the Pins To be Normal Input/Output by setting the bits to (00)*/
								CLR_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								CLR_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
						break;
						
						case REMAP:
						
								/*Making the Pins To be Alternative Function Input/Output by setting the bits to (11)*/
								SET_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								SET_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
						break;
						
						case PARTIAL_REMAP:
						
								/*Making the Pins To be Partial Alternative Function Input/Output by setting the bits to (01)*/
								SET_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								CLR_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
						break;
						
						case SECOND_PARTIAL_REMAP:
						
								/*Making the Pins To be Partial Alternative Function Input/Output by setting the bits to (10)*/
								CLR_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								SET_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
						break;
						
						default :
						
								/*ERROR*/
						break;
					}
			break;
			
			case AFIO_TIM3:
			
					switch(Copy_uint8Status)
					{
						case NO_REMAP:
						
								/*Making the Pins To be Normal Input/Output by setting the bits to (00)*/
								CLR_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								CLR_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
						break;
						
						case REMAP:
								
								/*Making the Pins To be Alternative Function Input/Output by setting the bits to (11)*/
								SET_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								SET_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
						break;
						
						case PARTIAL_REMAP:
						
								/*Making the Pins To be Partial Alternative Function Input/Output by setting the bits to (10)*/
								CLR_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								SET_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
						break;
						
						default :
						
								/*ERROR*/
						break;
					}
			break;
			
			case AFIO_CAN:
			
					switch(Copy_uint8Status)
					{
						case NO_REMAP:
						
								/*Making the Pins To be Normal Input/Output by setting the bits to (00)*/
								CLR_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								CLR_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
						break;
						
						case REMAP:
						
								/*Making the Pins To be Alternative Function Input/Output by setting the bits to (11)*/
								SET_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								SET_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
						break;
						
						case PARTIAL_REMAP:
								
								/*Making the Pins To be Partial Alternative Function Input/Output by setting the bits to (10)*/
								CLR_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								SET_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
						break;
						
						default :
						
								/*ERROR*/
						break;
					}
			break;
			
			case AFIO_SWJ_CFG:
					
					switch(Copy_uint8Status)
					{
						case FULL_SWJ:
						
								/*Setting the bits to (000)*/
								CLR_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								CLR_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
								CLR_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+2));
						break;
						
						case FULL_SWJ_WITHOUT_NJTRST:
						
								/*Setting the bits to (001)*/
								SET_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								CLR_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
								CLR_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+2));
						break;
						
						case JTAG_DP_DISABLED_SW_DP_ENABLED:
						
								/*Setting the bits to (010)*/
								CLR_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								SET_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
								CLR_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+2));
						break;
						
						case JTAG_DP_DISABLED_SW_DP_DISABLED:
						
								/*Setting the bits to (100)*/
								CLR_BIT(AFIO -> AFIO_MAPR,  Copy_uint8PeripheralName);
								CLR_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+1));
								SET_BIT(AFIO -> AFIO_MAPR, (Copy_uint8PeripheralName+2));
						break;
						
						default :
						
								/*ERROR*/
						break;
					}
			break;
			
			default:
			
					switch(Copy_uint8Status)
					{
						case NO_REMAP:
							
								/*Making the Pin To be Normal Input/Output*/
								CLR_BIT(AFIO -> AFIO_MAPR, Copy_uint8PeripheralName);
						break;
						
						case REMAP:
						
								/*Making the Pin To be Alternative Function Input/Output*/
								SET_BIT(AFIO -> AFIO_MAPR, Copy_uint8PeripheralName);
						break;
						
						default :
						
								/*ERROR*/
						break;
					}
			break;
			
		}
	}
	
	/*Checking if the Peripheral is in MAPR1*/	
	else if((Copy_uint8PeripheralName > AFIO_MAPR_1) && (Copy_uint8PeripheralName < AFIO_MAPR_2))
	{
		switch(Copy_uint8Status)
		{
			case NO_REMAP:
			
					/*Making the Pin To be Normal Input/Output*/
					CLR_BIT(AFIO -> AFIO_MAPR2, (Copy_uint8PeripheralName - AFIO_MAPR_1));
			break;
			
			case REMAP:
			
					/*Making the Pin To be Alternative Function Input/Output*/
					SET_BIT(AFIO -> AFIO_MAPR2, (Copy_uint8PeripheralName - AFIO_MAPR_1));
			break;
			
			default :
			
					/*ERROR*/
			break;
		}
	}
	
	else
	{
		/*ERROR*/
	}
	
}