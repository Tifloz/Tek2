##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for OOP_arcade_2018
##

NAME		=	arcade

CC			=	g++

RM			=	rm -f

SRCS		=	./src/Main.cpp			\
				./src/ErrorHandling.cpp

OBJS		=	$(SRCS:.cpp=.o)

CPPFLAGS	=	-I ./Include/
CPPFLAGS	+=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CPPFLAGS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

core:

games:

graphicals:

.PHONY:		all clean fclean re core games graphicals
