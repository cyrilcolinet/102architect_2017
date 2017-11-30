/*
** EPITECH PROJECT, 2017
** 102architect
** File description:
** 102architect functions (header file)
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>

# ifndef ARCHITECT_H
# define ARCHITECT_H

double 			*check_option(double *res, double *matrice, char **av, int ac);
void 			calc_translation(double *res, double *matrice, char **av, int i);

# endif