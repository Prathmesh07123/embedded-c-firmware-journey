/*
 * Problem: Compare Two Strings Using Pointers
 *
 * Firmware Usage:
 * - AT command validation (e.g., "OK", "ERROR")
 * - Command parser in UART / USB communication
 * - Configuration string verification
 * - Protocol header and keyword matching
 * - Bootloader command authentication
 */

#include <stdint.h>
#include <stdio.h>

int8_t compare_string(const char *str1, const char *str2);

int8_t compare_string(const char *str1, const char *str2){


    while(*str1 != '\0'){
        if(*str1 != *str2){
            return -2;
        }
        str1++;
        str2++;
    }

    if(*str1 == '\0' && *str2 == '\0'){
        return 0;
    }

    return -1;
}

int main(void){

    const char CMD1[] = "ERROR";
    const char CMD2[] = "ERROR123";

    int8_t  result = compare_string(CMD1,CMD2);

    if(result == 0){
        printf("Both Commands are Same\n");
    }
    else if(result == -1){
        printf("Command Length Mismatch\n");
    }
    else{
        printf("Command Data Mismatch\n");
    }

    return 0;
}