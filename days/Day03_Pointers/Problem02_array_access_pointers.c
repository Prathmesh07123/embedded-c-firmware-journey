/*
 * Problem: Array Access Using Pointers
 *
 * Firmware Usage:
 * DMA buffer traversal, ADC sample reading, UART RX parsing
 */

#include <stdio.h>
#include <stdint.h>

#define MAX_SIZE 10

static uint16_t samples[MAX_SIZE] = {10, 20, 30, 40, 50};
static uint8_t length = 5;

int main(void){

    uint16_t *ptr = samples;
    uint8_t i;

    printf("Samples in Buffer : ");

    // for(i = 0; i < length; i++){
    //     printf("%u ", *(ptr + i));
    // }

    while(ptr < samples + length){
        printf("%u ", *ptr);
        ptr++;
    }

    printf("\n");

    

    return 0;
}