/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						19 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: RCC Driver                                                        							                      *                     
* ! File Name	: RCC_intrface.h                                                     							                      *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/******************************************************* Clock Sources *****************************************************************/
#define HSI 								0
#define HSE 								1
#define PLL 								2
	
#define ENABLE 								0
#define DISABLE 							1
	
#define HSI_RDY 							1
#define HSE_RDY 							17
#define PLL_RDY 							25
	
#define CLK_ENABLE  						1
#define CLK_DISABLE 						0
	
#define AHB  								0
#define APB1 								1
#define APB2 								2

/****************************************************** AHB Perphirals ****************************************************************/
#define ETHMACRXEN 							16
#define ETHMACTXEN 							15
#define ETHMACEN   							14
#define OTGFSEN    							12
#define CRCEN      							6
#define FLITFEN    							4
#define SRAMEN     							2
#define DMA2EN     							1
#define DMA1EN     							0
/****************************************************** ABP1 Perphirals ***************************************************************/
#define DACEN      							29
#define PWREN      							28
#define BKPEN      							27
#define CAN2EN     							26
#define CAN1EN     							25
#define I2C2EN     							22
#define I2C1EN     							21
#define UART5EN    							20
#define UART4EN    							19
#define USART3EN   							18
#define UART2EN    							17
#define SPI3EN     							15
#define SPI2EN     							14
#define WWDGEN     							11
#define TIM7EN     							5
#define TIM6EN     							4
#define TIM5EN     							3
#define TIM4EN     							2
#define TIM3EN     							1
#define TIM2EN     							0
/****************************************************** ABP2 Perphirals ***************************************************************/
#define AFIOEN     							0
#define IOPA       							2
#define IOPB       							3
#define IOPC       							4
#define IOPD       							5
#define SPI1EN     							12
#define USARTEN    							14

/******************************************************** AHB Divisors ****************************************************************/
#define AHB_SYSCLK_NOT_DIVIDED    			0
#define AHB_SYSCLK_DIVIDED_BY_2   			8
#define AHB_SYSCLK_DIVIDED_BY_4   			9
#define AHB_SYSCLK_DIVIDED_BY_8   			10
#define AHB_SYSCLK_DIVIDED_BY_16  			11
#define AHB_SYSCLK_DIVIDED_BY_64  			12
#define AHB_SYSCLK_DIVIDED_BY_128 			13
#define AHB_SYSCLK_DIVIDED_BY_256 			14
#define AHB_SYSCLK_DIVIDED_BY_512 			15
/******************************************************* ABP1 Divisors ****************************************************************/
#define APB1_HCLK_NOT_DIVIDED   			0
#define APB1_HCLK_DIVIDED_BY_2  			4
#define APB1_HCLK_DIVIDED_BY_4  			5
#define APB1_HCLK_DIVIDED_BY_8  			6
#define APB1_HCLK_DIVIDED_BY_16 			7
/******************************************************* ABP2 Divisors ****************************************************************/
#define APB2_HCLK_NOT_DIVIDED   			0
#define APB2_HCLK_DIVIDED_BY_2  			4
#define APB2_HCLK_DIVIDED_BY_4  			5
#define APB2_HCLK_DIVIDED_BY_8  			6
#define APB2_HCLK_DIVIDED_BY_16 			7

/****************************************************** PLL Multiplier ****************************************************************/
#define PLL_INPUT_MUL_2  					0
#define PLL_INPUT_MUL_3  					1
#define PLL_INPUT_MUL_4  					2
#define PLL_INPUT_MUL_5  					3
#define PLL_INPUT_MUL_6  					4
#define PLL_INPUT_MUL_7  					5
#define PLL_INPUT_MUL_8  					6
#define PLL_INPUT_MUL_9  					7
#define PLL_INPUT_MUL_10 					8
#define PLL_INPUT_MUL_11 					9
#define PLL_INPUT_MUL_12 					10
#define PLL_INPUT_MUL_13 					11
#define PLL_INPUT_MUL_14 					12
#define PLL_INPUT_MUL_15 					13
#define PLL_INPUT_MUL_16 					14

/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MRCC_voidInit																				                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration to The Clock Source 										          *
**************************************************************************************************************************************/
void MRCC_voidInit();
/**************************************************************************************************************************************
* Function Name		: MRCC_SetPLLConfiguration																                	      *
* Parameters (in)	: uint8 copy_uint8PLLMulFactor, uint8 copy_uint8PLLSource, uint8 copy_uint8HSEDivided					          *
* Parameters (out)	: None																						                      *
* Return value		: None							 															    	              *
* Description		: Function To Set all PLL Configurations													                      *
**************************************************************************************************************************************/
void MRCC_SetPLLConfiguration(uint8 copy_uint8PLLMulFactor, uint8 copy_uint8PLLSource, uint8 copy_uint8HSEDivided);
/**************************************************************************************************************************************
* Function Name		: MRCC_voidSetBusesPrescalers																                      *
* Parameters (in)	: uint8 copy_uint8ClkSource 																	                  *
* Parameters (out)	: None																						                      *
* Return value		: uint8 local_uint8ReturnStatus 															    	              *
* Description		: Function To Set all Buses Prescallers														                      *
**************************************************************************************************************************************/
void MRCC_voidSetBusesPrescalers(uint8 copy_uint8AHBPrescaler, uint8 copy_uint8APB1Prescaler, uint8 copy_uint8APB2Prescaler);
/**************************************************************************************************************************************
* Function Name		: MRCC_uint8CheckClkSourceReady																                      *
* Parameters (in)	: uint8 copy_uint8ClkSource 																	                  *
* Parameters (out)	: None																						                      *
* Return value		: uint8 local_uint8ReturnStatus 															    	              *
* Description		: Function To Check That the  Clock Sources is Ready										                      *
**************************************************************************************************************************************/
uint8 MRCC_uint8CheckClkSourceReady(uint8 copy_uint8ClkSource);
/**************************************************************************************************************************************
* Function Name		: MRCC_voidSetClkStatus																		                      *
* Parameters (in)	: uint8 copy_uint8ClkSource, uint8 copy_uint8Status											                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Enable Or Disable Clock Sources												                      *
**************************************************************************************************************************************/
void MRCC_voidSetClkStatus(uint8 copy_uint8ClkSource, uint8 copy_uint8Status);
/**************************************************************************************************************************************
* Function Name		: MRCC_voidSetClkSource																		                      *
* Parameters (in)	: uint8 copy_uint8ClkSource																	                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Set the  Clock Sources To the System											                      *
**************************************************************************************************************************************/
void MRCC_voidSetClkSource(uint8 copy_uint8ClkSource);
/**************************************************************************************************************************************
* Function Name		: MRCC_voidSetPeripheralClock																                      *
* Parameters (in)	: uint8 copy_uint8Bus, uint8 copy_uint8Peripheral, uint8 copy_uint8Status						                  *
* Parameters (out)	: None																						                      *
* Return value		: None							 															    	              *
* Description		: Function To Enable Or Disable Clock Sources To a specific Perephiral						                      *
**************************************************************************************************************************************/
void MRCC_voidSetPeripheralClock(uint8 copy_uint8Bus, uint8 copy_uint8Peripheral, uint8 copy_uint8Status);
 

#endif /*RCC_INTERFACE_H*/