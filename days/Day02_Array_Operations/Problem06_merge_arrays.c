/*
 * Problem: Merge two arrays
 *
 * Firmware Usage:
 * Used in packet assembly, sensor data aggregation,
 * and UART/DMA transmit buffers
 */

#include <stdint.h>
#include <stdio.h>

#define MAX_SIZE 10

static uint16_t buffer1[] = {10, 20, 30};
static uint16_t buffer2[] = {40, 50};

static uint8_t len1 = 3;
static uint8_t len2 = 2;

static uint16_t merged_buffer[MAX_SIZE];
static uint8_t merged_len = 0;

int main(void){

    uint8_t i;

    for(i = 0; i < len1; i++){
        merged_buffer[merged_len++] = buffer1[i];
    }

    for(i = 0; i < len2; i++){
        merged_buffer[merged_len++] = buffer2[i];
    }

    printf("Merged Buffer: ");

    for (i = 0; i < merged_len; i++){
        printf("%u ", merged_buffer[i]);
    }
    
    printf("\n");

    return 0;
}