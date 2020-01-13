/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage)
{
    this->_name = name;
    this->_apcost = apcost;
    this->_damage = damage;
}

AWeapon::~AWeapon() = default;

std::string const &AWeapon::getName() const
{
    return (this->_name);
}

int AWeapon::getAPCost() const
{
    return this->_apcost;
}

int AWeapon::getDamage() const
{
    return this->_damage;
}
