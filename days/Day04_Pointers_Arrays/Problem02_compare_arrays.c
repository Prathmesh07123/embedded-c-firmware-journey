/*
 * Problem: Compare Two Arrays Using Pointers
 *
 * Firmware Usage:
 * - UART / SPI / I2C RX buffer validation
 * - DMA buffer integrity checks
 * - Protocol frame comparison (SBUS, MAVLink, AT commands)
 * - Sensor data consistency verification
 */

#include <stdint.h>
#include <stdio.h>

#define MAX_SIZE 10

int8_t compare_buffer(const uint16_t *buf1, const uint16_t *buf2, uint8_t len1, uint8_t len2);

int8_t compare_buffer(const uint16_t *buf1, const uint16_t *buf2, uint8_t len1, uint8_t len2){

    if(len1 != len2){
        return -1;
    }

    const uint16_t *end = buf1 + len1;

    while(buf1 < end){
        if(*buf1 != *buf2){
            return -2;
        }
        buf1++;
        buf2++;
    }

    return 0;
}


int main(void){

    uint16_t buffer1[MAX_SIZE] = {10, 20, 30, 40, 50};
    uint16_t buffer2[MAX_SIZE] = {10, 20, 30, 30, 50};

    uint8_t length1 = 5, length2 = 5;

    int8_t compare = compare_buffer(buffer1, buffer2, length1, length2);

    if(compare == 0){
        printf("Arrays are equal\n");
    }
    else if(compare == -1){
        printf("Arrays Length mismatch!\n");
    }
    else if(compare == -2){
        printf("Arrays Data mismatch!\n");
    }
  

    return 0;
}