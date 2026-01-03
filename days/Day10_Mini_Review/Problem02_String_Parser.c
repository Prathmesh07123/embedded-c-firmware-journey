/*
 * Problem 02: String Parser
 *
 * Firmware Usage:
 * - AT command parsing
 * - UART CLI commands
 * - Configuration input
 */

#include <stdio.h>
#include <stdint.h>

uint8_t parase_set_command(const char *cmd, uint16_t *value);

uint8_t parase_set_command(const char *cmd, uint16_t *value){

    if(cmd == NULL || value == NULL){
        return 0;
    }

    if(*cmd != 'S' || *(cmd + 1) != 'E' || *(cmd + 2) != 'T' || *(cmd + 3) != '='){
        return 0;
    }

    cmd += 4;

    if(*cmd == '\0'){
        return 0;
    }

    uint16_t num = 0;

    while(*cmd != '\0'){

        if(*cmd < '0' || *cmd > '9'){
            return 0;
        }

        num = num * 10 + (*cmd - '0');
        cmd++;
    }
    
    *value = num;

    return 1;
    
}

int main(void){

    const char command[] = "SET=123";   
    uint16_t parsed_value = 0;

    if(parase_set_command(command, &parsed_value)){

        printf("Parsed Value : %u\n", parsed_value);

    }
    else{

        printf("Invalid Command!\n");

    }

    return 0;

}