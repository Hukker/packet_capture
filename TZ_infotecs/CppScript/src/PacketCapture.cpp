#include "PacketCapture.h"
#include <iostream>

PacketCapture::PacketCapture(const std::string& pcapFile) : reader(pcapFile) {}

void PacketCapture::start(PacketClassifier& classifier) {
    if (!reader.open()) {
        std::cerr << "Error opening pcap file." << std::endl;
        return;
    }

    pcpp::RawPacket packet;

    while (reader.getNextPacket(packet)) {
        pcpp::Packet parsedPacket(&packet);
        classifier.processPacket(parsedPacket);
    }
}
