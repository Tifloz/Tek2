NAME	= libmy_malloc.so

CC	= gcc

RM	= rm -f

SRCS	=	./malloc.c	\
		./free.c	\
		./realloc.c

OBJS	= $(SRCS:.c=.o)

INCLUDE = -I .
CFLAGS = -W -Wall -Wextra
CFLAGS += -shared -fpic
LNK_NAME = libmy_malloc.so

all: $(NAME)

$(NAME):
	 $(CC) -o $(NAME) $(CFLAGS) $(SRCS)

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