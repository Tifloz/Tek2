/*
** EPITECH PROJECT, 2022
** cpp_d13_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D13_2018_PICTURE_HPP
#define CPP_D13_2018_PICTURE_HPP

#include <fstream>
#include <iostream>

class Picture {
    public:
    Picture();

    Picture(const std::string &file);

    virtual ~Picture();

    std::string data;

    bool getPictureFromFile(const std::string &file);
};

#endif //CPP_D13_2018_PICTURE_HPP
