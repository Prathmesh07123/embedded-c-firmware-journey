/*
 * Problem 01: Set a Bit
 *
 * Firmware Usage:
 * - GPIO output control
 * - Register configuration
 * - Enable peripheral features
 */

#include <stdint.h>
#include <stdio.h>

void set_bit(uint8_t *reg, uint8_t pos);

void set_bit(uint8_t *reg, uint8_t pos){

    *reg |= (1 << pos);
}

int main(void){

    uint8_t gpio_reg = 0x00;

    set_bit(&gpio_reg, 3);

    printf("Register: 0x%02X\n", gpio_reg);

    return 0;
}
