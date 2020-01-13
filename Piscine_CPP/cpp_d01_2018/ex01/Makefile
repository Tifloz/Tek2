NAME	= menger

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \
	  ./menger.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -std=gnu11 -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lm

clean:
	$(RM) $(eOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

tests_run :
	gcc -o unit_tests menger.c tests/tests_menger.c --coverage -lcriterion
	./unit_tests

.PHONY: all clean fclean re
