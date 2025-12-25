/*
 * Problem: Find Duplicate Elements Using Pointers
 *
 * Firmware Usage:
 * - Detect repeated sensor readings
 * - UART RX data validation
 * - Protocol frame sanity checks
 * - Fault detection in sampled data
 */

#include <stdio.h>
#include <stdint.h>

#define MAX_SIZE 10

void find_duplicates(uint16_t *arr, uint8_t len);

void find_duplicates(uint16_t *arr, uint8_t len){

    uint16_t *p1, *p2;
    uint8_t found;

    for(p1 = arr; p1 < arr + len; p1++){

        found = 0;
        for(p2 = p1 + 1; p2 < arr + len; p2++){
            if(*p1 == *p2){
                found = 1;
                break;
            }
        }
        if (found){
        
            printf("Duplicate found: %u\n", *p1);
        }
    }

}


int main(void){
    uint16_t samples[MAX_SIZE] = {10, 20, 30, 20, 40, 50, 30};
    uint8_t length = 7;

    find_duplicates(samples, length);

    return 0;
}