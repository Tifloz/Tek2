/*
** EPITECH PROJECT, 2022
** cpp_d07a_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D07A_2018_SKAT_HPP
#define CPP_D07A_2018_SKAT_HPP

#include <string>

class Skat {
    public:
    Skat(const std::string &name = "bob", int stimPaks = 15);

    ~Skat();

    int &stimPaks();

    const std::string &name();

    void shareStimPaks(int number, int &stock);

    void addStimPaks(unsigned int number);

    void useStimPaks();

    void status();

    private:
    const std::string &_name;
    int _stimPaks;
};

#endif //CPP_D07A_2018_SKAT_HPP
