#include "../includes/minishell.h"

int	ft_execute(t_main *main)
{
	int	i;

	i = -1;
	ft_check_type(main);
	if (main->cmd[0]->error == 8 && !main->cmd[1])
		return (ft_builtin_exit(main->cmd[0]->command));
	if (main->cmd[0]->error == 3 && !main->cmd[1])
		return (ft_cd(main, main->cmd[0]->command));
	if (main->cmd[0]->error == 5 && !main->cmd[1])
		return (ft_export(main, main->cmd[0]->command, 0));
	if (main->cmd[0]->error == 6 && !main->cmd[1])
		return (ft_unset(main, main->cmd[0]->command));
	while (main->cmd[++i])
		if (main->cmd[i]->error != 1)
			ft_init_pipe(main, i);
	dup2(main->tmp_in, 0);
	dup2(main->tmp_out, 1);
	return (-1);
}

void	ft_add_env2(char *key, t_main *main, char *str)
{
	int		len;
	char	**tmp;
	int		i;

	len = ft_arrlen(main->env);
	tmp = (char **)malloc(sizeof(char *) * len + 3);
	i = -1;
	while (main->env[++i])
		tmp[i] = main->env[i];
	tmp[i] = ft_strjoin(key, str);
	tmp[i + 1] = NULL;
	free(main->env);
	main->env = tmp;
	main->env[i] = ft_strdup(tmp[i]);
}

void	ft_add_env(char *key, t_main *main, char *str)
{
	int	i;
	int	len;

	if (key)
	{
		i = -1;
		while (main->env[++i])
		{
			if (ft_strlen(main->env[i]) > ft_strlen(key))
				len = ft_strlen(key);
			else
				len = ft_strlen(main->env[i]);
			if (ft_strncmp(main->env[i], key, len) == 0)
			{
				if (main->env[i])
					free(main->env[i]);
				main->env[i] = ft_strjoin(key, str);
				return ;
			}
		}
		ft_add_env2(key, main, str);
	}
}

static void	ft_check_type2(t_main *main, int i, int len)
{
	if (len >= 6)
	{
		if (ft_strncmp(main->cmd[i]->command[0], "export", 7) == 0)
		{
			if (!main->cmd[i]->command[1])
				main->cmd[i]->type = 5;
			else
				main->cmd[i]->error = 5;
		}
	}
	if (len >= 5)
		if (ft_strncmp(main->cmd[i]->command[0], "unset", 6) == 0)
			main->cmd[i]->error = 6;
	if (len >= 3)
		if (ft_strncmp(main->cmd[i]->command[0], "env", 4) == 0)
			main->cmd[i]->type = 7;
	if (len >= 4)
		if (ft_strncmp(main->cmd[i]->command[0], "exit", 5) == 0)
			main->cmd[i]->error = 8;
}

void	ft_check_type(t_main *main)
{
	int	i;
	int	len;

	i = -1;
	while (main->cmd[++i])
	{
		if (main->cmd[i]->error != 1)
		{
			len = ft_strlen(main->cmd[i]->command[0]);
			if (len >= 4)
				if (ft_strncmp(main->cmd[i]->command[0], "echo", 5) == 0)
					main->cmd[i]->type = 2;
			if (len >= 2)
				if (ft_strncmp(main->cmd[i]->command[0], "cd", 3) == 0)
					main->cmd[i]->error = 3;
			ft_check_type2(main, i, len);
			if (len >= 3)
				if (ft_strncmp(main->cmd[i]->command[0], "pwd", 4) == 0)
					main->cmd[i]->type = 4;
		}		
	}
}
