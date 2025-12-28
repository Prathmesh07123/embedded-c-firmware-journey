/*
 * Problem 01: Student Record System using Structure
 *
 * Firmware Usage:
 * - Telemetry records
 * - Sensor configuration blocks
 * - Device information tables
 */

#include <stdint.h>
#include <stdio.h>

typedef struct {
    uint16_t id;
    uint8_t age;
    uint16_t marks;   
} Student_t;

void print_student(const Student_t *s);

void print_student(const Student_t *s){

    printf("ID    : %u\n", s->id);
    printf("Age   : %u\n", s->age);
    printf("Marks : %u\n", s->marks);
}

int main(void){


    Student_t s1 = {101, 20, 85};

    print_student(&s1);

    return 0;


}
