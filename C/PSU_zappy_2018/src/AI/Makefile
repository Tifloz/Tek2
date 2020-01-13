##
## EPITECH PROJECT, 2019
## psu_zappy_2018
## File description:
## zappy_ai makefile
##

DIR = ./

SRC			=	$(DIR)main.cpp\
				$(DIR)Client.cpp\
				$(DIR)Player.cpp\
				$(DIR)Inventory.cpp\
				$(DIR)Commands.cpp\
				$(DIR)Ai.cpp

OBJ			= $(SRC:.cpp=.o)

CXXFLAGS	= -std=c++11 -Wall -Wextra
CXXDEBUG	= -std=c++11 -Wall -Wextra -g

NAME		= zappy_ai

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(CXXFLAGS) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

debug:
	g++ -o $(NAME) $(CXXFLAGS) $(SRC)

re:	fclean all

.PHONY: all clean fclean debug re
