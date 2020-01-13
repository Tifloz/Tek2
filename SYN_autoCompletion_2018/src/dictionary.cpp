/*
** EPITECH PROJECT, 2022
** SYN_autoCompletion_2018
** File description:
** Created by Florian Louvet,
*/

#include <iostream>
#include "dictionary.hpp"
#include <algorithm>

void Dictionary::addCity(const std::string &city)
{
    int already = 0;
    for (auto &tmp:_cities)
        if (tmp.getName() == city) {
            already = 1;
            tmp.addOccur();
        }
    if (!already)
        _cities.emplace_back(city);
}

Dictionary::~Dictionary()
{
}

std::list<Address> *Dictionary::findList(const std::string &city)
{
    for (auto &tmp:_cities)
        if (tmp.getName() == city)
            return tmp.getAddresses();

    return nullptr;
}

City *Dictionary::findCity(const std::string &city)
{
    for (auto &tmp:_cities)
        if (tmp.getName() == city)
            return &tmp;

    return nullptr;
}

std::list<City> *Dictionary::getCities()
{
    return &_cities;
}

void Dictionary::getList()
{
    for (auto &item:_cities) {
        std::cout << item.getName() << ": " << std::to_string(item.getOccur())
            << std::endl;
        for (auto &list:*item.getAddresses())
            printAddress(&item, list);
    }
}

void Dictionary::addAddress(const std::string &city, const std::string &address)
{
    std::list<Address> *tmp = findList(city);
    int already = 0;

    if (tmp == nullptr)
        return;
    for (auto &item:*tmp)
        if (item.getRaw() == address)
            already = 1;
    if (!already)
        tmp->push_back(Address(address));
}

void Dictionary::printAddress(City *city, Address address)
{
    std::cout << "=> " << city->getName() << ", " << address.getNb() << " "
        << address.getType() << " " << _utils.trim(address.getStreet()) << std::endl;
}

bool compare(const City &first, const City &second)
{
    if (first.getOccur() > second.getOccur())
        return true;
    else if (second.getOccur() > first.getOccur())
        return false;
    else {
        return first.getName() < second.getName();
    }
}

void Dictionary::sortCities()
{
    _cities.sort(compare);
}

Dictionary::Dictionary() = default;
