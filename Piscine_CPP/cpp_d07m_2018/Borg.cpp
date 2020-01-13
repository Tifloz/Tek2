/*
** EPITECH PROJECT, 2022
** cpp_d07m_2018
** File description:
** Created by Florian Louvet,
*/
#include <iostream>
#include "Borg.hpp"
#include "WarpSystem.hpp"

Borg::Ship::Ship(int weaponFrequency, short repair)
{
    this->_side = 300;
    this->_maxWarp = 9;
    this->_home = UNICOMPLEX;
    this->_location = this->_home;
    this->_weaponFrequency = weaponFrequency;
    this->_repair = repair;
    std::cout << "We are the Borgs. "
        << "Lower your shields and surrender yourselves unconditionally."
        << std::endl;
    std::cout << "Your biological characteristics and "
        << "technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship(void) = default;

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
}

void Borg::Ship::checkCore()
{
    std::string tmp = "Critical failure imminent.";

    if (this->_core->checkReactor()->isStable())
        tmp = "Everything is in order.";
    std::cout << tmp << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location &&
        this->_core->checkReactor()->isStable()) {
        this->_location = d;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move(int warp)
{
    return (move(warp, this->_home));
}

bool Borg::Ship::move(Destination d)
{
    return (move(this->_maxWarp, d));
}

bool Borg::Ship::move()
{
    return (move(this->_maxWarp, this->_home));
}

int Borg::Ship::getShield()
{
    return (this->_shield);
}

void Borg::Ship::setShield(int shield)
{
    this->_shield = shield;
}

int Borg::Ship::getWeaponFrequency()
{
    return (this->_weaponFrequency);
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
    this->_weaponFrequency = frequency;
}

short Borg::Ship::getRepair()
{
    return (this->_repair);
}

void Borg::Ship::setRepair(short repair)
{
    this->_repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    target->setShield(target->getShield() - this->getWeaponFrequency());
    std::cout << "Firing on target with " << this->getWeaponFrequency()
        << "GW frequency." << std::endl;
}

void Borg::Ship::fire(Federation::Ship *target)
{
    target->getCore()->checkReactor()->setStability(false);
    std::cout << "Firing on target with " << this->getWeaponFrequency()
        << "GW frequency." << std::endl;
}

void Borg::Ship::repair()
{
    if (this->_repair > 0) {
        this->_repair--;
        this->_shield = 100;
        std::cout << "Begin shield re-initialisation... "
                     "Done. Awaiting further instructions." << std::endl;
    } else
        std::cout << "Energy cells depleted, shield weakening." << std::endl;
}
