#ifndef WINSOCKSERVER_H
#define WINSOCKSERVER_H

#include <winsock2.h>
#include <string>

class WinsockServer {
public:
    // Constructors, initializing the state of WinsockServer.
    WinsockServer(int port);

    // Destructors, cleaning resources.
    ~WinsockServer();

    // Initializes the Winsock library.
    bool InitializeWinsock();

    // Binds the server socket to a specific port.
    bool BindSocket();

    // Starts listening for incoming connections on the server socket.
    bool StartListening();

    // Accepts incoming connections from clients.
    bool AcceptConnection();

    // Receives data from a connected client.
    std::string ReceiveData(SOCKET clientSocket);

    // Closes the connection with a client.
    void CloseConnection(SOCKET clientSocket);

    // Encapsulation, Private members used to encapsulate the state of the WinsockServer class.
private:
    int port;
    SOCKET serverSocket;

    // Processes data and sends a response back to the client.
    void HandleReceivedData(const std::string &receivedData, SOCKET clientSocket);
};

#endif // WINSOCKSERVER_H
