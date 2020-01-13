/*
** EPITECH PROJECT, 2022
** OOP_nanotekspice_2018
** File description:
** Created by Julien Thueux
*/

#include <iostream>
#include <string>

int main(int ac, char **av)
{
    std::string str("");

    while (str != "exit") {
        std::cout << "> ";
        getline(std::cin, str);
    }
    return (0);
}