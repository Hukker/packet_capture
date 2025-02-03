#include "Stream.h"
#include <string>

Stream::Stream(const std::string& src_ip, const std::string& dst_ip, uint16_t src_port, uint16_t dst_port)
    : src_ip(src_ip), dst_ip(dst_ip), src_port(src_port), dst_port(dst_port) {}

Stream::Stream() : src_ip(""), dst_ip(""), src_port(0), dst_port(0), packet_count(0), byte_count(0) {}

void Stream::addPacket(uint32_t bytes) {
    packet_count++;
    byte_count += bytes;
}

std::string Stream::toCSVFormat() const {
    return src_ip + "," + dst_ip + "," + std::to_string(src_port) + "," + std::to_string(dst_port) +
        "," + std::to_string(packet_count) + "," + std::to_string(byte_count);
}