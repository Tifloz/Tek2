/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#include "Character.hpp"
#include "RadScorpion.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main()
{
    const auto preda = new Character("Predator");
    const auto prey = new RadScorpion();
    std::cout << *preda;
    AWeapon *pr(new PlasmaRifle());
    AWeapon *pf(new PowerFist());
    preda->equip(pr);
    std::cout << *preda;
    preda->equip(pf);
    preda->attack(prey);
    std::cout << *preda;
    preda->equip(pr);
    std::cout << *preda;
    preda->attack(prey);
    std::cout << *preda;
    preda->attack(prey);
    std::cout << *preda;
    return 0;
}