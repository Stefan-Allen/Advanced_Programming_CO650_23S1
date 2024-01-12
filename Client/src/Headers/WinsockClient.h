#ifndef WINSOCKCLIENT_H
#define WINSOCKCLIENT_H

#include <winsock2.h>
#include <string>
#include <ws2tcpip.h>

// Abstraction
class WinsockClient {
public:
    // Constructors
    WinsockClient(const std::string &serverIp, int serverPort);

    // Destructor
    ~WinsockClient();

    // Abstraction
    bool InitializeWinsock();

    bool ConnectToServer();

    bool SendData(const std::string &data);

    bool SendOrder(const std::string &itemName, int quantity, const std::string &customerName);

    std::string ReceiveData();

    // Abstraction
    void CloseConnection();

private:
    std::string serverIp;
    int serverPort;
    SOCKET clientSocket;
};

#endif // WINSOCKCLIENT_H
