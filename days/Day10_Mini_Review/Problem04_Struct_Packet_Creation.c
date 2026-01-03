/*
 * Problem 04: Struct Packet Creation
 *
 * Firmware Usage:
 * - UART packets
 * - Telemetry frames
 * - Protocol communication
 */

#include <stdio.h>
#include <stdint.h>

typedef struct{

    uint8_t header;
    uint8_t device_id;
    uint8_t length;
    uint16_t data;
    uint8_t checksum;

} Packet_t;

uint8_t calculate_checksum(const Packet_t *pkt);

uint8_t calculate_checksum(const Packet_t *pkt){

    uint8_t sum = 0;

    sum += pkt->header;
    sum += pkt->device_id;
    sum += pkt->length;
    sum += (pkt->data & 0xFF);
    sum += (pkt->data >> 8);

    return sum;
}


int main(){

    Packet_t tx_packet;

    tx_packet.header = 0xAA;
    tx_packet.device_id = 0x01;
    tx_packet.length = sizeof(tx_packet.data);
    tx_packet.data = 1234;
    tx_packet.checksum = calculate_checksum(&tx_packet);

    printf("Packet Created:\n");
    printf("Header   : 0x%X\n", tx_packet.header);
    printf("Device ID: %u\n", tx_packet.device_id);
    printf("Length   : %u\n", tx_packet.length);
    printf("Data     : %u\n", tx_packet.data);
    printf("Checksum : 0x%X\n", tx_packet.checksum);

    return 0;

}