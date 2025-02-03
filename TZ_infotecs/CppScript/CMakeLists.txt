
cmake_minimum_required(VERSION 3.10)

project(PcapProcessingApp)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/libs/lib)

link_directories(${PROJECT_SOURCE_DIR}/libs)

set(SOURCES
    src/main.cpp
    src/Stream.h
    src/Stream.cpp
    src/PacketCapture.cpp
    src/PacketCapture.h
    src/PacketClassifier.cpp
    src/PacketClassifier.h
)

add_executable(PcapProcessingApp ${SOURCES})

target_link_libraries(PcapProcessingApp
    Pcap++.lib
    Common++.lib
    Packet++.lib
    Packet.lib
    wpcap.lib
    Ws2_32.lib
)
