/*
** EPITECH PROJECT, 2022
** cpp_d16_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D16_2018_PARSER_HPP
#define CPP_D16_2018_PARSER_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>

class Parser {
    public:
    Parser();

    virtual ~Parser();

    void feed(const std::string &content);

    void reset();

    int result() const;

    void parse(std::string calc);

    void calc();

    protected:
    int _result;
    int _final;
    std::stack<std::string> operators;
    std::stack<std::string> operands;
};

#endif //CPP_D16_2018_PARSER_HPP
