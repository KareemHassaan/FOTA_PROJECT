/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						12 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: SPI Driver                                                        							                      *
* ! File Name	: SPI_program.c                                                       							                      *
* ! Description : This file has the implementation of Basic of SPI functions        							                      *
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
#include"../../include/MCAL/08-SPI/SPI_interface.h"  
#include"../../include/MCAL/08-SPI/SPI_private.h"
#include"../../include/MCAL/08-SPI/SPI_config.h"

/***************************************************** Global Variables **************************************************************/

/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MSPI_voidInit																			                      	  *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Iniit SPI Configrations	 					          					  						  *
**************************************************************************************************************************************/
void MSPI_voidInit()
{
	uint16 Local_uint16CR1 = 0;
	
	SPI1 -> SPI_CR1 = 0;
	
	Local_uint16CR1 |= BIDIRECTIONAL_DATA_MODE_ENABLE	<< BIDIMODE_BIT;
	Local_uint16CR1 |= OUTPUT_ENABLE_IN_BIDIRECTIONAL	<< BIDIOE_BIT;
	Local_uint16CR1 |= HARDWARE_CRC_ENABLE				<< CRCEN_BIT;
	Local_uint16CR1 |= CRC_TRANSFER_NEXT				<< CRCNEXT_BIT;
	Local_uint16CR1 |= DATA_FRAME_FORMAT				<< DFF_BIT;
	Local_uint16CR1 |= RECEIVE_ONLY						<< RXONLY_BIT;
	Local_uint16CR1 |= SOFTWARE_SLAVE_MANAGEMENT		<< SSM_BIT;
	Local_uint16CR1 |= INTERNAL_SLAVE_SELECT			<< SSI_BIT;
	Local_uint16CR1 |= FRAME_FORMAT						<< LSBFIRST_BIT;
	Local_uint16CR1 |= SPI_ENABLE						<< SPE_BIT;
	Local_uint16CR1 |= BAUD_RAT_CONTROL					<< BR_BIT;
	Local_uint16CR1 |= MASTER_SELECTION					<< MSTR_BIT;
	Local_uint16CR1 |= CLOCK_POLARITY					<< CPOL_BIT;
	Local_uint16CR1 |= CLOCK_PHASE						<< CPHA_BIT;
	
	SPI1 -> SPI_CR1 = Local_uint16CR1; //0x0347 for TFT
	SPI1 -> SPI_CR2 = (TX_BUFFER_EMPTY_INTERRUPT_ENABLE			<< TXEIE_BIT)\
					  |(RX_BUFFER_NOT_EMPTY_INTERRUPT_ENABLE	<< RXNEIE_BIT)\
					  |(ERROR_INTERRUPT_ENABLE					<< ERRIE_BIT)\
					  |(SS_OUTPUT_ENABLE						<< SSOE_BIT);
}

/**************************************************************************************************************************************
* Function Name		: MSPI_voidTranscieve																	                      	  *
* Parameters (in)	: uint16 Copy_uint16Dat																			                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Send And Receive 	 							          					  						  *
**************************************************************************************************************************************/
uint16 MSPI_voidTranscieve(uint16 Copy_uint16Data)
{
	/*Put Data In the Register*/
	SPI1 -> SPI_DR = Copy_uint16Data;
	 
	/*check the Busy Flag*/
	while(GET_BIT(SPI1 -> SPI_SR, BSY_BIT) == 1);
	
	/*Reading the Recived Data*/
	return SPI1 -> SPI_DR;
}

/**************************************************************************************************************************************
* Function Name		: MSPI_voidTransmit																		                      	  *
* Parameters (in)	: uint16 Copy_uint16Data																		                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Transmit Data	 								          					  						  *
**************************************************************************************************************************************/
void MSPI_voidTransmit(uint16 Copy_uint16Data)
{
	/*Put Data In the Register*/
	SPI1 -> SPI_DR = Copy_uint16Data;
	 
	/*check the Busy Flag*/
	while(GET_BIT(SPI1 -> SPI_SR, BSY_BIT) == 1);
}

/**************************************************************************************************************************************
* Function Name		: MSPI_voidReceive																		                      	  *
* Parameters (in)	: uint16 * Copy_uint16Data																		                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Receive Data	 									       					  						  *
**************************************************************************************************************************************/
void MSPI_voidReceive(uint16 * Copy_uint16Data)
{
	/*Reading the Recived Data*/
	*Copy_uint16Data = SPI1 -> SPI_DR;
}

/**************************************************************************************************************************************
* Function Name		: MSPI_voidDMAEnable																	                      	  *
* Parameters (in)	: uint8 Copy_uint8Direction, uint8 Copy_uint8Status												                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Enable or Disable Making DMA Request	 		          					  						  *
**************************************************************************************************************************************/
void MSPI_voidDMARequestEnable(uint8 Copy_uint8Direction, uint8 Copy_uint8Status)
{
	switch(Copy_uint8Direction)
	{
		case TRANSMIT:
				switch(Copy_uint8Status)
				{
					case SPI_DISABLE:
							
							CLR_BIT(SPI1 -> SPI_CR2, TXDMAEN_BIT);
					break;
					case SPI_ENABLE:
							
							SET_BIT(SPI1 -> SPI_CR2, TXDMAEN_BIT);
					break;
				}
		break;
		
		case RECEIVE:
				switch(Copy_uint8Status)
				{
					case SPI_DISABLE:
					
							CLR_BIT(SPI1 -> SPI_CR2, RXDMAEN_BIT);
					break;
					case SPI_ENABLE:
					
							SET_BIT(SPI1 -> SPI_CR2, RXDMAEN_BIT);
					break;
				}
		break;
	}
}

