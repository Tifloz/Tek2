NAME	= program

CC	= g++

RM	= rm -f

SRCS	= ./Character.cpp \
	  ./main.cpp 

OBJS	= $(SRCS:.cpp=.o)

INCLUDE = -I ./include/
CPPFLAGS += -W -Wall -Wextra -Werror

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
