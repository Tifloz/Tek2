/*
** EPITECH PROJECT, 2022
** SYN_autoCompletion_2018
** File description:
** Created by Florian Louvet,
*/
#include "parser.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

void Parser::Helper()
{
    std::cout << "USAGE" << std::endl << "\t./autoCompletion dictionary"
        << std::endl << "DESCRIPTION" << std::endl
        << "\tdictionary    file containing one address per line, as knowledge base"
        << std::endl;
    exit(EXIT_SUCCESS);
}

Parser::Parser(int ac, char **av, Dictionary *dictionary)
{
    Diviner wizard(dictionary);
    if (ac < 2) {
        std::cerr << "Invalid argument" << std::endl;
        exit(84);
    }
    if (std::string(av[1]) == "-h")
        Helper();
    _dictionary = dictionary;
    Reader(av[1]);
    _dictionary->sortCities();
    wizard.Launcher();
}

Parser::~Parser() = default;

int Parser::Checker(const std::string &str, std::regex const &pattern)
{
    std::smatch match;
    if (regex_search(str, match, pattern))
        return 0;
    return 1;
}

void Parser::PrepareAddress(const std::string &str)
{
    std::string city(_utils.Split(str, ", ").front());
    std::string address = _utils.Split(str, ", ").back();
    _dictionary->addCity(city);
    _dictionary->addAddress(city, address);
}

void Parser::Reader(char *filename)
{
    std::regex const pattern{
        "((?:[A-Z].*[a-z]+))(,)(\\s+)(\\d+)(\\s+)((allée|avenue|rue|boulevard|chemin|impasse|place|quai|square))(\\s+)(\\w(.)+)"};
    std::regex const city{};
    int ret = 0;
    try {
        std::ifstream inFile;
        inFile.open(filename);
        if (!inFile) {
            throw std::runtime_error("Invalid argument");
        }
        if (inFile.is_open()) {
            if (inFile.peek() == std::ifstream::traits_type::eof())
                throw std::runtime_error("Invalid argument");
            std::string line;
            while (getline(inFile, line)) {
                if (Checker(line, pattern)) {
                    ret = 1;
                    std::cerr << line << std::endl;
                } else {
                    PrepareAddress(line);
                }
            }
            if (ret)
                std::cerr << ("Unknown address") << std::endl;
        }
        inFile.close();
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}
