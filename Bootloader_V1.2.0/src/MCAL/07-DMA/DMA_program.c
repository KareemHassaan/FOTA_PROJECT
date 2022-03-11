/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						11 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: DMA Driver                                                        							                      *
* ! File Name	: DMA_program.c                                                       							                      *
* ! Description : This file has the implementation of Basic of DMA functions        							                      *
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
#include"../../include/MCAL/07-DMA/DMA_interface.h"  
#include"../../include/MCAL/07-DMA/DMA_private.h"
#include"../../include/MCAL/07-DMA/DMA_config.h"

/***************************************************** Global Variables **************************************************************/
static void (*GlobalChannels_CBK_Array)();
/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MDMA_voidInit																			                      	  *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To 		 										          					  						  *
**************************************************************************************************************************************/
void MDMA_voidChannelSetup(uint8 Channel_uint8Num, Channel_Config_t * Channel_Cfg)
{
	uint32 CCR_Config = 0;
	
	CCR_Config |= ((Channel_Cfg -> MEM2MEM) 		<< PIN14);
	CCR_Config |= ((Channel_Cfg -> PINC) 			<< PIN6);
	CCR_Config |= ((Channel_Cfg -> MINC) 			<< PIN7);
	CCR_Config |= ((Channel_Cfg -> Priority_Level) 	<< PIN12);
	CCR_Config |= ((Channel_Cfg -> MSIZE) 			<< PIN10);
	CCR_Config |= ((Channel_Cfg -> PSIZE) 			<< PIN8);
	CCR_Config |= ((Channel_Cfg -> DIR) 			<< PIN4);
	CCR_Config |= ((Channel_Cfg -> Circular) 		<< PIN5);
	CCR_Config |= ((Channel_Cfg -> Half_TX_IE) 		<< PIN2);
	CCR_Config |= ((Channel_Cfg -> Full_TX_IE) 		<< PIN1);
	CCR_Config |= ((Channel_Cfg -> Error_IE) 		<< PIN3);
	
	DMA1 -> DMA_Channel[Channel_uint8Num].CCR = CCR_Config;
}

/**************************************************************************************************************************************
* Function Name		: MDMA_voidInit																			                      	  *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To 		 										          					  						  *
**************************************************************************************************************************************/
void MDMA_voidChannelStart(uint8 Channel_uint8Num, uint32 * Source, uint32 * Destination, uint16 Block_Size)
{
	/*Checking the channel is Disabled*/
	DMA1 -> DMA_Channel[Channel_uint8Num].CCR |= DISABLE;
	/*Set Block size*/
	DMA1 -> DMA_Channel[Channel_uint8Num].CNDTR = Block_Size;
	/*Set Destination Address*/
	DMA1 -> DMA_Channel[Channel_uint8Num].CPAR |= (uint32)Source;
	/*Set Source Address*/
	DMA1 -> DMA_Channel[Channel_uint8Num].CMAR |= (uint32)Destination;
	/*Enable The Channel To start DMA*/
	DMA1 -> DMA_Channel[Channel_uint8Num].CCR |= ENABLE;
}
/**************************************************************************************************************************************
* Function Name		: MDMA_voidInit																			                      	  *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To 		 										          					  						  *
**************************************************************************************************************************************/
void MDMA_voidSetCallBack(uint8 Channel_uint8Num, void (*Channel_CBK)())
{
	GlobalChannels_CBK_Array = Channel_CBK;
}

/*************************************************************************************************************************************/
/*************************************************** DMA1 Channel_1 Handler **********************************************************/
/*************************************************************************************************************************************/
void DMA1_Channel1_IRQHandler(void)
{
	if(NULL != GlobalChannels_CBK_Array)
	{
		GlobalChannels_CBK_Array(); 
	}		
}
