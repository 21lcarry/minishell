#include "../includes/minishell.h"

static int	ft_print_error(char *cmd)
{
	ft_putstr_fd("-minishell: export: '", STDERR);
	ft_putstr_fd(cmd, STDERR);
	ft_putstr_fd("':", STDERR);
	ft_putendl_fd("not a valid identifier", STDERR);
	return (1);
}

static int	ft_valid_var(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (1);
	return (0);
}

static int	ft_export_var2(t_main *main, char **cmd, int i)
{
	int	j;
	int	flag;

	flag = 0;
	j = -1;
	while (cmd[i][++j])
	{
		if (cmd[i][j] == '=' && j != 0)
		{
			ft_add_by_key(main, cmd[i], j);
			flag = 1;
			break ;
		}
		if (!ft_valid_var(cmd[i][j]) || ft_isdigit(cmd[i][0]))
		{
			flag = ft_print_error(cmd[i]);
			break ;
		}
	}
	return (flag);
}

static int	ft_export_var(t_main *main, char **cmd)
{
	int	i;
	int	flag;

	i = 0;
	while (cmd[++i])
	{
		flag = ft_export_var2(main, cmd, i);
		if (flag != 1)
			ft_add_env_exp(cmd[i], main, "");
	}
	return (flag);
}

int	ft_export(t_main *main, char **cmd, int flag)
{
	int		i;
	char	*str;

	if (flag == 1)
	{
		i = -1;
		while (main->env_exp[++i])
		{
			ft_putstr_fd("declare -x ", STDOUT);
			str = ft_get_export_str(main->env_exp[i]);
			ft_putendl_fd(str, STDOUT);
			free(str);
		}
		g_status = 0;
		exit(0);
	}
	else if (flag == 0)
		g_status = ft_export_var(main, cmd);
	return (-1);
}
