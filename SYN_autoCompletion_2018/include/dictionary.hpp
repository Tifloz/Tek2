/*
** EPITECH PROJECT, 2022
** SYN_autoCompletion_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_AUTOCOMPLETION_2018_DICTIONNARY_HPP
#define SYN_AUTOCOMPLETION_2018_DICTIONNARY_HPP

#include "city.hpp"
#include "address.hpp"
#include <list>
#include <map>
#include "utils.hpp"

class Dictionary {
    public:
    std::list<City> *getCities();

    void addCity(const std::string &city);

    void addAddress(const std::string &city, const std::string &address);

    void getList();

    Dictionary();

    virtual ~Dictionary();

    void printAddress(City *city, Address address);

    void sortCities();

    private:
    Utils _utils;
    std::list<City> _cities;

    std::list<Address> *findList(const std::string &city);

    City *findCity(const std::string &city);
};

#endif //SYN_AUTOCOMPLETION_2018_DICTIONNARY_HPP
