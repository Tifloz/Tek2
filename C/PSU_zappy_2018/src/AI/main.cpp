/*
** EPITECH PROJECT, 2019
** spu_zappy_2018
** File description:
** main.cpp
*/

#include <regex>
#include <iostream>
#include "Error.hpp"
#include "Client.hpp"

void printUsage(void)
{
    std::cout << "USAGE: ./zappy_ai -p port -n name -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tname\tis the name of the team" << std::endl;
    std::cout << "\tport\tis the name of the machine; localhost by default" << std::endl;
}

std::string getMachine(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (std::string(av[i]) == "-h")
            return std::string(av[i+1]);
    }
    std::cerr << "Machine name is missing\n" << std::endl;
    exit (84);
}

char *getPort(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (std::string(av[i]) == "-p")
            return (av[i+1]);
    }
    std::cerr << "Port number is missing\n" << std::endl;
    exit (84);
}

std::string getName(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (std::string(av[i]) == "-n")
            return std::string(av[i+1]);
    }
    std::cerr << "Team name is missing\n" << std::endl;
    exit (84);
}


int main (int ac, char **av)
{
    if (ac != 7 && ac != 5) {
        printUsage();
        if (ac == 2 && std::string(av[1]) == "-help")
            return 0;
        return 84;
    }

    std::string name = getName(ac, av);
    std::string machine = getMachine(ac, av);
    char *port = getPort(ac, av);

    if (!std::regex_match(port, std::regex("^[0-9][0-9]{2,}[0-9]$"))) {
        std::cerr << "Invalid port number" << std::endl;
        return 84;
    }
    if (!std::regex_match(machine, std::regex("^[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}$"))) {
        std::cerr << "Invalid machine" << std::endl;
        return 84;
    }
    try {
        Client client(atoi(port), name, machine);
        client.connection();
        client.initInformation();
        client.run(&client);
    }
    catch (AIError &e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}
