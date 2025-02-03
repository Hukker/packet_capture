#pragma once
#ifndef PACKET_CAPTURE_H
#define PACKET_CAPTURE_H

#include "PacketClassifier.h"
#include <iostream>
#include <string>
#include "PcapFileDevice.h"
#include "Stream.h"



class PacketCapture {
private:
    pcpp::PcapFileReaderDevice reader;

public:
    PacketCapture(const std::string& pcapFile);
    void start(PacketClassifier& classifier);
};

#endif