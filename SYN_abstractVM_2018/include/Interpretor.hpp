/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_ABSTRACTVM_2018_INTERPRETOR_HPP
#define SYN_ABSTRACTVM_2018_INTERPRETOR_HPP

#include "IOperand.hpp"
#include <stack>
#include <map>

class Interpretor {
    public:
    std::stack<IOperand *> _pile;
    std::map<int, IOperand *> _registers;

    Interpretor();

    virtual ~Interpretor();

    void push(IOperand *);

    void pop(IOperand *);

    void dump(IOperand *);

    void clear(IOperand *);

    void swap(IOperand *);

    void dup(IOperand *);

    void assert(IOperand *);

    void add(IOperand *);

    void sub(IOperand *);

    void mul(IOperand *);

    void div(IOperand *);

    void mod(IOperand *);

    void load(IOperand *);

    void store(IOperand *);

    void print(IOperand *);

    void exit(IOperand *);
};

#endif //SYN_ABSTRACTVM_2018_INTERPRETOR_HPP
