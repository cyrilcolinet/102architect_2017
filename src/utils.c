/*
** EPITECH PROJECT, 2017
** 102architect
** File description:
** utils functions
*/

# include "my.h"
# include "102architect.h"
# include "utils.h"

bool check_flag(char *param, char flag) {
	return (param[0] == '-' && param[1] == flag && !param[2]);
}

void check_err(char *str)
{
	if (!my_str_isnum(str)) {
		my_puterr("Argument is not a number.\n", false);
		exit(84);
	}
}