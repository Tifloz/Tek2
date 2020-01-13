/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_ABSTRACTVM_2018_IOPERAND_HPP
#define SYN_ABSTRACTVM_2018_IOPERAND_HPP

#include <string>

enum eOperandType {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE,
    BIGDECIMAL,
    NONE
};

class IOperand {
    public:
    virtual std::string toString() const = 0; // string  that  represents  the  instance
    virtual eOperandType getType() const = 0; // returns  the  type of  instance
    virtual int getPrecision() const = 0;

    virtual IOperand *operator+(const IOperand &rhs) const = 0; // sum
    virtual IOperand *operator-(const IOperand &rhs) const = 0; // diff
    virtual IOperand *operator*(const IOperand &rhs) const = 0; // mul
    virtual IOperand *operator/(const IOperand &rhs) const = 0; // div
    virtual IOperand *operator%(const IOperand &rhs) const = 0; // mod
    virtual ~IOperand()
    {
    }
};

#endif //SYN_ABSTRACTVM_2018_IOPERAND_HPP
