/*
 * Problem 05: Volatile Usage Demonstration
 *
 * Firmware Use Cases:
 * - ISR shared variables
 * - Hardware registers
 * - Flags updated outside main loop
 */

#include <stdint.h>
#include <stdio.h>

volatile uint8_t Button_Pressed = 0;

void EXTI_Button_IRQHandler(void){

    Button_Pressed = 1;

}

int main(void){

    printf("Waiting for button press...\n");

    uint32_t count = 0;

    while(Button_Pressed == 0){
        count++;
        if(count >= 1572000){
            count = 0;
            EXTI_Button_IRQHandler();
        }
    }

    printf("Button Pressed!\n");

    return 0;

}