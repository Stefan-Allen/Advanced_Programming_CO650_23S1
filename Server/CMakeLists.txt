cmake_minimum_required(VERSION 3.27)
project(Server)

set(CMAKE_CXX_STANDARD 17)

add_executable(Server main.cpp
        src/WinsockServer.cpp
        src/WinsockServer.h
)

target_link_libraries(Server wsock32 ws2_32)

