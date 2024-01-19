cmake_minimum_required(VERSION 3.12)
project(Client)

set(CMAKE_CXX_STANDARD 14)

add_executable(Client
        main.cpp
        src/Source/MenuItems.cpp
        src/Source/Menu.cpp
        src/Source/Order.cpp
        src/Source/Customer.cpp
        src/Source/Specials.cpp
        src/Source/WinsockClient.cpp
        src/Headers/MenuItems.h
        src/Headers/Menu.h
        src/Headers/Order.h
        src/Headers/Customer.h
        src/Headers/Specials.h
        src/Headers/WinsockClient.h
        src/Source/RegularOrder.cpp
        src/Headers/RegularOrder.h
        src/Headers/Exception.h
)

target_link_libraries(Client PRIVATE -lwsock32 -lws2_32)

target_include_directories(Client PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)