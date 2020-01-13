/*
** EPITECH PROJECT, 2022
** cpp_d17_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D17_2018_CESAR_HPP
#define CPP_D17_2018_CESAR_HPP

#include <iostream>
#include <cstdio>
#include "IEncryptionMethod.hpp"

class Cesar : public IEncryptionMethod {
    public:
    Cesar();

    virtual ~Cesar();

    void encryptChar(char plainchar);

    void decryptChar(char cipherchar);

    void reset();

    protected:
    int _digit;
};

#endif //CPP_D17_2018_CESAR_HPP
