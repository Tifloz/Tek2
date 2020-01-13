#include "Character.hpp"

/*
** EPITECH PROJECT, 2022
** cpp_d09_2018
** File description:
** Created by Florian Louvet,
*/
int main()
{
    Character c("poney", 42);
    c.TakeDamage(c.RangeAttack());
    c.TakeDamage(c.CloseAttack());
    c.TakeDamage(200);
}