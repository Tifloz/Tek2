/*
** EPITECH PROJECT, 2022
** 201yams_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef INC_201YAMS_2018_FULL_HPP
#define INC_201YAMS_2018_FULL_HPP

#include <string>
#include <vector>

class Full {
    public:
    explicit Full(std::vector<std::string> &v);

    void calc();

    private:
    std::vector<std::string> _v;
};

#endif //INC_201YAMS_2018_FULL_HPP
