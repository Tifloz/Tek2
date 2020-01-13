/*
** EPITECH PROJECT, 2022
** SYN_autoCompletion_2018
** File description:
** Created by Florian Louvet,
*/
#include "address.hpp"
#include <regex>
#include <iostream>

std::string Address::getRaw()
{
    return _raw;
}

int Address::getNb()
{
    return _nb;
}

std::string Address::getStreet()
{
    return _street;
}

std::string Address::getType()
{
    return _type;
}

Address::Address(const std::string &raw)
{
    std::regex const streetNumber{"(\\d+)"};
    std::regex const streetType{
        "(allée|avenue|rue|boulevard|chemin|impasse|place|quai|square)"};
    std::smatch match;

    _raw = raw;
    if (regex_search(_raw, match, streetNumber)) {
        _nb = atoi(match[0].str().c_str());
        _raw.substr(_raw.find(match[0].str()), match[0].length());
        if (regex_search(_raw, match, streetType)) {
            _type = match[0].str();
            _street = raw.substr(_raw.find(match[0].str()) + match[0].length());
        }
    }
}
