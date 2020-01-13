/*
** EPITECH PROJECT, 2022
** cpp_d07m_2018
** File description:
** Created by Florian Louvet,
*/
#include "Borg.hpp"
#include <iostream>
#include "Destination.hpp"
#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(int _length, int _width, std::string _name,
    short _maxWarp, int torpedo
)
{
    this->_length = _length;
    this->_width = _width;
    this->_name = _name;
    this->_maxWarp = _maxWarp;
    this->_home = EARTH;
    this->_location = this->_home;
    this->_shield = 100;
    this->_photonTorpedo = torpedo;

    std::cout << "The ship USS " << this->_name << " has been finished."
        << std::endl << "It is " << this->_length << " m in length and "
        << this->_width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
    if (torpedo > 0)
        std::cout << "Weapons are set: " << this->_photonTorpedo
            << " torpedoes ready." << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    std::string res = "unstable";

    if (this->_core->checkReactor()->isStable())
        res = "stable";
    std::cout << "USS " << this->_name << ": The core is " << res
        << " at the time." << std::endl;
}

void Federation::Starfleet::Ship::promote(
    Federation::Starfleet::Captain *captain
)
{
    std::cout << captain->getName()
        << ": I'm glad to be the captain of the USS " << this->_name << "."
        << std::endl;
}

Federation::Starfleet::Ship::~Ship() = default;

Federation::Ship::Ship(int length, int width, std::string name)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = 1;
    this->_home = VULCAN;
    this->_location = this->_home;
    std::cout << "The independant ship " << this->_name
        << " just finished its construction.\nIt is " << this->_length
        << " m in length and " << this->_width << " m in width." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
    std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    std::string tmp = "unstable";

    if (this->_core->checkReactor()->isStable())
        tmp = "stable";
    std::cout << this->_name << ": The core is " << tmp << " at the time."
        << std::endl;
}

Federation::Ship::~Ship() = default;

Federation::Starfleet::Captain::Captain(std::string name)
{
    this->_name = name;
}

Federation::Starfleet::Captain::~Captain(void) = default;

std::string Federation::Starfleet::Captain::getName()
{
    return (this->_name);
}

int Federation::Starfleet::Captain::getAge()
{
    return (this->_age);
}

void Federation::Starfleet::Captain::setAge(int age)
{
    this->_age = age;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    this->_name = name;
    std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign() = default;

bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location &&
        this->_core->checkReactor()->isStable()) {
        this->_location = d;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(int warp)
{
    return (move(warp, this->_home));
}

bool Federation::Ship::move(Destination d)
{
    return (move(this->_maxWarp, d));
}

bool Federation::Ship::move()
{
    return (move(this->_maxWarp, this->_home));
}

WarpSystem::Core *Federation::Ship::getCore()
{
    return (this->_core);
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location &&
        this->_core->checkReactor()->isStable()) {
        this->_location = d;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(int warp)
{
    return (move(warp, this->_home));
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    return (move(this->_maxWarp, d));
}

bool Federation::Starfleet::Ship::move()
{
    return (move(this->_maxWarp, this->_home));
}

int Federation::Starfleet::Ship::getShield()
{
    return (this->_shield);
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    this->_shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return (this->_photonTorpedo);
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    this->_photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    fire(1, target);
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (torpedoes <= this->_photonTorpedo) {
        target->setShield(target->getShield() - 50 * torpedoes);
        this->_photonTorpedo -= torpedoes;
        std::cout << this->_name << ": Firing on target. "
            << this->_photonTorpedo << " torpedoes remaining." << std::endl;
    } else if (this->_photonTorpedo < torpedoes)
        std::cout << this->_name << ": No enough torpedoes to fire, "
            << this->_captain->getName() << "!" << std::endl;
    else
        std::cout << this->_name << ": No more torpedo to fire, "
            << this->_captain->getName() << "!" << std::endl;
}
