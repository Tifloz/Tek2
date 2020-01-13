/*
** EPITECH PROJECT, 2022
** cpp_d07a_2018
** File description:
** Created by Florian Louvet,
*/
#include "Parts.hpp"

Arms::Arms(std::string serial, bool functionnal)
{
    this->_serial = serial;
    this->_functionnal = functionnal;
}

Arms::~Arms() = default;

bool Arms::isFunctionnal() const
{
    return (this->_functionnal);
}

std::string Arms::serial()
{
    return (this->_serial);
}

void Arms::informations() const
{
    std::string res = "KO";
    if (this->_functionnal)
        res = "OK";
    std::cout << "\t[Parts] Arms " << this->_serial << " status : " << res
        << std::endl;
}

Legs::Legs(std::string serial, bool functionnal)
{
    this->_serial = serial;
    this->_functionnal = functionnal;
}

Legs::~Legs() = default;

bool Legs::isFunctionnal() const
{
    return (this->_functionnal);
}

std::string Legs::serial()
{
    return (this->_serial);
}

void Legs::informations() const
{
    std::string res = "KO";
    if (this->_functionnal)
        res = "OK";
    std::cout << "\t[Parts] Legs " << this->_serial << " status : " << res
        << std::endl;
}

Head::Head(std::string serial, bool functionnal)
{
    this->_serial = serial;
    this->_functionnal = functionnal;
}

Head::~Head() = default;

bool Head::isFunctionnal() const
{
    return (this->_functionnal);
}

std::string Head::serial()
{
    return (this->_serial);
}

void Head::informations() const
{
    std::string res = "KO";
    if (this->_functionnal)
        res = "OK";
    std::cout << "\t[Parts] Head " << this->_serial << " status : " << res
        << std::endl;
}
