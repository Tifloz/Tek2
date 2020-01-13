/*
** EPITECH PROJECT, 2019
** psu_zappy_2018
** File description:
** client hpp
*/

#ifndef CLIENT_H
#define CLIENT_H

#include <cstring>
#include <string>
#include <iostream>
#include <regex>
#include <vector>
#include "Socket.hpp"

class Client
{
public:
    Client(int port, std::string name, std::string machine = "localhost");
    ~Client();

    void connection();
    void run(Client *client);
    void initInformation();

    int getPort() const;
    std::string getName() const;
    std::string getMachine() const;
    std::vector<std::string> getKoList();

    void setPlaceAvailable(int n);
    void addKo(std::string command);

private:
    int _port;
    std::string _name;
    std::string _machine;
    bool _socketIsOpen;
    int _socket;
    int _clientFd;
    std::string _serveurMessage;
    int _placeAvailable;
    int _x;
    int _y;
    std::vector<std::string> _koList;

    struct sockaddr_in _addr;
};

#endif
