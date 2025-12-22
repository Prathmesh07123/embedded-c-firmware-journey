/*  
 *Problem: Find maximum and minimum in array
 *
 * Firmware Usage: 
 * Used in ADC sample analysis
 * to detect sensor range limit
 */

#include <stdint.h>
#include <stdio.h>

#define ARRAY_SIZE 8

static int16_t adc_samples[ARRAY_SIZE] = {  //statics load value in RAM safely //16bit = 65535(max)
    120, 340, 560, 230, 90, 800, 410, 275
};

int main(void){

    int16_t max = adc_samples[0];
    int16_t min = adc_samples[0];

    uint8_t i;

    for(i = 1; i < ARRAY_SIZE; i++){
        if(adc_samples[i] > max){
            max = adc_samples[i];
        }
        if(adc_samples[i] < min){
            min = adc_samples[i];
        }
    }

    printf("ADC Sample : ");
    for(uint8_t i = 0; i < ARRAY_SIZE; i++){
        printf("%d ", adc_samples[i]);
    }
    printf("\n");

    printf("Maximum value in ADC sample : %d \n", max);
    printf("Minimum value in ADC sample : %d \n", min);
}