/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, std::string const &type)
{
    this->_hp = hp;
    this->_type = type;
}

AEnemy::~AEnemy() = default;

std::string const &AEnemy::getType() const
{
    return this->_type;
}

int AEnemy::getHP() const
{
    return this->_hp;
}

void AEnemy::takeDamage(int damage)
{
    if (damage < 0)
        return;
    this->_hp -= damage;
}
