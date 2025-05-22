#include "NetworkClient.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

NetworkClient::NetworkClient(const std::string &host, uint16_t port)
    : host_(host), port_(port), sockfd_(-1) {}

NetworkClient::~NetworkClient() {
    disconnect();
}

bool NetworkClient::connect() {
    sockfd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd_ < 0) {
        std::perror("socket");
        return false;
    }

    sockaddr_in addr {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port_);
    if (inet_pton(AF_INET, host_.c_str(), &addr.sin_addr) <= 0) {
        std::cerr << "Invalid address\n";
        return false;
    }

    if (::connect(sockfd_, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) < 0) {
        std::perror("connect");
        return false;
    }

    return true;
}

bool NetworkClient::sendFrame(const std::string &frame) {
    if (sockfd_ < 0) return false;
    ssize_t n = ::send(sockfd_, frame.c_str(), frame.size(), 0);
    return n == static_cast<ssize_t>(frame.size());
}

void NetworkClient::disconnect() {
    if (sockfd_ >= 0) {
        ::close(sockfd_);
        sockfd_ = -1;
    }
}
