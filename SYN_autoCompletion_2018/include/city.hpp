/*
** EPITECH PROJECT, 2022
** SYN_autoCompletion_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_AUTOCOMPLETION_2018_CITY_HPP
#define SYN_AUTOCOMPLETION_2018_CITY_HPP

#include <string>
#include <list>
#include "address.hpp"

class City {
    public:
    struct SortCities {
        bool operator()(const City *lhs, const City *rhs) const
        {
            return *lhs < *rhs;
        }
    };

    std::list<Address> *getAddresses();

    std::string getName() const;

    void addOccur();

    int getOccur() const;

    City(std::string name);

    bool operator<(const City &p) const;

    bool operator==(const City &rhs) const;

    private:
    std::string _name;
    int _occur;
    std::list<Address> _addresses;

    bool occurSort(const City &city) const;
};

#endif //SYN_AUTOCOMPLETION_2018_CITY_HPP
