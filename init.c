#include "includes/minishell.h"

t_main  *ft_init_struct(char **ev)
{
	t_main *res;

	(void)ev;
	res = (t_main *)ft_calloc(1, sizeof(t_main));
	res->line = NULL;
	res->stop = 0;

	return (res);
}