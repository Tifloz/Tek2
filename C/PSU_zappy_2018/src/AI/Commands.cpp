/*
** EPITECH PROJECT, 2019
** psu_zappy_2018
** File description:
** player cpp
*/

#include "Commands.hpp"

Commands::Commands()
{
    _commands[FORWARD] = "Forward\n";
    _commands[RIGHT] = "Right\n";
    _commands[LEFT] = "Left\n";
    _commands[LOOK] = "Look\n";
    _commands[INVENTORY] = "Inventory\n";
    _commands[CONNECT] = "Connect_nbr\n";
    _commands[FORK] = "Fork\n";
    _commands[EJECT] = "Eject\n";
    _commands[TAKE] = "Take ";
    _commands[SET] = "Set ";
    _commands[INCANTATION] = "Incantation\n";
    _commands[BROADCAST] = "Broadcast";
    _noObj = false;
    _foodTile = 0;
    _linemateTile = 0;
    _deraumereTile = 0;
    _siburTile = 0;
    _mendianeTile = 0;
    _phirasTile = 0;
    _thystameTile = 0;
    _readyToIncant = 0;
    _stopError = false;
}

Commands::~Commands()
{
}

int Commands::getReadyToIncant()
{
    return _readyToIncant;
}

void Commands::changeNoObj(bool value)
{
    _noObj = value;
}

void Commands::changeReadyForIncant(int n)
{
    _readyToIncant = n;
}

std::string *Commands::getCommands()
{
    return _commands;
}

unsigned int Commands::getFoodTile()
{
    return _foodTile;
}

unsigned int Commands::getLinemateTile()
{
    return _linemateTile;
}

unsigned int Commands::getDeraumereTile()
{
    return _deraumereTile;
}

unsigned int Commands::getSiburTile()
{
    return _siburTile;
}

unsigned int Commands::getMendianeTile()
{
    return _mendianeTile;
}

unsigned int Commands::getPhirasTile()
{
    return _phirasTile;
}

unsigned int Commands::getThystameTile()
{
    return _thystameTile;
}

unsigned int Commands::getPlayerTile()
{
    return _playerTile;
}

bool Commands::getStopError()
{
    return _stopError;
}

void Commands::removeFoodTile()
{
    if (_foodTile > 0)
        _foodTile--;
}

void Commands::removeLinemateTile()
{
    if (_linemateTile > 0)
        _linemateTile--;
}

void Commands::removeDeraumereTile()
{
    if (_deraumereTile > 0)
        _deraumereTile--;
}

void Commands::removeSiburTile()
{
    if (_siburTile > 0)
        _siburTile--;
}

void Commands::removeMendianeTile()
{
    if (_mendianeTile > 0)
        _mendianeTile--;
}

void Commands::removePhirasTile()
{
    if (_phirasTile > 0)
        _phirasTile--;
}

void Commands::removeThystameTile()
{
    if (_thystameTile > 0)
        _thystameTile--;
}

bool Commands::getNoObj()
{
    return _noObj;
}

std::string Commands::getNextSet()
{
    return _toSet[0];
}

void Commands::deleteFirstSet()
{
    _toSet.erase(_toSet.begin());
}

size_t Commands::getSizeSetList()
{
    return (_toSet.size());
}

int Commands::checkForIncantation(Player *player)
{
    std::vector<int *> ritual;
    int l1[7] = {1, 1, 0, 0, 0, 0, 0};
    int l2[7] = {2, 1, 1, 1, 0, 0, 0};
    int l3[7] = {2, 2, 0, 1, 0, 2, 0};
    int l4[7] = {4, 1, 1, 2, 0, 1, 0};
    int l5[7] = {4, 1, 2, 1, 3, 0, 0};
    int l6[7] = {6, 1, 2, 3, 0, 1, 0};
    int l7[7] = {6, 2, 2, 2, 2, 2, 1};

    ritual.push_back(l1);
    ritual.push_back(l2);
    ritual.push_back(l3);
    ritual.push_back(l4);
    ritual.push_back(l5);
    ritual.push_back(l6);
    ritual.push_back(l7);

    if (ritual[player->getLevel() - 1][1] > player->getInventory()->getLinemate())
        return 1;
    if (ritual[player->getLevel() - 1][2] > player->getInventory()->getDeraumere())
        return 1;
    if (ritual[player->getLevel() - 1][3] > player->getInventory()->getSibur())
        return 1;
    if (ritual[player->getLevel() - 1][4] > player->getInventory()->getMendiane())
        return 1;
    if (ritual[player->getLevel() - 1][5] > player->getInventory()->getPhiras())
        return 1;
    if (ritual[player->getLevel() - 1][6] > player->getInventory()->getThystame())
        return 1;
    if (ritual[player->getLevel() - 1][0] > (int) _playerTile)
        return 1;

    for (int i = 0; i < ritual[player->getLevel() - 1][1]; i++)
        _toSet.push_back("Set linemate\n");
    for (int i = 0; i < ritual[player->getLevel() - 1][2]; i++)
        _toSet.push_back("Set deraumere\n");
    for (int i = 0; i < ritual[player->getLevel() - 1][3]; i++)
        _toSet.push_back("Set sibur\n");
    for (int i = 0; i < ritual[player->getLevel() - 1][4]; i++)
        _toSet.push_back("Set mendiane\n");
    for (int i = 0; i < ritual[player->getLevel() - 1][5]; i++)
        _toSet.push_back("Set phiras\n");
    for (int i = 0; i < ritual[player->getLevel() - 1][6]; i++)
        _toSet.push_back("Set thystame\n");
    return 2;
}

void Commands::forkResponse()
{
    return;
}

void Commands::ejectResponse(std::string serveurMessage, std::string command, Client *client)
{
    if (strncmp(serveurMessage.c_str(), "ko\n", 3) != 0 && strncmp(serveurMessage.c_str(), "ok\n", 3) != 0) {
        _stopError = true;
        return;
    }
    if (strncmp(serveurMessage.c_str(), "ko", 3) == 0)
        client->addKo(command);
    else
        return;
}

void Commands::takeObjectResponse(std::string serveurMessage, std::string command, Client *client)
{
    if (strncmp(serveurMessage.c_str(), "ko\n", 3) != 0 && strncmp(serveurMessage.c_str(), "ok\n", 3) != 0) {
        _stopError = true;
        return;
    }
    if (strncmp(serveurMessage.c_str(), "ko\n", 3) == 0)
        client->addKo(command);
    else
        return;
}

void Commands::setObjectResponse(std::string serveurMessage, std::string command, Client *client)
{
    if (strncmp(serveurMessage.c_str(), "ko\n", 3) != 0 && strncmp(serveurMessage.c_str(), "ok\n", 3) != 0) {
        _stopError = true;
        return;
    }
    if (strncmp(serveurMessage.c_str(), "ko\n", 3) == 0)
        client->addKo(command);
    else
        return;
}

void Commands::IncantationResponse(std::string serveurMessage, std::string command, Player *player, Client *client)
{
    if (strncmp(serveurMessage.c_str(), "ko\n", 3) != 0 && strncmp(serveurMessage.c_str(), "Elevation underway", 18) != 0) {
        _stopError = true;
        return;
    }
    if (strncmp(serveurMessage.c_str(), "ko\n", 3) == 0)
        client->addKo(command);
    else {
        int i = 0;
        std::string element;
        for (;serveurMessage[i] < '0' || serveurMessage[i] > '9';i++);
        for (; serveurMessage[i] >= '0' && serveurMessage[i] <= '9'; i++)
                element = element + serveurMessage[i];
        player->setLevel(std::stoi(element));
    }
}

void Commands::broadcastResponse()
{
    return;
}

int lookparser(std::string serveurMessage, int &i, char mark) {
    std::string element;
    int ret = 0;

    if (serveurMessage[i] == mark) {
        for (;serveurMessage[i] < '0' || serveurMessage[i] > '9'; i++);
        for (; serveurMessage[i] >= '0' && serveurMessage[i] <= '9'; i++)
            element = element + serveurMessage[i];
        ret = std::stoi(element);
        i++;
    }
    return (ret);
}

void Commands::lookResponse(std::string serveurMessage)
{
    int i = 0;
    int j = 0;
    std::string player;

    if (strncmp(serveurMessage.c_str(), "[player x", 8) != 0) {
        _stopError = true;
        return;
    }

    for (j = 9; serveurMessage[j] >= '0' && serveurMessage[j] <= '9'; j++);
    j++;
    if (serveurMessage[j] == ',' || serveurMessage[j] == ']')
        _noObj = true;
    else {
        for (;serveurMessage[i] < '0' || serveurMessage[i] > '9'; i++);
        for (; serveurMessage[i] >= '0' && serveurMessage[i] <= '9'; i++)
            player = player + serveurMessage[i];
        _playerTile = std::stoi(player);
        i++;
        _foodTile = lookparser(serveurMessage, i, 'f');
        _linemateTile = lookparser(serveurMessage, i, 'l');
        _deraumereTile = lookparser(serveurMessage, i, 'd');
        _siburTile = lookparser(serveurMessage, i, 's');
        _mendianeTile = lookparser(serveurMessage, i, 'm');
        _phirasTile = lookparser(serveurMessage, i, 'p');
        _thystameTile = lookparser(serveurMessage, i, 't');
        return;
    }
}


void Commands::parseAnswer(std::string serveurMessage, std::string command, Player *player, Client *client)
{
    if (command == "Look\n")
        lookResponse(serveurMessage);
    else if (command == "Inventory\n") {
        player->getInventory()->setInventory(serveurMessage);
        _readyToIncant = checkForIncantation(player);
        std::cout << "ready to incant ? " << _readyToIncant << std::endl;
    } else if (command == "Connect_nbr\n")
        client->setPlaceAvailable(std::stoi(serveurMessage));
    else if (command == "Fork\n")
        forkResponse();
    else if (command == "Eject\n")
        ejectResponse(serveurMessage, command, client);
    else if (strncmp(command.c_str(), "Take ", 5) == 0)
        takeObjectResponse(serveurMessage, command, client);
    else if (strncmp(command.c_str(), "Set ", 4) == 0)
        setObjectResponse(serveurMessage, command, client);
    else if (command == "Incantation\n")
        IncantationResponse(serveurMessage, command, player, client);
    else if (command == "Broadcast")
        return;
    return;
}
