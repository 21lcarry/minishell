#include "../includes/minishell.h"

char	**ft_get_path(t_main *main)
{
	int		j;
	char	**res;

	j = -1;
	while (main->env[++j])
	{
		if (ft_strncmp("PATH=", main->env[j], 5) == 0)
		{
			res = ft_split(&main->env[j][5], ':');
			break ;
		}
	}
	return (res);
}

int	ft_findcmd_path(t_main *main, int i, char **path)
{
	int		j;
	char	*tmp;
	char	*cmd;

	j = -1;
	while (path[++j])
	{
		tmp = ft_strjoin(path[j], "/");
		cmd = ft_strjoin(tmp, main->cmd[i]->command[0]);
		free(tmp);
		if (execve(cmd, main->cmd[i]->command, main->env) != -1)
		{
			free(cmd);
			ft_arr_free(path);
			return (0);
		}
		free(cmd);
	}
	return (1);
}
