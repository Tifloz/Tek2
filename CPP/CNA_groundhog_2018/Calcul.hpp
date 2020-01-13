/*
** EPITECH PROJECT, 2022
** CNA_groundhog_2018
** File description:
** Created by Julien Thueux,
*/

#ifndef CNA_GROUNDHOG_2018_CALCUL_HPP
#define CNA_GROUNDHOG_2018_CALCUL_HPP

#include <vector>

class Calcul
{
    public:
        Calcul(double period);
        double period;
        std::vector<double> memory;
        std::vector<double> s_memory;
        double save_r;
        int count_switch;
};

#endif //CNA_GROUNDHOG_2018_CALCUL_HPP