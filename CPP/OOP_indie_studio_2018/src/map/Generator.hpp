/*
** EPITECH PROJECT, 2017
** Indie Studio
** Generator.hpp
*/

#ifndef MAPS_HPP
#define MAPS_HPP

#include <string>

class Generator
{
public:
    Generator(std::string name);
    ~Generator();

    void decreaseFreeBlock();
    void decreaseRigidBlock();
    void decreaseBreakableBlock();

private:
    std::string _name;
    int _freeBlock;
    int _rigidBlock;
    int _breakableBlock;
    int _lowerTypeBlock;
};

#endif //MAPS_HPP
