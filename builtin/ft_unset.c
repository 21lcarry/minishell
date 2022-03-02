#include "../includes/minishell.h"

static int	ft_print_error(char *cmd)
{
	ft_putstr_fd("-minishell: unset: '", STDERR);
	ft_putstr_fd(cmd, STDERR);
	ft_putstr_fd("':", STDERR);
	ft_putendl_fd("not a valid identifier", STDERR);
	g_status = 1;
	return (-1);
}

static int	ft_valid_var(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (1);
	return (0);
}

static int	ft_unset_start(t_main *main, char *cmd)
{
	ft_del_env_exp(cmd, main);
	ft_del_env(cmd, main);
	return (-1);
}

int	ft_unset(t_main *main, char **cmd)
{
	int	i;
	int	j;

	i = 0;
	g_status = 0;
	while (cmd[++i])
	{
		j = -1;
		while (cmd[i][++j])
		{
			if (!ft_valid_var(cmd[i][j]))
				return (ft_print_error(cmd[i]));
		}
		ft_unset_start(main, cmd[i]);
	}
	return (-1);
}
