NAME	=	deBruijn

SRC	=	app/Main.hs		\
		src/DeBruijn.hs		\
		src/Commands.hs		\
		src/Parser.hs		\
		src/Utils.hs

all:	$(NAME)

$(NAME): $(SRC)
	stack build --copy-bins --local-bin-path .

clean:
	stack clean
	rm .stack-work deBruijn.cabal -rf

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
