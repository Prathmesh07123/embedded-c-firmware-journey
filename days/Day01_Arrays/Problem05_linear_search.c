/*
 * Problem: Linear search in array
 *
 * Firmware Usage:
 * Used in lookup tables, command matching, ID detection
 */

#include <stdint.h>
#include <stdio.h>

#define ARRAY_SIZE 8

static uint16_t lookup_table[] = {
    120, 340, 560, 230, 90, 800, 410, 275
};

int main(void){

    uint8_t i;
    uint16_t target = 230;
    int8_t found_index = -1;

    for(i = 0; i < ARRAY_SIZE; i++){

        if(lookup_table[i] == target){
            found_index = i;
            break;
        }
    }

    if(found_index >= 0){
        printf("Value %u found at index %d\n", target, found_index);
    }
    else{
        printf("Value %u not found\n", target);
    }

    return 0;
}
