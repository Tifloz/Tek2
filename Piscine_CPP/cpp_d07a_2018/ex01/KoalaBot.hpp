/*
** EPITECH PROJECT, 2022
** cpp_d07a_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D07A_2018_KOALABOT_HPP
#define CPP_D07A_2018_KOALABOT_HPP

#include <iostream>
#include "Parts.hpp"

class KoalaBot {
    public:
    KoalaBot(std::string serial = "Bob-01");

    ~KoalaBot();

    void setParts(const Arms arms);

    void setParts(const Legs legs);

    void setParts(const Head head);

    void swapParts( Arms &arms);

    void swapParts( Legs &legs);

    void swapParts( Head &head);

    void informations() const;

    bool status() const;

    private:
    std::string _serial;
    bool functionnal;
    Arms _arms;
    Legs _legs;
    Head _head;
};

#endif //CPP_D07A_2018_KOALABOT_HPP
