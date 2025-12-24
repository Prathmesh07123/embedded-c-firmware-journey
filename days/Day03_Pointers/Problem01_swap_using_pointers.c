/*
 * Problem: Swap Two Numbers Using Pointers
 *
 * Firmware Usage:
 * ISR-safe value swapping, register value manipulation
 */


#include <stdint.h>
#include <stdio.h>

void swap(uint32_t *a, uint32_t *b);

void swap(uint32_t *a, uint32_t *b){
    uint32_t temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){

    uint32_t A = 10, B = 20;

    printf("Value of A Before Swapping : %lu\n", A);
    printf("Value of B Before Swapping : %lu\n", B);

    swap(&A, &B);

    printf("Value of A After Swapping : %lu\n", A);
    printf("Value of B After Swapping : %lu\n", B);

    return 0;
}
