/*
 * Problem: Count Frequency of an Element Using Pointers
 *
 * Firmware Usage:
 * - UART RX command parsing
 * - Error and fault repetition counting
 * - Sensor data validation
 * - Protocol frame analysis
 */

#include <stdio.h>
#include <stdint.h>

#define MAX_SIZE 10

uint8_t count_frequency(const uint16_t *arr, uint8_t len, uint16_t target);

uint8_t count_frequency(const uint16_t *arr, uint8_t len, uint16_t target){
    uint8_t count = 0;
    const uint16_t *p = arr;

    while(p < arr + len){
        if(*p == target){
            count++;
        }
        p++;
    }
    return count;
}

int main(void){
    uint16_t samples[MAX_SIZE] = {10, 20, 30, 20, 40, 20, 50};
    uint8_t length = 7;
    uint16_t target = 20;

    uint8_t freq = count_frequency(samples, length, target);

    printf("Value %u appears %u times\n", target, freq);

    return 0;
}