#include "../includes/minishell.h"

void	ft_env(t_main *main)
{
	int	i;

	i = -1;
	while (main->env[++i])
		ft_putendl_fd(main->env[i], STDOUT);
	exit(0);
}
