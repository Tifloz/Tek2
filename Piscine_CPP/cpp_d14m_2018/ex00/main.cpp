#include "Lemon.hpp"
#include "Banana.hpp"

/*
** EPITECH PROJECT, 2022
** cpp_d14m_2018
** File description:
** Created by Florian Louvet,
*/
int main()
{
    Lemon l;
    Banana b;
    std::cout << l.getVitamins() << std::endl;
    std::cout << b.getVitamins() << std::endl;
    std::cout << l.getName() << std::endl;
    std::cout << b.getName() << std::endl;
    Fruit &f = l;
    std::cout << f.getVitamins() << std::endl;
    std::cout << f.getName() << std::endl;
    return 0;
}