SRC	=	./string.c  \
        ./append.c \
        ./assign.c  \
        ./utils.c    \
        ./compare.c   \
        ./find.c	\
        ./insert.c	\
        ./my_clean_str.c	\
        ./my_str_to_wordarray.c	\
        ./my_strcat.c	\
        ./split.c	\


OBJ	=	$(SRC:.c=.o)

NAME	=	libstring.a

CFLAGS	=	-Wall -Wextra -Werror -std=gnu11

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
