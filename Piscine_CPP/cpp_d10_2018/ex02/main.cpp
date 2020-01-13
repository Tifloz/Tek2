#include "ISquad.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include <memory>

/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
int main()
{
    std::unique_ptr<ISquad> vlc(new Squad);
    vlc->push(new TacticalMarine);
    vlc->push(new AssaultTerminator);
    for (int i = 0; i < vlc->getCount(); ++i) {
        const auto cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    return 0;
}