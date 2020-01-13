/*
** EPITECH PROJECT, 2022
** cpp_d13_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D13_2018_TOY_HPP
#define CPP_D13_2018_TOY_HPP

#include "Picture.hpp"
#include <iostream>

class Toy {
    public:
    enum ToyType {
        BASIC_TOY,
        ALIEN,
        BUZZ,
        WOODY
    };

    Toy();

    Toy(ToyType type, std::string const &name, std::string const &picture);

    Toy(const Toy &copy);

    virtual ~Toy();

    int getType() const;

    std::string const &getName() const;

    std::string const &getAscii() const;

    void setName(std::string const &name);

    void setAscii(std::string const &picture);

    Toy &operator=(const Toy &toy);

    virtual void speak(const std::string &message);

    protected:
    ToyType _type;
    std::string _name;
    Picture _picture;
};

#endif //CPP_D13_2018_TOY_HPP
