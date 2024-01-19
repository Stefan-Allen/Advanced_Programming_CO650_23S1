#include "../Headers/WinsockClient.h"
#include "../Headers/Exception.h"

#include <iostream>

WSADATA wsaData;

WinsockClient::WinsockClient(const std::string &serverIp, int serverPort)
    : serverIp(serverIp), serverPort(serverPort), clientSocket(INVALID_SOCKET) {
    InitializeWinsock();
}

WinsockClient::~WinsockClient() {
    try {
        CloseConnection();
        WSACleanup();
    } catch (const Exception& ex) {
        std::cerr << "Exception caught in WinsockClient destructor: " << ex.what() << std::endl;
    }
}

bool WinsockClient::InitializeWinsock() {
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        throw Exception("Error initializing Winsock.", WSAGetLastError());
    }
    return true;
}

bool WinsockClient::ConnectToServer() {
    struct sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(serverPort);
    inet_pton(AF_INET, serverIp.c_str(), &(serverAddress.sin_addr));

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        throw Exception("Error creating socket.", WSAGetLastError());
    }

    if (connect(clientSocket, reinterpret_cast<struct sockaddr*>(&serverAddress), sizeof(serverAddress)) == SOCKET_ERROR) {
        throw Exception("Error connecting to server.", WSAGetLastError());
    }

    return true;
}

bool WinsockClient::SendData(const std::string &data) {
    int result = send(clientSocket, data.c_str(), data.size(), 0);
    if (result == SOCKET_ERROR) {
        throw Exception("Error sending data.", WSAGetLastError());
    }
    return true;
}

bool WinsockClient::SendOrder(const std::string &itemName, int quantity, const std::string &customerName) {
    std::string orderMessage = "Item name:" " " + itemName + ", " " Quantity: " + std::to_string(quantity) + ", " " " +
                               customerName;

    int result = send(clientSocket, orderMessage.c_str(), orderMessage.size(), 0);
    if (result == SOCKET_ERROR) {
        throw Exception("Error sending order.", WSAGetLastError());
    }

    return true;
}

std::string WinsockClient::ReceiveData() {
    const int bufferSize = 1024;
    char buffer[bufferSize];
    memset(buffer, 0, bufferSize);

    int bytesRead = recv(clientSocket, buffer, bufferSize - 1, 0);
    if (bytesRead == SOCKET_ERROR) {
        throw Exception("Error receiving data.", WSAGetLastError());
    }

    return std::string(buffer, bytesRead);
}

void WinsockClient::CloseConnection() {
    if (clientSocket != INVALID_SOCKET) {
        closesocket(clientSocket);
        clientSocket = INVALID_SOCKET;
    }
}
