/*
 * Problem: Struct Copy
 *
 * Firmware Usage:
 * - Copy IMU sample from ISR buffer to main buffer
 * - Build telemetry frames
 * - Data handoff between modules
 */

#include <stdio.h>
#include <stdint.h>

typedef struct {
    int16_t acc_x;
    int16_t acc_y;
    int16_t acc_z;
    float temp;
} IMU_Data_t;

void copy_imu_data(IMU_Data_t *dst, const IMU_Data_t *src);

void copy_imu_data(IMU_Data_t *dst, const IMU_Data_t *src){

    if(dst == NULL || src == NULL){
        return;
    }

    *dst = *src;
}

int main(void){

    IMU_Data_t imu_sensor = {
        .acc_x = 100,
        .acc_y = -50,
        .acc_z = 980,
        .temp = 38.5f
    };

    IMU_Data_t imu_copy;

    copy_imu_data(&imu_copy, &imu_sensor);

    printf("Copied IMU Data:\n");
    printf("AX: %d\n", imu_copy.acc_x);
    printf("AY: %d\n", imu_copy.acc_y);
    printf("AZ: %d\n", imu_copy.acc_z);
    printf("Temp: %.2f\n", imu_copy.temp);

    return 0;


}
