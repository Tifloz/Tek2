/*
** EPITECH PROJECT, 2019
** Default
** File description:
** Default
*/

#include "../../include/Factory.hpp"
#include "../../include/types/AOperand.hpp"
#include "../../include/Error.hpp"
#include <limits>

template<typename T>
AOperand<T>::AOperand(eOperandType type, const std::string &value)
{
    this->_type = type;
    this->_value = value;
}

template<typename T>
std::string AOperand<T>::toString() const
{
    return (this->_value);
}

template<typename T>
IOperand *AOperand<T>::operator+(IOperand const &rhs) const
{
    IOperand *operand;
    auto *factory = new Factory();
    auto source_value = static_cast<double>(stod(this->_value));
    double target_value = static_cast<double>(stod(rhs.toString()));

    if ((target_value > 0) &&
        (source_value > std::numeric_limits<T>::max() + target_value))
        throw Exception("Overflow");
    if ((target_value < 0) &&
        (source_value < std::numeric_limits<T>::min() + target_value - 1))
        throw Exception("Underflow");
    std::ostringstream out;
    if (this->getPrecision() + rhs.getPrecision() == 0) {
        out << source_value + target_value;
        out.str() = out.str().substr(0, out.str().find(".", 0));
        operand = factory->createOperand(this->getType(), out.str());
    }
    else if (this->getPrecision() > rhs.getPrecision()) {
        out.precision(this->getPrecision());
        out << source_value + target_value;
        operand = factory->createOperand(this->getType(), out.str());
    }
    else {
        out.precision(rhs.getPrecision());
        out << source_value + target_value;
        operand = factory->createOperand(rhs.getType(), out.str());
    }
    delete factory;
    return operand;
}

template<typename T>
IOperand *AOperand<T>::operator-(const IOperand &rhs) const
{
    IOperand *operand;
    auto *factory = new Factory();
    auto source_value = static_cast<double>(stod(this->_value));
    double target_value = static_cast<double>(stod(rhs.toString()));

    if ((target_value > 0) &&
        (source_value > std::numeric_limits<T>::max() - target_value))
        throw Exception("Overflow");
    if ((target_value < 0) &&
        (source_value < std::numeric_limits<T>::min() - target_value - 1))
        throw Exception("Underflow");
    std::ostringstream out;
    if (this->getPrecision() + rhs.getPrecision() == 0) {
        out << source_value - target_value;
        out.str() = out.str().substr(0, out.str().find(".", 0));
        operand = factory->createOperand(this->getType(), out.str());
    } else if (this->getPrecision() > rhs.getPrecision()) {
        out.precision(this->getPrecision());
        out << source_value - target_value;
        operand = factory->createOperand(this->getType(), out.str());
    }
    else {
        out.precision(rhs.getPrecision());
        out << source_value - target_value;
        operand = factory->createOperand(rhs.getType(), out.str());
    }
    delete factory;
    return operand;
}

template<typename T>
IOperand *AOperand<T>::operator*(const IOperand &rhs) const
{
    IOperand *operand;
    auto *factory = new Factory();
    auto source_value = static_cast<double>(stod(this->_value));
    double target_value = static_cast<double>(stod(rhs.toString()));

    if ((target_value > 0) &&
        (source_value > std::numeric_limits<T>::max() * target_value))
        throw Exception("Overflow");
    if ((target_value < 0) &&
        (source_value < std::numeric_limits<T>::min() * target_value - 1))
        throw Exception("Underflow");
    std::ostringstream out;
    if (this->getPrecision() + rhs.getPrecision() == 0) {
        out << source_value * target_value;
        out.str() = out.str().substr(0, out.str().find(".", 0));
        operand = factory->createOperand(this->getType(), out.str());
    } else if (this->getPrecision() > rhs.getPrecision()) {
        out.precision(this->getPrecision());
        out << source_value * target_value;
        operand = factory->createOperand(this->getType(), out.str());
    }
    else {
        out.precision(rhs.getPrecision());
        out << source_value * target_value;
        operand = factory->createOperand(rhs.getType(), out.str());
    }
    delete factory;
    return operand;
}

template<typename T>
IOperand *AOperand<T>::operator/(const IOperand &rhs) const
{
    IOperand *operand;
    auto *factory = new Factory();
    auto source_value = static_cast<double>(stod(this->_value));
    double target_value = static_cast<double>(stod(rhs.toString()));

    if ((target_value > 0) &&
        (source_value > std::numeric_limits<T>::max() / target_value))
        throw Exception("Overflow");
    if ((target_value < 0) &&
        (source_value < std::numeric_limits<T>::min() / target_value - 1))
        throw Exception("Underflow");
    std::ostringstream out;
    if (this->getPrecision() + rhs.getPrecision() == 0) {
        out << source_value / target_value;
        out.str() = out.str().substr(0, out.str().find(".", 0));
        operand = factory->createOperand(this->getType(), out.str());
    } else if (this->getPrecision() > rhs.getPrecision()) {
        out.precision(this->getPrecision());
        out << source_value / target_value;
        operand = factory->createOperand(this->getType(), out.str());
    } else {
        out.precision(rhs.getPrecision());
        out << source_value / target_value;
        operand = factory->createOperand(rhs.getType(), out.str());
    }
    delete factory;
    return operand;
}

template<typename T>
IOperand *AOperand<T>::operator%(const IOperand &rhs) const
{
    if (this->_type == FLOAT || rhs.getType() == FLOAT)
        throw Exception("Modulo with float");
    if (this->_type == DOUBLE || rhs.getType() == DOUBLE)
        throw Exception("Modulo with double");
    IOperand *operand;
    Factory *factory = new Factory();
    uint64_t source_value = static_cast<int>(stod(this->_value));
    uint64_t target_value = static_cast<int>(stod(rhs.toString()));
    if ((target_value > 0) &&
        (source_value > std::numeric_limits<T>::max() - target_value))
        throw Exception("Overflow");
    if ((target_value < 0) &&
        (source_value < std::numeric_limits<T>::min() - target_value - 1))
        throw Exception("Underflow");
    std::ostringstream out;
    if (this->getPrecision() + rhs.getPrecision() == 0) {
        out << source_value % target_value;
        out.str() = out.str().substr(0, out.str().find(".", 0));
        operand = factory->createOperand(this->getType(), out.str());
    } else if (this->getPrecision() > rhs.getPrecision()) {
        out.precision(this->getPrecision());
        out << source_value % target_value;
        operand = factory->createOperand(this->getType(), out.str());
    } else {
        out.precision(rhs.getPrecision());
        out << source_value % target_value;
        operand = factory->createOperand(rhs.getType(), out.str());
    }
    delete factory;
    return operand;
}

template<typename T>
AOperand<T>::~AOperand() = default;