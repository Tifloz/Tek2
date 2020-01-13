/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/
#include <string>
#include <sstream>
#include "../../include/types/Int16.hpp"
#include "../../include/Factory.hpp"
#include "../../include/Error.hpp"

Int16::Int16(const std::string & value) : AOperand(INT16, value)
{
}

Int16::~Int16()
= default;
