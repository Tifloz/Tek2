/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_ABSTRACTVM_2018_FLOAT_HPP
#define SYN_ABSTRACTVM_2018_FLOAT_HPP

#include "../IOperand.hpp"
#include <string>
#include "AOperand.hpp"

class Float : public AOperand<float >
{
    public:
        explicit Float (const std::string & value);
        ~Float();
};

template <>
int AOperand<float >::getPrecision() const
{
    return 7;
}

template <>
eOperandType AOperand<float>::getType() const
{
    return FLOAT;
}
#endif //SYN_ABSTRACTVM_2018_FLOAT_HPP
