NAME	= autoCompletion

CC	= g++

RM	= rm -f

SRCS	= ./src/main.cpp \
	  ./src/parser.cpp \
	  ./src/city.cpp \
	  ./src/dictionary.cpp \
	  ./src/address.cpp \
	  ./src/diviner.cpp \
	  ./src/utils.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS += -W -Wall -Wextra -I include -O3

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
