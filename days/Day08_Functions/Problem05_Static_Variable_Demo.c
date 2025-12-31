/*
 * Problem 05: Static Variable Demo
 *
 * Firmware Usage:
 * - Driver state tracking
 * - ISR execution counters
 * - Retry logic
 * - One-time initialization flags
 */ 

#include <stdio.h>
#include <stdint.h>

void sensor_read_task(void);

void sensor_read_task(void){

    static uint32_t read_count = 0;

    read_count++;

    printf("Sensor read count : %lu\n", read_count);

}

int main(void){

    sensor_read_task();
    sensor_read_task();
    sensor_read_task();

    return 0;

}