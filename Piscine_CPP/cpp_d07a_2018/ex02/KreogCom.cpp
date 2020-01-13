/*
** EPITECH PROJECT, 2022
** cpp_d07a_2018
** File description:
** Created by Florian Louvet,
*/
#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial) : _x(x), _y(y), m_serial(serial)
{
    this->next = nullptr;
    std::cout << "KreogCom " << m_serial << " initialisated" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    auto *next_elem = new KreogCom(x, y, serial);
    next_elem->next = this->next;
    this->next = next_elem;
}

KreogCom *KreogCom::getCom()
{
    if (this->next == nullptr)
        return (nullptr);
    return (this->next);
}

void KreogCom::removeCom()
{
    KreogCom *next;
    if (this->next != nullptr) {
        next = this->next;
        this->next = this->next->next;
        delete next;
    }
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << this->m_serial << " currently at " << this->_x
        << " " << this->_y << std::endl;
}

void KreogCom::locateSquad() const
{
    if (this->next)
        this->next->locateSquad();
    this->ping();
}