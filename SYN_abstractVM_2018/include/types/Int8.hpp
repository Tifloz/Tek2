/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_ABSTRACTVM_2018_INT8_HPP
#define SYN_ABSTRACTVM_2018_INT8_HPP

#include <string>
#include "../IOperand.hpp"
#include "AOperand.hpp"

class Int8 : public AOperand<int8_t>
{
    public:
        explicit Int8(const std::string & value);
        ~Int8();
};

template <>
int AOperand<int8_t>::getPrecision() const
{
    return 0;
}

template <>
eOperandType AOperand<int8_t>::getType() const
{
    return INT8;
}

#endif //SYN_ABSTRACTVM_2018_INT8_HPP
