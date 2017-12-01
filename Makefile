##
## EPITECH PROJECT, 2017
## my_ls
## File description:
## Makefile with build project rule and units tests
##

.PHONY			: all, fclean, clean, re, tests_run, library

NAME			= 102architect

INCLUDE_DIR		= ./include

SRC				= src/main.c 				\
				  src/utils.c 				\
				  src/calculation.c 		\
				  src/102architect.c 		\
				  src/matrice.c

UT_SRC			= src/my_ls.c 				\
				  tests/my_ls_tests.c

UT_OBJ			= $(UT_SRC:.c=.o)

CFLAGS			= -Wall -Wextra

FLAGS			= $(CFLAGS) -I$(INCLUDE_DIR) -lm -L./lib -lmy

UT_FLAGS		= $(CFLAGS) -lcriterion -lgcov --coverage $(FLAGS)

## Compile all (without unitary tests)
all:			library $(NAME)

## Compile library
library:
				make -C ./lib/my

## Compile into $NAME file the output files
$(NAME):		$(SRC)
				gcc -o $(NAME) $(SRC) $(FLAGS)

## Clean output files, ut files and valgrind core errors files
clean:
				rm -f *.o
				rm -f vgcore.*
				rm -f *.gc*

## Clean files bellow, and $NAME file
fclean:			clean
				rm -f $(NAME)
				make fclean -C ./lib/my

## clean and fileclean before compilation
re:				fclean all

## Build and run unitary tests
tests_run:		
				gcc -o units $(UT_FLAGS) $(UT_OBJ)
				./units