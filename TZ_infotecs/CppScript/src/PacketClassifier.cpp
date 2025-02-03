#include "PacketClassifier.h"
#include <fstream>

void PacketClassifier::processPacket(const pcpp::Packet& packet) {
    if (packet.isPacketOfType(pcpp::IPv4)) {
        auto ipLayer = packet.getLayerOfType<pcpp::IPv4Layer>();
        if (ipLayer != nullptr) {
            std::string src_ip = ipLayer->getSrcIPAddress().toString();
            std::string dst_ip = ipLayer->getDstIPAddress().toString();

            if (packet.isPacketOfType(pcpp::TCP)) {
                auto tcpLayer = packet.getLayerOfType<pcpp::TcpLayer>();
                uint16_t src_port = tcpLayer->getSrcPort();
                uint16_t dst_port = tcpLayer->getDstPort();
                std::string key = src_ip + dst_ip + std::to_string(src_port) + std::to_string(dst_port);
                if (streams.find(key) == streams.end()) {
                    streams[key] = Stream(src_ip, dst_ip, src_port, dst_port);
                }

                if (packet.getRawPacket() != nullptr) {
                    streams[key].addPacket(packet.getRawPacket()->getRawDataLen());
                }
            }
            else if (packet.isPacketOfType(pcpp::UDP)) {
                auto udpLayer = packet.getLayerOfType<pcpp::UdpLayer>();
                uint16_t src_port = udpLayer->getSrcPort();
                uint16_t dst_port = udpLayer->getDstPort();
                std::string key = src_ip + dst_ip;
                if (streams.find(key) == streams.end()) {
                    streams[key] = Stream(src_ip, dst_ip, src_port, dst_port);
                }
                if (packet.getRawPacket() != nullptr) {
                    streams[key].addPacket(packet.getRawPacket()->getRawDataLen());
                }
            }
        }
    }
}

void PacketClassifier::writeCSV(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        //file << "Src IP,Dst IP,Source Port,Destination Port,Packet Count,Byte Count" << std::endl;
        for (const auto& stream : streams) {
            file << stream.second.toCSVFormat() << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
}