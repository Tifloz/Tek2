/*
** EPITECH PROJECT, 2022
** cpp_d15_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D15_2018_ET05_HPP
#define CPP_D15_2018_ET05_HPP

#include <iostream>

template<typename T>
class array {
    public:
    array()
    {
        _array = NULL;
        _n = 0;
    }

    explicit array(unsigned int n)
    {
        _n = n;
        _array = new T[_n]();
    }

    array(const array<T> &new_elem)
    {
        _n = new_elem._n;
        _array = NULL;
        _array = new T[_n];
        for (unsigned int i = 0; i < _n; i++) {
            _array[i] = new_elem._array[i];
        }
    }

    virtual ~array()
    {
        if (_array)
            delete[] _array;
    }

    array<T> &operator=(const array<T> &obj)
    {
        _n = obj._n;
        if (_array)
            delete[] _array;
        _array = new T[_n];
        for (unsigned int i = 0; i < _n; i++) {
            _array[i] = obj._array[i];
        }
        return *this;
    }

    T &operator[](unsigned int index)
    {
        if (index >= _n) {
            T *new_elem = new T[index + 1]();
            for (unsigned int i = 0; i < _n; i++) {
                new_elem[i] = _array[i];
            }
            delete[] _array;
            _array = new_elem;
            _n = index + 1;
        }
        return _array[index];
    }

    T &operator[](unsigned int index) const
    {
        if (index >= _n) {
            throw std::exception();
        }
        return _array[index];
    }

    unsigned int size() const
    {
        return _n;
    }

    void dump() const
    {
        std::cout << "[";
        for (unsigned int i = 0; i < _n; i++) {
            std::cout << _array[i];
            if (i < _n - 1)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }

    template<typename U>
    array<U> convertTo(U(*convert)(const T &)) const
    {
        array<U> duplicate(_n);
        for (unsigned int i = 0; i < _n; i++) {
            duplicate[i] = (*convert)(_array[i]);
        }
        return duplicate;
    }

    protected:
    unsigned int _n;
    T *_array;
};

template<>
void array<bool>::dump() const
{
    std::cout << "[";
    for (unsigned int i = 0; i < _n; i++) {
        std::cout << ((_array[i]) ? "true" : "false");
        if (i < _n - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

#endif //CPP_D15_2018_ET05_HPP
