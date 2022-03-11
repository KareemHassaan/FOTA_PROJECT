/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						21 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: NVIC Driver                                                        							                      *                     
* ! File Name	: NVIC_intrface.h                                                     							                      *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/******************************************************** Interrupts IDs *************************************************************/

#define NVIC_EN_WWDG							0
#define NVIC_EN_PVD								1
#define NVIC_EN_TAMPER							2
#define NVIC_EN_RTC								3
#define NVIC_EN_FLASH							4
#define NVIC_EN_RCC								5
#define NVIC_EN_EXTI0							6
#define NVIC_EN_EXTI1							7
#define NVIC_EN_EXTI2							8
#define NVIC_EN_EXTI3							9
#define NVIC_EN_EXTI4							10
#define NVIC_EN_DMA1_CH1						11
#define NVIC_EN_DMA1_CH2						12
#define NVIC_EN_DMA1_CH3						13
#define NVIC_EN_DMA1_CH4						14
#define NVIC_EN_DMA1_CH5						15
#define NVIC_EN_DMA1_CH6						16
#define NVIC_EN_DMA1_CH7						17
#define NVIC_EN_ADC1_2							18
#define NVIC_EN_USB_HP_CAN_TX					19
#define NVIC_EN_USB_LP_CAN_RX0					20
#define NVIC_EN_CAN_RX1							21
#define NVIC_EN_CAN_SCE							22
#define NVIC_EN_EXTI9_5							23
#define NVIC_EN_TIM1_BRK						24
#define NVIC_EN_TIM1_UP							25
#define NVIC_EN_TIM1_TRG_COMM					26
#define NVIC_EN_TIM1_CC							27
#define NVIC_EN_TIM2							28
#define NVIC_EN_TIM3							29
#define NVIC_EN_TIM4							30
#define NVIC_EN_I2C1_EV							31
#define NVIC_EN_I2C1_ER							32
#define NVIC_EN_I2C2_EV							33
#define NVIC_EN_I2C2_ER							34
#define NVIC_EN_SPI1							35
#define NVIC_EN_SPI2							36
#define NVIC_EN_USART1							37
#define NVIC_EN_USART2							38
#define NVIC_EN_USART3							39
#define NVIC_EN_EXTI15_10						40
#define NVIC_EN_RTCAlaram						41
#define NVIC_EN_USBWakeup						42
#define NVIC_EN_TIM8_BRK						43
#define NVIC_EN_TIM8_UP							44
#define NVIC_EN_TIM8_TRG_COM					45
#define NVIC_EN_TIM8_CC							46
#define NVIC_EN_ADC3							47
#define NVIC_EN_FSMC							48
#define NVIC_EN_SDIO							49
#define NVIC_EN_TIM5							50
#define NVIC_EN_SPI3							51
#define NVIC_EN_UART4							52
#define NVIC_EN_UART5							53
#define NVIC_EN_TIM6							54
#define NVIC_EN_TIM7							55
#define NVIC_EN_DMA2_CH1						56
#define NVIC_EN_DMA2_CH2						57
#define NVIC_EN_DMA2_CH3						58
#define NVIC_EN_DMA2_CH4_5						59

/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MNVIC_voidEnableInterrupt																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Set Specific Bit To Enable Interrupt 										          				  *
**************************************************************************************************************************************/
void MNVIC_voidEnableInterrupt(uint8 Copy_uint8InterruptNumber);
/**************************************************************************************************************************************
* Function Name		: MNVIC_voidDisableInterrupt																                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Set Specific Bit To Enable Interrupt 										          				  *
**************************************************************************************************************************************/
void MNVIC_voidDisableInterrupt(uint8 Copy_uint8InterruptNumber);
/**************************************************************************************************************************************
* Function Name		: MNVIC_voidSetPendingFlag																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Set the Pending Flag Used in Testing The ISR 							          					  *
**************************************************************************************************************************************/
void MNVIC_voidSetPendingFlag(uint8 Copy_uint8InterruptNumber);
/**************************************************************************************************************************************
* Function Name		: MNVIC_voidClearPendingFlag																                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Clear the Pending Flag Used in Testing The ISR 						          					  *
**************************************************************************************************************************************/
void MNVIC_voidClearPendingFlag(uint8 Copy_uint8InterruptNumber);
/**************************************************************************************************************************************
* Function Name		: MNVIC_uint8GetActiveInterrupt																                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Get the Interrupt Status		 										          					  *
**************************************************************************************************************************************/
uint8 MNVIC_uint8GetActiveInterrupt(uint8 Copy_uint8InterruptNumber);

#endif /*NVIC_INTERFACE_H*/