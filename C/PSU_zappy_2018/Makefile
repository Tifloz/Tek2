##
## EPITECH PROJECT, 2019
## psu_zappy_2018
## File description:
## zappy makefile
##

zappy_server:
	@(cd src/C && $(MAKE))
	mv src/C/zappy_server .

zappy_ai:
	@(cd src/AI && $(MAKE))
	mv src/AI/zappy_ai .

all: zappy_server zappy_ai

clean:
	@(cd src/C && $(MAKE) $@)
	@(cd src/AI && $(MAKE) $@)

fclean : clean
	@(cd src/C && $(MAKE) $@)
	@(cd src/AI && $(MAKE) $@)
	rm -f zappy_server zappy_ai

tests_run :
	@(cd src/C && $(MAKE) $@)

re: fclean all
