/*
** EPITECH PROJECT, 2019
** CPP_RUSH03_2018_SYSTEM_HPP
** File description:
** HEADER
*/
#ifndef CPP_RUSH03_2018_SYSTEM_HPP
#define CPP_RUSH03_2018_SYSTEM_HPP

#include "SystemCore.hpp"
#include "../modules/systemModule.hpp"

class System : public systemModule, public SystemCore {
    public:
    System();
    ~System();
    void DisplaySystem();
};

#endif //CPP_RUSH03_2018_SYSTEM_HPP
