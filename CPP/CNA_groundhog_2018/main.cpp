/*
** EPITECH PROJECT, 2022
** CNA_groundhog_2018
** File description:
** Created by Julien Thueux
*/

#include <string>
#include <iostream>
#include <istream>
#include "Calcul.hpp"
#include <math.h>
#include <cmath>
#include <iomanip>

bool is_number(const char *str)
{
    std::string s(str);
    std::string::const_iterator it = s.begin();
    bool point = false;

    while (it != s.end() && (std::isdigit(*it) || *it == '.')) {
        if (*it == '.') {
            if (point)
                return false;
            else
                point = true;
        }
        ++it;
    }
    return !s.empty() && it == s.end();
}

double calc_r(Calcul *my_cal)
{
    double numbOne = my_cal->memory.at(0);
    double numbTwo = my_cal->memory.at(my_cal->period);
    double result = 0;

    result = (numbTwo * 100);
    result = ((result / numbOne) - 100);
    return (result);
}

double calc_s(Calcul *my_cal)
{
    double result = 0;
    double moyenne = 0;
    int n = 0;

    if (my_cal->s_memory.size() >= my_cal->period) {
        while (n != my_cal->s_memory.size()) {
            moyenne += my_cal->s_memory.at(n);
            n++;
        }
        moyenne = moyenne / my_cal->s_memory.size();
        n = 0;
        while (n != my_cal->s_memory.size()) {
            result += (my_cal->s_memory.at(n) - moyenne) *
                (my_cal->s_memory.at(n) - moyenne);
            n++;
        }
        result = result / my_cal->s_memory.size();
        result = sqrt(result);
        std::cout << "\ts=" << std::fixed << std::setprecision(2) << result;
        my_cal->s_memory.erase(my_cal->s_memory.begin());
        return (result);
    }
    std::cout << "\ts=nan";
    return (-1);
}

void do_calc(Calcul *my_calcul, double number)
{
    double g_result = 0;
    double r_result = 0;
    int n = 0;
    double numbOne = 0;
    double numbTwo = 0;

    my_calcul->memory.push_back(number);
    my_calcul->s_memory.push_back(number);
    if (my_calcul->memory.size() > my_calcul->period) {
        if (my_calcul->memory.size() - 1 == my_calcul->period) {
            while (n != my_calcul->period) {
                numbOne = my_calcul->memory.at(n);
                numbTwo = my_calcul->memory.at(n + 1);
                if (numbOne < numbTwo) {
                    g_result += numbTwo - numbOne;
                } else
                    g_result += 0;
                n++;
            }
            g_result = g_result / my_calcul->period;
            r_result = calc_r(my_calcul);
            r_result = round(r_result);
            if (g_result >= 1)
                std::cout << "g=" << std::fixed << std::setprecision(2)
                    << g_result << "\tr=" << std::setprecision(0) << r_result << "%";
            else {
                std::cout << "g=" << std::fixed << std::setprecision(2)
                    << g_result << "\tr=" << std::setprecision(0) << r_result << "%";
            }
        }
        if (my_calcul->memory.size() > my_calcul->period)
            my_calcul->memory.erase(my_calcul->memory.begin());
    } else {
        std::cout << "g=nan\tr=nan";
    }
    calc_s(my_calcul);
    if (r_result != 0) {
        if (my_calcul->save_r < 0 && r_result > 0) {
            std::cout << "\ta switch occurs" << std::endl;
            my_calcul->count_switch += 1;
        }
        else if (my_calcul->save_r > 0 && r_result < 0) {
            std::cout << "\ta switch occurs" << std::endl;
            my_calcul->count_switch += 1;
        }
        else
            std::cout << std::endl;
    } else
        std::cout << std::endl;
    my_calcul->save_r = r_result;
}

int groundhog(char *str)
{
    std::string numb;
    Calcul my_calcul(atof(str)); 

    while (numb != "STOP") {
        std::cin >> numb;
        if (numb == "STOP") {
            std::cout << "Global tendency switched " << my_calcul.count_switch << " times" << std::endl;
            return (0);
        }
        else if (is_number(numb.c_str()))
            do_calc(&my_calcul, atof(numb.c_str()));
        else
            return 84;
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 2 || !is_number(av[1])) {
        std::cout << "bad parameters" << std::endl;
        return (84);
    } else {
        return (groundhog(av[1]));
    }
}