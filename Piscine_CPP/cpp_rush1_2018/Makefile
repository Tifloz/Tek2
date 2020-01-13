NAME	= menger

CC	= gcc

RM	= rm -f

SRCS	= 	tests/tests_new.c	\
			./new.c	\
			./player.c	\
			./point.c	\
			./vertex.c	\
			./int.c	\
			./float.c	\
			./char.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I .
CFLAGS += -std=gnu11 -Wall -Wextra

all :

tests_run :
	gcc -o unit_tests $(SRCS) --coverage -lcriterion
	./unit_tests

.PHONY: tests_run
