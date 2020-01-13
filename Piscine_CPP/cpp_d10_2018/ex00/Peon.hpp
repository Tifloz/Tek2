/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D10_2018_PEON_HPP
#define CPP_D10_2018_PEON_HPP

#include "Victim.hpp"

class Peon : public Victim {
    public:
    Peon(std::string name);

    ~Peon();

    void getPolymorphed() const override;
};

#endif //CPP_D10_2018_PEON_HPP
