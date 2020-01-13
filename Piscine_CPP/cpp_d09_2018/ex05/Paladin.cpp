/*
** EPITECH PROJECT, 2022
** cpp_d09_2018
** File description:
** Created by Florian Louvet,
*/
#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int level) : Character(name, level),
    Warrior(name, level), Priest(name, level)
{
    this->_name = name;
    this->_level = level;
    this->_pv = 100;
    this->_power = 100;
    this->_strenght = 9;
    this->_stamina = 10;
    this->_intelligence = 10;
    this->_spirit = 10;
    this->_agility = 2;
    this->Range = Character::CLOSE;
    this->weaponName = std::string("hammer");

    std::cout << "the light falls on " << this->_name << std::endl;
}

Paladin::~Paladin() = default;

int Paladin::CloseAttack()
{
    int dmg = 0;

    if (this->_power >= 30) {
        this->_power -= 30;
        dmg = 20 + this->_strenght;
        std::cout << this->_name << " strikes with his " << this->weaponName
            << std::endl;
    } else
        std::cout << this->_name << " out of power" << std::endl;
    return (dmg);
}

int Paladin::RangeAttack()
{
    int dmg = 0;

    if (this->_power >= 25) {
        this->_power -= 25;
        dmg = 20 + this->_spirit;
        std::cout << this->_name << " launches a fire ball" << std::endl;
    } else
        std::cout << this->_name << " out of power" << std::endl;
    return (dmg);
}

void Paladin::Heal()
{
    if (this->_power >= 10) {
        this->_power -= 10;
        this->_pv += 70;
        if (this->_pv > 100)
            this->_pv = 100;
        std::cout << this->_name << " casts a little heal spell" << std::endl;
    } else
        std::cout << this->_name << " out of power" << std::endl;
}

void Paladin::RestorePower()
{
    this->_power = 100;
    std::cout << this->_name << " eats" << std::endl;
}

int Paladin::Intercept()
{
    if (this->_power >= 10) {
        this->_power -= 10;
        std::cout << this->_name << " intercepts" << std::endl;
        this->Range = Character::CLOSE;
    } else
        std::cout << this->_name << " out of power" << std::endl;
    return 0;
}
