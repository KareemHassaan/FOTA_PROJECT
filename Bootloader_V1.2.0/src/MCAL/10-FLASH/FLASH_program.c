/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						02 MAR,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: FLASH Driver                                           							                     		 	  *
* ! File Name	: FLASH_program.c                                   		                   						                  *
* ! Description : This file has the implementation of Basic of FLASH functions  					   						          *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL	                  						                                         							  *
**************************************************************************************************************************************/

/**************************************************** Library Inclusions *************************************************************/
#include "../../include/LIB/BIT_MATH.h"
#include "../../include/LIB/STD_TYPES.h"
/************************************************** Lower Layer Inclusions ***********************************************************/


/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/
#include "../../include/MCAL/10-FLASH/FLASH_interface.h"
#include "../../include/MCAL/10-FLASH/FLASH_private.h"
#include "../../include/MCAL/10-FLASH/FLASH_config.h"

/***************************************************** Global Variables **************************************************************/

/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: HWIFI_VoidInit																				                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
void MFLASH_voidWrite(uint32 Copy_uint32Address, uint16 * Copy_uint16Data, uint8 Copy_uint8Length)
{
	uint8 Local_uint8LoopCounter;

	while(GET_BIT(FLASH-> FLASH_SR, BSY_BIT) == 1);

	FlashUnlock();

	for (Local_uint8LoopCounter = 0; Local_uint8LoopCounter< Copy_uint8Length; Local_uint8LoopCounter++)
	{
		/* Write Flash Programming */
		SET_BIT(FLASH->FLASH_CR, PG_BIT);

		/* Half word operation */
		*((volatile uint16*)Copy_uint32Address) = Copy_uint16Data[Local_uint8LoopCounter];
		Copy_uint32Address += 2 ;

		/* Wait Busy Flag */
		while (GET_BIT(FLASH->FLASH_SR, BSY_BIT) == 1);

		/* EOP */
		SET_BIT(FLASH->FLASH_SR, EOP_BIT);
		CLR_BIT(FLASH->FLASH_CR, PG_BIT);
	}
}

/**************************************************************************************************************************************
* Function Name		: HWIFI_VoidInit																				                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
void MFLASH_voidPageErase(uint8 Copy_uint8PageNum )
{
	while(GET_BIT(FLASH-> FLASH_SR, BSY_BIT) == 1);

	FlashUnlock();

	SET_BIT(FLASH->FLASH_CR, PER_BIT);

	FLASH->FLASH_AR =  (FLASH_PAGE0_ADDRESS) + (uint32) (Copy_uint8PageNum * PageSize);

	SET_BIT(FLASH->FLASH_CR, STRT_BIT);

	while(GET_BIT(FLASH-> FLASH_SR, BSY_BIT) == 1);

	SET_BIT(FLASH->FLASH_SR, EOP_BIT);

	CLR_BIT(FLASH->FLASH_CR, PER_BIT);
}

/**************************************************************************************************************************************
* Function Name		: HWIFI_VoidInit																				                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
void MFLASH_voidAreaErase(void)
{
	uint8 Local_uint8LoopCounter;

	for(Local_uint8LoopCounter = START_PAGE; Local_uint8LoopCounter < END_PAGE; Local_uint8LoopCounter++)
	{
		MFLASH_voidPageErase(Local_uint8LoopCounter);
	}
}

/**************************************************************************************************************************************
* Function Name		: HWIFI_VoidInit																				                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
static void FlashUnlock(void)
{
	if(GET_BIT(FLASH->FLASH_CR, LOCK_BIT) == 1)
		{
			FLASH->FLASH_KEYR = KEY1;
			FLASH->FLASH_KEYR = KEY2;
		}
}
