/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						09 MAR,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: WIFI Driver                                           							                     		 	  *
* ! File Name	: WIFI_program.c                                   		                   						                      *
* ! Description : This file has the implementation of Basic of WIFI functions  					   						              *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL	                  						                                         							  *
**************************************************************************************************************************************/

/**************************************************** Library Inclusions *************************************************************/

#include "../../include/LIB/STD_TYPES.h"
#include "../../include/LIB/BIT_MATH.h"

/************************************************** Lower Layer Inclusions ***********************************************************/

#include"../../include/MCAL/01-RCC/RCC_interface.h"
#include"../../include/MCAL/02-GPIO/GPIO_interface.h"
#include"../../include/MCAL/03-NVIC/NVIC_interface.h"
#include"../../include/MCAL/04-EXTI/EXTI_interface.h"
#include"../../include/MCAL/05-SYS_TICK/SYS_TICK_interface.h"
#include"../../include/MCAL/06-AFIO/AFIO_interface.h"
#include"../../include/MCAL/09-UART/UART_interface.h"
#include"../../include/HAL/06-WIFI/WIFI_intrface.h"
 
#define UPDATE	 						'1'
#define HEX_END  						1 
#define SCB_VTOR 						*((volatile uint32*)0xE000ED08)
#define VECTOR_TABLE_ADDRESS 			0x08002000
#define ENTRY_POINT_APP		 			0x08002004

/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/

/***************************************************** Global Variables **************************************************************/
uint8 Global_uint8Record[100] = {0};

typedef void (*PointerToFunction_t)(void);
PointerToFunction_t Application_Address = 0;

/*************************************************************************************************************************************/
/********************************************** SW Interrupt Call Back Function ******************************************************/
/*************************************************************************************************************************************/
void SW_INT_CBKFunc(void)
{
	/*Setting the Address of Vector table of the Application*/
	SCB_VTOR = VECTOR_TABLE_ADDRESS;

	/*Jumping to the First address in the Entry Point of the application*/
	Application_Address = *(PointerToFunction_t*)(ENTRY_POINT_APP);
	Application_Address();
}

/*************************************************************************************************************************************/
/********************************************************* Main Function *************************************************************/
/*************************************************************************************************************************************/
void main ()
{
	/*Initialize The RCC Peripheral and all about it*/
	MRCC_voidInit();
	MRCC_voidSetPeripheralClock(APB2, IOPA,CLK_ENABLE);
	MRCC_voidSetPeripheralClock(APB2, USARTEN, CLK_ENABLE);

	/*Initialize The NVIC Peripheral and all about it*/
	MNVIC_voidEnableInterrupt(NVIC_EN_USART1);
	MNVIC_voidEnableInterrupt(NVIC_EN_EXTI0);

	/*Initialize The EXTI Peripheral and all about it*/
	MEXTI_VoidInit();
	MEXTI_VoidEnableLine(EXTI0);
	EXTI_vidsetCallBack(EXTI0, SW_INT_CBKFunc);

	/*Initialize the GPIO Pins Tx and Rx of theb UART*/
	MGPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN9, OUTPUT_MODE_MAX_SPEED_2_MHZ, ALTERNATE_FUNCTION_OUTPUT_PUSH_PULL);
	MGPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN10, INPUT_MODE, FLOATING_INPUT);
	
	
	/*Initialize The Systick Peripheral*/
	MSYS_TICK_voidInit();
	/*Initialize The UART Peripheral*/
	MUART_voidInit();
	
	/*Initialize The WIFI Module*/
	HWIFI_voidInit();
	/*Connecting the Wifi To the Router*/
	HWIFI_voidConnectToWifi();
	/*Connecting the Wifi To the Server*/
	HWIFI_voidConnectToServer();
	/*Sending HTTP Request To the Server*/
	HWIFI_VoidSendHttpRequest((uint8*)"http://iti-nc.freevar.com/upgrade.txt", (uint8*)"43");
	/*Receiving The Record From the Server*/
	HWIFI_VoidReceiveRecord(Global_uint8Record);

	/*Checking uf there is an update on the server or not*/
	if(Global_uint8Record[0] != UPDATE)
	{
		/* SW Interrupt to jump on the APP*/
		MEXTI_VoidSetSWInterrupt(EXTI0);
	}
	else if(Global_uint8Record[0] == UPDATE)
	{
		/*Clearing the Application Area (Pages in Flash)*/
		MFLASH_voidAreaErase();

		/*Checking reach the End of the Hex file*/
		while(Global_uint8Record[8] != HEX_END)
		{
			/*Connecting the Wifi To the Server*/
			HWIFI_voidConnectToServer();
			/*Sending HTTP Request To the Server*/
			HWIFI_VoidSendHttpRequest((uint8*)"http://iti-nc.freevar.com/Recive.php?response=OK", (uint8*)"54");
			
			/*Reconnecting the Wifi To the Server*/
			HWIFI_voidConnectToServer();
			/*Sending HTTP Request To the Server*/
			HWIFI_VoidSendHttpRequest((uint8*)"http://iti-nc.freevar.com/code.txt", (uint8*)"40");
			
			/*Receiving The Record From the Server*/
			HWIFI_VoidReceiveRecord(Global_uint8Record);
			/*Wrinting Data In the Falash from the Record*/
			Parser_voidParseRecord(Global_uint8Record);
		}
	}
}
