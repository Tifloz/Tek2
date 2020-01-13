/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/
#include <iostream>
#include "../include/Error.hpp"
#include "../include/Interpretor.hpp"

Interpretor::Interpretor() = default;

Interpretor::~Interpretor() = default;

void Interpretor::push(IOperand *pile)
{
    this->_pile.push(pile);
}

void Interpretor::pop(IOperand *pile)
{
    if (this->_pile.empty())
        throw (Exception("Pop instruction on an empty stack"));
    this->_pile.pop();
    (void)pile;
}

void Interpretor::dump(IOperand *pile)
{
    std::stack<IOperand *> print;

    print = this->_pile;
    if (_pile.empty())
        return;
    while (!print.empty()) {
        std::cout << print.top()->toString() << std::endl;
        print.pop();
    }
    (void)pile;
}

void Interpretor::clear(IOperand *pile)
{
    while (!this->_pile.empty()) {
        this->_pile.pop();
    }
    (void)pile;
}

void Interpretor::swap(IOperand *pile)
{
    IOperand *tmp;
    IOperand *tmp2;

    if (this->_pile.size() < 2)
        throw (Exception(
            "the stack strictly has less than two values during the execution of an arithmetical instruction."));
    else {
        tmp = this->_pile.top();
        this->_pile.pop();
        tmp2 = this->_pile.top();
        this->_pile.pop();
        this->_pile.push(tmp);
        this->_pile.push(tmp2);
    }
    (void)pile;
}

void Interpretor::dup(IOperand *pile)
{
    IOperand *tmp;

    if (this->_pile.size() < 1)
        throw (Exception(
            "the stack strictly has less than two values during the execution of an arithmetical instruction."));
    else {
        tmp = this->_pile.top();
        this->_pile.push(tmp);
    }
    (void)pile;
}

void Interpretor::assert(IOperand *pile)
{
    std::stack<IOperand *> print;
    print = this->_pile;
    if (!this->_pile.empty()) {
        if (print.top()->toString() != pile->toString() ||
            print.top()->getType() != pile->getType())
            throw (Exception("an assert instruction is not verified"));
    } else
        throw (Exception("Dump instruction on empty stack"));
}

void Interpretor::add(IOperand *pile)
{
    (void)pile;
    IOperand *add1;
    IOperand *add2;

    if (_pile.size() < 2)
        throw (Exception("Add on stack with less than two values"));
    if (!this->_pile.empty()) {
        add1 = this->_pile.top();
        this->_pile.pop();
        add2 = this->_pile.top();
        this->_pile.pop();
        IOperand *r = *add1 + *add2;
        this->_pile.push(r);
    }
}

void Interpretor::sub(IOperand *pile)
{
    (void)pile;
    IOperand *add1;
    IOperand *add2;

    if (_pile.size() < 2)
        throw (Exception("Add on stack with less than two values"));
    if (!this->_pile.empty()) {
        add1 = this->_pile.top();
        this->_pile.pop();
        add2 = this->_pile.top();
        this->_pile.pop();
        IOperand *r = (*add2) - (*add1);
        this->_pile.push(r);
    }
}

void Interpretor::mul(IOperand *pile)
{
    (void)pile;
    IOperand *add1;
    IOperand *add2;

    if (_pile.size() < 2)
        throw (Exception("Add on stack with less than two values"));
    if (!this->_pile.empty()) {
        add1 = this->_pile.top();
        this->_pile.pop();
        add2 = this->_pile.top();
        this->_pile.pop();
        IOperand *r = (*add1) * (*add2);
        this->_pile.push(r);
    }
}

void Interpretor::div(IOperand *pile)
{
    (void)pile;
    IOperand *add1;
    IOperand *add2;

    if (_pile.size() < 2)
        throw (Exception("Div on stack with less than two values"));
    if (!this->_pile.empty()) {
        add1 = this->_pile.top();
        this->_pile.pop();
        add2 = this->_pile.top();
        this->_pile.pop();
        if (add1->toString() != "0") {
            IOperand *r = *add2 / *add1;
            this->_pile.push(r);
        } else
            throw (Exception("Division by 0."));
    }
}

void Interpretor::mod(IOperand *pile)
{
    (void)pile;
    IOperand *add1;
    IOperand *add2;

    if (_pile.size() < 2)
        throw (Exception("Div on stack with less than two values"));
    if (!this->_pile.empty()) {
        add1 = this->_pile.top();
        this->_pile.pop();
        add2 = this->_pile.top();
        this->_pile.pop();
        if (add1->toString() == "0")
            throw (Exception("Modulo by 0."));
        else {
            IOperand *r = *add2 % *add1;
            this->_pile.push(r);
        }
    }
}

void Interpretor::load(IOperand *pile)
{
    int reg = atoi(pile->toString().c_str());

    if (reg >= 0 && reg <= 15) {
        if (this->_registers[reg] != NULL)
            this->_pile.push(this->_registers[reg]);
        else
            throw Exception("Empty cell");
    } else
        throw Exception("Must be between 0 and 15");
}

void Interpretor::store(IOperand *pile)
{
    if (this->_pile.empty())
        throw (Exception("Store instruction on an empty stack"));
    int reg = atoi(pile->toString().c_str());
    if (reg >= 0 && reg <= 15) {
        this->_registers[reg] = this->_pile.top();
        this->_pile.pop();
    } else
        throw Exception("Must be between 0 and 15");
}

void Interpretor::print(IOperand *pile)
{
    std::string str;

    (void)pile;
    if (_pile.empty())
        throw Exception("Stack is empty");
    IOperand *c = _pile.top();
    if (c->getType() != eOperandType::INT8)
        throw Exception("The value is not an Int8");
    std::cout << static_cast<char> (stoi(c->toString()));
    std::cout << std::endl;
}

void Interpretor::exit(IOperand *pile)
{
    (void)pile;
    std::exit(0);
}
