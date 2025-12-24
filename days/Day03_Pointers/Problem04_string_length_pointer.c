/*
 * Problem: String Length Using Pointer
 *
 * Firmware Usage:
 * Used in UART RX command parsing, AT command handling,
 * protocol frame length detection.
 */

#include <stdint.h>
#include <stdio.h>

uint8_t stlen(const char *p);

uint8_t stlen(const char *p){

    uint8_t count = 0;
    while(*p != '\0'){
        count++;
        p++;
    }

    return count;
}

int main(void){

    char str[] = "Hello World";

    uint8_t length = stlen(str);

    printf("Length of a String : %u\n", length);

    return 0;
}