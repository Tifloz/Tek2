##
## EPITECH PROJECT, 2019
## SYN_jetpack2Tek3
## File description:
## jetpack2Tek3 makefile
##

NAME =		clientJ2T3

RM = 		rm -f

CC = 		gcc

CFLAGS = 	-Wall -Wextra -pedantic -I include -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lpthread -O3

SRCS =	main.c \
		graph/run.c \
		graph/drawer.c \
		graph/init.c \
		graph/assets_manager.c \
		network/run.c \
		network/main_cmds.c \
		network/cmd_player.c \
		network/utils.c \
		get_next_line.c \
		my_str_to_wordarray.c

all: $(NAME)

OBJS = 		$(SRCS:.c=.o)

debug: $(OBJS)
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all
