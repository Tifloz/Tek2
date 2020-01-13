NAME	= myftp

CC	= gcc

RM	= rm -f

SRCS	= ./src/server.c \
			./src/socket_utils.c \
			./src/cmds_handler.c \
			./src/utils.c \
			./src/base_cmds.c \
			./src/login.c

OBJS	= $(SRCS:.c=.o)

INCLUDE =
CFLAGS += -W -Wall -Wextra -I include
CFLAGS += -std=gnu11

REQUIRE_LIB = 

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(INCLUDE) $(LDFLAGS) $(REQUIRE_LIB)

debug:	clean $(OBJS)
	$(CC) -v $(OBJS) -o $(NAME) $(INCLUDE) $(LDFLAGS) $(REQUIRE_LIB)

noflag:	clean $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(INCLUDE) $(REQUIRE_LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all debug noflag clean fclean re
