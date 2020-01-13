/*
** EPITECH PROJECT, 2022
** cpp_d15_2018
** File description:
** Created by Florian Louvet,
*/
#include  <iostream>
#include  <string>
#include "ex01.hpp"

int main()
{
    toto a, b;

    std::cout << ::compare(a, b) << std::endl;
    std::cout << ::compare(1, 2) << std::endl;
    std::cout << ::compare<const char *>("chaineZ", "chaineA42") << std::endl;
    const char *s1 = "42", *s2 = "lulz";
    std::cout << ::compare(s1, s2) << std::endl;
}