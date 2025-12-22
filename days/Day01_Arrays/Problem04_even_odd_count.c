/*
 * Problem: Count even and odd numbers in array
 *
 * Firmware Usage:
 * Used for data classification and diagnostics counters
 */

#include <stdint.h>
#include <stdio.h>

#define ARRAY_SIZE 8

static uint16_t data_buffer[ARRAY_SIZE] = {
    120, 341, 560, 231, 90, 801, 410, 275
};

int main(void)
{
    uint8_t i;
    uint8_t even_count = 0;
    uint8_t odd_count  = 0;

    for(i = 0; i < ARRAY_SIZE; i++){
        if((data_buffer[i] % 2) == 0){
            even_count++;
        }
        else{
            odd_count++;
        }
    }

    printf("Even count: %u\n", even_count);
    printf("Odd  count: %u\n", odd_count);

    return 0;
}
