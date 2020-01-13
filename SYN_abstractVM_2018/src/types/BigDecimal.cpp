/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/
#include "../../include/types/BigDecimal.hpp"
#include "../../include/Error.hpp"
#include "../../include/Factory.hpp"

BigDecimal::BigDecimal(const std::string &value)
{
    try {
        std::stold(value);
    } catch (const std::out_of_range &orr) {
        throw (Exception("Invalid value"));
    }
    _str = value;
    _value = std::stold(value);
}

IOperand *BigDecimal::operator+(const IOperand &rhs) const
{
    std::string::size_type a, b;
    std::string s1, s2;

    s1 = rhs.toString();
    s2 = this->toString();
    if (s1[0] == '-')
        s1.erase(s1.begin());
    if (s2[0] == '-')
        s2.erase(s2.begin());
    a = s1.find('.');
    b = s2.find('.');
    if (a == std::string::npos) {
        a = s1.size();
        s1.push_back('.');
    }
    if (b == std::string::npos) {
        b = s2.size();
        s2.push_back('.');
    }
    while (a != b) {
        if (a < b) {
            s1.insert(s1.begin(), '0');
            a++;
        } else {
            s2.insert(s2.begin(), '0');
            b++;
        }
    }
    while (s1.size() != s2.size()) {
        if (s1.size() < s2.size())
            s1.push_back('0');
        else
            s2.push_back('0');
    }
    if ((rhs.toString()[0] == '-' && this->toString()[0] == '-') ||
        (rhs.toString()[0] != '-' && this->toString()[0] != '-')) {
        s1 = this->add(s1, s2);
        if (rhs.toString()[0] == '-')
            s1.insert(s1.begin(), '-');
    } else {
        if (rhs.toString()[0] == '-')
            s1 = sub(s2, s1);
        else
            s1 = sub(s1, s2);
    }
    return Factory::createOperand(this->getType(), s1);
}

std::string BigDecimal::add(std::string s1, std::string s2) const
{
    std::string::iterator v1, v2;
    int ret = 0;

    v1 = s1.end();
    v2 = s2.end();
    while (v1 != s1.begin() && v2 != s2.begin()) {
        if (*v1 == '.') {
            v1--;
            v2--;
            continue;
        }
        *v1 += *v2 + ret - 48;
        ret = 0;
        if (*v1 > '9') {
            ret = 1;
            *v1 -= 10;
        }
        v1--;
        v2--;
    }
    *v1 += *v2 + ret - 48;
    if (*v1 > '9') {
        *v1 -= 10;
        s1.insert(s1.begin(), '1');
    }
    while ((*(s1.end() - 1) == '0' && s1.find('.') != std::string::npos) ||
        *(s1.end() - 1) == '.')
        s1.pop_back();
    while (*s1.begin() == '0' && s1.size() > 1 && s1[1] != '.')
        s1.erase(s1.begin());
    return (s1);
}

IOperand *BigDecimal::operator-(const IOperand &rhs) const
{
    std::string::size_type a, b;
    std::string::iterator v1, v2;
    std::string s1, s2;

    if (s1[0] == '-')
        s1.erase(s1.begin());
    if (s2[0] == '-')
        s2.erase(s2.begin());
    s1 = rhs.toString();
    s2 = this->toString();
    a = s1.find('.');
    b = s2.find('.');
    if (a == std::string::npos) {
        a = s1.size();
        s1.push_back('.');
    }
    if (b == std::string::npos) {
        b = s2.size();
        s2.push_back('.');
    }
    while (a != b) {
        if (a < b) {
            s1.insert(s1.begin(), '0');
            a++;
        } else {
            s2.insert(s2.begin(), '0');
            b++;
        }
    }
    while (s1.size() != s2.size()) {
        if (s1.size() < s2.size())
            s1.push_back('0');
        else
            s2.push_back('0');
    }
    if (rhs.toString()[0] == '-' && this->toString()[0] != '-') {
        s1 = add(s1, s2);
        return Factory::createOperand(this->getType(), s1);
    } else if (rhs.toString()[0] != '-' && this->toString()[0] == '-') {
        s1 = add(s1, s2);
        s1.insert(s1.begin(), '-');
        return Factory::createOperand(this->getType(), s1);
    }
    int i = 0;
    while (s1[i] >= s2[i]) {
        if (s1[i] > s2[i]) {
            s1 = sub(s1, s2);
            s1.insert(s1.begin(), '-');
            return Factory::createOperand(this->getType(), s1);
        }
        i++;
    }
    s1 = sub(s2, s1);
    return Factory::createOperand(this->getType(), s1);
}

std::string BigDecimal::sub(std::string s1, std::string s2) const
{
    std::string::iterator v1, v2;
    int ret = 0;

    v1 = s1.end();
    v2 = s2.end();
    while (v1 != s1.begin() && v2 != s2.begin()) {
        if (*v1 == '.') {
            v1--;
            v2--;
            continue;
        }
        *v1 -= *v2 + ret - 48;
        ret = 0;
        if (*v1 < '0') {
            ret = 1;
            *v1 += 10;
        }
        v1--;
        v2--;
    }
    *v1 -= *v2 + ret - 48;
    if (*v1 < '0') {
        *v1 += 10;
        s1.insert(s1.begin(), '-');
    }
    while ((*(s1.end() - 1) == '0' && s1.find('.') != std::string::npos) ||
        *(s1.end() - 1) == '.')
        s1.pop_back();
    while (*s1.begin() == '0' && s1[1] != '.' && s1.size() > 1)
        s1.erase(s1.begin());
    if (s1 == "-0")
        s1.erase(s1.begin());
    return (s1);
}

IOperand *BigDecimal::operator*(const IOperand &rhs) const
{
    std::string s1, s2;
    std::string::size_type a, b;

    s1 = rhs.toString();
    s2 = rhs.toString();
    if (s1[0] == '-')
        s1.erase(s1.begin());
    if (s2[0] == '-')
        s2.erase(s2.begin());
    a = s1.find('.');
    b = s2.find('.');
    if (a == std::string::npos) {
        a = s1.size();
        s1.push_back('.');
    }
    if (b == std::string::npos) {
        b = s2.size();
        s2.push_back('.');
    }
    while (a != b) {
        if (a < b) {
            s1.insert(s1.begin(), '0');
            a++;
        } else {
            s2.insert(s2.begin(), '0');
            b++;
        }
    }
    while (s1.size() != s2.size()) {
        if (s1.size() < s2.size())
            s1.push_back('0');
        else
            s2.push_back('0');
    }
    s1 = mul(s1, s2);
    if ((rhs.toString()[0] == '-' && this->toString()[0] != '-') ||
        (rhs.toString()[0] != '-' && this->toString()[0] == '-'))
        s1.insert(s1.begin(), '-');
    return Factory::createOperand(this->getType(), s1);
}

std::string BigDecimal::mul(std::string s1, std::string s2) const
{
    throw (Exception("Not implemented"));
}

IOperand *BigDecimal::operator/(const IOperand &rhs) const
{
    throw (Exception("Not implemented"));
}

IOperand *BigDecimal::operator%(const IOperand &rhs) const
{
    throw (Exception("Not implemented"));
}

BigDecimal::~BigDecimal()
{
}
