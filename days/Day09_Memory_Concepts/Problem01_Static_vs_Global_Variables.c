/*
 * Problem 01: Static vs Global Variables
 *
 * Firmware Usage:
 * - ISR-safe counters
 * - Driver internal states
 * - System status flags
 */

#include <stdint.h>
#include <stdio.h>

uint32_t global_count = 0;

static uint32_t static_file_count = 0;

void demo_counter(void){

    static uint32_t static_function_count = 0;

    global_count++;
    static_file_count++;
    static_function_count++;

    printf("Global Count            : %lu\n", global_count);
    printf("Static File Count       : %lu\n", static_file_count);
    printf("Static Funvtion Count   : %lu\n", static_function_count);
}

int main(void){

    demo_counter();
    demo_counter();
    demo_counter();

    return 0;

}