#include "../Headers/WinsockClient.h"
#include <iostream>

// Constructors, Used for initializing the state of WinsockClient.
WinsockClient::WinsockClient(const std::string &serverIp, int serverPort)
    : serverIp(serverIp), serverPort(serverPort), clientSocket(INVALID_SOCKET) {
    InitializeWinsock();
}

// Destructor, Used close the connection when WinsockClient objects are destroyed.
WinsockClient::~WinsockClient() {
    CloseConnection();
    WSACleanup();
}

// Abstraction, Initializes Winsock, abstracting the details of the Winsock library.
bool WinsockClient::InitializeWinsock() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Error initializing Winsock." << std::endl;
        return false;
    }
    return true;
}

// Abstraction, Establishes a connection using provided IP address and port.
bool WinsockClient::ConnectToServer() {
    struct sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(serverPort);
    inet_pton(AF_INET, serverIp.c_str(), &(serverAddress.sin_addr));

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Error creating socket: " << WSAGetLastError() << std::endl;
        return false;
    }

    if (connect(clientSocket, reinterpret_cast<struct sockaddr *>(&serverAddress), sizeof(serverAddress)) ==
        SOCKET_ERROR) {
        std::cerr << "Error connecting to server: " << WSAGetLastError() << std::endl;
        closesocket(clientSocket);
        return false;
    }

    return true;
}

// Abstraction, Sends data to the connected server.
bool WinsockClient::SendData(const std::string &data) {
    int result = send(clientSocket, data.c_str(), data.size(), 0);
    if (result == SOCKET_ERROR) {
        std::cerr << "Error sending data: " << WSAGetLastError() << std::endl;
        return false;
    }
    return true;
}

// Abstraction, Sends order message to the server.
bool WinsockClient::SendOrder(const std::string &itemName, int quantity, const std::string &customerName) {
    std::string orderMessage = "Item name:" " " + itemName + ", " " Quantity: " + std::to_string(quantity) + ", " " " +
                               customerName;

    int result = send(clientSocket, orderMessage.c_str(), orderMessage.size(), 0);
    if (result == SOCKET_ERROR) {
        std::cerr << "Error sending order: " << WSAGetLastError() << std::endl;
        return false;
    }

    return true;
}

// Abstractiom, Receives data from the connected server.
std::string WinsockClient::ReceiveData() {
    const int bufferSize = 1024;
    char buffer[bufferSize];
    memset(buffer, 0, bufferSize);

    int bytesRead = recv(clientSocket, buffer, bufferSize - 1, 0);
    if (bytesRead == SOCKET_ERROR) {
        std::cerr << "Error receiving data: " << WSAGetLastError() << std::endl;
        return "";
    }

    return std::string(buffer, bytesRead);
}

// Abstraction, Closes the connection.
void WinsockClient::CloseConnection() {
    if (clientSocket != INVALID_SOCKET) {
        closesocket(clientSocket);
        clientSocket = INVALID_SOCKET;
    }
}
