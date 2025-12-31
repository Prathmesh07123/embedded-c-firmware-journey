/*
 * Problem 03: Return Pointer from Function
 *
 * Firmware Usage:
 * - Sensor calibration data
 * - Driver internal buffers
 * - Configuration blocks
 */

#include <stdio.h>
#include <stdint.h>

#define MAX_SIZE 10

uint16_t* get_max(uint16_t *arr, uint8_t len);

uint16_t* get_max(uint16_t *arr, uint8_t len){

    if(arr == NULL || len == 0){
        return NULL;
    }

    uint16_t *max = arr;
    uint16_t *end = arr + len;
    arr++;

    while(arr < end){
        if(*arr > *max){
            max = arr;
        }
        arr++;
    }

    return max;
}



int main(void){

    uint16_t buffer_sample[MAX_SIZE] = {125, 254, 987, 542, 123};
    uint8_t length = 5;

    uint16_t *max = get_max(buffer_sample, length);

    if(max != NULL){
        printf("Max value = %u\n", *max);   
    }

    return 0;
}