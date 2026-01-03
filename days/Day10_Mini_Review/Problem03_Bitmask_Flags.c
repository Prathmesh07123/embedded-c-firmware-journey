/*
 * Problem 03: Bitmask Flags
 *
 * Firmware Usage:
 * - Status registers
 * - Driver state tracking
 * - Error flags
 * - RTOS event flags
 */

#include <stdio.h>
#include <stdint.h>

#define FLAG_SENSOR_READY   (1 << 0)
#define FLAG_DATA_VALID     (1 << 1)
#define FLAG_ERROR          (1 << 2)
#define FLAG_OVERTEMP       (1 << 3)

int main(void){

    uint8_t status = 0;

    status |= FLAG_SENSOR_READY;
    status |= FLAG_DATA_VALID;

    if(status & FLAG_SENSOR_READY){
        printf("Sensor is ready\n");
    }

    status |= FLAG_ERROR;   //Set error flag

    status &= ~FLAG_ERROR;  //Clear error flag

    status ^= FLAG_DATA_VALID;  //Toggle data valid

    if(!(status & FLAG_OVERTEMP)){
        printf("Temperature OK\n");
    }

    return 0;

}