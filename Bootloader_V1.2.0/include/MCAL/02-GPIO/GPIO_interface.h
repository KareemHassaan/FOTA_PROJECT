/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						20 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: GPIO Driver                                                        							                      *                     
* ! File Name	: GPIO_intrface.h                                                     							                      *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/******************************************************* Port Numbers ****************************************************************/
#define	GPIO_PORTA									0
#define	GPIO_PORTB									1
#define	GPIO_PORTC									2
/******************************************************* Pin Numbers *****************************************************************/
#define	GPIO_PIN0									0
#define	GPIO_PIN1									1
#define	GPIO_PIN2									2
#define	GPIO_PIN3									3
#define	GPIO_PIN4									4
#define	GPIO_PIN5									5
#define	GPIO_PIN6									6
#define	GPIO_PIN7									7
#define	GPIO_PIN8									8
#define	GPIO_PIN9									9
#define	GPIO_PIN10									10
#define	GPIO_PIN11									11
#define	GPIO_PIN12									12
#define	GPIO_PIN13									13
#define	GPIO_PIN14									14
#define	GPIO_PIN15									15

#define	GPIO_LOW									0
#define	GPIO_HIGH									1

/************************************ Port x configuration bits In input mode (MODE[1:0]=00) *****************************************/
#define ANALOG_MODE									0
#define FLOATING_INPUT								1
#define INPUT_PULL_UP_PULL_DOWN						2
/********************************** Port x configuration bits In output mode (MODE[1:0] > 00) ****************************************/	
#define GENERAL_PURPOSE_OUTPUT_PUSH_PULL			0
#define GENERAL_PURPOSE_OUTPUT_OPEN_DRAIN			1
#define ALTERNATE_FUNCTION_OUTPUT_PUSH_PULL			2
#define ALTERNATE_FUNCTION_OUTPUT_OPEN_DRAIN		3
/******************************************************** Port x modes bits ***********************************************************/	
#define INPUT_MODE									0
#define OUTPUT_MODE_MAX_SPEED_10_MHZ				1
#define OUTPUT_MODE_MAX_SPEED_2_MHZ					2
#define OUTPUT_MODE_MAX_SPEED_50_MHZ				3


/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MGPIO_voidSetPinDirection																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration 										          					  *
**************************************************************************************************************************************/
void MGPIO_voidSetPinDirection(uint8 Copy_uint8PortNum, uint8 Copy_uint8PinNum, uint8 Copy_uint8PinMode, uint8 Copy_uint8PinCnf);
/**************************************************************************************************************************************
* Function Name		: MGPIO_voidSetPinDirection																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration 										          					  *
**************************************************************************************************************************************/
void MGPIO_voidSetPinValue(uint8 Copy_uint8PortNum, uint8 Copy_uint8PinNum, uint8 Copy_uint8PinValue);
/**************************************************************************************************************************************
* Function Name		: MGPIO_voidSetPinDirection																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration 										          					  *
**************************************************************************************************************************************/
void MGPIO_voidAtomicSetPinValue(uint8 Copy_uint8PortNum, uint8 Copy_uint8PinNum, uint8 Copy_uint8PinValue);
/**************************************************************************************************************************************
* Function Name		: MGPIO_voidSetPinDirection																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration 										          					  *
**************************************************************************************************************************************/
uint8 MGPIO_uint8GetPinValue(uint8 Copy_uint8PortNum, uint8 Copy_uint8PinNum);
/**************************************************************************************************************************************
* Function Name		: MGPIO_voidSetPortDirection																	                  *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration 										          					  *
**************************************************************************************************************************************/
void MGPIO_voidSetPortDirection(uint8 Copy_uint8PortNum, uint8 Copy_uint8StartBit, uint8 Copy_uint8EndBit, uint8 Copy_uint8PortMode, uint8 Copy_uint8PortCnf);
/**************************************************************************************************************************************
* Function Name		: MGPIO_voidSetPinDirection																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration 										          					  *
**************************************************************************************************************************************/
void MGPIO_voidSetPortValue(uint8 Copy_uint8PortNum, uint16 Copy_uint16Mask, uint16 Copy_uint16PortValue);
/**************************************************************************************************************************************
* Function Name		: MGPIO_voidSetPinDirection																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration 										          					  *
**************************************************************************************************************************************/
uint16 MGPIO_uint8GetPortValue(uint8 Copy_uint8PortNum);
/**************************************************************************************************************************************
* Function Name		: MGPIO_voidSetPinDirection																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration 										          					  *
**************************************************************************************************************************************/
void MGPIO_voidPinLockEnable(uint8 Copy_uint8PortNum);
/**************************************************************************************************************************************
* Function Name		: MGPIO_voidSetPinDirection																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration 										          					  *
**************************************************************************************************************************************/
void MGPIO_voidPinLock(uint8 Copy_uint8PortNum, uint8 Copy_uint8PinNum);

#endif /*GPIO_INTERFACE_H*/