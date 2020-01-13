/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/
#include "../../include/types/Double.hpp"
#include "../../include/Error.hpp"

Double::Double(const std::string & value) : AOperand(DOUBLE, value)
{
}

Double::~Double()
= default;
