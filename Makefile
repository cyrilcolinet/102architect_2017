##
## EPITECH PROJECT, 2017
## my_ls
## File description:
## Makefile with build project rule and units tests
##

.PHONY			: all, fclean, clean, re, tests_run, library

NAME			= 102architect

INCLUDE_DIR		= ./include

SRC			= src/main.c 				\
			  src/utils.c 				\
			  src/calculation.c 		\
			  src/102architect.c 		\
			  src/matrice.c

UT_SRC			= src/my_ls.c 				\
			  tests/my_ls_tests.c

UT_OBJ			= $(UT_SRC:.c=.o)

CFLAGS			= -Wall -Wextra

FLAGS			= $(CFLAGS) -I$(INCLUDE_DIR) -lm -L./lib -lmy --coverage

UT_FLAGS		= $(CFLAGS) -lcriterion -lgcov --coverage $(FLAGS)

all:			library $(NAME)

library:
			make -C ./lib/my

$(NAME):		$(SRC)
			gcc -o $(NAME) $(SRC) $(FLAGS)

clean:
			rm -f *.o
			rm -f vgcore.*
			rm -f *.gc*

fclean:			clean
			rm -f $(NAME)
			make fclean -C ./lib/my


re:			fclean all

tests_run:		
			gcc -o units $(UT_FLAGS) $(UT_OBJ)
			./units
