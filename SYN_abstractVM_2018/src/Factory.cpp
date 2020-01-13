/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/
#include "../include/Factory.hpp"
#include "../include/types/Int8.hpp"
#include "../include/types/Int16.hpp"
#include "../include/types/Int32.hpp"
#include "../include/types/Float.hpp"
#include "../include/types/Double.hpp"
#include "../include/types/BigDecimal.hpp"
#include <map>
#include <iostream>

IOperand *Factory::createInt8(const std::string &value)
{
    auto ptr = new(Int8)(value);

    return ((IOperand *)ptr);
}

IOperand *Factory::createInt16(const std::string &value)
{
    auto *ptr = new(Int16)(value);

    return ((IOperand *)ptr);
}

IOperand *Factory::createInt32(const std::string &value)
{
    auto *ptr = new(Int32)(value);

    return ((IOperand *)ptr);
}

IOperand *Factory::createFloat(const std::string &value)
{
    auto *ptr = new(Float)(value);

    return ((IOperand *)ptr);
}

IOperand *Factory::createDouble(const std::string &value)
{
    auto *ptr = new(Double)(value);

    return ((IOperand *)ptr);
}

IOperand *Factory::createBigDecimal(const std::string &value)
{
    auto *ptr = new(BigDecimal)(value);

    return ((IOperand *)ptr);
}

Factory::Factory() = default;

Factory::~Factory() = default;

IOperand *Factory::createOperand(eOperandType type, const std::string &value)
{
    Factory tmp;
    static std::map<eOperandType, ptr> map;
    std::string str = value;

    if (type == NONE) {
        type = INT8;
        str = "1";
    }
    map[INT8] = &Factory::createInt8;
    map[INT16] = &Factory::createInt16;
    map[INT32] = &Factory::createInt32;
    map[FLOAT] = &Factory::createFloat;
    map[DOUBLE] = &Factory::createDouble;
    map[BIGDECIMAL] = &Factory::createBigDecimal;
    return ((tmp.*map[type])(str));
}
