/*
** EPITECH PROJECT, 2022
** cpp_d06_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D06_2018_KOALADOCTOR_HPP
#define CPP_D06_2018_KOALADOCTOR_HPP

# include <iostream>
# include "SickKoala.hpp"

class KoalaDoctor {
    public:
    KoalaDoctor(std::string name);

    ~KoalaDoctor();

    void diagnose(SickKoala *koala);

    void timeCheck();

    private:
    std::string name;
    bool is_working;
};

#endif //CPP_D06_2018_KOALADOCTOR_HPP
