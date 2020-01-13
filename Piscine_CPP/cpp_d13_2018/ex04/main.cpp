/*
** EPITECH PROJECT, 2022
** cpp_d13_2018
** File description:
** Created by Florian Louvet,
*/
#include  <iostream>
#include "Toy.hpp"

int main()
{
    Toy a(Toy::BASIC_TOY, "REX", "rex.txt");
    std::cout << a;
    a << "\\o/";
    std::cout << a;
}