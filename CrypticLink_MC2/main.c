/*
 * main.c (Slave)
 *
 * Created on: Mar 15, 2024
 * Author: ad
 */

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/SPI/SPI_interface.h"
#include "HAL/LCD/LCD_HAL_interface.h"
#include <util/delay.h>


int main(void) {
    // Initialize SPI as Slave
    SPI_vidInit();
    // Initialize LCD
    LCD_enuInit();

    uint8_t receivedData;

    	SPI_enuSlaveReceive_Char(&receivedData);
    	LCD_enuSendData(receivedData);
    while (1) {
        // Receive data from SPI


    }

    return 0;
}
