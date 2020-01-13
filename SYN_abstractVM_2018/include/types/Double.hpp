/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_ABSTRACTVM_2018_DOUBLE_HPP
#define SYN_ABSTRACTVM_2018_DOUBLE_HPP

#include "../IOperand.hpp"
#include <string>
#include "AOperand.hpp"

class Double : public AOperand<double >
{
    public:
        explicit Double (const std::string & value);
        ~Double();
};

template <>
int AOperand<double>::getPrecision() const
{
    return 15;
}

template <>
eOperandType AOperand<double>::getType() const
{
    return DOUBLE;
}

#endif //SYN_ABSTRACTVM_2018_DOUBLE_HPP
