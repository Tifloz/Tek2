//
// Created by gauthierbetaucourt on 6/16/19.
//

#include <vector>
#include "Save.hpp"

Save::Save(std::string fileName, Map &map, std::vector<Player *> &players)
{
    std::string folder("./");
    mkdir(folder.c_str(), 0777);
    std::cout << fileName << std::endl;
    std::ofstream file;
    file.open(fileName);

    std::cout << players.size() << "tiles = " << map.getTiles().size() << std::endl;
    std::vector<std::string> list = map.getTiles();
    for(std::size_t i = 0; i != players.size(); i++) {
        if (players.at(i)->isAlive())
            changeTiles(list, players.at(i)->getPos(), players.at(i)->getId());
    }
    for(std::size_t i = (list.size() - 1); i != -1; i--) {
        std::cout << list.at(i) << std::endl;
        file << list.at(i) << std::endl;
    }
    file.close();
}

void Save::changeTiles(std::vector<std::string> &list, irr::core::vector3df pos, int numb)
{
    list.at((std::size_t)pos.Y / 10).at((std::size_t)pos.X / 10) = (numb + 48);
}
