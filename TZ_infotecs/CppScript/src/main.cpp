#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include "PacketClassifier.h"
#include "PacketCapture.h"

int main() {
    PacketClassifier classifier;
    PacketCapture capture("1_packet.pcap");

    capture.start(classifier);
    classifier.writeCSV("output.csv");
        
    
    return 0;
}
