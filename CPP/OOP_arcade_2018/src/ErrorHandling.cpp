/*
** EPITECH PROJECT, 2018
** ErrorHandling.cpp
** File description:
** Error handling of OPP_arcade_2018
*/

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>

void printUsage()
{
	std::cout << "USAGE:" << std::endl;
	std::cout << "\t./arcade <graphics library path>" << std::endl;
	exit(84);
}

int checkFile(char *file)
{
	std::ifstream path(file);

	if (path.is_open())
		path.close();
	else
		return (84);
	return 0;
}

int checkArguments(int ac, char **av)
{
	if (ac != 2)
		printUsage();
	if (std::strlen(av[1]) < 1)
		return 84;
	return checkFile(av[1]);
}
