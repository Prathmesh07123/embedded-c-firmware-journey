/*
 * Problem 02: Memory Size Analysis
 *
 * Firmware Usage:
 * - Stack overflow prevention
 * - Buffer placement decisions
 * - ISR-safe memory design
 */

#include <stdio.h>
#include <stdint.h>

uint8_t g_flag;
uint32_t g_counter;
uint16_t g_buffer[100];

void memory_demo(void);

void memory_demo(void){

    uint8_t s_flag;
    uint32_t s_counter;
    uint16_t s_buffer[10];

    printf("Size of Global Buffer : %lu\n", sizeof(g_buffer));
    printf("Size of Stack Buffer  : %lu\n", sizeof(s_buffer));
}

int main(void){

    printf("Size of uint8_t   : %lu\n", sizeof(uint8_t));
    printf("Size of uint16_t  : %lu\n", sizeof(uint16_t));
    printf("Size of uint32_t  : %lu\n", sizeof(uint32_t));

    memory_demo();

    return 0;

}