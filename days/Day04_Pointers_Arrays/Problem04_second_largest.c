/*
 * Problem: Find Second Largest Element Using Pointers
 *
 * Firmware Usage:
 * - Peak & sub-peak detection in sensor data
 * - Signal analysis and thresholding
 * - Priority-based control decisions
 */

#include <stdio.h>
#include <stdint.h>

#define MAX_SIZE 10

int8_t second_largest(const uint16_t *arr, uint8_t len, uint16_t *result);

int8_t second_largest(const uint16_t *arr, uint8_t len, uint16_t *result){

    if(len < 2){
        return -1;
    }

    const uint16_t *p = arr;
    uint16_t largest, second;

    if(*p > *(p + 1)){
        largest = *p;
        second = *(p + 1);
    }
    else{
        second = *p;
        largest = *(p + 1);
    }

    p += 2;

    while(p < arr + len){
        if(*p > largest){
            second = largest;
            largest = *p;
        }
        else if(*p < largest && *p > second){
            second = *p;
        }
        p++;
    }
    *result = second;
    return 0; 
}

int main(void){

    uint16_t samples[MAX_SIZE] = {10, 50, 30, 40, 20};
    uint8_t length = 5;
    uint16_t second_max;

    if (second_largest(samples, length, &second_max) == 0) {
        printf("Second largest value: %u\n", second_max);
    } else {
        printf("Error: Not enough data\n");
    }

    return 0;


}