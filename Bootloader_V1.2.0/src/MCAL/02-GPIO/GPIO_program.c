/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						20 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: GPIO Driver                                                        							                      *
* ! File Name	: GPIO_program.c                                                       							                      *
* ! Description : This file has the implementation of Basic of GPIO functions        							                      *
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
#include"../../include/MCAL/02-GPIO/GPIO_interface.h"  
#include"../../include/MCAL/02-GPIO/GPIO_private.h"
#include"../../include/MCAL/02-GPIO/GPIO_config.h"

/***************************************************** Global Variables **************************************************************/


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MGPIO_voidSetPinDirection																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration 										          					  *
**************************************************************************************************************************************/
void MGPIO_voidSetPinDirection(uint8 Copy_uint8PortNum, uint8 Copy_uint8PinNum, uint8 Copy_uint8PinMode, uint8 Copy_uint8PinCnf)
{
	switch(Copy_uint8PortNum)
	{
		case GPIO_PORTA:
		
				if(Copy_uint8PinNum <= GPIO_PIN7)
				{
					SET_SPECIFIC_REG_BITS_VALUE(GPIOA -> GPIO_CRL, ~((GPIO_CRX_MASK) << (Copy_uint8PinNum)*4),\
									  (((Copy_uint8PinCnf << 2)|(Copy_uint8PinMode)) << (Copy_uint8PinNum)*4));
				}
				else
				{
					Copy_uint8PinNum -= GPIO_PIN8;
					SET_SPECIFIC_REG_BITS_VALUE(GPIOA -> GPIO_CRH, ~((GPIO_CRX_MASK) << (Copy_uint8PinNum)*4),\
									  (((Copy_uint8PinCnf << 2)|(Copy_uint8PinMode)) << (Copy_uint8PinNum)*4));
				}
		break;
		
		case GPIO_PORTB:
		
				if(Copy_uint8PinNum <= GPIO_PIN7)
				{
					SET_SPECIFIC_REG_BITS_VALUE(GPIOB -> GPIO_CRL, ~((GPIO_CRX_MASK) << (Copy_uint8PinNum)*4),\
									  (((Copy_uint8PinCnf << 2)|(Copy_uint8PinMode)) << (Copy_uint8PinNum)*4));
				}
				else
				{
					Copy_uint8PinNum -= GPIO_PIN8;
					SET_SPECIFIC_REG_BITS_VALUE(GPIOB -> GPIO_CRH, ~((GPIO_CRX_MASK) << (Copy_uint8PinNum)*4),\
									  (((Copy_uint8PinCnf << 2)|(Copy_uint8PinMode)) << (Copy_uint8PinNum)*4));
				}
		break;
		
		case GPIO_PORTC:
				
				if(Copy_uint8PinNum >= GPIO_PIN13)
				{
					SET_SPECIFIC_REG_BITS_VALUE(GPIOC -> GPIO_CRH, ~((GPIO_CRX_MASK) << (Copy_uint8PinNum)*4),\
									  (((Copy_uint8PinCnf << 2)|(Copy_uint8PinMode)) << (Copy_uint8PinNum)*4));
				}
				else
				{
					/*ERROR*/
				}
		break;
		
		default:
				/*ERROR*/
		break;
	}
}

/**************************************************************************************************************************************
* Function Name		: MGPIO_voidSetPinDirection																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration 										          					  *
**************************************************************************************************************************************/
void MGPIO_voidSetPinValue(uint8 Copy_uint8PortNum, uint8 Copy_uint8PinNum, uint8 Copy_uint8PinValue)
{
	switch(Copy_uint8PortNum)
	{
		case GPIO_PORTA:
				
				switch(Copy_uint8PinValue)
				{
					case GPIO_LOW:
					
							CLR_BIT(GPIOA -> GPIO_ODR, Copy_uint8PinNum);	
					break;
					
					case GPIO_HIGH:
					
							SET_BIT(GPIOA -> GPIO_ODR, Copy_uint8PinNum);
					break;
					
					default:
							/*ERROR*/
					break;
				}
		break;
		
		case GPIO_PORTB:
		
				switch(Copy_uint8PinValue)
				{
					case GPIO_LOW:
					
							CLR_BIT(GPIOB -> GPIO_ODR, Copy_uint8PinNum);	
					break;
					
					case GPIO_HIGH:
					
							SET_BIT(GPIOB -> GPIO_ODR, Copy_uint8PinNum);
					break;
					
					default:
							/*ERROR*/
					break;
				}
		break;
		
		case GPIO_PORTC:
				
				if(Copy_uint8PinNum >= GPIO_PIN13)
				{
						switch(Copy_uint8PinValue)
						{
							case GPIO_LOW:
							
									CLR_BIT(GPIOC -> GPIO_ODR, Copy_uint8PinNum);	
							break;
							
							case GPIO_HIGH:
							
									SET_BIT(GPIOC -> GPIO_ODR, Copy_uint8PinNum);
							break;
							
							default:
									/*ERROR*/
							break;
						}
				}
				else
				{
					/*ERROR*/
				}
		break;
		
		default:
				/*ERROR*/
		break;
	}
}

/**************************************************************************************************************************************
* Function Name		: MGPIO_voidSetPinDirection																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration 										          					  *
**************************************************************************************************************************************/
void MGPIO_voidAtomicSetPinValue(uint8 Copy_uint8PortNum, uint8 Copy_uint8PinNum, uint8 Copy_uint8PinValue)
{
	switch(Copy_uint8PortNum)
	{
		case GPIO_PORTA:
				
				switch(Copy_uint8PinValue)
				{
					case GPIO_LOW:
					
							GPIOA -> GPIO_BRR = (1 << Copy_uint8PinNum);	
					break;
					
					case GPIO_HIGH:
					
							GPIOA -> GPIO_BSRR = (1 << Copy_uint8PinNum);
					break;
					
					default:
							/*ERROR*/
					break;
				}
		break;
		
		case GPIO_PORTB:
		
				switch(Copy_uint8PinValue)
				{
					case GPIO_LOW:
					
							GPIOB -> GPIO_BRR = (1 << Copy_uint8PinNum);	
					break;
					
					case GPIO_HIGH:
					
							GPIOB -> GPIO_BSRR = (1 << Copy_uint8PinNum);
					break;
					
					default:
							/*ERROR*/
					break;
				}
		break;
		
		case GPIO_PORTC:
				
				if(Copy_uint8PinNum >= GPIO_PIN13)
				{
						switch(Copy_uint8PinValue)
						{
							case GPIO_LOW:
							
									GPIOC -> GPIO_BRR = (1 << Copy_uint8PinNum);
							break;
							
							case GPIO_HIGH:
							
									GPIOC -> GPIO_BSRR = (1 << Copy_uint8PinNum);
							break;
							
							default:
									/*ERROR*/
							break;
						}
				}
				else
				{
					/*ERROR*/
				}
		break;
		
		default:
				/*ERROR*/
		break;
	}
}

/**************************************************************************************************************************************
* Function Name		: MGPIO_voidSetPinDirection																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration 										          					  *
**************************************************************************************************************************************/
uint8 MGPIO_uint8GetPinValue(uint8 Copy_uint8PortNum, uint8 Copy_uint8PinNum)
{
	uint8 Local_ReturnPinStatus;
	
	switch(Copy_uint8PortNum)
	{
		case GPIO_PORTA:
				
				Local_ReturnPinStatus = GET_BIT(GPIOA -> GPIO_IDR, Copy_uint8PinNum);
		break;
		
		case GPIO_PORTB:
		
				Local_ReturnPinStatus = GET_BIT(GPIOB -> GPIO_IDR, Copy_uint8PinNum);
		break;
		
		case GPIO_PORTC:
				
				if(Copy_uint8PinNum >= GPIO_PIN13)
				{
					Local_ReturnPinStatus = GET_BIT(GPIOC -> GPIO_IDR, Copy_uint8PinNum);	
				}
				else
				{
					/*ERROR*/
				}
		break;
		
		default:
				/*ERROR*/
		break;
	}
	
	return Local_ReturnPinStatus;
}

/**************************************************************************************************************************************
* Function Name		: MGPIO_voidSetPortDirection																	                  *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration 										          					  *
**************************************************************************************************************************************/
void MGPIO_voidSetPortDirection(uint8 Copy_uint8PortNum, uint8 Copy_uint8StartBit, uint8 Copy_uint8EndBit, uint8 Copy_uint8PortMode, uint8 Copy_uint8GPIO_PORTCnf)
{
	uint8 Local_uint8LoopCounter = 0;
	
	for(Local_uint8LoopCounter = Copy_uint8StartBit; Local_uint8LoopCounter <= Copy_uint8EndBit; Local_uint8LoopCounter++)
	{
		MGPIO_voidSetPinDirection(Copy_uint8PortNum, Local_uint8LoopCounter, Copy_uint8PortMode, Copy_uint8GPIO_PORTCnf);
	}
}

/**************************************************************************************************************************************
* Function Name		: MGPIO_voidSetPortValue																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration 										          					  *
**************************************************************************************************************************************/
void MGPIO_voidSetPortValue(uint8 Copy_uint8PortNum, uint16 Copy_uint16Mask, uint16 Copy_uint16PortValue)
{
	switch(Copy_uint8PortNum)
	{
		case GPIO_PORTA:
				
				SET_SPECIFIC_REG_BITS_VALUE(GPIOA -> GPIO_ODR,Copy_uint16Mask, Copy_uint16PortValue);
		break;
		
		case GPIO_PORTB:
		
				SET_SPECIFIC_REG_BITS_VALUE(GPIOB -> GPIO_ODR,Copy_uint16Mask, Copy_uint16PortValue);
		break;
		
		default:
				/*ERROR*/
		break;
	}
}

/**************************************************************************************************************************************
* Function Name		: MGPIO_voidSetPinDirection																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration 										          					  *
**************************************************************************************************************************************/
uint16 MGPIO_uint8GetPortValue(uint8 Copy_uint8PortNum)
{
	uint16 Local_uint16ReturnPortStatus;
	
	switch(Copy_uint8PortNum)
	{
		case GPIO_PORTA:
				
				Local_uint16ReturnPortStatus = GPIOA -> GPIO_IDR;
		break;
		
		case GPIO_PORTB:
		
				Local_uint16ReturnPortStatus = GPIOB -> GPIO_IDR;
		break;
		
		default:
				/*ERROR*/
		break;
	}
	
	return Local_uint16ReturnPortStatus;
}

/**************************************************************************************************************************************
* Function Name		: MGPIO_voidSetPinDirection																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration 										          					  *
**************************************************************************************************************************************/
void MGPIO_voidPinLockEnable(uint8 Copy_uint8PortNum)
{
	switch(Copy_uint8PortNum)
	{
		case GPIO_PORTA:
				
				SET_BIT(GPIOA -> GPIO_LCKR, GPIO_LCKK_BIT);
				CLR_BIT(GPIOA -> GPIO_LCKR, GPIO_LCKK_BIT);
				SET_BIT(GPIOA -> GPIO_LCKR, GPIO_LCKK_BIT);
				
				while(GET_BIT(GPIOA -> GPIO_LCKR, GPIO_LCKK_BIT) == 0);
		break;
		
		case GPIO_PORTB:
				
				SET_BIT(GPIOB -> GPIO_LCKR, GPIO_LCKK_BIT);
				CLR_BIT(GPIOB -> GPIO_LCKR, GPIO_LCKK_BIT);
				SET_BIT(GPIOB -> GPIO_LCKR, GPIO_LCKK_BIT);
				
				while(GET_BIT(GPIOB -> GPIO_LCKR, GPIO_LCKK_BIT) == 0);
		break;
		
		case GPIO_PORTC:
				
				SET_BIT(GPIOC -> GPIO_LCKR, GPIO_LCKK_BIT);
				CLR_BIT(GPIOC -> GPIO_LCKR, GPIO_LCKK_BIT);
				SET_BIT(GPIOC -> GPIO_LCKR, GPIO_LCKK_BIT);
				
				while(GET_BIT(GPIOC -> GPIO_LCKR, GPIO_LCKK_BIT) == 0);
		break;
		
		default:
				/*ERROR*/
		break;
	}
}
/**************************************************************************************************************************************
* Function Name		: MGPIO_voidSetPinDirection																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration 										          					  *
**************************************************************************************************************************************/
void MGPIO_voidPinLock(uint8 Copy_uint8PortNum, uint8 Copy_uint8PinNum)
{
	switch(Copy_uint8PortNum)
	{
		case GPIO_PORTA:
				
				SET_BIT(GPIOA -> GPIO_LCKR, Copy_uint8PinNum);
		break;
		
		case GPIO_PORTB:
		
				SET_BIT(GPIOB -> GPIO_LCKR, Copy_uint8PinNum);
		break;
		
		case GPIO_PORTC:
				
				if(Copy_uint8PinNum >= GPIO_PIN13)
				{
					SET_BIT(GPIOC -> GPIO_LCKR, Copy_uint8PinNum);
				}
				else
				{
					/*ERROR*/
				}
		break;
		
		default:
				/*ERROR*/
		break;
	}
}






