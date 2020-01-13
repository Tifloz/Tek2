/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_ABSTRACTVM_2018_FACTORY_HPP
#define SYN_ABSTRACTVM_2018_FACTORY_HPP

#include <string>
#include "IOperand.hpp"

class Factory {
    public:
    Factory();

    virtual ~Factory();

    static IOperand *createOperand(eOperandType type, const std::string &value);

    private:
    IOperand *createInt8(const std::string &value);

    IOperand *createInt16(const std::string &value);

    IOperand *createInt32(const std::string &value);

    IOperand *createFloat(const std::string &value);

    IOperand *createDouble(const std::string &value);

    IOperand *createBigDecimal(const std::string &value);

    typedef IOperand *(Factory::*ptr)(const std::string &value);
};

#endif //SYN_ABSTRACTVM_2018_FACTORY_HPP
