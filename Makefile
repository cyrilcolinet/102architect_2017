##
## EPITECH PROJECT, 2017
## 102architect
## File description:
## Makefile with build project rule and units tests
##

.PHONY			: all, fclean, clean, re, tests_run, library

NAME 			= 102architect

SRC 			= src/main.c 		\
			  src/102architect.c 	\
			  src/calculation.c 	\
			  src/matrice.c 	\
			  src/utils.c

CFLAGS 			= -Wall -Wextra -I./include --coverage

EXTRA_FLAGS 		= -lm -L./lib/ -lmy -g3

CC 			= gcc

RM 			= rm -f

OBJ 			= $(SRC:.c=.o)

all: 			library $(NAME)

$(NAME):		$(OBJ)
			$(CC) $(CFLAGS) $(EXTRA_FLAGS) $(OBJ) ./lib/my/*.o -o $(NAME)

library:
			make -C ./lib

clean:
			$(RM) $(OBJ)
			$(RM) vgcore.*
			$(RM) src/*.gc*

fclean: 		clean
			$(RM) $(NAME)
			make fclean -C ./lib

re: 			fclean all

tests_run:		re
			@echo "Running units tests..."

