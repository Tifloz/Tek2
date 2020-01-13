/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_ABSTRACTVM_2018_PARSER_HPP
#define SYN_ABSTRACTVM_2018_PARSER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

class Parser {
public:
    Parser() = default;
    ~Parser() = default;

    void readLine();
    void readFile(std::string file);

    std::string checkLine(std::string s);

    void parse_command();

    std::vector<std::smatch> getCommand();

private:
    bool _file;
    bool _run;
    std::vector<std::string> _list;
    std::vector<std::smatch> _command;
};

#endif //SYN_ABSTRACTVM_2018_PARSER_HPP
