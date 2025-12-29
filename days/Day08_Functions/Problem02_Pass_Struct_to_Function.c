/*
 * Problem 02: Pass Structure to Function
 *
 * Firmware Usage:
 * - IMU sensor data handling
 * - Telemetry packet formatting
 * - Sensor abstraction layers
 */

#include <stdio.h>
#include <stdint.h>

typedef struct{

    int16_t accel_x;
    int16_t accel_y;
    int16_t accel_z;

}IMU_Data_t;

void print_imu_data(const IMU_Data_t *imu);

void print_imu_data(const IMU_Data_t *imu){

    if(imu == NULL){
        return;
    }

    printf("IMU Data : \n");
    printf("X: %d\n", imu->accel_x);
    printf("Y: %d\n", imu->accel_y);
    printf("Z: %d\n", imu->accel_z);
}

int main(void){

    IMU_Data_t imu_sample = {
        .accel_x = 120,
        .accel_y = -95,
        .accel_z = 980
    };

    print_imu_data(&imu_sample);

    return 0;
}

