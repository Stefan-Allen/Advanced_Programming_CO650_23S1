#include "WinsockServer.h"
#include <iostream>

// Constructors, Used for initializing the state of WinsockServer.
WinsockServer::WinsockServer(int port) : port(port), serverSocket(INVALID_SOCKET) {
    if (InitializeWinsock() && BindSocket() && StartListening()) {
        std::cerr << "Successful" << std::endl;
    } else {
        std::cerr << "Initialization failure" << std::endl;
    }
}

// Destructors, for cleaning up resources.
WinsockServer::~WinsockServer() {
    closesocket(serverSocket);
    WSACleanup();
}

// Initializes Winsock library and server socket.
bool WinsockServer::InitializeWinsock() {
    WSADATA wsaData;
    return WSAStartup(MAKEWORD(2, 2), &wsaData) == 0;
}

// Binds server socket to specific port.
bool WinsockServer::BindSocket() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Error creating socket" << std::endl;
        return false;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    if (bind(serverSocket, reinterpret_cast<sockaddr *>(&serverAddr), sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Error binding socket: " << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        return false;
    }

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Error listening: " << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        return false;
    }

    return true;
}

// listening for incoming connections.
bool WinsockServer::StartListening() {
    return true;
}

// Accepts incoming connections from clients.
bool WinsockServer::AcceptConnection() {
    SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Error accepting connection: " << WSAGetLastError() << std::endl;
        return false;
    }

    std::cout << "------------------------\nClient connected" << std::endl;

    std::string receivedData = ReceiveData(clientSocket);
    HandleReceivedData(receivedData, clientSocket);

    CloseConnection(clientSocket);

    return true;
}

// Receives data from a connected client.
std::string WinsockServer::ReceiveData(SOCKET clientSocket) {
    const int bufferSize = 1024;
    char buffer[bufferSize];
    memset(buffer, 0, bufferSize);

    int bytesReceived = recv(clientSocket, buffer, bufferSize - 1, 0);

    if (bytesReceived <= 0) {
        return "";
    }

    return std::string(buffer, bytesReceived);
}

// Closes connection with a client.
void WinsockServer::CloseConnection(SOCKET clientSocket) {
    closesocket(clientSocket);
}

// Received data and sends a response back to the client.
void WinsockServer::HandleReceivedData(const std::string &receivedData, SOCKET clientSocket) {
    std::cout << "------------------------\nReceived order: " << receivedData << std::endl;

    // Respond to the client
    std::string response = "Order received successfully!";
    send(clientSocket, response.c_str(), response.length(), 0);
}
