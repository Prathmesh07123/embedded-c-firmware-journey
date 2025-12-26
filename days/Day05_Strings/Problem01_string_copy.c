/*
 * Problem: Copy String Using Pointers
 *
 * Firmware Usage:
 * - AT command processing
 * - UART RX/TX string buffers
 * - Telemetry packet assembly
 * - Configuration strings
 */

#include <stdint.h>
#include <stdio.h>

void copy_string(const char *str, char *dst);

void copy_string(const char *str, char *dst){

    while(*str != '\0'){
        *dst = *str;
        str++;
        dst++;
    }
    *dst = '\0';
}

int main(void){

    const char String[] = "Hello World";
    char Destination[15];

    copy_string(String, Destination);

    const char *str = String, *dst = Destination;

    printf("Source String : ");
    while(*str != '\0'){
        printf("%c", *str);
        str++;
    }
    printf("\n");

    printf("Destination String : ");
    while(*dst != '\0'){
        printf("%c", *dst);
        dst++;
    }
    printf("\n");

    return 0;
}