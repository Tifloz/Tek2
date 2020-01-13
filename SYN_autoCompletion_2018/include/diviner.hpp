/*
** EPITECH PROJECT, 2022
** SYN_autoCompletion_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_AUTOCOMPLETION_2018_DIVINER_HPP
#define SYN_AUTOCOMPLETION_2018_DIVINER_HPP

#include "dictionary.hpp"

class Diviner {
    public:
    void Launcher();

    virtual ~Diviner();

    Diviner(Dictionary *dictionary);

    private:
    Dictionary *_dictionary;
    Utils *_utils;
    std::string _query;
    std::string _state;
    void *_current;
    std::vector<std::pair<char, int>> _prob;
    std::vector<std::pair<int, Address *>> _choices;

    void printChoices();

    void setChances();

    void insertInVector(char letter);

    void splitAndInsert(const std::string &str, int occur);

    void Checker();

    bool onlyOneValue();

    void printPossibilities(const std::vector<std::string> &);

    void askChoice(std::string &hint);

    int answerChoice();
};

#endif //SYN_AUTOCOMPLETION_2018_DIVINER_HPP
