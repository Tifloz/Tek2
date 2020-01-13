NAME	= program

CC	= gcc

RM	= rm -f

SRCS	= ./nm.c 

OBJS	= $(SRCS:.c=.o)

INCLUDE = -I ./include/
CFLAGS += -W -Wall -Wextra -Werror
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
