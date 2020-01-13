/*
** EPITECH PROJECT, 2022
** cpp_d17_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D17_2018_ONETIME_HPP
#define CPP_D17_2018_ONETIME_HPP

#include <iostream>
#include <cstdlib>
#include "IEncryptionMethod.hpp"

class OneTime : public IEncryptionMethod {
    public:
    OneTime(std::string key);

    virtual ~OneTime();

    void encryptChar(char plainchar);

    void decryptChar(char cipherchar);

    void reset();

    protected:
    std::string _key;
    unsigned long _index;
};

#endif //CPP_D17_2018_ONETIME_HPP
