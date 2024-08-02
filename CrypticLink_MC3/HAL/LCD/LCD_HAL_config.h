/*
 * LCD_HAL_config.h
 *
 *  Created on: Jan 5, 2024
 *      Author: ad
 */

#ifndef HAL_LCD_HAL_CONFIG_H_
#define HAL_LCD_HAL_CONFIG_H_

///*************** Include Section Start ********************/
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_HAL_priv.h"
///**********************************************************/


/***************** Mode of Operation *****************/
// Options: FOUR_BIT or EIGHT_BIT
#define LCD_MODE 					FOUR_BIT
/****************************************************/


/******************* Control Pins *******************/

#define RS_PORT 			    	DIO_u8PortC
#define RS_PIN						DIO_u8PIN6


#define RW_PORT						DIO_u8PortC
#define RW_PIN						DIO_u8PIN0

#define EN_PORT 					DIO_u8PortC
#define EN_PIN						DIO_u8PIN7
/***************************************************/


/******************** Data Pins ********************/

#if(LCD_MODE == FOUR_BIT)
	/*Define 4digital pins*/
	#define LCD_DATA_PORT 	DIO_u8PortD


	#define DB7_PORT				DIO_u8PortD
	#define DB7_PIN					DIO_u8PIN3

	#define DB6_PORT				DIO_u8PortD
	#define DB6_PIN					DIO_u8PIN2

	#define DB5_PORT				DIO_u8PortD
	#define DB5_PIN					DIO_u8PIN1

	#define DB4_PORT				DIO_u8PortD
	#define DB4_PIN					DIO_u8PIN0
#endif

#if(LCD_MODE == EIGHT_BIT)
	#define LCD_DATA_PORT 	DIO_u8PortD


	#define DB7_PORT 				DIO_u8PortD
	#define DB7_PIN					DIO_u8PIN7

	#define DB6_PORT 				DIO_u8PortD
	#define DB6_PIN					DIO_u8PIN6

	#define DB5_PORT 				DIO_u8PortD
	#define DB5_PIN					DIO_u8PIN5

	#define DB4_PORT 				DIO_u8PortD
	#define DB4_PIN					DIO_u8PIN4

	#define DB3_PORT 				DIO_u8PortD
	#define DB3_PIN					DIO_u8PIN3

	#define DB2_PORT 				DIO_u8PortD
	#define DB2_PIN					DIO_u8PIN2

	#define DB1_PORT 				DIO_u8PortD
	#define DB1_PIN					DIO_u8PIN1

	#define DB0_PORT 				DIO_u8PortD
	#define DB0_PIN					DIO_u8PIN0

#endif


/***************************************************/


#endif /* HAL_LCD_HAL_CONFIG_H_ */
