/*
** EPITECH PROJECT, 2022
** cpp_d16_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D16_2018_DOMESTICKOALA_HPP
#define CPP_D16_2018_DOMESTICKOALA_HPP

#include <iostream>
#include <vector>
#include <string>
#include "KoalaAction.hpp"

class DomesticKoala {
    public:
    DomesticKoala(KoalaAction &act);

    DomesticKoala(const DomesticKoala &koala);

    virtual ~DomesticKoala();

    DomesticKoala &operator=(const DomesticKoala &koala);

    typedef void (KoalaAction::*methodPointer_t)(std::string const &);

    std::vector<methodPointer_t> const *getActions(void) const;

    void learnAction(unsigned char, methodPointer_t);

    void unlearnAction(unsigned char);

    void doAction(unsigned char, const std::string &);

    void setKoalaAction(KoalaAction &);

    private:
    KoalaAction _action;
    std::vector<methodPointer_t> _actPtr;
};

#endif //CPP_D16_2018_DOMESTICKOALA_HPP
