/*  
 *Problem: Reverse an array
 *
 * Firmware Usage: 
 * Used in signal processing buffers
 * or reversing DMA sample order
 */

#include <stdint.h>
#include <stdio.h>

#define ARRAY_SIZE 8

static int16_t buffer[ARRAY_SIZE] = {
    120, 340, 560, 230, 90, 800, 410, 275
};

int main(void)
{
    uint8_t i;
    int16_t temp;

    for(i = 0; i < (ARRAY_SIZE / 2); i++){  //Simple Swapping logic
        temp = buffer[i];
        buffer[i] = buffer[ARRAY_SIZE - 1 - i];
        buffer[ARRAY_SIZE - 1 - i] = temp;
    }

    printf("Reversed array: ");
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    return 0;
}