/*
** EPITECH PROJECT, 2022
** cpp_d16_2018
** File description:
** Created by Florian Louvet,
*/
#include <sstream>
#include "Parser.hpp"

Parser::Parser()
{
    this->_result = 0;
    this->_final = 0;
}

Parser::~Parser() = default;

int isDigit(char c)
{
    if (c >= 48 && c <= 57)
        return 1;
    return 0;
}

std::string getCalc(std::string content, const int start, const int end)
{
    int tmp = start + 1;

    return content.substr(tmp, (end - tmp));
}

int nbCalc(const std::string &nb)
{
    int i = 0;
    int _digits = 0;

    while (nb[i]) {
        if (isDigit(nb[i]) == 1 && isDigit(nb[i + 1]) == 0)
            _digits++;
        i++;
    }
    return _digits;
}

void Parser::feed(const std::string &content)
{
    int i = 0;
    int start = 0;
    int end = 0;
    std::string calc = content;

    calc.erase(std::remove_if(calc.begin(), calc.end(), ::isspace), calc.end());
    int is_calc = nbCalc(calc);
    if (calc[0] != '(')
        calc = "(" + calc + ")";
    while (calc[i]) {
        if (calc[i] == '(') {
            start = i;
        }
        if (calc[i] == ')') {
            end = i;
            break;
        }
        i++;
    }
    if (is_calc > 1) {
        this->parse(getCalc(calc, start, end));
        calc.erase(static_cast<unsigned long>(start), (end - start + 1));
        std::stringstream os;
        os << this->_final;
        calc.insert(start, os.str());
        this->feed(calc);
        return;
    }
    this->_result += this->_final;
}

void Parser::reset()
{
    std::stack<std::string> clear;

    this->operators = clear;
    this->operands = clear;
    this->_result = 0;
    this->_final = 0;
}

int Parser::result() const
{
    return this->_result;
}

void Parser::parse(std::string calc)
{
    int i = 0;

    while (calc[i]) {
        if (calc[i] == '*' || calc[i] == '+' || calc[i] == '-' ||
            calc[i] == '%' || calc[i] == '/') {
            std::string op(1, calc[i]);
            this->operators.push(op);
            this->operands.push(calc.substr(0, static_cast<unsigned long>(i)));
            i++;
            this->operands.push(calc.substr(static_cast<unsigned long>(i),
                strlen(calc.c_str())));
            break;
        }
        i++;
    }
    this->calc();
}

void Parser::calc()
{
    int nb1 = atoi(this->operands.top().c_str());
    this->operands.pop();
    int nb2 = atoi(this->operands.top().c_str());
    if (this->operators.top() == "+")
        this->_final = nb2 + nb1;
    if (this->operators.top() == "-")
        this->_final = nb2 - nb1;
    if (this->operators.top() == "/")
        this->_final = nb2 / nb1;
    if (this->operators.top() == "%")
        this->_final = nb2 % nb1;
    if (this->operators.top() == "*")
        this->_final = nb2 * nb1;
    this->operators.pop();
}
