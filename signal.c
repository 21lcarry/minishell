#include "includes/minishell.h"

void ft_sigint(int param)
{
	(void)param;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}