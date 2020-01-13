/*
** EPITECH PROJECT, 2022
** cpp_d07a_2018
** File description:
** Created by Florian Louvet,
*/
#include "KreogCom.hpp"

int main()
{
    KreogCom k(42, 42, 101010);
    k.addCom(56, 25, 65);
    k.addCom(73, 34, 51);
    k.locateSquad();
    k.removeCom();
    k.removeCom();
    return 0;
}