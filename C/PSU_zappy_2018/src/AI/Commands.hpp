/*
** EPITECH PROJECT, 2019
** psu_zappy_2018
** File description:
** Commands hpp
*/

#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>
#include <iostream>

#include "Cmds.hpp"
#include "Inventory.hpp"
#include "Player.hpp"
#include "Client.hpp"


class Commands
{
public:
    Commands();
    ~Commands();

    std::string *getCommands();
    void parseAnswer(std::string serveurMessage, std::string command, Player *player, Client *client);
    void forkResponse();
    void ejectResponse(std::string serveurMessage, std::string command, Client *client);
    void takeObjectResponse(std::string serveurMessage, std::string command, Client *client);
    void setObjectResponse(std::string serveurMessage, std::string command, Client *client);
    void IncantationResponse(std::string serveurMessage, std::string command, Player *player, Client *client);
    void broadcastResponse();
    void lookResponse(std::string serveurMessage);

    unsigned int getFoodTile();
    unsigned int getLinemateTile();
    unsigned int getDeraumereTile();
    unsigned int getSiburTile();
    unsigned int getMendianeTile();
    unsigned int getPhirasTile();
    unsigned int getThystameTile();
    unsigned int getPlayerTile();

    void removeFoodTile();
    void removeLinemateTile();
    void removeDeraumereTile();
    void removeSiburTile();
    void removeMendianeTile();
    void removePhirasTile();
    void removeThystameTile();

    int checkForIncantation(Player *player);
    int getReadyToIncant();
    void changeReadyForIncant(int n);
    bool getNoObj();
    void changeNoObj(bool value);
    void deleteFirstSet();

    std::string getNextSet();

    size_t getSizeSetList();

    bool getStopError();

private:
    std::string _commands[12];
    bool _noObj;
    unsigned int _foodTile;
    unsigned int _linemateTile;
    unsigned int _deraumereTile;
    unsigned int _siburTile;
    unsigned int _mendianeTile;
    unsigned int _phirasTile;
    unsigned int _thystameTile;
    unsigned int _playerTile;

    int _readyToIncant;
    std::vector<std::string> _toSet;

    bool _stopError;
};

#endif
