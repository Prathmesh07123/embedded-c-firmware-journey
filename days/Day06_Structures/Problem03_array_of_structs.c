/*
 * Problem 03: Array of Structures
 *
 * Firmware Usage:
 * - IMU sample buffers
 * - Telemetry batching
 * - DMA memory blocks
 * - Flash logging
 */

#include <stdio.h>
#include <stdint.h>

#define IMU_BUFFER_SIZE 5

typedef struct {
    int16_t accel_x;
    int16_t accel_y;
    int16_t accel_z;

    int16_t gyro_x;
    int16_t gyro_y;
    int16_t gyro_z;

    int16_t temperature;
} IMU_Data_t;

void print_imu_buffer(const IMU_Data_t *buf, uint8_t len);

void print_imu_buffer(const IMU_Data_t *buf, uint8_t len){

    const IMU_Data_t *end = buf + len;

    while(buf < end){
        printf("Accel : %d %d %d | Gyro : %d %d %d | Temp : %d\n",
                buf->accel_x, buf->accel_y, buf->accel_z, 
                buf->gyro_x, buf->gyro_y, buf->gyro_z,
                buf->temperature);
        buf++;
    }
}

int main(void){

    IMU_Data_t imu_buffer[IMU_BUFFER_SIZE] = {
        {100, 200, 300,  1,  2,  3, 30},
        {110, 210, 310,  2,  3,  4, 31},
        {120, 220, 320,  3,  4,  5, 32},
        {130, 230, 330,  4,  5,  6, 33},
        {140, 240, 340,  5,  6,  7, 34}
    };

    print_imu_buffer(imu_buffer, IMU_BUFFER_SIZE);

    return 0;
}