/*
** EPITECH PROJECT, 2022
** SYN_autoCompletion_2018
** File description:
** Created by Florian Louvet,
*/
#include <utility>
#include "city.hpp"
#include <boost/algorithm/string.hpp>

std::string City::getName() const
{
    return _name;
}

void City::addOccur()
{
    _occur++;
}

int City::getOccur() const
{
    return _occur;
}

City::City(std::string name) : _name(std::move(name))
{
    _occur = 1;
}

bool City::occurSort(const City &city) const
{
    return _occur < city.getOccur();
}

std::list<Address> *City::getAddresses()
{
    return &_addresses;
}

bool City::operator==(const City &rhs) const
{
    return boost::algorithm::to_lower_copy(this->_name) ==
        boost::algorithm::to_lower_copy(rhs._name);
}
