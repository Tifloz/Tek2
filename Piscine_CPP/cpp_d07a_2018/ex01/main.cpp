#include "KoalaBot.hpp"

/*
** EPITECH PROJECT, 2022
** cpp_d07a_2018
** File description:
** Created by Florian Louvet,
*/


int main()
{
    KoalaBot kb;
    std::cout << std::boolalpha << kb.status() << std::endl;
    kb.informations();
    return 0;
}