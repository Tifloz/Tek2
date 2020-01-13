/*
** EPITECH PROJECT, 2022
** CNA_groundhog_2018
** File description:
** Created by Julien Thueux
*/

#include "Calcul.hpp"
#include <math.h>

Calcul::Calcul(double period)
{
    this->save_r = 0;
    this->count_switch = 0;
    this->period = period;
}