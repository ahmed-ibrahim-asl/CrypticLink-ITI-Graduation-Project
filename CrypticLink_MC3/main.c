/*
 * main.c
 *
 *  Created on: Aug 2, 2024
 *      Author: ad
 */


/******************** Include  Section Start ********************/
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/SPI/SPI_interface.h"
#include "MCAL/TIMER/TIMER_interface.h"

#include "HAL/LCD/LCD_HAL_interface.h"
#include "HAL/LED/LED_Interface.h"
#include <util/delay.h>
/****************************************************************/

#define EXTRACT_DEVICE(frame) ((frame >> 5) & 0b111)
#define EXTRACT_CONTROL_MODE(frame) ((frame >> 4) & 0b1)
#define EXTRACT_SPEED(frame) ((frame >> 2) & 0b11)



int main(){

    TIMER0_voidInit();
    TIMER2_voidInit();
    LCD_enuInit();

    LED_voidInit(DIO_u8PortC, DIO_u8PIN3);  // GREEN  LED
    LED_voidInit(DIO_u8PortC, DIO_u8PIN4);  // YELLOW LED
    LED_voidInit(DIO_u8PortC, DIO_u8PIN5);  // RED    LED

    SPI_vidInit();
    uint8_t Local_u8ReceivedData = 0;
    uint8_t Local_u8Device, Local_u8ControlMode, Local_u8Speed;


    while(1){
        SPI_enuSlaveReceive_Char(&Local_u8ReceivedData);

        // Unpack the received frame
        Local_u8Device = EXTRACT_DEVICE(Local_u8ReceivedData);
        Local_u8ControlMode = EXTRACT_CONTROL_MODE(Local_u8ReceivedData);
        Local_u8Speed = EXTRACT_SPEED(Local_u8ReceivedData);


        switch(Local_u8Device){
            case 0x00:

            	LCD_u8SetPosXY(0, 0);
                LCD_enuClearDisplay();

                LCD_u8SendString("Motor 1");
                LCD_u8SetPosXY(0, 2);



                if(Local_u8ControlMode == 1){
                	switch(Local_u8Speed){
                		case 0b00:
                			LCD_u8SendString("LoW Speed");
                            TIMER0_voidSetPWM(100);
                        break;

                		case 0b01:
                			LCD_u8SendString("Medium Speed");
                			TIMER0_voidSetPWM(155);
                		break;

                		case 0b10:
                			LCD_u8SendString("High Speed");
                			TIMER0_voidSetPWM(255);
                	}
                }


                else if(Local_u8ControlMode == 0){
                    LCD_u8SendString("OFF ");
                    TIMER0_voidSetPWM(0);
                }

            break;
            case 0x01:
            	LCD_u8SetPosXY(0, 0);
                LCD_enuClearDisplay();

                LCD_u8SendString("Motor 2");
                LCD_u8SetPosXY(0, 2);



                if(Local_u8ControlMode == 1){
                	switch(Local_u8Speed){
                		case 0b00:
                			LCD_u8SendString("LoW Speed");
                            TIMER2_voidSetPWM(100);
                        break;

                		case 0b01:
                			LCD_u8SendString("Medium Speed");
                			TIMER2_voidSetPWM(155);
                		break;

                		case 0b10:
                			LCD_u8SendString("High Speed");
                			TIMER2_voidSetPWM(255);
                	}
                }


                else if(Local_u8ControlMode == 0){
                    LCD_u8SendString("OFF ");
                    TIMER2_voidSetPWM(0);
                }

            break;
            case 0x02:
                LCD_u8SetPosXY(0, 0);
                LCD_enuClearDisplay();

                LCD_u8SendString("LED1_RED");
                LCD_u8SetPosXY(0, 2);

                if(Local_u8ControlMode == 0){
                    LCD_u8SendString("OFF ");
                    LED_voidOFF(DIO_u8PortC, DIO_u8PIN5);
                }else if(Local_u8ControlMode == 1){
                    LCD_u8SendString("ON ");
                    LED_voidON(DIO_u8PortC, DIO_u8PIN5);
                }

            break;
            case 0x03:
                LCD_u8SetPosXY(0, 0);
                LCD_enuClearDisplay();

                LCD_u8SendString("LED2_YELLOW");
                LCD_u8SetPosXY(0, 2);

                if(Local_u8ControlMode == 0){
                    LCD_u8SendString("OFF ");
                    LED_voidOFF(DIO_u8PortC, DIO_u8PIN4);
                }else if(Local_u8ControlMode == 1){
                    LCD_u8SendString("ON ");
                    LED_voidON(DIO_u8PortC, DIO_u8PIN4);
                }

            break;
            case 0x04:
                LCD_u8SetPosXY(0, 0);
                LCD_enuClearDisplay();

                LCD_u8SendString("LED3_GREEN");
                LCD_u8SetPosXY(0, 2);

                if(Local_u8ControlMode == 0){
                    LCD_u8SendString("OFF ");
                    LED_voidOFF(DIO_u8PortC, DIO_u8PIN3);
                }else if(Local_u8ControlMode == 1){
                    LCD_u8SendString("ON ");
                    LED_voidON(DIO_u8PortC, DIO_u8PIN3);
                }
            break;
        }

        _delay_ms(500); // Short delay to prevent LCD flickering
    }

    return 0;
}
