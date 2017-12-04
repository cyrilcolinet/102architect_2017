/*
** EPITECH PROJECT, 2017
** 102architect
** File description:
** calc functions
*/

# include "102architect.h"

void calc_translation(double *res, double *matrice, char **av, int offset)
{
	double trans_x = atof(av[offset + 1]);
	double trans_y = atof(av[offset + 2]);

	matrice[2] += trans_x;
	matrice[5] += trans_y;

	if (matrice[2] == 0)
		matrice[2] = 0;
	
	if (matrice[5] == 0)
		matrice[5] = 0;

	printf("Translation by the vector (%.0f, %.0f)\n", trans_x, trans_y);

	res[0] += trans_x;
	res[1] += trans_y;
}

void calc_homothety(double *res, double *matrice, char **av, int offset)
{
	double homo_x = atof(av[offset + 1]);
	double homo_y = atof(av[offset + 2]);

	for (int i = 0; i < 6; i++) {
		matrice[i] *= ((i <= 2) ? homo_x : homo_y);

		if (matrice[i] == 0)
			matrice[i] = 0;
	}

	printf("Homothety by the ratios %.0f and %.0f\n", homo_x, homo_y);

	res[0] *= homo_x;
	res[1] *= homo_y;
}

void calc_rotation(double *res, double *matrice, char **av, int offset)
{
	double rot_matrice[9];
	double alpha = atof(av[offset + 1]);
	double rot_x = 0;
	double rot_y = 0;
	double stock = 0;

	alpha = (alpha * M_PI) / 180;
	rot_x = cos(alpha);
	rot_y = sin(alpha);
	fill_matrice_rotation(&rot_matrice[0], rot_x, rot_y);
	multiply_matrice(&matrice[0], &rot_matrice[0]);
	printf("Rotation at a %s degree angle\n", av[offset + 1]);
	stock = res[0];
	res[0] = stock * rot_matrice[0] + res[1] * rot_matrice[1];
	res[1] = stock * rot_matrice[3] + res[1] * rot_matrice[4];
}

void calc_symmetery(double *res, double *matrice, char **av, int offset)
{
	double sym_matrice[9];
	double alpha = atof(av[offset + 1]);
	double sym_x = 0;
	double sym_y = 0;
	double stock = 0;

	alpha = (alpha * M_PI) / 180;
	sym_x = cos(2 * alpha);
	sym_y = sin(2 * alpha);
	fill_matrice_symmetery(&sym_matrice[0], sym_x, sym_y);
	multiply_matrice(&matrice[0], &sym_matrice[0]);
	printf("Symmetry about an axis inclined with an angle of %s degrees\n", av[offset + 1]);
	stock = res[0];
	res[0] = stock * sym_matrice[0] + res[1] * sym_matrice[1];
	res[1] = stock * sym_matrice[3] + res[1] * sym_matrice[4];
}