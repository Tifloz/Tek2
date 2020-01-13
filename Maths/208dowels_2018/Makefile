NAME	= 208dowels

CC	= g++

RM	= rm -f

SRCS	= ./src/Calc.cpp \
	  ./src/Parser.cpp \
	  ./src/Printer.cpp \
	  ./src/main.cpp

OBJS	= $(SRCS:.cpp=.o)

INCLUDE = -I ./include/
CPPFLAGS += -W -Wall -Wextra

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
