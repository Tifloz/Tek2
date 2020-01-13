/*
** EPITECH PROJECT, 2022
** 201yams_2018
** File description:
** Created by Florian Louvet,
*/
#include <sstream>
#include <algorithm>
#include "Full.hpp"
#include "tools.hpp"

Full::Full(std::vector<std::string> &v) : _v(v)
{
}

void Full::calc()
{
    std::stringstream ss;
    std::string str;
    std::stringstream ss2;
    std::string str2;
    std::size_t nb = this->_v[5].find('_') + 1;
    std::size_t nb2 = this->_v[5].find('_') + 3;

    if ((this->_v[5][nb] - 48) > 6 || (this->_v[5][nb] - 48) < 1 ||
        (this->_v[5][nb2] - 48) > 6 || (this->_v[5][nb2] - 48) < 1) {
        std::cerr << "Bad input" << std::endl;
        exit(84);
    }
    ss << this->_v[5][nb];
    ss >> str;
    ss2 << this->_v[5][nb2];
    ss2 >> str2;
    if (std::count(this->_v.begin(), this->_v.end(), str) == 3 &&
        std::count(this->_v.begin(), this->_v.end(), str2) == 2)
        std::cout << "chances to get a " << str << " full of " << str2
            << ": 100.00%" << std::endl;
    else
        std::cout << "chances to get a " << str << " full of " << str2
            << ": 0.13%" << std::endl;
}
