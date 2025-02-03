#pragma once
#ifndef PACKET_CLASSIFIER_H
#define PACKET_CLASSIFIER_H

#include <iostream>
#include <string>
#include <map>
#include "Packet.h"
#include "IPv4Layer.h"
#include "TcpLayer.h"
#include "UdpLayer.h"
#include <memory>
#include "PcapFileDevice.h"
#include "Stream.h"
#include <fstream>

class PacketClassifier {
private:
    std::map<std::string, Stream> streams;

public:
    void processPacket(const pcpp::Packet& packet);
    void writeCSV(const std::string& filename);
};

#endif