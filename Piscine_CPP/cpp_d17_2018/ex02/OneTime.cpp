/*
** EPITECH PROJECT, 2022
** cpp_d17_2018
** File description:
** Created by Florian Louvet,
*/
#include "OneTime.hpp"

OneTime::OneTime(std::string key) : _key(key), _index(0)
{
}

OneTime::~OneTime() = default;

void OneTime::encryptChar(char plainchar)
{
    if (isalpha(plainchar)) {
        int base = plainchar > 96 ? 97 : 65;
        int mask = this->_key[this->_index] > 96 ? 97 : 65;
        plainchar = static_cast<char>(
            (plainchar - base + (this->_key[this->_index] - mask)) % 26 +
                base);
    }
    std::cout << plainchar;
    this->_index = (this->_index + 1) % this->_key.size();
}

void OneTime::decryptChar(char cipherchar)
{
    if (isalpha(cipherchar)) {
        int base = cipherchar > 96 ? 122 : 90;
        int mask = this->_key[this->_index] > 96 ? 97 : 65;
        cipherchar = static_cast<char>(
            (cipherchar - base - (this->_key[this->_index] - mask)) % 26 +
                base);
    }
    std::cout << cipherchar;
    this->_index = (this->_index + 1) % this->_key.size();
}

void OneTime::reset()
{
    this->_index = 0;
}
