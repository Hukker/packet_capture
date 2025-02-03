#pragma once
#ifndef STREAM_H
#define STREAM_H

#include <string>

class Stream {
public:
    std::string src_ip;
    std::string dst_ip;
    uint16_t src_port;
    uint16_t dst_port;
    uint32_t packet_count = 0;
    uint32_t byte_count = 0;

    Stream(const std::string& src_ip, const std::string& dst_ip, uint16_t src_port, uint16_t dst_port);
    Stream();

    void addPacket(uint32_t bytes);
    std::string toCSVFormat() const;
};

#endif