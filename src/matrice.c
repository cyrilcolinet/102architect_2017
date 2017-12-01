/*
** EPITECH PROJECT, 2017
** 102architect
** File description:
** matrice functions
*/

# include "my.h"
# include "102architect.h"

void display_matrice(double *matrice)
{
	int offset = 0;
	int i;

	while (offset < 9) {
		printf("%.2f", matrice[offset]);
		offset++;

		if (offset % 3 == 0) {
			printf("\n");
			i++;
		} else {
			printf("\t");
		}
	}
}

void multiply_matrice(double *matrice, double *matrice2)
{
	double mat[9];

	for (int i = 0; i < 9; i++)
		mat[i] = matrice[i];

	matrice[0] = mat[0] * matrice2[0] + mat[1] * matrice2[3] + mat[2] * matrice2[6];
	matrice[1] = mat[0] * matrice2[1] + mat[1] * matrice2[4] + mat[2] * matrice2[7];
	matrice[2] = mat[0] * matrice2[2] + mat[1] * matrice2[5] + mat[2] * matrice2[8];
	matrice[3] = mat[3] * matrice2[0] + mat[4] * matrice2[3] + mat[5] * matrice2[6];
	matrice[4] = mat[3] * matrice2[1] + mat[4] * matrice2[4] + mat[5] * matrice2[7];
	matrice[5] = mat[3] * matrice2[2] + mat[4] * matrice2[5] + mat[5] * matrice2[8];
	matrice[6] = mat[6] * matrice2[0] + mat[7] * matrice2[3] + mat[8] * matrice2[6];
	matrice[7] = mat[6] * matrice2[1] + mat[7] * matrice2[4] + mat[8] * matrice2[7];
	matrice[8] = mat[6] * matrice2[2] + mat[7] * matrice2[5] + mat[8] * matrice2[8];
}

void fill_matrice_honothety(double *matrice, double homo_x, double homo_y)
{
	matrice[0] = homo_x;
	matrice[1] = 0;
	matrice[2] = 0;
	matrice[3] = 0;
	matrice[4] = homo_y;
	matrice[5] = 0;
	matrice[6] = 0;
	matrice[7] = 0;
	matrice[8] = 1;
}

void fill_matrice_rotation(double *matrice, double rot_x, double rot_y)
{
	matrice[0] = rot_x;
	matrice[1] = -rot_y;
	matrice[2] = 0;
	matrice[3] = rot_y;
	matrice[4] = rot_x;
	matrice[5] = 0;
	matrice[6] = 0;
	matrice[7] = 0;
	matrice[8] = 1;
}