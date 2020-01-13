/*
** EPITECH PROJECT, 2019
** CPP_RUSH03_2018_SYSTEMCORE_HPP
** File description:
** HEADER
*/
#ifndef CPP_RUSH03_2018_SYSTEMCORE_HPP
#define CPP_RUSH03_2018_SYSTEMCORE_HPP

#include <ncurses.h>
#include "../IMonitorDisplay.hpp"

class SystemCore : public IMonitorDisplay {
    public:
        bool updateData() override;
            SystemCore();
            ~SystemCore();
};


#endif //CPP_RUSH03_2018_SYSTEMCORE_HPP
