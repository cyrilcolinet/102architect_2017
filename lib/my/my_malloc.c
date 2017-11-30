/*
** EPITECH PROJECT, 2017
** my_malloc
** File description:
** Malloc with exit when fail
*/

#include <stdlib.h>

void *my_malloc(unsigned int size)
{
	void *ptr = malloc(size);
	if (ptr == NULL) {
		my_putstr("error");
		exit(84);
	}
	return (ptr);
}
