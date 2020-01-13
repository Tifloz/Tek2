##
## EPITECH PROJECT, 2019
## SYN_jetpack2Tek3
## File description:
## jetpack2Tek3 makefile
##

NAME =		serverJ2T3

RM = 		rm -f

CC = 		gcc

CFLAGS = 	-Wall -Wextra -g -I include

SRCS =	src/main.c              \
	src/args.c              \
        src/check_map.c         \
        src/server.c            \
        src/handle_commands.c   \
	src/str_to_word_tab.c	\
	src/new_client.c	\
	src/commands.c          \
        src/game.c		\
	src/get_next_line.c

all: 	$(NAME)

OBJS = 	$(SRCS:.c=.o)

debug: $(OBJS)
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJS)

$(NAME): $(OBJS)
	 $(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	 make clean

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all
