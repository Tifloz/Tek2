/*
** EPITECH PROJECT, 2022
** CPE_my_rpg_2017
** File description:
** Created by Florian Louvet,
*/
#ifndef CPE_MY_RPG_2017_SICKKOALA_HPP
#define CPE_MY_RPG_2017_SICKKOALA_HPP

# include <iostream>

class SickKoala {
    public:
    SickKoala(std::string name);

    ~SickKoala();

    void poke();

    bool takeDrug(std::string smth);

    void overDrive(std::string str);

    std::string getName();

    private:
    std::string name;
};

#endif //CPE_MY_RPG_2017_SICKKOALA_HPP
