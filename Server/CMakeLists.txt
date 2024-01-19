cmake_minimum_required(VERSION 3.27)
project(Server)

set(CMAKE_CXX_STANDARD 17)

add_executable(Server main.cpp
        src/Headers/WinsockServer.h
        src/Headers/WinsockServer.h
)

target_link_libraries(Server wsock32 ws2_32)

