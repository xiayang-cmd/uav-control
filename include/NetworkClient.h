#ifndef NETWORK_CLIENT_H
#define NETWORK_CLIENT_H

#include <string>
#include <cstdint>

class NetworkClient {
public:
    NetworkClient(const std::string &host, uint16_t port);
    ~NetworkClient();

    bool connect();
    bool sendFrame(const std::string &frame);
    void disconnect();

private:
    std::string host_;
    uint16_t port_;
    int sockfd_;
};

#endif // NETWORK_CLIENT_H
