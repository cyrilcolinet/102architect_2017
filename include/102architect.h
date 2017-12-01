/*
** EPITECH PROJECT, 2017
** 102architect
** File description:
** 102architect functions (header file)
*/

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>

# ifndef ARCHITECT_H
# define ARCHITECT_H

// Basics
void			check_option(double *res, double *matrice, char **av, int ac);

// Actions
void 			do_translation(char **av, int offset, double *res, double *matrice);
void 			do_homothety(char **av, int offset, double *res, double *matrice);
void 			do_rotation(char **av, int offset, double *res, double *matrice);
void 			do_symetry(char **av, int offset, double *res, double *matrice);

// Calculus
void 			calc_translation(double *res, double *matrice, char **av, int i);
void 			calc_homothety(double *res, double *matrice, char **av, int offset);
void 			calc_rotation(double *res, double *matrice, char **av, int offset);
void 			calc_symmetery(double *res, double *matrice, char **av, int offset);

//Matrice
void 			display_matrice(double *matrice);
void 			multiply_matrice(double *matrice, double *matrice2);
void 			fill_matrice_honothety(double *matrice, double homo_x, double homo_y);
void 			fill_matrice_rotation(double *matrice, double rot_x, double rot_y);
void 			fill_matrice_symmetery(double *matrice, double sym_x, double sym_y);

# endif