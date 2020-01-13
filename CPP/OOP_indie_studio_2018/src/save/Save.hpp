//
// Created by gauthierbetaucourt on 6/16/19.
//

#ifndef BOMBERMAN_SAVE_HPP
#define BOMBERMAN_SAVE_HPP


#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include "../board/Map.hpp"
#include "../board/Player.hpp"

class Save {
public:
    Save(std::string fileName, Map &map, std::vector<Player *> &players);
    void changeTiles(std::vector<std::string> &, irr::core::vector3df, int);
private:
protected:

};


#endif //BOMBERMAN_SAVE_HPP
