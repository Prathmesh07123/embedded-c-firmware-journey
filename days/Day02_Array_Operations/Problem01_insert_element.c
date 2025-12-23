/*
 * Problem: Insert element at a given position
 *
 * Firmware Usage:
 * Used in sensor queues and command buffers
 */

#include <stdint.h>
#include <stdio.h>

#define MAX_SIZE 10

static uint16_t buffer[MAX_SIZE] = {10, 20, 30, 40, 50};
static uint8_t length = 5;

int main(void)
{
    uint8_t pos = 2;     // insert at index 2
    uint16_t value = 99;
    // uint8_t count = 0;
    // uint16_t temp;


    if (length >= MAX_SIZE) {
        printf("Buffer full, insertion not possible\n");
        return 0;
    }

    if(pos > length){
        printf("Invalid position\n");
        return 0;
    }

    for (int8_t i = length - 1; i >= pos; i--) {
        buffer[i + 1] = buffer[i];
    }

    buffer[pos] = value;

    length++;
    // for(uint8_t i = 0; i < MAX_SIZE; i++){
    //     if(buffer[i] != 0){
    //         count++;
    //     }
    // }

    // printf("count = %u\n", count);

    // if(count < MAX_SIZE){
    //     for(uint8_t i = count - 1; i >= pos; i--){
    //         buffer[i + 1] = buffer[i];
    //     }
    //     buffer[pos] = value;
    // }

    printf("Buffer: ");
    for(uint8_t i = 0; i < length; i++)
    {
        printf("%u ", buffer[i]);
    }
    printf("\n");

    return 0;
}
