/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2018
** File description:
** Created by Florian Louvet,
*/

#include "../include/Parser.hpp"
#include "../include/Error.hpp"

void Parser::readLine()
{
    this->_file = false;
    this->_run = true;
    std::string in;

    while (this->_run) {
        std::getline(std::cin, in);
        if (in.empty())
            continue;
        in = this->checkLine(in);
        if (!in.empty())
            this->_list.push_back(in);
    }
}

void Parser::readFile(std::string file)
{
    std::ifstream myfile(file);
    std::string line;
    this->_file = true;

    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            line = this->checkLine(line);
            if (line.empty())
                continue;
            this->_list.push_back(line);
        }
    } else
        throw Exception("Unable to open file");
}

std::string Parser::checkLine(std::string s)
{
    auto it = s.begin();
    size_t len = 0;

    if (!this->_file && *it == ';' && *(std::next(it, 1)) == ';')
        this->_run = false;
    while (it != s.end() && *it != ';') {
        it++;
        len++;
    }
    s = s.substr(0, len);
    return (s);
}

void Parser::parse_command()
{
    const std::regex formatD(
        "^\\s*(\\w*)\\s*(int8|int16|int32|float|double|bigdecimal)\\s*\\(([-]?\\d*\\.?\\d*)\\)\\s*$");
    const std::regex formatS("^\\s*(\\w*)\\s*$");
    std::smatch match;

    for (auto &it : this->_list) {
        std::regex_match(it, match, formatS);
        if (match.empty())
            std::regex_match(it, match, formatD);
        if (match.empty())
            throw Exception("Syntactical error");
        else
            this->_command.push_back(match);
    }
}

std::vector<std::smatch> Parser::getCommand()
{
    return (this->_command);
}