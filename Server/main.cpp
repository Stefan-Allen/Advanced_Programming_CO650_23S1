#include <chrono>
#include <thread>
#include "src/WinsockServer.h"

int main() {
    // Abstract process of running a Winsock server.
    // Encapsulation of WinsockServer encapsulated within the WinsockServer class.
    WinsockServer winsockServer(3011);

    while (true) {
        // Incoming connections handling them
        if (!winsockServer.AcceptConnection()) {
            break;
        }
    }

    return 0;
}
