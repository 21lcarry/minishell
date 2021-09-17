#include "../includes/minishell.h"

static int	ft_strisnum(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_builtin_exit(char **cmd)
{
	unsigned char	res;

	ft_putendl_fd("exit", STDERR);
	if (cmd[1] && ft_strisnum(cmd[1]) == 0)
	{
		res = 2;
		ft_putstr_fd("minishell: exit: ", STDERR);
		ft_putstr_fd(cmd[1], STDERR);
		ft_putendl_fd(": numeric argument required", STDERR);
	}
	else if (cmd[1] && cmd[2])
		ft_putendl_fd("minishell: exit: too many arguments", STDERR);
	else if (cmd[1])
		res = ft_atoi(cmd[1]);
	else
		res = 0;
	g_status = (int)res;
	return (-3);
}
