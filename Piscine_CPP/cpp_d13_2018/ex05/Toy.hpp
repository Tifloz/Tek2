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

    class Error {
        public:
        enum ErrorType {
            UNKNOWN,
            PICTURE,
            SPEAK
        };

        Error();

        ErrorType type;

        std::string what() const;

        std::string where() const;

        void setType(ErrorType type);
    };

    Toy();

    Toy(ToyType type, std::string const &name, std::string const &picture);

    Toy(const Toy &copy);

    virtual ~Toy();

    int getType() const;

    std::string const &getName() const;

    std::string const &getAscii() const;

    void setName(std::string const &name);

    bool setAscii(std::string const &picture);

    Toy &operator=(const Toy &toy);

    virtual void speak(const std::string &message);

    virtual bool speak_es(std::string const &message);

    Toy &operator<<(std::string const &message);

    Toy::Error const &getLastError() const;

    protected:
    ToyType _type;
    std::string _name;
    Picture _picture;
    Error error;
};

std::ostream &operator<<(std::ostream &os, Toy const &obj);

#endif //CPP_D13_2018_TOY_HPP
