/*
 * Problem: Pointer Arithmetic
 *
 * Firmware Usage:
 * DMA increments memory address based on data width.
 * For uint16_t samples, DMA jumps 2 bytes per transfer.
 */

#include <stdint.h>
#include <stdio.h>



int main(void){

    uint16_t arr[5] = {10, 20, 30, 40, 50};
    uint16_t *p = arr;

    printf("Base address  : %p\n", (void*)p);
    printf("p + 1 address : %p\n", (void*)(p + 1));
    printf("p + 2 address : %p\n", (void*)(p + 2));

    return 0;

}