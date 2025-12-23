/*
 * Problem: Update element at a given position
 *
 * Firmware Usage:
 * Used in configuration updates and parameter tuning
 */

#include <stdint.h>
#include <stdio.h>

#define MAX_SIZE 10

static uint16_t buffer[MAX_SIZE] = {10, 20, 30, 40, 50};
static uint8_t length = 5;

int main(void)
{
    uint8_t pos = 1;        // position to update
    uint16_t new_value = 99;


    if(pos >= length){
        printf("Invalid position\n");
        return -1;
    }

    buffer[pos] = new_value;

    printf("Buffer: ");
    for(uint8_t i = 0; i < length; i++)
    {
        printf("%u ", buffer[i]);
    }
    printf("\n");

    return 0;
}
