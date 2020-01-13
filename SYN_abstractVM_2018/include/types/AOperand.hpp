/*
** EPITECH PROJECT, 2019
** Default
** File description:
** Default
*/

#ifndef SYN_ABSTRACTVM_2018_AOPERAND_HPP
#define SYN_ABSTRACTVM_2018_AOPERAND_HPP

#include "../IOperand.hpp"

template<typename T>
class AOperand : public IOperand {
    protected:
    std::string _value;
    eOperandType _type;
    public:
    AOperand(eOperandType type, const std::string &value);

    virtual std::string toString() const;

    virtual int getPrecision() const;

    virtual eOperandType getType() const;

    virtual IOperand *operator+(const IOperand &) const;

    virtual IOperand *operator-(const IOperand &) const;

    virtual IOperand *operator*(const IOperand &) const;

    virtual IOperand *operator/(const IOperand &) const;

    virtual IOperand *operator%(const IOperand &) const;

    ~AOperand();
};

template
class AOperand<int8_t>;

template
class AOperand<int32_t>;

template
class AOperand<int16_t>;

template
class AOperand<float>;

template
class AOperand<double>;

#endif //SYN_ABSTRACTVM_2018_AOPERAND_HPP
