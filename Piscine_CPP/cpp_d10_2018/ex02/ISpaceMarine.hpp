/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D10_2018_ISPACEMARINE_HPP
#define CPP_D10_2018_ISPACEMARINE_HPP

class ISpaceMarine {
    public:
    virtual ~ISpaceMarine() = default;

    virtual ISpaceMarine *clone() const = 0;

    virtual void battleCry() const = 0;

    virtual void rangedAttack() const = 0;

    virtual void meleeAttack() const = 0;
};

#endif //CPP_D10_2018_ISPACEMARINE_HPP
