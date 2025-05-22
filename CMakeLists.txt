cmake_minimum_required(VERSION 3.5)
project(uav-control)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(uav-control
    src/main.cpp
    src/NetworkClient.cpp
)
