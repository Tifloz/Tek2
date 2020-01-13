/*
** EPITECH PROJECT, 2022
** cpp_d06_2018
** File description:
** Created by Florian Louvet,
*/
#include <iostream>
#include <stdlib.h>
#include <fstream>

void args_handler(char *str)
{
    std::ifstream fs;
    char buff;

    fs.open(str);
    if (!fs) {
        std::cerr << "my_cat: " << str << ": No such file or directory"
            << std::endl;
    } else
        while (!fs.eof()) {
            buff = (char)fs.get();
            if (buff != -1)
                std::cout << buff;
        }
    fs.close();
}

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return (EXIT_FAILURE);
    }
    for (int i = 1; av[i]; i++) {
        args_handler(av[i]);
    }
    return (EXIT_SUCCESS);
}