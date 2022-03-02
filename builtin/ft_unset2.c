#include "../includes/minishell.h"

int	ft_del_env2(t_main *main, int i)
{
	int	j;
	int	k;
	int	n;

	free(main->env[i]);
	j = -1;
	k = -1;
	n = -1;
	while (main->env[++n])
	{
		if (n == i)
			++k;
		main->env[++j] = main->env[++k];
	}
	if (main->env[j])
		main->env[++j] = NULL;
	return (-1);
}

int	ft_del_env(char *key, t_main *main)
{
	int	i;
	int	len;
	int	flag;

	i = -1;
	flag = 0;
	while (main->env[++i])
	{
		if (ft_strlen(main->env[i]) > ft_strlen(key))
			len = ft_strlen(key);
		else
			len = ft_strlen(main->env[i]);
		if (ft_strncmp(main->env[i], key, len) == 0)
		{
			flag = 1;
			break ;
		}
	}
	if (flag == 1)
		return (ft_del_env2(main, i));
	else
		return (-1);
}

int	ft_del_env_exp2(t_main *main, int i)
{
	int	j;
	int	k;
	int	n;

	free(main->env_exp[i]);
	j = -1;
	k = -1;
	n = -1;
	while (main->env_exp[++n])
	{
		if (n == i)
			++k;
		main->env_exp[++j] = main->env_exp[++k];
	}
	if (main->env_exp[j])
		main->env_exp[++j] = NULL;
	return (-1);
}

int	ft_del_env_exp(char *key, t_main *main)
{
	int	i;
	int	len;
	int	flag;

	i = -1;
	flag = 0;
	while (main->env_exp[++i])
	{
		if (ft_strlen(main->env_exp[i]) > ft_strlen(key))
			len = ft_strlen(key);
		else
			len = ft_strlen(main->env_exp[i]);
		if (ft_strncmp(main->env_exp[i], key, len) == 0)
		{
			flag = 1;
			break ;
		}
	}
	if (flag == 1)
		return (ft_del_env_exp2(main, i));
	else
		return (-1);
}
