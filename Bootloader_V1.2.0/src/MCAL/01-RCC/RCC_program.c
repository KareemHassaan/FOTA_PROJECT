/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						19 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: RCC Driver                                                        							                      *
* ! File Name	: RCC_program.c                                                       							                      *
* ! Description : This file has the implementation of Basic of RCC functions        							                      *
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
#include"../../include/MCAL/01-RCC/RCC_interface.h"  
#include"../../include/MCAL/01-RCC/RCC_private.h"
#include"../../include/MCAL/01-RCC/RCC_config.h"

/***************************************************** Global Variables **************************************************************/


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MRCC_voidInit																				                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Initialize All The Configration to The Clock Source 										          *
**************************************************************************************************************************************/
void MRCC_voidInit()
{
	/*Checking If The Clock Source Configure To be HSE*/
	 #if CLOCK_SOURCE == HSE

		/*Enable The HSE Clock Source*/
		 MRCC_voidSetClkStatus(HSE, ENABLE);
		
		/*Check That The HSE Clock Source is Ready and Stable*/
		 if(MRCC_uint8CheckClkSourceReady(HSE_RDY) != CLK_SOURCE_NOT_READY)
		 {
			/*Selecting That HSE Is the Clock Source of The System*/
			 MRCC_voidSetClkSource(HSE);
			/*Disable The HSI Clock Source*/
			 MRCC_voidSetClkStatus(HSI, DISABLE);
			/*Disable The PLL Clock Source*/
			 MRCC_voidSetClkStatus(PLL, DISABLE);
		 } 
	
	
	/*Checking If The Clock Source Configure To be HSI*/
  	 #elif CLOCK_SOURCE == HSI
	
		/*Enable The HSI Clock Source*/
		 MRCC_voidSetClkStatus(HSI, ENABLE);
		
		/*Check That The HSI Clock Source is Ready and Stable*/
		 if(MRCC_uint8CheckClkSourceReady(HSI_RDY) != CLK_SOURCE_NOT_READY)
		 {
			/*Selecting That HSI Is the Clock Source of The System*/
			 MRCC_voidSetClkSource(HSI);
			/*Disable The HSE Clock Source*/
			 MRCC_voidSetClkStatus(HSE, DISABLE);
			/*Disable The PLL Clock Source*/
			 MRCC_voidSetClkStatus(PLL, DISABLE);
		 }
	
	
	/*Checking If The Clock Source Configure To be PLL*/	
	 #elif CLOCK_SOURCE == PLL
		/*Checking If The Clock Source of PLL Configure To be HSE_SOURCE*/
		 #if PLL_SOURCE == HSE_SOURCE
		 
			/*Enable The HSE Clock Source*/
			 MRCC_voidSetClkStatus(HSE, ENABLE);
			 
			/*Check That The HSE Clock Source is Ready and Stable*/
			 if(MRCC_uint8CheckClkSourceReady(HSE_RDY) != CLK_SOURCE_NOT_READY)
			 {
				/*Selecting That HSI Is the Clock Source of The System*/
				 MRCC_voidSetClkSource(HSI);
				/*Disable The PLL Clock Source To Configure it*/
				 MRCC_voidSetClkStatus(PLL, DISABLE);
				 
				 
				/*Configure HSI Division Factor and PLL Multiplication Factor, Set HSI as PLL Source*/
				MRCC_SetPLLConfiguration(PLL_MULTIPLICATION_FACTOR, HSE, HSE_DIVISION_FACTOR);
				/*Setting AHB , APB1, APB2 Buses Prescaler*/
				MRCC_voidSetBusesPrescalers(AHB_PRESCALER,APB1_PRESCALER,APB2_PRESCALER);
				
				
				/*Enable The PLL Clock Source*/
				 MRCC_voidSetClkStatus(PLL, ENABLE);
				 
				/*Check That The PLL Clock Source is Ready and Stable*/
				if(MRCC_uint8CheckClkSourceReady(PLL_RDY) != CLK_SOURCE_NOT_READY)
				{
					/*Selecting That PLL Is the Clock Source of The System*/
					 MRCC_voidSetClkSource(PLL);
					/*Disable The HSI Clock Source*/
					 MRCC_voidSetClkStatus(HSI, DISABLE);
				}
			}
			
			
		/*Checking If The Clock Source of PLL Configure To be HSI_SOURCE*/
		 #elif PLL_SOURCE == HSI_SOURCE
			
			/*Enable The HSI Clock Source*/
			 MRCC_voidSetClkStatus(HSI, ENABLE);
			 
			/*Check That The HSI Clock Source is Ready and Stable*/
			 if(MRCC_uint8CheckClkSourceReady(HSI_RDY) != CLK_SOURCE_NOT_READY)
			 {
				/*Selecting That HSI Is the Clock Source of The System*/
				 MRCC_voidSetClkSource(HSI);
				/*Disable The PLL Clock Source To Configure it*/
				 MRCC_voidSetClkStatus(PLL, DISABLE);
				 
				 
				/*Configure HSI Division Factor and PLL Multiplication Factor, Set HSI as PLL Source*/
				MRCC_SetPLLConfiguration(PLL_MULTIPLICATION_FACTOR, HSI, HSE_DIVISION_FACTOR);
				/*Setting AHB , APB1, APB2 Buses Prescaler*/
				MRCC_voidSetBusesPrescalers(AHB_PRESCALER,APB1_PRESCALER,APB2_PRESCALER);
				
				
				/*Enable The PLL Clock Source*/
				 MRCC_voidSetClkStatus(PLL, ENABLE);
				 
				/*Check That The PLL Clock Source is Ready and Stable*/
				if(MRCC_uint8CheckClkSourceReady(PLL_RDY) != CLK_SOURCE_NOT_READY)
				{
					/*Selecting That PLL Is the Clock Source of The System*/
					 MRCC_voidSetClkSource(PLL);
					/*Disable The HSE Clock Source*/
					 MRCC_voidSetClkStatus(HSE, DISABLE);
				}
			}
			
		 #else 
			/*Printing an Error Message That PLL_SOURCE Configration Error*/
			 #error"PLL_SOURCE Configration Error"
		 #endif	
#else 
	/*Printing an Error Message That CLOCK_SOURCE Configration Error*/
	 #error"CLOCK_SOURCE Configration Error"
 #endif
 
}

/**************************************************************************************************************************************
* Function Name		: MRCC_SetPLLConfiguration																                	      *
* Parameters (in)	: uint8 copy_uint8PLLMulFactor, uint8 copy_uint8PLLSource, uint8 copy_uint8HSEDivided					          *
* Parameters (out)	: None																						                      *
* Return value		: 								 															    	              *
* Description		: Function To Set all PLL Configurations													                      *
**************************************************************************************************************************************/
void MRCC_SetPLLConfiguration(uint8 copy_uint8PLLMulFactor, uint8 copy_uint8PLLSource, uint8 copy_uint8HSEDivided)
{
	SET_SPECIFIC_REG_BITS_VALUE(RCC -> RCC_CFGR, RCC_CFGR_PLL_CONFIG_MASK, ((copy_uint8PLLMulFactor << RCC_CFGR_PLL_MUL_BIT )
																		   |(copy_uint8HSEDivided << RCC_CFGR_HSE_DIVIDER_BIT)
																		   |(copy_uint8PLLSource << RCC_CFGR_PLL_SOURCE_BIT)));
}

/**************************************************************************************************************************************
* Function Name		: MRCC_voidSetBusesPrescalers																                      *
* Parameters (in)	: uint8 copy_uint8ClkSource 																	                  *
* Parameters (out)	: None																						                      *
* Return value		: uint8 local_uint8ReturnStatus 															    	              *
* Description		: Function To Set all Buses Prescallers														                      *
**************************************************************************************************************************************/
void MRCC_voidSetBusesPrescalers(uint8 copy_uint8AHBPrescaler, uint8 copy_uint8APB1Prescaler, uint8 copy_uint8APB2Prescaler)
{

	SET_SPECIFIC_REG_BITS_VALUE(RCC -> RCC_CFGR, RCC_CFGR_Prescaller_BITS_MASK, ((copy_uint8AHBPrescaler << RCC_CFGR_AHB_PRESCALER_START_BIT )\
																				|(copy_uint8APB1Prescaler << RCC_CFGR_APB1_PRESCALER_START_BIT)\
																				|(copy_uint8APB2Prescaler << RCC_CFGR_APB2_PRESCALER_START_BIT)));
}

/**************************************************************************************************************************************
* Function Name		: MRCC_uint8CheckClkSourceReady																                      *
* Parameters (in)	: uint8 copy_uint8ClkSource 																	                  *
* Parameters (out)	: None																						                      *
* Return value		: uint8 local_uint8ReturnStatus 															    	              *
* Description		: Function To Check That the  Clock Sources is Ready										                      *
**************************************************************************************************************************************/
uint8 MRCC_uint8CheckClkSourceReady(uint8 copy_uint8ClkSource)
{
	/*Variable To Store The Return Value That the Clock Source is Ready or Not*/
	 uint8 local_uint8ReturnStatus = CLK_SOURCE_READY;
	/*Variable To Store The Time Out Value Of Waiting*/
	 uint32 local_uint32TimeOut 	  = 0;
	
	/*Busy Waiting to The Clock Source To Be Ready*/
	 while(GET_BIT(RCC -> RCC_CR, copy_uint8ClkSource) == CLK_SOURCE_NOT_READY)
	 {
		/*Incrementing the Time Out Value*/
		 local_uint32TimeOut++;
		
		/*Check If The Time Out Or Not*/
		 if (local_uint32TimeOut == CLK_SOURCE_READY_TIME_OUT)
		 {
			/*Return That the Clock Source Not Ready*/
			 local_uint8ReturnStatus = CLK_SOURCE_NOT_READY;
			break;
		 } 
	 }

	return local_uint8ReturnStatus;
}

/**************************************************************************************************************************************
* Function Name		: MRCC_voidSetClkStatus																		                      *
* Parameters (in)	: uint8 copy_uint8ClkSource, uint8 copy_uint8Status											                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Enable Or Disable Clock Sources												                      *
**************************************************************************************************************************************/
void MRCC_voidSetClkStatus(uint8 copy_uint8ClkSource, uint8 copy_uint8Status)
{
	/*Switch on the Clock Source which one*/
	 switch(copy_uint8ClkSource)
	 {
		case HSI:
				/*Switch The Status Wanted Enable Or Disable*/
				 switch(copy_uint8Status)
				 {
					case ENABLE:
					
							/*Enable The HSI Clock Source*/
							 SET_BIT(RCC -> RCC_CR, RCC_CR_HSI_ON_BIT);
					break;
					
					case DISABLE:
					
							/*Disable The HSI Clock Source*/
							 CLR_BIT(RCC -> RCC_CR, RCC_CR_HSI_ON_BIT);
					break;
				 } 
		break;
		
		case HSE:
		
				/*Switch The Status Wanted Enable Or Disable*/
				switch(copy_uint8Status)
				{
					case ENABLE:
					
							/*Enable The HSE Clock Source*/
							 SET_BIT(RCC -> RCC_CR, RCC_CR_HSE_ON_BIT);
					break;
					
					case DISABLE:
					
							/*Disable The HSE Clock Source*/
							 CLR_BIT(RCC -> RCC_CR, RCC_CR_HSE_ON_BIT);
					break;
				}
		break;
		
		case PLL:
				/*Switch The Status Wanted Enable Or Disable*/
				switch(copy_uint8Status)
				{
					case ENABLE:
					
							/*Enable The PLL Clock Source*/
							 SET_BIT(RCC -> RCC_CR, RCC_CR_PLL_ON_BIT);
					break;
					
					case DISABLE:
					
							/*Disable The PLL Clock Source*/
							 CLR_BIT(RCC -> RCC_CR, RCC_CR_PLL_ON_BIT);
					break;
				}
		break;
		
		default:
				/*ERORR*/
		break;
	}
}

/**************************************************************************************************************************************
* Function Name		: MRCC_voidSetClkSource																		                      *
* Parameters (in)	: uint8 copy_uint8ClkSource																	                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Set the  Clock Sources To the System											                      *
**************************************************************************************************************************************/
void MRCC_voidSetClkSource(uint8 copy_uint8ClkSource)
{
	switch (copy_uint8ClkSource)
	{
		case HSI:
				
				/*Set The HSI To be the System Clock Source By Set SW Bits 0b00*/
				 SET_SPECIFIC_REG_BITS_VALUE(RCC -> RCC_CFGR, RCC_CFGR_SW_BITS_MASK, HSI);
		break;
		
		case HSE:
				
				/*Set The HSE To be the System Clock Source By Set SW Bits 0b01*/
				 SET_SPECIFIC_REG_BITS_VALUE(RCC -> RCC_CFGR, RCC_CFGR_SW_BITS_MASK, HSE);
		break;
				
		case PLL:
		
				/*Set The PLL To be the System Clock Source By Set SW Bits 0b10*/
				SET_SPECIFIC_REG_BITS_VALUE(RCC -> RCC_CFGR, RCC_CFGR_SW_BITS_MASK, PLL);
		break;
		
		default:  
				/*ERROR*/
		break;
	}
}

/**************************************************************************************************************************************
* Function Name		: MRCC_voidSetPeripheralClock																                      *
* Parameters (in)	: uint8 copy_uint8Bus, uint8 copy_uint8Peripheral, uint8 copy_uint8Status						                  *
* Parameters (out)	: None																						                      *
* Return value		: None							 															    	              *
* Description		: Function To Enable Or Disable Clock Sources To a specific Perephiral						                      *
**************************************************************************************************************************************/
void MRCC_voidSetPeripheralClock(uint8 copy_uint8Bus, uint8 copy_uint8Peripheral, uint8 copy_uint8Status)
{
	/*Switch Which Bus Needed*/
	 switch(copy_uint8Bus)
	 {
		case AHB:
				/*Switch which status Wanted Enable Or Disable*/
				switch (copy_uint8Status)
				{
					case CLK_ENABLE :
							
							/*Enable The Clock To The Wanted Perephiral On AHB*/
							 SET_BIT(RCC -> RCC_AHBENR, copy_uint8Peripheral);
					break;
					case CLK_DISABLE:
							
							/*Disable The Clock To The Wanted Perephiral On AHB*/
							 CLR_BIT(RCC -> RCC_AHBENR, copy_uint8Peripheral);
					break;
					
					default:
							/*ERROR*/
					break;
				}
		break;

		case APB1:
				/*Switch which status Wanted Enable Or Disable*/
				switch (copy_uint8Status)
				{
					case CLK_ENABLE :

							/*Enable The Clock To The Wanted Perephiral On APB1*/
							 SET_BIT(RCC -> RCC_APB1ENR, copy_uint8Peripheral);
					break;
					case CLK_DISABLE: 
					
							/*Disable The Clock To The Wanted Perephiral On APB1*/
							 CLR_BIT(RCC -> RCC_APB1ENR, copy_uint8Peripheral);
					break;
					
					default:    
							/*ERROR*/
					break;
				}
		break;

		case APB2:
				/*Switch which status Wanted Enable Or Disable*/
				switch (copy_uint8Status)
				{
					case CLK_ENABLE :

							/*Enable The Clock To The Wanted Perephiral On APB2*/
							 SET_BIT(RCC -> RCC_APB2ENR,copy_uint8Peripheral);
					break;
					case CLK_DISABLE: 
					
							/*Disable The Clock To The Wanted Perephiral On APB2*/
							 CLR_BIT(RCC -> RCC_APB2ENR,copy_uint8Peripheral);
					break;
					
					default:
							/*ERROR*/
					break;
				}
		break;

		default:    
				/*ERROR*/
		break;
	 }
}
