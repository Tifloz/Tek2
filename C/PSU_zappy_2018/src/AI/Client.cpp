/*
** EPITECH PROJECT, 2019
** psu_zappy_2018
** File description:
** client cpp
*/

#include <cmath>
#include <ctime>
#include "Client.hpp"
#include "Commands.hpp"
#include "Player.hpp"
#include "Ai.hpp"

int getRandomCommand()
{
    int minimum = 0;
    int range = 11;
    srand(time(NULL));
    return minimum + rand() % range;
}

Client::Client(int port, std::string name, std::string machine) :
_port(port), _name(name), _machine(machine), _socketIsOpen(false), _socket(0), _clientFd(0), _serveurMessage(""), _placeAvailable(-1),
_x(0), _y(0)
{
}

Client::~Client()
{
}

void Client::connection()
{
    _socket = socket(PF_INET, SOCK_STREAM, 0);
    if(_socket == INVALID_SOCKET) {
        perror("socket()");
        exit(84);
    }

    _socketIsOpen = true;
    _addr.sin_family = AF_INET;
    _addr.sin_port = htons(_port);
    _addr.sin_addr.s_addr = inet_addr(_machine.c_str());

    _clientFd = connect(_socket, (struct sockaddr *) &_addr, sizeof(_addr));
    if (_clientFd == -1) {
        perror("connect()");
        exit(84);
    }

    int n = write(_socket, _name.c_str(), sizeof(_name));
    if (n < 0)
         perror("ERROR writing to socket");
}

void Client::initInformation()
{
    int j = 0;
    int occurence = 0;
    std::string place;
    std::string x;
    std::string y;

    _serveurMessage.resize(4096);
    int len = read(_socket, &_serveurMessage[0], _serveurMessage.size());

    if (strncmp(_serveurMessage.c_str(), "wrong team name", 15) == 0) {
        std::cerr << "Wrong team name" << std::endl;
        exit(84);
    }
    for (int a = 0; a < len; a++)
        if (_serveurMessage[a] == '\n')
            occurence++;

    if (occurence == 1) {
        for(j = 0; _serveurMessage[j] != '\n'; j++)
            place = place + _serveurMessage[j];
        _placeAvailable = std::stoi(place);

        memset(&_serveurMessage[0], 0, 4096);
        len = read(_socket, &_serveurMessage[0], _serveurMessage.size());
        for(j = 0; _serveurMessage[j] != ' '; j++)
            x = x + _serveurMessage[j];
        _x = std::stoi(x);

        j++;
        for(; _serveurMessage[j] != '\0'; j++)
            y = y + _serveurMessage[j];
        _y = std::stoi(y);
    } else if (occurence == 2) {
        for(j = 0; _serveurMessage[j] != '\n'; j++)
            place = place + _serveurMessage[j];
        _placeAvailable = std::stoi(place);
        j++;

        for(; _serveurMessage[j] != ' '; j++)
            x = x + _serveurMessage[j];
        _x = std::stoi(x);

        j++;
        for(; _serveurMessage[j] != '\0'; j++)
            y = y + _serveurMessage[j];
        _y = std::stoi(y);
    }
}

void Client::run(Client *client)
{
    int w = 0;
    fd_set rfds;
    Player *player = new Player();
    Commands *commands = new Commands();
    Ai ai = Ai();
    std::vector<std::string> queue;
    std::string sending;
    bool stop = false;

    FD_SET(_socket, &rfds);

    while (_socketIsOpen && !stop) {
        if (queue.size() < 10 && !stop) {
            sending = ai.getToDo()[0];
            queue.push_back(sending);
            w = write(_socket, sending.c_str(), sizeof(_name));
            if (w > 0)
                std::cout << "--> " << sending;
        }
        select(_socket + 1, &rfds, NULL, NULL, NULL);
        if (FD_ISSET(_socket, &rfds) == true) {
            memset(&_serveurMessage[0], 0, 4096);
            read(_socket, &_serveurMessage[0], _serveurMessage.size());
            if (strcmp(_serveurMessage.c_str(), "dead\n") == 0) {
                std::cout << "<-- " << _serveurMessage << std::endl;
                _socketIsOpen = false;
                exit (0);
            } else {
                std::cout << "<-- " << _serveurMessage << std::endl;
                commands->parseAnswer(_serveurMessage, queue[0], player, client);
                queue.erase(queue.begin());
            }
        }
        ai.chooseNextCommand(commands);
        stop = commands->getStopError();
    }
    std::cerr << "Something bad happened..." << std::endl;
    clock_t timeStart = clock();
    while (_socketIsOpen && stop) {
        if ((clock() - timeStart) / CLOCKS_PER_SEC >= 15) {
            std::cerr << "No response from server for 15 seconds, quiting." << std::endl;
            break;
        }
        select(_socket + 1, &rfds, NULL, NULL, NULL);
        if (FD_ISSET(_socket, &rfds) == true) {
            memset(&_serveurMessage[0], 0, 4096);
            read(_socket, &_serveurMessage[0], _serveurMessage.size());
            if (strcmp(_serveurMessage.c_str(), "dead\n") == 0) {
                std::cout << "<---------- " << _serveurMessage << std::endl;
                _socketIsOpen = false;
                exit (0);
            }
        }
    }
}

int Client::getPort() const
{
    return _port;
}

std::string Client::getName() const
{
    return _name;
}

std::string Client::getMachine() const
{
    return _machine;
}

std::vector<std::string> Client::getKoList()
{
    return _koList;
}

void Client::setPlaceAvailable(int n)
{
    _placeAvailable = n;
}

void Client::addKo(std::string command)
{
    _koList.push_back(command);
}
