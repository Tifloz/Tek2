/*
** EPITECH PROJECT, 2022
** 201yams_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef INC_201YAMS_2018_PAIR_HPP
#define INC_201YAMS_2018_PAIR_HPP

#include <string>
#include <vector>

class Pair {
    public:
    explicit Pair(std::vector<std::string> &v);

    void calc();

    private:
    std::vector<std::string> _v;
};

#endif //INC_201YAMS_2018_PAIR_HPP
