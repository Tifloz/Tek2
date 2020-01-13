/*
** EPITECH PROJECT, 2022
** cpp_d14m_2018
** File description:
** Created by Florian Louvet,
*/
#include "FruitBox.hpp"

FruitBox::FruitBox(int size) : _size(size), _count(0), header(nullptr)
{
}

FruitBox::~FruitBox() = default;

int FruitBox::nbFruits() const
{
    return this->_count;
}

bool FruitBox::putFruit(Fruit *f)
{
    FruitNode *temp;
    FruitNode *prev = nullptr;
    if (!f)
        return false;
    if (this->_count < this->_size) {
        auto *node = new FruitNode();
        temp = this->header;
        while (temp) {
            if (temp->_fruit == f)
                return false;
            prev = temp;
            temp = temp->next;
        }
        temp = node;
        if (prev)
            prev->next = temp;
        temp->_fruit = f;
        temp->next = nullptr;
        if (!this->header)
            this->header = temp;
        this->_count++;
        return true;
    }
    return false;
}

Fruit *FruitBox::pickFruit()
{
    if (this->_count) {
        FruitNode *node = this->header;
        Fruit *fruit = node->_fruit;
        this->header = this->header->next;
        delete node;
        this->_count--;
        return fruit;
    }
    return nullptr;
}

FruitNode *FruitBox::head() const
{
    return (this->header);
}
