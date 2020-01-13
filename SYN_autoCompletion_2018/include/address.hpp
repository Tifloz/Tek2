/*
** EPITECH PROJECT, 2022
** SYN_autoCompletion_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_AUTOCOMPLETION_2018_ADDRESS_HPP
#define SYN_AUTOCOMPLETION_2018_ADDRESS_HPP

#include <string>
#include <vector>

class Address {
    public:
    std::string getRaw();

    Address(const std::string &raw);

    int getNb();

    std::string getStreet();

    std::string getType();

    private:
    std::string _raw;
    int _nb;
    std::string _type;
    std::string _street;

    void setType(const std::string &str);
};

#endif //SYN_AUTOCOMPLETION_2018_ADDRESS_HPP
