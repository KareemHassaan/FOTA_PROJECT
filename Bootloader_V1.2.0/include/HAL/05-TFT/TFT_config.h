/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						13 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Infera Red Driver   		                             							                                  *
* ! File Name	: TFT_config.h                   	                                   							                  	  *
* ! Description : This file has the Configrations needed		     		        	 						                      *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL	                  						                                         							  *
**************************************************************************************************************************************/
#ifndef TFT_CONFIG_H
#define TFT_CONFIG_H

/**************************************************************************************************************************************
* MACRO		: 	To Configure The Infera Red Port																	         		  *
* options	:	GPIO_PORTA		/		GPIO_PORTB		/		GPIO_PORTC		/													  *
**************************************************************************************************************************************/
#define TFT_PORT									GPIO_PORTA

#define TFT_A0_PIN									GPIO_PIN0
#define TFT_RST_PIN									GPIO_PIN1
#define TFT_SCK_PIN									GPIO_PIN2
#define TFT_SDA_PIN									GPIO_PIN3



#endif /*TFT_CONFIG_H*/  
