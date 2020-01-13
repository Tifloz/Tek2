/*
** EPITECH PROJECT, 2019
** psu_zappy_2018
** File description:
** ai cpp
*/

#include "Ai.hpp"

Ai::Ai()
{
    _toDo.insert(_toDo.begin(), "Look\n");
}

Ai::~Ai()
{
}

std::vector<std::string> Ai::getToDo()
{
    return _toDo;
}

void Ai::setToDo(std::string command)
{
    _toDo.erase(_toDo.begin());
    _toDo.insert(_toDo.begin(), command);
}

void Ai::chooseNextCommand(Commands *commands)
{
    if (commands->getReadyToIncant() == 2 && commands->getSizeSetList() > 0) {
        std::string toSend = commands->getNextSet();
        _toDo.insert(_toDo.begin(), toSend);
        commands->deleteFirstSet();
    } else if (commands->getReadyToIncant() == 2 && commands->getSizeSetList() <= 0){
        _toDo.insert(_toDo.begin(), commands->getCommands()[INCANTATION]);
        commands->changeReadyForIncant(0);
        commands->changeNoObj(false);
    } else if (commands->getReadyToIncant() == 1) {
        _toDo.insert(_toDo.begin(), commands->getCommands()[FORWARD]);
        commands->changeReadyForIncant(0);
        commands->changeNoObj(false);
    } else if (commands->getNoObj() == true)
        _toDo.insert(_toDo.begin(), commands->getCommands()[INVENTORY]);
    else if (commands->getFoodTile() > 0) {
        _toDo.insert(_toDo.begin(), "Take food\n");
        commands->removeFoodTile();
    } else if (commands->getLinemateTile() > 0) {
        _toDo.insert(_toDo.begin(), "Take linemate\n");
        commands->removeLinemateTile();
    } else if (commands->getDeraumereTile() > 0) {
        _toDo.insert(_toDo.begin(), "Take deraumere\n");
        commands->removeDeraumereTile();
    } else if (commands->getSiburTile() > 0) {
        _toDo.insert(_toDo.begin(), "Take sibur\n");
        commands->removeSiburTile();
    } else if (commands->getMendianeTile() > 0) {
        _toDo.insert(_toDo.begin(), "Take mendiane\n");
        commands->removeMendianeTile();
    } else if (commands->getPhirasTile() > 0) {
        _toDo.insert(_toDo.begin(), "Take phiras\n");
        commands->removePhirasTile();
    } else if (commands->getThystameTile() > 0) {
        _toDo.insert(_toDo.begin(), "Take thystame\n");
        commands->removeThystameTile();
    } else {
        _toDo.insert(_toDo.begin(), commands->getCommands()[LOOK]);
    }
}
