##
## EPITECH PROJECT, 2019
## SYN_jetpack2Tek3
## File description:
## jetpack2Tek3 makefile
##

all: client server

server:
	@(cd src/server && $(MAKE))
	mv src/server/serverJ2T3 .

client:
	@(cd src/client && $(MAKE))
	mv src/client/clientJ2T3 .

debug:
	@(cd src/server && $(MAKE) $@)
	@(cd src/client && $(MAKE) $@)
	mv src/server/serverJ2T3 .
	mv src/client/clientJ2T3 .

clean:
	@(cd src/server && $(MAKE) $@)
	@(cd src/client && $(MAKE) $@)

fclean : clean
	@(cd src/server && $(MAKE) $@)
	@(cd src/client && $(MAKE) $@)
	rm -f serverJ2T3 clientJ2T3

tests_run :
	@(cd src/server && $(MAKE) $@)

re: fclean all
