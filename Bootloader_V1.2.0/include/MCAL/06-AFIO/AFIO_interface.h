/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						01 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: AFIO Driver                                                        							                      *                     
* ! File Name	: AFIO_intrface.h                                                     							                      *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/

#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

/************************************************* PORTS MACROS FOR EVENT ENABLE *****************************************************/

#define AFIO_PORTA							0
#define AFIO_PORTB							1
#define AFIO_PORTC							2

/************************************************* PINS MACROS FOR EVENT ENABLE ******************************************************/

#define AFIO_PIN0							0
#define AFIO_PIN1							1
#define AFIO_PIN2							2
#define AFIO_PIN3							3
#define AFIO_PIN4							4
#define AFIO_PIN5							5
#define AFIO_PIN6							6
#define AFIO_PIN7							7
#define AFIO_PIN8							8
#define AFIO_PIN9							9
#define AFIO_PIN10							10
#define AFIO_PIN11							11
#define AFIO_PIN12							12
#define AFIO_PIN13							13
#define AFIO_PIN14							14
#define AFIO_PIN15							15

/*************************************************** MACROS FOR EXTI ENABLE *********************************************************/

#define AFIO_EXTI0							0
#define AFIO_EXTI1							1
#define AFIO_EXTI2							2
#define AFIO_EXTI3							3
#define AFIO_EXTI4							4
#define AFIO_EXTI5							5
#define AFIO_EXTI6							6
#define AFIO_EXTI7							7
#define AFIO_EXTI8							8
#define AFIO_EXTI9							9
#define AFIO_EXTI10							10
#define AFIO_EXTI11							11
#define AFIO_EXTI12							12
#define AFIO_EXTI13							13
#define AFIO_EXTI14							14
#define AFIO_EXTI15							15

/*********************************************** MACROS FOR PERIPHERALS ENABLE ******************************************************/
#define NO_REMAP							0
#define	REMAP								1
#define	PARTIAL_REMAP						2
#define	SECOND_PARTIAL_REMAP				3


#define AFIO_SPI1                           0
#define AFIO_I2C1                           1
#define AFIO_USART1                         2
#define AFIO_USART2                         3
#define AFIO_USART3		                    4
#define AFIO_TIM1	                        6
#define AFIO_TIM2	                        8
#define AFIO_TIM3	                        10
#define AFIO_TIM4                           12
#define AFIO_CAN		                    13
#define AFIO_PD01							15
#define AFIO_TIM5CH4_IREMAP                 16
#define AFIO_ADC1_ETRGINJ                   17
#define AFIO_ADC1_ETRGREG                   18
#define AFIO_ADC2_ETRGINJ                   19
#define AFIO_ADC2_ETRGREG                   20
#define AFIO_SWJ_CFG						24
#define AFIO_TIM9 							37
#define AFIO_TIM10							38
#define AFIO_TIM11							39
#define AFIO_TIM13							40
#define AFIO_TIM14							41
#define AFIO_FSMC_NADV						42

/******************************************** MACROS FOR PERIPHERALS ENABLE (JTAG) ***************************************************/

#define FULL_SWJ 							0
#define FULL_SWJ_WITHOUT_NJTRST				1
#define JTAG_DP_DISABLED_SW_DP_ENABLED		2
#define JTAG_DP_DISABLED_SW_DP_DISABLED		3

/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MAFIO_voidEventEnable																	                      	  *
* Parameters (in)	: uint8 Copy_uint8PortNum, uint8 Copy_uint8PinNum												                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Enable AFIO For Event Out		 										          					  *
**************************************************************************************************************************************/
void MAFIO_voidEventEnable(uint8 Copy_uint8PortNum, uint8 Copy_uint8PinNum);
/**************************************************************************************************************************************
* Function Name		: MAFIO_voidAFExternalInterruptEnable																	          *
* Parameters (in)	: uint8 Copy_uint8PortNum, uint8 Copy_uint8_EXTI_Num											                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Enable AFIO For EXTI 			 										          					  *
**************************************************************************************************************************************/
void MAFIO_voidAFExternalInterruptEnable(uint8 Copy_uint8PortNum, uint8 Copy_uint8_EXTI_Num);
/**************************************************************************************************************************************
* Function Name		: MAFIO_voidAFExternalInterruptEnable																	          *
* Parameters (in)	: uint8 Copy_uint8PeripheralName, uint8 Copy_uint8Status										                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Enable AFIO For Peripherals 	 										          					  *
**************************************************************************************************************************************/
void MAFIO_voidAFPeripheralsEnable(uint8 Copy_uint8PeripheralName, uint8 Copy_uint8Status);

#endif /*AFIO_INTERFACE_H*/