cmake_minimum_required(VERSION 3.5)
project(uav-control)

set(CMAKE_CXX_STANDARD 11)

include_directories(include utils)

add_library(uav-control-lib
    src/NetworkClient.cpp
    utils/CLinuxTCPCom.cpp
)

add_executable(uav-control
    examples/main.cpp
)

target_link_libraries(uav-control PRIVATE uav-control-lib)
