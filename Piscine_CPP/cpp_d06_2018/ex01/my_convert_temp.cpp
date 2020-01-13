/*
** EPITECH PROJECT, 2022
** cpp_d06_2018
** File description:
** Created by Florian Louvet,
*/
#include <iostream>
#include <stdlib.h>
#include <iomanip>

void calc_temperature(float value, int type)
{
    float result;

    switch (type) {
    case 1:
        result = static_cast<float>(value * 9.0 / 5.0 + 32);
        std::cout << std::setw(16) << std::fixed << std::setprecision(3)
            << result << std::setw(16) << "Fahrenheit" << std::endl;
        break;
    case 2:
        result = static_cast<float>((value - 32) * (5.0 / 9.0));
        std::cout << std::setw(16) << std::fixed << std::setprecision(3)
            << result << std::setw(16) << "Celsius" << std::endl;
        break;
    default:
        return;
    }
}

int type_checker(std::string type)
{
    if (type == "Celsius")
        return (1);
    else if (type == "Fahrenheit")
        return (2);
    else
        return (0);
}

int main()
{
    float value;
    std::string type;

    std::cin >> value >> type;
    if (std::cin.fail() || type_checker(type) == 0) {
        std::cerr << "Please enter a correct value !" << std::endl;
        return (EXIT_FAILURE);
    }
    calc_temperature(value, type_checker(type));
    return (EXIT_SUCCESS);
}