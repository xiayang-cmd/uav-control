#ifndef C_LINUX_TCP_COM_H
#define C_LINUX_TCP_COM_H

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

#define TCP_BUFF_LEN 1024

class CLinuxTCPCom
{
public:
    CLinuxTCPCom();
    ~CLinuxTCPCom();

    /**
     * @brief \u521d\u59cb\u5316\u4e3aTCP\u670d\u52a1\u5668\u6a21\u5f0f
     * @param ip_str \u7ed1\u5b9a\u7684\u672c\u673aIP\u5730\u5740(\u5982"127.0.0.1")
     * @param port \u76d1\u542c\u7aef\u53e3\u53f7
     * @return \u6210\u529f\u8fd4\u56de0\uff0c\u5931\u8d25\u8fd4\u56de-1
     * @note \u8be5\u51fd\u6570\u4f1a\u521b\u5efa\u76d1\u542c\u5957\u63a5\u5b50\u5e76\u4f7f\u7528bind()\u548clisten()\u3002
     */
    int TCPInitServer(const char *ip_str, uint16_t port);

    /**
     * @brief \u7b49\u5f85\u5ba2\u6237\u7aef\u8fde\u63a5\uff08\u4ec5\u5728\u670d\u52a1\u5668\u6a21\u5f0f\u4e0b\u4f7f\u7528\uff09
     * @return \u6210\u529f\u8fd4\u56de\u65b0\u751f\u6210\u7684\u901a\u4fe1socket\u7684\u6587\u4ef6\u63cf\u8ff0\u7b26\uff0c\u5931\u8d25\u8fd4\u56de-1
     * @note \u6b64\u51fd\u6570\u8c03\u7528accept()\u963b\u585e\u7b49\u5f85\u5ba2\u6237\u7aef\u8fde\u63a5\uff0c\u4e00\u65e6\u6709\u8fde\u63a5\u8bf7\u6c42\u4f1a\u4ea7\u751f\u65b0\u7684\u5957\u63a5\u5b50\u7528\u4e8e\u901a\u4fe1\u3002
     */
    int TCPAccept();

    /**
     * @brief \u521d\u59cb\u5316\u4e3aTCP\u5ba2\u6237\u7aef\u6a21\u5f0f
     * @param ip_str \u670d\u52a1\u5668IP\u5730\u5740
     * @param port \u670d\u52a1\u5668\u7aef\u53e3\u53f7
     * @return \u6210\u529f\u8fd4\u56de0\uff0c\u5931\u8d25\u8fd4\u56de-1
     * @note \u8be5\u51fd\u6570\u4f1a\u521b\u5efa\u4e00\u4e2a\u5957\u63a5\u5b50\uff0c\u7136\u540e\u4f7f\u7528connect()\u4e0e\u670d\u52a1\u5668\u5efa\u7acb\u8fde\u63a5\u3002
     */
    int TCPInitClient(const char *ip_str, uint16_t port);

    /**
     * @brief \u53d1\u9001\u6570\u636e
     * @param buf \u5f85\u53d1\u9001\u6570\u636e\u7684\u7f13\u51b2\u533a\u6307\u9488
     * @param size \u5f85\u53d1\u9001\u6570\u636e\u7684\u957f\u5ea6
     * @return \u6210\u529f\u53d1\u9001\u7684\u5b57\u8282\u6570\uff0c\u51fa\u9519\u8fd4\u56de-1
     */
    int TCPSendData(const void *buf, size_t size);

    /**
     * @brief \u63a5\u6536\u6570\u636e
     * @param buf \u63a5\u6536\u6570\u636e\u7684\u7f13\u51b2\u533a\u6307\u9488
     * @param size \u7f13\u51b2\u533a\u53ef\u63a5\u6536\u6570\u636e\u7684\u6700\u5927\u957f\u5ea6
     * @return \u5b9e\u9645\u63a5\u6536\u5230\u7684\u5b57\u8282\u6570\uff0c\u51fa\u9519\u8fd4\u56de-1\uff08\u5bf9\u7aef\u5173\u95ed\u8fde\u63a5\u53ef\u80fd\u8fd4\u56de0\uff09
     */
    int TCPRecvData(void *buf, size_t size);

    /**
     * @brief \u8bbe\u7f6e\u901a\u4fe1\u4f7f\u7528\u7684\u6587\u4ef6\u63cf\u8ff0\u7b26\uff08\u5982\u670d\u52a1\u5668accept\u540e\u7684\u5957\u63a5\u5b50\uff09
     */
    void SetCommFd(int fd);

    /**
     * @brief \u83b7\u53d6\u5f53\u524d\u7684\u901a\u4fe1\u5957\u63a5\u5b50\u6587\u4ef6\u63cf\u8ff0\u7b26
     */
    int GetCommFd() const;

    /**
     * @brief \u5173\u95ed\u5957\u63a5\u5b50
     */
    void CloseFd();

private:
    int listen_fd;   // \u670d\u52a1\u5668\u76d1\u542c\u5957\u63a5\u5b50\uff08\u670d\u52a1\u5668\u6a21\u5f0f\u4e0b\u4f7f\u7528\uff09
    int comm_fd;     // \u901a\u4fe1\u5957\u63a5\u5b50\uff08\u5ba2\u6237\u7aef\u6a21\u5f0f\u6216\u670d\u52a1\u5668accept\u540e\u4f7f\u7528\uff09
    struct sockaddr_in ser_addr;
    struct sockaddr_in cli_addr;
    char recv_buf[TCP_BUFF_LEN];
};

#endif // C_LINUX_TCP_COM_H
