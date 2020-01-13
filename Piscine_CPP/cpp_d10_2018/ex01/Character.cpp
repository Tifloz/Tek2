/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#include "Character.hpp"

Character::Character(std::string const &name)
{
    this->_name = name;
    this->_ap = 40;
}

Character::~Character() = default;

void Character::recoverAP()
{
    this->_ap += 10;
    if (this->_ap > 40)
        this->_ap = 40;
}

void Character::equip(AWeapon *weapon)
{
    this->_weapon = weapon;
}

void Character::attack(AEnemy *enemy)
{
    if (this->_weapon)
        if (this->_ap >= this->_weapon->getAPCost()) {
            this->_ap -= this->_weapon->getAPCost();
            enemy->takeDamage(this->_weapon->getDamage());
            std::cout << this->_name << " attacks " << enemy->getType()
                << " with a " << this->_weapon->getName() << std::endl;
            this->_weapon->attack();
            if (enemy->getHP() <= 0)
                delete enemy;
        }
}

std::string const &Character::getName() const
{
    return (this->_name);
}

int Character::getAP() const
{
    return (this->_ap);
}

AWeapon *Character::getWeapon() const
{
    return (this->_weapon);
}

std::ostream &operator<<(std::ostream &os, Character const &elem)
{
    if (elem.getWeapon())
        return (os << elem.getName() << " has " << elem.getAP()
            << " AP and wields a " << elem.getWeapon()->getName() << std::endl);
    return (os << elem.getName() << " has " << elem.getAP()
        << " AP and is unarmed" << std::endl);
}
