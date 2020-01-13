/*
** EPITECH PROJECT, 2022
** cpp_d07a_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D07A_2018_PARTS_HPP
#define CPP_D07A_2018_PARTS_HPP

#include <iostream>

class Arms {
    public:
    Arms(std::string serial = "A-01", bool functionnal = true);

    ~Arms();

    bool isFunctionnal() const;

    std::string serial();

    void informations() const;

    private:
    std::string _serial;
    bool _functionnal;
};

class Legs {
    public:
    Legs(std::string serial = "L-01", bool functionnal = true);

    ~Legs();

    bool isFunctionnal() const;

    std::string serial();

    void informations() const;

    private:
    std::string _serial;
    bool _functionnal;
};

class Head {
    public:
    Head(std::string serial = "H-01", bool functionnal = true);

    ~Head();

    bool isFunctionnal() const;

    std::string serial();

    void informations() const;

    private:
    std::string _serial;
    bool _functionnal;
};

#endif //CPP_D07A_2018_PARTS_HPP
