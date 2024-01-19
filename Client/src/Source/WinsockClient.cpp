#include "../Headers/WinsockClient.h"
#include "../Headers/Exception.h"

#include <iostream>

WSADATA wsaData;

// Constructor: Initializes the Winsock library and sets member variables
WinsockClient::WinsockClient(const std::string &serverIp, int serverPort)
    : serverIp(serverIp), serverPort(serverPort), clientSocket(INVALID_SOCKET) {
    InitializeWinsock();
}

// Destrustor: Closes connection and cleans winsock resouces
WinsockClient::~WinsockClient() {
    try {
        CloseConnection();
        WSACleanup();
    } catch (const Exception &ex) {
        throw Exception("Exception caught in WinsockClient destructor:", WSAGetLastError());
    }
}

// Initializes the Winsock library
bool WinsockClient::InitializeWinsock() {
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        throw Exception("Error initializing Winsock.", WSAGetLastError());
    }
    return true;
}

// Connects to server using Encapsulation and Abstraction
bool WinsockClient::ConnectToServer() {
    // Set up server address
    struct sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(serverPort);
    inet_pton(AF_INET, serverIp.c_str(), &(serverAddress.sin_addr));

    // Create a socket using Encapsulation
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        throw Exception("Error creating socket.", WSAGetLastError());
    }

    // Connect to the server using Abstraction
    if (connect(clientSocket, reinterpret_cast<struct sockaddr *>(&serverAddress), sizeof(serverAddress)) ==
        SOCKET_ERROR) {
        throw Exception("Error connecting to server.", WSAGetLastError());
    }

    return true;
}

// Sends data to the connected server using Abstraction
bool WinsockClient::SendData(const std::string &data) {
    // Send data over the socket using Abstraction
    int result = send(clientSocket, data.c_str(), data.size(), 0);
    if (result == SOCKET_ERROR) {
        throw Exception("Error sending data.", WSAGetLastError());
    }
    return true;
}

// Sends an order message to the server using Abstraction
bool WinsockClient::SendOrder(const std::string &itemName, int quantity, const std::string &customerName) {
    std::string orderMessage = "Item name:" " " + itemName + ", " " Quantity: " + std::to_string(quantity) + ", " " " +
                               customerName;

    // Create an order message
    int result = send(clientSocket, orderMessage.c_str(), orderMessage.size(), 0);
    if (result == SOCKET_ERROR) {
        throw Exception("Error sending order.", WSAGetLastError());
    }

    return true;
}

// Receives data from the connected server sing Abstraction
std::string WinsockClient::ReceiveData() {
    const int bufferSize = 1024;
    char buffer[bufferSize];
    memset(buffer, 0, bufferSize);

    // Receive data from the socket
    int bytesRead = recv(clientSocket, buffer, bufferSize - 1, 0);
    if (bytesRead == SOCKET_ERROR) {
        throw Exception("Error receiving data.", WSAGetLastError());
    }

    return std::string(buffer, bytesRead);
}

// Closes the connection by closing the socket using Abstraction
void WinsockClient::CloseConnection() {
    if (clientSocket != INVALID_SOCKET) {
        closesocket(clientSocket);
        clientSocket = INVALID_SOCKET;
    }
}
