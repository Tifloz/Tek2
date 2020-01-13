/*
** EPITECH PROJECT, 2019
** CPP_RUSH03_2018_USERMODULE_HPP
** File description:
** HEADER
*/
#ifndef CPP_RUSH03_2018_USER_HPP
#define CPP_RUSH03_2018_USER_HPP

#include "SystemCore.hpp"
#include "../modules/userModule.hpp"

class User : public userModule, public SystemCore {
    public:
        User();
        ~User();
        void DisplayUserHost();
};

#endif //CPP_RUSH03_2018_USER_HPP
