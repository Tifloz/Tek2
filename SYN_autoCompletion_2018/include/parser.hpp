/*
** EPITECH PROJECT, 2022
** SYN_autoCompletion_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_AUTOCOMPLETION_2018_PARSER_HPP
#define SYN_AUTOCOMPLETION_2018_PARSER_HPP

#include "address.hpp"
#include "dictionary.hpp"
#include "diviner.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <map>
#include <regex>

class Parser {

    public:
    Parser(int ac, char **av, Dictionary *dictionary);

    virtual ~Parser();

    private:
    Dictionary *_dictionary;
    Utils _utils;

    void Reader(char *filename);

    static int Checker(const std::string &str, std::regex const &pattern);

    static void Helper();

    void PrepareAddress(const std::string &);
};

#endif //SYN_AUTOCOMPLETION_2018_PARSER_HPP
