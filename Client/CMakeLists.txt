cmake_minimum_required(VERSION 3.12)
project(Client)

set(CMAKE_CXX_STANDARD 14)

add_executable(Client
        main.cpp
        src/MenuItems.cpp
        src/Menu.cpp
        src/Order.cpp
        src/Customer.cpp
        src/Specials.cpp
        src/WinsockClient.cpp
        src/MenuItems.h
        src/Menu.h
        src/Order.h
        src/Customer.h
        src/Specials.h
        src/WinsockClient.h)

target_link_libraries(Client PRIVATE -lwsock32 -lws2_32)
