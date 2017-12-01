/*
** EPITECH PROJECT, 2017
** 102architect
** File description:
** main function
*/

# include "my.h"
# include "102architect.h"

int main(int ac, char **av)
{
	double matrice[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
	double result[3];

	if (ac < 5) {
		my_puterr("Missing arguments. Minimum 5 arguments needed.\n");
		return (84);
	}

	result[0] = atof(av[1]);
	result[1] = atof(av[2]);
	result[2] = 1;
	check_option(result, matrice, av, ac);
	display_matrice(matrice);
	printf("(%s, %s) => (%.2f, %.2f)\n", av[1], av[2], result[0], result[1]);
	return (0);
}