#include "Character.hpp"
#include "Warrior.hpp"

/*
** EPITECH PROJECT, 2022
** cpp_d09_2018
** File description:
** Created by Florian Louvet,
*/
int main()
{
    Character c("Kreog", 21);
    Warrior b("Thor", 42);
    c.TakeDamage(c.RangeAttack());
    c.TakeDamage(c.CloseAttack());
    b.RestorePower();
}