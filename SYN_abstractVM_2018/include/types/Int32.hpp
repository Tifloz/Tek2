/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_ABSTRACTVM_2018_INT32_HPP
#define SYN_ABSTRACTVM_2018_INT32_HPP

#include "../IOperand.hpp"
#include <string>
#include "AOperand.hpp"

class Int32 : public AOperand<int32_t>
{
    public:
        explicit Int32(const std::string & value);
        ~Int32();
};

template <>
int AOperand<int32_t >::getPrecision() const
{
    return 0;
}

template <>
eOperandType AOperand<int32_t>::getType() const
{
    return INT32;
}

#endif //SYN_ABSTRACTVM_2018_INT32_HPP
