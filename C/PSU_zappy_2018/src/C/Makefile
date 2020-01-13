##
## EPITECH PROJECT, 2019
## psu_zappy_2018
## File description:
## zappy_ai makefile
##

NAME =		zappy_server

RM = 		rm -f

CC = 		gcc

CFLAGS = 	-Wall -Wextra -Iinclude -lm -g

DIR = ./

PARSE = parser/
SERV = server/
INIT = server/init/
CHECK = server/player_check/
MAP = server/map_check/
CMD = server/commands/
GRAPH = server/graph/

SRCS =	$(DIR)main.c \
		$(DIR)$(PARSE)dispatch.c	\
		$(DIR)$(PARSE)get_args.c	\
		$(DIR)free.c				\
		$(DIR)$(INIT)entry.c			\
		$(DIR)$(INIT)map.c		\
		$(DIR)$(INIT)player.c	\
		$(DIR)$(INIT)socket.c	\
		$(DIR)$(SERV)listen.c	\
		$(DIR)$(SERV)new_connection.c	\
		$(DIR)$(SERV)handle_clients.c	\
		$(DIR)$(SERV)handle_client_tools.c	\
		$(DIR)$(CHECK)check.c	\
		$(DIR)$(CHECK)set_command.c	\
		$(DIR)$(MAP)map_actualisation.c	\
		$(DIR)$(MAP)player_move.c	\
		$(DIR)$(MAP)player_pos.c	\
		$(DIR)$(SERV)primary_input.c	\
		$(DIR)$(CMD)death.c	\
		$(DIR)$(CMD)broadcast.c	\
		$(DIR)$(CMD)connect.c	\
		$(DIR)$(CMD)eject.c	\
		$(DIR)$(CMD)fork.c	\
		$(DIR)$(CMD)forward.c	\
		$(DIR)$(CMD)incant_but_norm.c	\
		$(DIR)$(CMD)incant.c	\
		$(DIR)$(CMD)inventory.c	\
		$(DIR)$(CMD)left.c	\
		$(DIR)$(CMD)look_but_norm.c	\
		$(DIR)$(CMD)look.c	\
		$(DIR)$(CMD)right.c	\
		$(DIR)$(CMD)set.c	\
		$(DIR)$(CMD)take.c	\
		$(DIR)$(CMD)error.c	\
		$(DIR)$(GRAPH)send_first_data.c	\
		$(DIR)$(GRAPH)send_first_data_norming.c	\


all: $(NAME)


OBJS = 		$(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

tests_run :
	gcc -o unit_tests parser/dispatch.c ../../tests/mainTests.c -I include --coverage -lcriterion
	./unit_tests

re: fclean all
