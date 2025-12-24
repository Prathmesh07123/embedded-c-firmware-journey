/*
 * Problem: Reverse Array Using Pointers
 *
 * Firmware Usage:
 * Used in signal processing buffers, DMA data reordering,
 * endianness correction, and sample post-processing.
 */

#include <stdint.h>
#include <stdio.h>

void Reverse_samples(uint16_t *p, uint8_t len);

void Reverse_samples(uint16_t *p, uint8_t len){

    uint8_t i;
    uint16_t temp;
    for(i = 0; i < (int)len/2; i++){
        temp = *(p + i);
        *(p + i) = *(p + (len - 1 - i));
        *(p + (len - 1 - i)) = temp;
    }
}

void Reverse_samples2(uint16_t *start, uint8_t len){

    uint16_t *end = start + len - 1;
    uint16_t temp;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

#define MAX_SIZE 10


int main(void){

    uint8_t length = 5;
    uint16_t samples[MAX_SIZE] = {10, 20, 30, 40, 50};
    uint16_t *ptr = samples;
    
    printf("Samples Before Reverse : ");

    while(ptr < samples + length){
        printf("%u ", *ptr);
        ptr++;
    }

    printf("\n");

    Reverse_samples2(samples, length);

    uint16_t *ptrs = samples;

    printf("Samples After Reverse : ");

    while(ptrs < samples + length){
        printf("%u ", *ptrs);
        ptrs++;
    }

    printf("\n");

    return 0;

}

