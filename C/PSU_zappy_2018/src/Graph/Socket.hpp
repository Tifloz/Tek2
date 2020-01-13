/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** socket
*/

#ifndef SOCKET_H
#define SOCKET_H

#include <algorithm>
#include <string>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

class Socket
{
public:
    Socket();
    ~Socket();

    bool init();
    bool connect(const std::string &host, int port);
    void listen(fd_set *, int &) const;
    bool isActiv(fd_set *) const;
    bool operator<<(const std::string &) const;
    bool operator>>(std::string &) const;

    int getFd() const;

protected:
    int _fd;
    sockaddr_in _addr;
};

#endif
