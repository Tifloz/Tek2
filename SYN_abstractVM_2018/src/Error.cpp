/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** Cpp file
*/

#include "../include/Error.hpp"

Exception::Exception(String const &error) noexcept
{
    this->_error = error;
}

const char *Exception::what() const noexcept
{
    return (this->_error.c_str());
}

Exception::~Exception() = default;
