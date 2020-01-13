/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_ABSTRACTVM_2018_BIGDECIMAL_HPP
#define SYN_ABSTRACTVM_2018_BIGDECIMAL_HPP

#include "../IOperand.hpp"
#include "AOperand.hpp"
#include <string>

class BigDecimal : public IOperand
{
    public:
        explicit BigDecimal (const std::string & value);
        ~BigDecimal() override;

        std::string add(std::string s1, std::string s2) const;
        std::string sub(std::string s1, std::string s2) const;
        std::string mul(std::string s1, std::string s2) const;

        IOperand *operator+(const IOperand &rhs) const override;
        IOperand *operator-(const IOperand &rhs) const override;
        IOperand *operator*(const IOperand &rhs) const override;
        IOperand *operator/(const IOperand &rhs) const override;
        IOperand *operator%(const IOperand &rhs) const override;

        std::string toString() const override
        {
            return (_str);
        };
        int getPrecision() const override
        {
            return 200;
        };
        eOperandType getType() const override
        {
            return BIGDECIMAL;
        };
    protected:
        long _value;
        std::string _str;
};

#endif //SYN_ABSTRACTVM_2018_BIGDECIMAL_HPP
