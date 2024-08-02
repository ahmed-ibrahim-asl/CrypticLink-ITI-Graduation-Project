/*
 * main.c (Master)
 *
 * Created on: Mar 15, 2024
 * Author: ad
 */

/******************** Include  Section Start ********************/
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/SPI/SPI_interface.h"
#include "HAL/LCD/LCD_HAL_interface.h"
#include "HAL/keypad/keypad_HAL_interface.h"
#include <util/delay.h> // Include delay header
/****************************************************************/


uint8_t Handle_keyInput();





// Device Selection
#define MOTOR1              0b000
#define MOTOR2              0b001
#define LED1_RED            0b010
#define LED2_YELLOW         0b011
#define LED3_GREEN          0b100

// Control Mode
#define TURN_OFF            0b0
#define TURN_ON             0b1

// Speed Control (for Motors)
#define SPEED_NONE          0b11  // Special value for not applicable
#define SPEED_LOW           0b00
#define SPEED_MEDIUM        0b01
#define SPEED_HIGH          0b10


// Macro to create frame
#define CREATE_FRAME(device, control_mode, speed) ((device << 5) | (control_mode << 4) | ((device <= MOTOR2 ? speed : 0) << 2))





int main(void) {
    // Initialize SPI as Master
    SPI_vidInit();

    keypad_enuInit();
    LCD_enuInit();

    uint8_t Local_u8InputCheck = 1;
    uint8_t u8_keyInput = 0;


    while (1) {
//    SPI_enuMasterTransmit_String("Ahmed");


    	while(Local_u8InputCheck){
			LCD_enuClearDisplay();
			LCD_u8SendString("M1:1, M2:2, R:3");

			LCD_u8SetPosXY(0, 2);
			LCD_u8SendString("Y:4, G:5 > ");
			u8_keyInput = Handle_keyInput();

			if(u8_keyInput >= 49 && u8_keyInput <= 53  ){
				break;
			}
    	}

        switch(u8_keyInput){
        	case '1':
            	LCD_enuClearDisplay();
            	LCD_u8SendString("Motor 1, ON:1");
            	LCD_u8SetPosXY(0, 2);
            	LCD_u8SendString("OFF:0 > ");



				u8_keyInput = Handle_keyInput();
        		while(Local_u8InputCheck){
					if(u8_keyInput == '1'){
						// send signal to turn MOTOR  ON
						LCD_enuClearDisplay();
						LCD_u8SendString("LOW:1, Medium:2");
						LCD_u8SetPosXY(0, 2);
						LCD_u8SendString("High:3 > ");
						u8_keyInput = Handle_keyInput();

		        		while(Local_u8InputCheck){
							if(u8_keyInput == '1'){
								SPI_enuMasterTransmit_Char(CREATE_FRAME(MOTOR1, TURN_ON, SPEED_LOW));


								Local_u8InputCheck = 0;
							}else if(u8_keyInput == '2'){
								SPI_enuMasterTransmit_Char(CREATE_FRAME(MOTOR1, TURN_ON, SPEED_MEDIUM));


								Local_u8InputCheck = 0;
							}else if(u8_keyInput == '3'){
								SPI_enuMasterTransmit_Char(CREATE_FRAME(MOTOR1, TURN_ON, SPEED_HIGH));


								Local_u8InputCheck = 0;
							}
		        		}

						Local_u8InputCheck = 0;
					}else if(u8_keyInput == '0'){
						// send signal to turn RED LED OFF
						SPI_enuMasterTransmit_Char(CREATE_FRAME(MOTOR1, TURN_OFF, SPEED_NONE));

						Local_u8InputCheck = 0;
					}
        		}



            break;

        	case '2':
            	LCD_enuClearDisplay();
            	LCD_u8SendString("Motor 2, ON:1");
            	LCD_u8SetPosXY(0, 2);
            	LCD_u8SendString("OFF:0 > ");



				u8_keyInput = Handle_keyInput();
        		while(Local_u8InputCheck){
					if(u8_keyInput == '1'){
						// send signal to turn MOTOR  ON
						LCD_enuClearDisplay();
						LCD_u8SendString("LOW:1, Medium:2");
						LCD_u8SetPosXY(0, 2);
						LCD_u8SendString("High:3 > ");
						u8_keyInput = Handle_keyInput();

		        		while(Local_u8InputCheck){
							if(u8_keyInput == '1'){
								SPI_enuMasterTransmit_Char(CREATE_FRAME(MOTOR2, TURN_ON, SPEED_LOW));


								Local_u8InputCheck = 0;
							}else if(u8_keyInput == '2'){
								SPI_enuMasterTransmit_Char(CREATE_FRAME(MOTOR2, TURN_ON, SPEED_MEDIUM));


								Local_u8InputCheck = 0;
							}else if(u8_keyInput == '3'){
								SPI_enuMasterTransmit_Char(CREATE_FRAME(MOTOR2, TURN_ON, SPEED_HIGH));


								Local_u8InputCheck = 0;
							}
		        		}

						Local_u8InputCheck = 0;
					}else if(u8_keyInput == '0'){
						// send signal to turn RED LED OFF
						SPI_enuMasterTransmit_Char(CREATE_FRAME(MOTOR2, TURN_OFF, SPEED_NONE));

						Local_u8InputCheck = 0;
					}
        		}



        	break;

        	case '3':


        		while(Local_u8InputCheck){

					LCD_enuClearDisplay();
					LCD_u8SendString("RED LED, ON:1");
					LCD_u8SetPosXY(0, 2);
					LCD_u8SendString("OFF:0 > ");

					u8_keyInput = Handle_keyInput();
					if(u8_keyInput == '1'){
						// send signal to turn RED LED ON

						SPI_enuMasterTransmit_Char(CREATE_FRAME(LED1_RED, TURN_ON, SPEED_NONE));

						Local_u8InputCheck = 0;
					}else if(u8_keyInput == '0'){
						// send signal to turn RED LED OFF
						SPI_enuMasterTransmit_Char(CREATE_FRAME(LED1_RED, TURN_OFF, SPEED_NONE));

						Local_u8InputCheck = 0;
					}
        		}

            break;

        	case '4':

        		while(Local_u8InputCheck){

                	LCD_enuClearDisplay();
                	LCD_u8SendString("YELLOW LED, ON:1");
                	LCD_u8SetPosXY(0, 2);
                	LCD_u8SendString("OFF:0 > ");

					u8_keyInput = Handle_keyInput();
					if(u8_keyInput == '1'){
						// send signal to turn YELLOW LED ON
						SPI_enuMasterTransmit_Char(CREATE_FRAME(LED2_YELLOW, TURN_ON, SPEED_NONE));


						Local_u8InputCheck = 0;
					}else if(u8_keyInput == '0'){
						// send signal to turn YELLOW LED OFF
						SPI_enuMasterTransmit_Char(CREATE_FRAME(LED2_YELLOW, TURN_OFF, SPEED_NONE));

						Local_u8InputCheck = 0;
					}
        		}

        	break;

        	case '5':

        		while(Local_u8InputCheck){

                	LCD_enuClearDisplay();
                	LCD_u8SendString("GREEN LED, ON:1");
                	LCD_u8SetPosXY(0, 2);
                	LCD_u8SendString("OFF:0 > ");

					u8_keyInput = Handle_keyInput();
					if(u8_keyInput == '1'){
						// send signal to turn YELLOW LED ON
						SPI_enuMasterTransmit_Char(CREATE_FRAME(LED3_GREEN, TURN_ON, SPEED_NONE));


						Local_u8InputCheck = 0;
					}else if(u8_keyInput == '0'){
						// send signal to turn RED LED OFF
						SPI_enuMasterTransmit_Char(CREATE_FRAME(LED3_GREEN, TURN_OFF, SPEED_NONE));


						Local_u8InputCheck = 0;
					}
        		}


        	break;
        }

        Local_u8InputCheck = 1;
//        _delay_ms(4000);
    }

    return 0;
}


uint8_t Handle_keyInput() {
    uint8_t keyStatus = 0;
    uint8_t padPressedValue = 0;



    while(1){
		keyStatus = keypad_enuGetPressedKey(&padPressedValue);

		if (keyStatus == 0 && padPressedValue != 0) {
			LCD_enuSendData(padPressedValue);
			break;
		}

		while (keyStatus == 0 && padPressedValue != 0) {
			keyStatus = keypad_enuGetPressedKey(&padPressedValue);
		}

    }

    return padPressedValue;
}



