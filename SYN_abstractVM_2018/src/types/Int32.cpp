/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/
#include "../../include/types/Int32.hpp"
#include "../../include/Factory.hpp"
#include <string>
#include <sstream>
#include "../../include/Error.hpp"

Int32::Int32(const std::string & value) : AOperand(INT32, value)
{
}

Int32::~Int32()
= default;

