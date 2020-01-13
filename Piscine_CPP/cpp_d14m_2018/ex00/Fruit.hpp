/*
** EPITECH PROJECT, 2022
** cpp_d14m_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D14M_2018_FRUIT_HPP
#define CPP_D14M_2018_FRUIT_HPP

#include <iostream>

class Fruit {
    public:
    Fruit(const std::string &name, int vitamins);

    virtual ~Fruit();

    virtual std::string const &getName() const;

    int getVitamins() const;

    Fruit &operator=(const Fruit &fruit);

    bool operator==(const Fruit &fruit);

    protected:
    std::string _name;
    int _vitamins;
};

#endif //CPP_D14M_2018_FRUIT_HPP
