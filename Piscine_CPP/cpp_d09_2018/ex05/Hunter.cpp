/*
** EPITECH PROJECT, 2022
** cpp_d09_2018
** File description:
** Created by Florian Louvet,
*/
#include "Hunter.hpp"

Hunter::Hunter(const std::string &name, int level) : Warrior(name, level),
    Character(name, level)
{
    this->_name = name;
    this->_level = level;
    this->_pv = 100;
    this->_power = 100;
    this->_strenght = 9;
    this->_stamina = 9;
    this->_intelligence = 5;
    this->_spirit = 6;
    this->_agility = 24;
    this->Range = Character::CLOSE;
    this->weaponName = std::string("sword");
    std::cout << this->_name << " is born from a tree" << std::endl;
}

Hunter::~Hunter() = default;

int Hunter::CloseAttack()
{
    int dmg = 0;

    this->weaponName = std::string("sword");
    if (this->_power >= 30) {
        this->_power -= 30;
        dmg = this->_strenght + 20;
        std::cout << this->_name << " strikes with his " << this->weaponName
            << std::endl;
    } else
        std::cout << this->_name << " out of power" << std::endl;
    return (dmg);
}

int Hunter::RangeAttack()
{
    int dmg = 0;

    if (this->_power >= 25) {
        this->_power -= 25;
        dmg = this->_agility + 20;
        std::cout << this->_name << " uses his bow";
    } else
        std::cout << this->_name << " out of power" << std::endl;
    return (dmg);
}

void Hunter::Heal()
{
    this->_pv += 50;
    if (this->_pv > 100)
        this->_pv = 100;
    std::cout << this->_name << " takes a potion" << std::endl;
}

void Hunter::RestorePower()
{
    this->_power = 100;
    std::cout << this->_name << " meditates" << std::endl;
}
