#include "../includes/minishell.h"

int	ft_fill_fd_newtmp(t_main *main, int tmp_i, int *i, int j)
{
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;

	if (tmp_i != 0 && main->cmd[j]->tmp[tmp_i - 1] == SP)
		tmp1 = ft_substr(main->cmd[j]->tmp, 0, tmp_i - 1);
	else
		tmp1 = ft_substr(main->cmd[j]->tmp, 0, tmp_i);
	tmp2 = ft_strdup(&main->cmd[j]->tmp[*i]);
	*i = ft_strlen(tmp1);
	tmp3 = ft_strjoin(tmp1, tmp2);
	free(main->cmd[j]->tmp);
	free(tmp1);
	free(tmp2);
	main->cmd[j]->tmp = tmp3;
	if (main->cmd[j]->tmp == NULL)
		return (0);
	return (1);
}

static char	*ft_join_nl(char *s_free, char *res)
{
	char	*res2;

	res2 = res;
	if (res[0] != '\0')
	{
		s_free = res;
		res2 = ft_strjoin(res, "\n");
		free(s_free);
	}
	return (res2);
}

char	*ft_read_hdoc(char *key)
{
	char	*res;
	char	*buff;
	char	*s_free;

	buff = readline("> ");
	res = ft_strdup("");
	while (ft_strncmp(buff, key, ft_strlen(key) + 1) != 0)
	{
		res = ft_join_nl(s_free, res);
		s_free = res;
		res = ft_strjoin(res, buff);
		free(s_free);
		free(buff);
		buff = readline("> ");
	}
	res = ft_join_nl(s_free, res);
	free(buff);
	return (res);
}

void	ft_printerr_fd(char *path)
{
	ft_putstr_fd("-minishell: ", STDERR);
	ft_putstr_fd(path, STDERR);
	ft_putendl_fd(": ", STDERR);
}
