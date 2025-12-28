/*
 * Problem 04: Check Bit State
 *
 * Firmware Usage:
 * - Read GPIO input state
 * - Check interrupt flags
 * - Status register validation
 */

#include <stdio.h>
#include <stdint.h>

uint8_t is_bit_set(uint8_t *reg, uint8_t pos);

uint8_t is_bit_set(uint8_t *reg, uint8_t pos){
    
    return (*reg & (1 << pos)) != 0;
    
}

int main(void){

    uint8_t gpio_reg = 0x02;

    if(is_bit_set(&gpio_reg, 1)){
        printf("Bit is Set!");
    }
    else{
        printf("Bit is Clear!");
    }

    return 0;
}
