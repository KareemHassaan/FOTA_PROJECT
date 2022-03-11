/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						12 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: SPI Driver                                                        							                      *                     
* ! File Name	: SPI_intrface.h                                                     							                      *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#define TRANSMIT													0
#define RECEIVE														1

#define SPI_DISABLE														0
#define SPI_ENABLE														1

/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MSPI_voidInit																			                      	  *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Iniit SPI Configrations	 					          					  						  *
**************************************************************************************************************************************/
void MSPI_voidInit();
/**************************************************************************************************************************************
* Function Name		: MSPI_voidTranscieve																	                      	  *
* Parameters (in)	: uint16 Copy_uint16Dat																			                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Send And Receive 	 							          					  						  *
**************************************************************************************************************************************/
uint16 MSPI_voidTranscieve(uint16 Copy_uint16Data);
/**************************************************************************************************************************************
* Function Name		: MSPI_voidTransmit																		                      	  *
* Parameters (in)	: uint16 Copy_uint16Data																		                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Transmit Data	 								          					  						  *
**************************************************************************************************************************************/
void MSPI_voidTransmit(uint16 Copy_uint16Data);
/**************************************************************************************************************************************
* Function Name		: MSPI_voidReceive																		                      	  *
* Parameters (in)	: uint16 * Copy_uint16Data																		                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Receive Data	 									       					  						  *
**************************************************************************************************************************************/
void MSPI_voidReceive(uint16 * Copy_uint16Data);
/**************************************************************************************************************************************
* Function Name		: MSPI_voidDMAEnable																	                      	  *
* Parameters (in)	: uint8 Copy_uint8Direction, uint8 Copy_uint8Status												                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Enable or Disable Making DMA Request	 		          					  						  *
**************************************************************************************************************************************/
void MSPI_voidDMARequestEnable(uint8 Copy_uint8Direction, uint8 Copy_uint8Status);



#endif /*SPI_INTERFACE_H*/
