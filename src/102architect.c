/*
** EPITECH PROJECT, 2017
** 102architect
** File description:
** 102architect functions
*/

# include "my.h"
# include "utils.h"
# include "102architect.h"

void do_translation(char **av, int offset, double *res, double *matrice)
{
	check_err(av[offset + 1]);
	check_err(av[offset + 2]);
	calc_translation(res, matrice, av, offset);
}

void do_homothety(char **av, int offset, double *res, double *matrice)
{
	check_err(av[offset + 1]);
	check_err(av[offset + 2]);
	calc_homothety(res, matrice, av, offset);
}

void do_rotation(char **av, int offset, double *res, double *matrice)
{
	check_err(av[offset + 1]);
	calc_rotation(res, matrice, av, offset);
}

void do_symetry(char **av, int offset, double *res, double *matrice)
{
	check_err(av[offset + 1]);
	calc_symmetery(res, matrice, av, offset);
}

void check_option(double *res, double *matrice, char **av, int ac)
{
	int offset = 3;

	while (offset < ac) {
		if (check_flag(av[offset], 't') || check_flag(av[offset], 'h')) {
			if ((offset + 2) <= ac) {
				if (check_flag(av[offset], 't')) do_translation(av, offset, &res[0], &matrice[0]);
				else do_homothety(av, offset, &res[0], &matrice[0]);
			} else {
				my_puterr("After -t/-h option, you must enter two numbers.\n");
				exit(84);
			}

			offset += 3;
		} else if (check_flag(av[offset], 'r') || check_flag(av[offset], 's')) {
			if ((offset + 1) <= ac) {
				if (check_flag(av[offset], 'r')) do_rotation(av, offset, &res[0], &matrice[0]);
				else do_symetry(av, offset, &res[0], &matrice[0]);
			} else {
				my_puterr("After -r/-hs option, you must enter only one number.\n");
				exit(84);
			}

			offset += 2;
		} else {
			my_puterr("Unknowned option. Only -thrs flags allowed.\n");
			exit(84);
		}
	}
}