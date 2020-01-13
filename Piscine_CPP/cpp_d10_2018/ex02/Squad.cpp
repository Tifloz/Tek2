/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#include "Squad.hpp"

Squad::Squad() : _count(0), _size(10)
{
    int i = 0;

    this->_array = new ISpaceMarine *[this->_size];
    while (i < this->_size)
        this->_array[i++] = nullptr;
}

Squad::Squad(Squad const &squad)
{

    this->_count = squad._count;
    this->_size = squad._size;
    this->_array = new ISpaceMarine *[this->_size];
    for (int i = 0; i < this->_size; i++) {
        this->_array[i] = nullptr;
        if (squad._array[i])
            this->_array[i] = squad._array[i]->clone();
    }
}

Squad::~Squad()
{
    for (int i = 0; i < this->_count; i++) {
        delete this->_array[i];
    }
    delete[] this->_array;
}

int Squad::getCount() const
{
    return (this->_count);
}

ISpaceMarine *Squad::getUnit(int pos)
{
    if (pos > this->_size || pos < 0)
        return nullptr;
    return this->_array[pos];
}

int Squad::push(ISpaceMarine *marine)
{
    if (marine) {
        if (this->_count >= this->_size)
            this->resize();
        for (int i = 0; i < (this->_count); i++)
            if (this->_array[i++] == marine)
                return this->_count;
        this->_array[this->_count++] = marine;
    }
    return this->_count;
}

Squad &Squad::operator=(const Squad &squad)
{
    for (int i = 0; i < this->_count;)
        delete this->_array[i];
    delete[] this->_array;
    this->_count = squad._count;
    this->_size = squad._size;
    this->_array = new ISpaceMarine *[this->_size];
    for (int j = 0; j < this->_size; j++) {
        this->_array[j] = nullptr;
        if (squad._array[j])
            this->_array[j] = squad._array[j]->clone();
    }
    return *this;
}

void Squad::resize()
{
    size_t new_size = this->_size * 1.5;
    auto **new_array = new ISpaceMarine *[new_size];
    int i = 0;

    while (i < (int)this->_size) {
        new_array[i] = this->_array[i];
        i++;
    }
    while (i < (int)new_size)
        new_array[i++] = nullptr;
    delete[] this->_array;
    this->_array = new_array;
    this->_size = static_cast<int>(new_size);
}
