/*
 * Problem 04: Inline Function Usage
 *
 * Firmware Usage:
 * - Fast math helpers
 * - GPIO macros replacement
 * - ISR optimization
 */

#include <stdio.h>
#include <stdint.h>

static inline uint16_t max_u16(uint16_t a, uint16_t b);

static inline uint16_t max_u16(uint16_t a, uint16_t b){

    return (a < b) ? b : a;

}

int main(void){

    uint16_t sensor1 = 320;
    uint16_t sensor2 = 450;

    uint16_t max_value = max_u16(sensor1, sensor2);

    printf("Max Value : %u", max_value);

    return 0;
}