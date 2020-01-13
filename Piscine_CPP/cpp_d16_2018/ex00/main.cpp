/*
** EPITECH PROJECT, 2022
** cpp_d16_2018
** File description:
** Created by Florian Louvet,
*/
#include  <iostream>
#include "Parser.hpp"

int main()
{
    Parser p;
    p.feed("((12*2) +14)");
    std::cout << p.result() << std::endl;
    p.feed("((17 % 9) / 4)");
    std::cout << p.result() << std::endl;
    p.reset();
    p.feed("17 - (4 * 13)");
    std::cout << p.result() << std::endl;
    p.feed("(((133 / 5) + 6) * ((45642 % 127) - 21))");
    std::cout << p.result() << std::endl;
    return 0;
}