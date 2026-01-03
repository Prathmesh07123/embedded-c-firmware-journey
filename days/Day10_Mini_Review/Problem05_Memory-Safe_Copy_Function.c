/*
 * Problem 05: Memory-Safe Copy Function
 *
 * Firmware Usage:
 * - UART RX buffers
 * - Protocol parsing
 * - DMA data handling
 * - Bootloader memory safety
 */

#include <stdint.h>
#include <stdio.h>

int8_t safe_memcpy(uint8_t *dst, uint8_t dst_size, const uint8_t *src, uint8_t src_len);

int8_t safe_memcpy(uint8_t *dst, uint8_t dst_size, const uint8_t *src, uint8_t src_len){

    if(dst == NULL || src == NULL){
        return -1;
    }

    if(src_len > dst_size){
        return -2;
    }

    while(src_len--){
        *dst = *src;
        dst++;
        src++;
    }

    return 0;
}

int main(void){

    uint8_t rx_buffer[10];
    uint8_t uart_data[] = {1, 2, 3, 4, 5};

    int8_t status = safe_memcpy(rx_buffer, sizeof(rx_buffer), uart_data, sizeof(uart_data));

    if(status == 0){
        printf("Copy successful: ");
        for(uint8_t i = 0; i < sizeof(uart_data); i++){
            printf("%u ", rx_buffer[i]);
        }
        printf("\n");
    }
    else{
        printf("Copy failed! Error = %d\n", status);
    }

    return 0;
}