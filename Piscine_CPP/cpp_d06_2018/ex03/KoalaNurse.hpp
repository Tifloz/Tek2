/*
** EPITECH PROJECT, 2022
** CPE_my_rpg_2017
** File description:
** Created by Florian Louvet,
*/
#ifndef CPE_MY_RPG_2017_KOALANURSE_HPP
#define CPE_MY_RPG_2017_KOALANURSE_HPP

#include "SickKoala.hpp"

class KoalaNurse {
    public:
    KoalaNurse(int id);

    ~KoalaNurse();

    void timeCheck();

    void giveDrug(std::string drug, SickKoala *patient);

    std::string readReport(std::string report);

    private:
    int id;
    bool is_working;
};

#endif //CPE_MY_RPG_2017_KOALANURSE_HPP
