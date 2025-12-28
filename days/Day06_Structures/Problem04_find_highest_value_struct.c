/*
 * Problem 04: Find Highest Value Structure
 *
 * Firmware Usage:
 * - Peak sensor detection
 * - Thermal monitoring
 * - Safety threshold checks
 * - Control loop decisions
 */

#include <stdint.h>
#include <stdio.h>

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

const IMU_Data_t *find_max_temperature(const IMU_Data_t *buf, uint8_t len);

const IMU_Data_t *find_max_temperature(const IMU_Data_t *buf, uint8_t len){

    if(len == 0){
        return NULL;
    }

    const IMU_Data_t *max = buf;
    const IMU_Data_t *end = buf + len;

    while(buf < end){
        if(buf->temperature > max->temperature){
            max = buf;
        }
        buf++;
    }

    return max;
}


int main(void){

    IMU_Data_t imu_buffer[IMU_BUFFER_SIZE] = {
        {100, 200, 300, 1, 2, 3, 30},
        {120, 210, 310, 2, 3, 4, 32},
        {110, 220, 320, 3, 4, 5, 29},
        {130, 230, 330, 4, 5, 6, 35},
        {140, 240, 340, 5, 6, 7, 31}
    };

    const IMU_Data_t *max_temp_sample = find_max_temperature(imu_buffer, IMU_BUFFER_SIZE);

    if(max_temp_sample != NULL){
        printf("Highest Temperature Found:\n");
        printf("Temp : %d | Accel: %d %d %d | Gyro: %d %d %d\n",
                max_temp_sample->temperature,
                max_temp_sample->accel_x,
                max_temp_sample->accel_y,
                max_temp_sample->accel_z,
                max_temp_sample->gyro_x,
                max_temp_sample->gyro_y,
                max_temp_sample->gyro_z);
    }

    return 0;
    
}