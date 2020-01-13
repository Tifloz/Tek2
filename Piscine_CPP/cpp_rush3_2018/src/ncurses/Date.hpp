/*
** EPITECH PROJECT, 2019
** CPP_RUSH03_2018_DATA_HPP
** File description:
** HEADER
*/
#ifndef CPP_RUSH03_2018_DATA_HPP
#define CPP_RUSH03_2018_DATA_HPP

#include "SystemCore.hpp"
#include "../modules/dateModule.hpp"

class Date : public dateModule, public SystemCore {
    public:
    Date();
    ~Date() override;
    void DisplayDateTime();
};

#endif //CPP_RUSH03_2018_DATA_HPP
