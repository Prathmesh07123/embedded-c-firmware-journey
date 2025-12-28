/*
 * Problem 05: Count Set Bits
 *
 * Firmware Usage:
 * - Error flag analysis
 * - CRC pre-checks
 * - Diagnostic status decoding
 */

#include <stdint.h>
#include <stdio.h>

uint8_t count_set_bits(uint8_t value);

uint8_t count_set_bits(uint8_t value){

    uint8_t count = 0;

    while(value){
        count += value & 1;
        value >>= 1;
    }

    return count;
}

int main(void){

    uint8_t value = 0xD7;

    uint8_t set_bit_count = count_set_bits(value);

    printf("In Value : 0x%02X, %d Bits Sets!", value, set_bit_count);

    return 0;
}
