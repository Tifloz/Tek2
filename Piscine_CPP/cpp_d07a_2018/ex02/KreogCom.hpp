/*
** EPITECH PROJECT, 2022
** cpp_d07a_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D07A_2018_KREOGCOM_HPP
#define CPP_D07A_2018_KREOGCOM_HPP

#include <iostream>

class KreogCom {
    public:
    KreogCom(int x, int y, int serial);

    ~KreogCom();

    void addCom(int x, int y, int serial);

    KreogCom *getCom();

    void removeCom();

    void ping() const;

    void locateSquad() const;

    private:
    int _x;
    int _y;
    const int m_serial;
    KreogCom *next;
};

#endif //CPP_D07A_2018_KREOGCOM_HPP
