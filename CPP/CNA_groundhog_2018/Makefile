##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Navy Makefile
##

NAME	= groundhog

CC	= g++

RM	= rm -f

SRCS	= 	./main.cpp	\
		./Calcul.cpp

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
