/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D10_2018_AENEMY_HPP
#define CPP_D10_2018_AENEMY_HPP

#include <string>

class AEnemy {
    public:
    AEnemy(int hp, std::string const &type);

    virtual ~AEnemy();

    std::string const &getType() const;

    int getHP() const;

    virtual void takeDamage(int damage);

    protected:
    std::string _type;
    int _hp;
};

#endif //CPP_D10_2018_AENEMY_HPP
