/*
** EPITECH PROJECT, 2018
** Main.cpp
** File description:
** Main of OPP_arcade_2018
*/

#include <iostream>

int checkArguments(int ac, char **av);

int main(int ac, char **av)
{
	if (checkArguments(ac, av))
		return 84;
	std::cout << "Yeah, I past the error handling !" << std::endl;
	return (0);
}
