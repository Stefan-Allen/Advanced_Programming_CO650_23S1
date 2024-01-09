#ifndef WINSOCKCLIENT_H
#define WINSOCKCLIENT_H

#include <winsock2.h>
#include <string>
#include <ws2tcpip.h>

// Abstraction, Represents a client using Winsock to communicate with a server.
class WinsockClient {
public:
    // Constructors, Used for initializing the state of WinsockClient objects.
    WinsockClient(const std::string &serverIp, int serverPort);

    // Destructor, Used to release resources.
    ~WinsockClient();

    // Abstraction, Initializes Winsock, abstracting the details of the Winsock library.
    bool InitializeWinsock();

    // Abstraction, Establishes a connection to the server using the provided IP address and port.
    bool ConnectToServer();

    // Abstraction, Sends data to the connected server.
    bool SendData(const std::string &data);

    // Abstraction, Sends an order message to the server.
    bool SendOrder(const std::string &itemName, int quantity, const std::string &customerName);

    // Abstraction, Receives data from the connected server.
    std::string ReceiveData();

    // Abstraction, Closes the connection.
    void CloseConnection();

private:
    std::string serverIp;
    int serverPort;
    SOCKET clientSocket;
};

#endif // WINSOCKCLIENT_H
