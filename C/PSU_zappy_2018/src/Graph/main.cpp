/*
** EPITECH PROJECT, 2018
** Core
** File description:
** main.cpp
*/

#include <iostream>
#include "Core.hpp"
#include "Error.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Launching Zappy - Graphic" << std::endl;
    Core core;
    try {
        core.init(argc, argv);
        core.run();
        std::cout << "Process finished." << std::endl;
    }
    catch (ZappyError &e) {
        std::cout << e.what() << std::endl;
        return 84;
    }
    return 0;
}