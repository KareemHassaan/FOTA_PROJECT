/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						02 MAR,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: FLASH Driver	    		                                                							              *
* ! File Name	: FLASH_private.h                                   		                  						                  *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                       							      *
**************************************************************************************************************************************/

#ifndef MCAL_10_FLASH_FLASH_PRIVATE_H_
#define MCAL_10_FLASH_FLASH_PRIVATE_H_

#define FLASH										((volatile FLASH_t *) 0x40022000 )
#define FLASH_PAGE0_ADDRESS							(0x08000000)
#define PageSize									1024


typedef struct
{
		volatile uint32 FLASH_ACR;
		volatile uint32 FLASH_KEYR;
		volatile uint32 FLASH_OPTKEYR;
		volatile uint32 FLASH_SR;
		volatile uint32 FLASH_CR;
		volatile uint32 FLASH_AR;
		volatile uint32 RESERVED;
		volatile uint32 FLASH_OBR;
		volatile uint32 FLASH_WRPR;

}FLASH_t;


#define BSY_BIT											0
#define LOCK_BIT										7
#define	PER_BIT											1
#define STRT_BIT										6
#define EOP_BIT											5
#define PG_BIT											0

#define KEY1  		 									0x45670123
#define	KEY2 											0xCDEF89AB

/*************************************************************************************************************************************/
/********************************************** Static Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: HWIFI_VoidInit																				                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize the Pins Of The Infera Red	Module									                      *
**************************************************************************************************************************************/
static void FlashUnlock(void);

#endif /* MCAL_10_FLASH_FLASH_PRIVATE_H_ */
