/*
 * Problem: Copy Array Using Pointers
 *
 * Firmware Usage:
 * Used in signal processing buffers, DMA data reordering,
 * endianness correction, and sample post-processing.
 */

#include <stdint.h>
#include <stdio.h>

#define MAX_SIZE 10

uint8_t copy_buffer(uint16_t *dst, const uint16_t *src, uint8_t len);

uint8_t copy_buffer(uint16_t *dst, const uint16_t *src, uint8_t len){

    if(len == 0){
        return 1;
    }

    const uint16_t *end = src + len;
    while(src < end){
        *dst = *src;
        src++;
        dst++;
    }

    return 0;
}

int main(void){

    uint16_t src_buffer[MAX_SIZE] = {10, 20, 30, 40, 50};
    uint16_t dst_buffer[MAX_SIZE];

    uint8_t length = 5;

    uint8_t is_successful = copy_buffer(dst_buffer, src_buffer, length);

    uint16_t *src = src_buffer, *dst = dst_buffer;

    if(is_successful == 0){
        printf("Successful Copy Buffer...\n");
        printf("Source Buffer : ");
        while(src < src_buffer + length){
            printf("%u ", *src);
            src++;
        }
        printf("\n");
        printf("Destination Buffer : ");
        while(dst < dst_buffer + length){
            printf("%u ", *dst);
            dst++;
        }
        printf("\n");
    }

    return 0;
}