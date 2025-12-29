/*
 * Problem 01: Pass Array to Function
 *
 * Firmware Usage:
 * - UART RX buffer processing
 * - ADC sample analysis
 * - DMA buffer parsing
 * - Sensor data streams
 */

#include <stdio.h>
#include <stdint.h>

#define MAX_SIZE 10

void print_buffer(const uint16_t *buf, uint8_t len);

void print_buffer(const uint16_t *buf, uint8_t len){

    if(buf == NULL | len == 0){
        return;
    }

    const uint16_t *end = buf + len;

    printf("ADC Samples : ");
    while(buf < end){
        printf("%u ", *buf);
        buf++;
    }
    printf("\n");
}

int main(void){

    uint16_t adc_samples[MAX_SIZE] = {10, 20, 30, 40, 50};
    uint8_t length = 5;

    print_buffer(adc_samples, length);

    return 0;
    
}