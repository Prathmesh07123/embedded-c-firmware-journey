/*
 * Problem: Sum of array elements
 *
 * Firmware Usage:
 * Used for ADC averaging and sensor filtering
 */

#include <stdint.h>
#include <stdio.h>

#define ARRAY_SIZE 8

static uint16_t adc_samples[ARRAY_SIZE] = {
    120, 340, 560, 230, 90, 800, 410, 275
};

int main(void){

    uint8_t i;
    uint32_t sum = 0;

    for(i = 0; i < ARRAY_SIZE; i++){
        sum += adc_samples[i];
    }

    printf("Sum of ADC samples: %lu\n", sum);

    return 0;
}
