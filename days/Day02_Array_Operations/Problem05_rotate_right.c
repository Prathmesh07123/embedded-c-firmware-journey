/*
 * Problem: Rotate array right by 1
 *
 * Firmware Usage:
 * Used in circular buffers, time-shifted data,
 * and sensor queue management
 */

#include <stdint.h>
#include <stdio.h>

#define MAX_SIZE 10

static uint16_t buffer[MAX_SIZE] = {10, 20, 30, 40, 50};
static uint8_t length = 5;

int main(void){

    uint16_t temp = buffer[length - 1];

    for(uint8_t i = length - 1; i > 0; i--){
        buffer[i] = buffer[i - 1];
    }

    buffer[0] = temp;

    printf("Rotated Right: ");

    for (uint8_t i = 0; i < length; i++){
        printf("%u ", buffer[i]);
    }
    printf("\n");

    
    return 0;
}