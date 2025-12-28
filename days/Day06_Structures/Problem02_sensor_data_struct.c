/*
 * Problem 02: Sensor Data Structure
 *
 * Firmware Usage:
 * - IMU drivers
 * - Telemetry frames
 * - DMA buffers
 * - Control loops
 */

#include <stdint.h>
#include <stdio.h>

typedef struct{

    int16_t accel_x;
    int16_t accel_y;
    int16_t accel_z;

    int16_t gyro_x;
    int16_t gyro_y;
    int16_t gyro_z;

    int16_t temperature;
} IMU_Data_t;

void print_imu_data(const IMU_Data_t *data);

void print_imu_data(const IMU_Data_t *data){
    printf("Accel : X=%d, Y=%d, Z=%d\n", 
                data->accel_x, data->accel_y, data->accel_z);

    printf("Gyro  : X=%d, Y=%d, Z=%d\n", 
                data->gyro_x, data->gyro_y, data->gyro_z);

    printf("Temp  : %d\n", data->temperature);
}

int main(void){

    IMU_Data_t imu_sample = {
        .accel_x = 1024,
        .accel_y = -512,
        .accel_z = 16384,
        .gyro_x  = 25,
        .gyro_y  = -10,
        .gyro_z  = 5,
        .temperature = 32
    };

    print_imu_data(&imu_sample);

    return 0;

}

