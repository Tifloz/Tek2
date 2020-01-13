/*
** EPITECH PROJECT, 2022
** SYN_autoCompletion_2018
** File description:
** Created by Florian Louvet,
*/
#include "dictionary.hpp"
#include "parser.hpp"

int main(int ac, char **av)
{
    try {
        Dictionary dictionary;
        Parser parsing(ac, av, &dictionary);
    } catch (std::exception const &exception) {
        std::cerr << exception.what() << std::endl;
        return (84);
    }
}