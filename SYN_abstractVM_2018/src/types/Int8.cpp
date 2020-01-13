/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/
#include "../../include/Factory.hpp"
#include "../../include/types/Int8.hpp"
#include <string>
#include <sstream>
#include "../../include/Error.hpp"

Int8::Int8(const std::string & value) : AOperand(INT8, value)
{
}

Int8::~Int8()
= default;
