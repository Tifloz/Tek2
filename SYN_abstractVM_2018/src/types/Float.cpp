/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/
#include "../../include/Error.hpp"
#include "../../include/types/Float.hpp"

Float::Float(const std::string & value) : AOperand(FLOAT, value)
{
}

Float::~Float()
= default;