/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_ABSTRACTVM_2018_INT16_HPP
#define SYN_ABSTRACTVM_2018_INT16_HPP

#include <string>
#include "../IOperand.hpp"
#include "AOperand.hpp"

class Int16 : public AOperand<int16_t>
{
    public:
        explicit Int16(const std::string & value);
        ~Int16();
};

template <>
int AOperand<int16_t >::getPrecision() const
{
    return 0;
}

template <>
eOperandType AOperand<int16_t>::getType() const
{
    return INT16;
}


#endif //SYN_ABSTRACTVM_2018_INT16_HPP
