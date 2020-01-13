/*
** EPITECH PROJECT, 2022
** 201yams_2018
** File description:
** Created by Florian Louvet,
*/
#include <sstream>
#include <iostream>
#include <algorithm>
#include "Brelan.hpp"

Brelan::Brelan(std::vector<std::string> &v) : _v(v)
{
}

void Brelan::calc()
{
    std::stringstream ss;
    std::string str;
    std::size_t nb = this->_v[5].find('_') + 1;

    if ((this->_v[5][nb] - 48) > 6 || (this->_v[5][nb] - 48) < 1) {
        std::cerr << "Bad input" << std::endl;
        exit(84);
    }
    ss << this->_v[5][nb];
    ss >> str;
    if (std::count(this->_v.begin(), this->_v.end(), str) >= 3)
        std::cout << "chances to get a " << str << " three-of-a-kind: 100.00%"
            << std::endl;
    else
        std::cout << "chances to get a " << str << " three-of-a-kind: 3.55%"
            << std::endl;
}
