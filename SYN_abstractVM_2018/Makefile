NAME	= abstractVM

CC	= g++

RM	= rm -f

SRCS	= ./src/Factory.cpp \
	  ./src/Interpretor.cpp \
	  ./src/Parser.cpp \
	  ./src/Utils.cpp \
	  ./src/types/BigDecimal.cpp \
	  ./src/types/Double.cpp \
	  ./src/types/Float.cpp \
	  ./src/types/Int16.cpp \
	  ./src/types/Int32.cpp \
	  ./src/types/Int8.cpp \
	  ./src/main.cpp      \
	  ./src/types/AOperand.cpp \
	  ./src/Error.cpp

OBJS	= $(SRCS:.cpp=.o)

INCLUDE = -I ./include/
CPPFLAGS += -W -Wall -Wextra

REQUIRE_LIB = 

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(INCLUDE) $(CPPFLAGS) $(REQUIRE_LIB)

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
