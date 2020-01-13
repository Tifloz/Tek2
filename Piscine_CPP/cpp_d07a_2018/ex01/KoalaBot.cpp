/*
** EPITECH PROJECT, 2022
** cpp_d07a_2018
** File description:
** Created by Florian Louvet,
*/
#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial)
{
    this->_serial = serial;
}

KoalaBot::~KoalaBot() = default;

void KoalaBot::setParts(const Arms arms)
{
    this->_arms = arms;
}

void KoalaBot::setParts(const Legs legs)
{
    this->_legs = legs;
}

void KoalaBot::setParts(const Head head)
{
    this->_head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    setParts(arms);
}

void KoalaBot::swapParts(Legs &legs)
{
    setParts(legs);
}

void KoalaBot::swapParts(Head &head)
{
    setParts(head);
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << this->_serial << std::endl;
    this->_arms.informations();
    this->_legs.informations();
    this->_head.informations();
}

bool KoalaBot::status() const
{
    return (this->_arms.isFunctionnal() && this->_legs.isFunctionnal() &&
        this->_head.isFunctionnal());
}
