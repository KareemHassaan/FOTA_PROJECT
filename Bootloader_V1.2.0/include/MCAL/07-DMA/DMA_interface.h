/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						11 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: DMA Driver                                                        							                      *                     
* ! File Name	: DMA_intrface.h                                                     							                      *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

typedef struct
{
	uint16 MEM2MEM			:1;
	uint16 PINC				:1;
	uint16 MINC				:1;
	uint16 Priority_Level	:2;
	uint16 MSIZE			:2;
	uint16 PSIZE			:2;
	uint16 DIR				:1;
	uint16 Circular			:1;
	uint16 Half_TX_IE		:1;
	uint16 Full_TX_IE		:1;
	uint16 Error_IE			:1;

}Channel_Config_t;
/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MDMA_voidInit																			                      	  *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To 		 										          					  						  *
**************************************************************************************************************************************/
void MDMA_voidChannelSetup(uint8 Channel_uint8Num, Channel_Config_t * Channel_Cfg);
/**************************************************************************************************************************************
* Function Name		: MDMA_voidInit																			                      	  *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To 		 										          					  						  *
**************************************************************************************************************************************/
void MDMA_voidChannelStart(uint8 Channel_uint8Num, uint32 * Source, uint32 * Destination, uint16 Block_Size);
/**************************************************************************************************************************************
* Function Name		: MDMA_voidInit																			                      	  *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To 		 										          					  						  *
**************************************************************************************************************************************/
void MDMA_voidSetCallBack(uint8 Channel_uint8Num, void (*Channel_CBK)());
#endif /*DMA_INTERFACE_H*/
