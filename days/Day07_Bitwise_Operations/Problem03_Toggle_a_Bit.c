/*
 * Problem 03: Toggle a Bit
 *
 * Firmware Usage:
 * - LED toggling
 * - Debug pin control
 * - State flipping
 */

#include <stdint.h>
#include <stdio.h>

void toggle_bit(uint8_t *reg, uint8_t pos);

void toggle_bit(uint8_t *reg, uint8_t pos){

    *reg ^= (1 << pos);

}

int main(void){

    uint8_t gpio_reg = 0x00;

    toggle_bit(&gpio_reg, 3);

    printf("Register: 0x%02X\n", gpio_reg);

    return 0;
}