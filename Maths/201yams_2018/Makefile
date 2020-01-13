###############
#  VARIABLES  #
###############

#Nom du projet (binaire)
NAME=		201yams

#Répertoire des sources (.c)
SRC_DIR=	$(realpath ./src)

#Répertoire de la lib (.a)
LIB_DIR=	$(./lib/my)

#Répertoire des includes (.h)
INC_DIR=	./include

#Fichiers sources à compiler
#(Par défaut, compile tous les .c du dossier src)
SRC=		$(SRC_DIR)/*.cpp \
			$(SRC_DIR)/Cases/*.cpp

#Lib à inclure
LIB=		my

#Fichiers objets (.o)
OBJ=		$(SRC:.cpp=.o)

#Arguments g++ (Ajoutez ici les libs supplémentaires)
#Ex: -lm pour math.h, -lncurses pour ncurses, ...
GCC_ARG= -W -Wall -Wextra -I$(INC_DIR)
GCC_ARG_DEBUG=-I$(INC_DIR) -g


############
#  RÈGLES  #
############

all:		$(NAME)

#Compilation normale (lib + binaire)
$(NAME):
		@echo -e "\n\033[1m\033[36mCompiling $(NAME)...\033[0m\n"
		g++ -o $(NAME) $(SRC) $(GCC_ARG)

#Compilation "debug" pour Valgrind et GDB (binaire uniquement)
debug:
		@echo -e "\n\033[1m\033[92mCompiling $(NAME) in debug mode...\033[0m"
		g++ -o $(NAME) $(SRC) $(GCC_ARG_DEBUG)

#Efface les .o dans lib/my
clean:
		@echo -e "\n\033[1m\033[33mCleaning files...\033[0m"
		rm -f $(OBJ)

#Efface le binaire et la lib
fclean:
		@echo -e "\033[1m\033[33mCleaning files and binary...\033[0m\n"
		rm -f $(NAME)

re:		fclean all
