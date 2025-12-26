/*
 * Problem: Reverse Strings Using Pointers
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

void reverse_string(char *str);

void reverse_string(char *str){

    char *start = str;
    char *end = str;

    while(*end != '\0'){
        end++;
    }
    end--;

    while(start < end){
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

}

int main(void){

    char String[] = "Hello";

    char *str = String;

    printf("String Before Reverse : ");
    while(*str != '\0'){
        printf("%c", *str);
        str++;
    }
    printf("\n");

    reverse_string(String);
    char *rstr = String;

    printf("String After Reverse : ");
    while(*rstr != '\0'){
        printf("%c", *rstr);
        rstr++;
    }
    printf("\n");

    return 0;
}