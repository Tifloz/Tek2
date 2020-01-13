/*
** EPITECH PROJECT, 2022
** cpp_d17_2018
** File description:
** Created by Florian Louvet,
*/
#include "Cesar.hpp"

Cesar::Cesar() : _digit(3)
{
}

Cesar::~Cesar() = default;

void Cesar::encryptChar(char plainchar)
{
    if (isalpha(plainchar)) {
        int base = plainchar > 96 ? 97 : 65;
        plainchar = static_cast<char>((plainchar - base + this->_digit) % 26 +
            base);
    }
    this->_digit = (this->_digit + 1) % 26;
    std::cout << plainchar;
}

void Cesar::decryptChar(char cipherchar)
{
    if (isalpha(cipherchar)) {
        int base = cipherchar > 96 ? 122 : 90;
        cipherchar = static_cast<char>((cipherchar - base - this->_digit) % 26 +
            base);
    }
    this->_digit = (this->_digit + 1) % 26;
    std::cout << cipherchar;
}

void Cesar::reset()
{
    this->_digit = 3;
}
