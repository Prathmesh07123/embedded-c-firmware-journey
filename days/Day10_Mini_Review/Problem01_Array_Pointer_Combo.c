/*
 * Problem 01: Array + Pointer Combo
 *
 * Firmware Usage:
 * - ADC sample buffers
 * - DMA data processing
 * - Sensor averaging
 */

#include <stdint.h>
#include <stdio.h>

#define MAX_SIZE 10

uint32_t array_sum(const uint16_t *arr, uint8_t len);

uint32_t array_sum(const uint16_t *arr, uint8_t len){

    uint32_t sum = 0;
    const uint16_t *end = arr + len;

    while(arr < end){
        sum += *arr;
        arr++;
    }

    return sum;
}

int main(void){

    uint16_t Sample_Buffer[MAX_SIZE] = {100, 200, 300, 400, 500};
    uint8_t length = 5;

    uint32_t sum = array_sum(Sample_Buffer, length);

    printf("Sum : %lu\n", sum);

    return 0;
}