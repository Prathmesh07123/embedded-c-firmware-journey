/*
 * Problem 04: Const Correctness Demonstration
 *
 * Firmware Usage:
 * - Protect read-only data (Flash, ROM)
 * - Safer driver APIs
 * - Prevent accidental memory corruption
 */

#include <stdio.h>
#include <stdint.h>

void point_buffer(const uint16_t *buf, uint8_t len);

void point_buffer(const uint16_t *buf, uint8_t len){

    const uint16_t *end = buf + len;

    printf("Buffer : ");
    while(buf < end){
        printf("%u ", *buf);
        buf++;
    }
    printf("\n");
}

int main(void){

    uint16_t data1[5] = {10, 20, 30, 40, 50};
    uint16_t data2[5] = {1, 2, 3, 4, 5};

    const uint16_t *p1 = data1;
    //*p1 = 99;     //Not Allowed To Change Data
    p1 = data2;     //Allowed To Changed Address

    point_buffer(p1, 5);

    uint16_t *const p2 = data1;
    *(p2 + 1) = 100;    //Allowed To Modify Data
    //p2 = data2;       //Not Allowed To Change Address

    point_buffer(p2, 5);

    const uint16_t *const p3 = data2;
    //*p3 = 100;      //Not Allowed To Change Data
    //p3 = data2;     //Not Allowed To Change Address

    point_buffer(p3, 5);

    return 0;
}