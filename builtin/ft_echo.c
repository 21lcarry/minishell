#include "../includes/minishell.h"

static int	ft_args_count(char **av)
{
	int	count;

	count = 0;
	while (av[count])
		++count;
	return (count);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_echo(char **cmd)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (ft_args_count(cmd) > 1)
	{
		while (cmd[i] && ft_strcmp(cmd[i], "-n") == 0)
		{
			flag = 1;
			++i;
		}
		while (cmd[i])
		{
			ft_putstr_fd(cmd[i], 1);
			if (cmd[i + 1] && cmd[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (flag == 0)
		write(1, "\n", 1);
	exit(0);
}
