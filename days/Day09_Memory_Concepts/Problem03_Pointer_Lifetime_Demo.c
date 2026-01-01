/*
 * Problem 03: Pointer Lifetime Demo
 *
 * Firmware Usage:
 * - Prevent returning invalid pointers
 * - Safe driver API design
 */

#include <stdio.h>
#include <stdint.h>

// uint32_t* wrong_pointer(void){
//     uint32_t temp = 50;
//     return &temp;
// }

uint32_t* safe_pointer(void){
    static uint32_t temp = 50;
    return &temp;
}

int main(void){

    //uint32_t *p1 = wrong_pointer();
    uint32_t *p2 = safe_pointer();

    //printf("Wrong Pointer Value : %lu\n", *p1);
    printf("Safe Pointer Value  : %lu\n", *p2);

    return 0;

}