/*
 * Problem: Rotate array left by 1
 *
 * Firmware Usage:
 * Used in circular buffers and sensor queues
 */

#include <stdint.h>
#include <stdio.h>

#define MAX_SIZE 10

static uint16_t buffer[MAX_SIZE] = {10, 20, 30, 40, 50};
static uint8_t length = 5;

int main(void){

    uint16_t temp = buffer[0];

    for(uint8_t  i = 0; i < length - 1; i++){
        buffer[i] = buffer[i + 1];
    }

    buffer[length - 1] = temp;

    printf("Rotated Left: ");

    for(uint8_t  i = 0; i < length; i++){
        printf("%u ", buffer[i]);
    }

    printf("\n");

    return 0;
}