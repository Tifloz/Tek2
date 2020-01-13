/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D10_2018_SORCERER_HPP
#define CPP_D10_2018_SORCERER_HPP

#include <string>
#include "Victim.hpp"

class Sorcerer {
    public:
    Sorcerer(std::string name, std::string title);

    ~Sorcerer();

    std::string getName() const;

    std::string getTitle() const;

    void polymorph(const Victim &slave) const;

    private:
    std::string _name;
    std::string _title;
};

std::ostream &operator<<(std::ostream &os, Sorcerer const &mage);

#endif //CPP_D10_2018_SORCERER_HPP
