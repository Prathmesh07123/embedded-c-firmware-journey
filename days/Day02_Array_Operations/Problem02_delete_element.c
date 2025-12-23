/*
 * Problem: Delete element at a given position
 *
 * Firmware Usage:
 * Used in command buffers and data queues
 */

#include <stdint.h>
#include <stdio.h>

#define MAX_SIZE 10

static uint16_t buffer[MAX_SIZE] = {10, 20, 30, 40, 50};
static uint8_t length = 5;

int main(void)
{
    uint8_t pos = 3;  // delete index 3

    /* TODO:
     * 1. Validate position
     * 2. Shift elements left
     * 3. Decrease length
     */

    if(pos >= length){
        printf("Invalid position\n");
        return 0;
    }

    for(int8_t i = pos; i < length - 1; i++){
        buffer[i] = buffer[i + 1];
    }

    length--;

    printf("Buffer: ");
    for(uint8_t i = 0; i < length; i++)
    {
        printf("%u ", buffer[i]);
    }
    printf("\n");

    return 0;
}
