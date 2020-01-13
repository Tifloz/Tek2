/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** socket
*/

#include "Socket.hpp"

Socket::Socket() : _fd(-1)
{
}

Socket::~Socket()
{
    if (_fd != -1)
        ::close(_fd);
}

bool Socket::init()
{
    _fd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;

    return (_fd != -1 && !setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, (const char *)&opt, sizeof(opt)));
}

bool Socket::connect(const std::string &host, int port)
{
    if (_fd == -1)
        return false;
    _addr.sin_family = AF_INET;
    _addr.sin_port = htons(port);
    return (inet_pton(AF_INET, host.c_str(), &_addr.sin_addr) == 1 &&
        !::connect(_fd, (sockaddr *)&_addr, sizeof(_addr)));
}

void Socket::listen(fd_set *set, int &max) const
{
    FD_SET(_fd, set);
    if (_fd > max)
        max = _fd;
}

bool Socket::isActiv(fd_set *set) const
{
    return (FD_ISSET(_fd, set));
}

bool Socket::operator<<(const std::string &msg) const
{
    return (_fd != -1 && send(_fd, msg.c_str(), msg.size(), 0) != -1);
}

bool Socket::operator>>(std::string &msg) const
{
    char buf[501];
    memset(buf, 0, 501);
    if (_fd == -1 || recv(_fd, buf, 500, 0) == -1)
        return false;
    msg = buf;
    return true;
}

int Socket::getFd() const
{
    return _fd;
}
