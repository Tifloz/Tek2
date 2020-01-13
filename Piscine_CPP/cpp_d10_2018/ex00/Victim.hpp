/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D10_2018_VICTIM_HPP
#define CPP_D10_2018_VICTIM_HPP

#include <string>

class Victim {
    public:
    Victim(std::string name);

    ~Victim();

    std::string getName() const;

    virtual void getPolymorphed() const;

    protected:
    std::string _name;
};

std::ostream &operator<<(std::ostream &os, Victim const &slave);

#endif //CPP_D10_2018_VICTIM_HPP
