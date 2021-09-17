#include "../includes/minishell.h"

int	ft_fill_fd(t_main *main, int *i, int j)
{
	int	result;

	result = 1;
	if (main->cmd[j]->tmp[*i] == OUT && main->cmd[j]->tmp[*i + 1] == OUT)
		result = ft_fill_fd_dout(main, i, j);
	else if (main->cmd[j]->tmp[*i] == OUT)
		result = ft_fill_fd_out(main, i, j);
	else if (main->cmd[j]->tmp[*i] == IN && main->cmd[j]->tmp[*i + 1] == IN)
		result = ft_fill_fd_din(main, i, j);
	else if (main->cmd[j]->tmp[*i] == IN)
		result = ft_fill_fd_in(main, i, j);
	return (result);
}

int	ft_fd_close(t_main *main, int j)
{
	if (main->cmd[j]->fd_in != -1)
		if (close(main->cmd[j]->fd_in) == -1)
			return (0);
	if (main->cmd[j]->h_doc)
	{
		free(main->cmd[j]->h_doc);
		main->cmd[j]->h_doc = NULL;
	}
	return (1);
}

int	ft_fill_fd_din(t_main *main, int *i, int j)
{
	int		k;
	char	*key;
	int		tmp_i;

	tmp_i = *i;
	++*i;
	if (main->cmd[j]->tmp[++*i] == SP)
		++*i;
	k = *i;
	while (main->cmd[j]->tmp[*i] && main->cmd[j]->tmp[*i] != SP
		&& main->cmd[j]->tmp[*i] != IN && main->cmd[j]->tmp[*i] != OUT)
		++(*i);
	key = ft_substr(main->cmd[j]->tmp, k, *i - k);
	if (!ft_fd_close(main, j))
		return (0);
	main->cmd[j]->h_doc = ft_read_hdoc(key);
	if (key)
		free(key);
	if (!ft_fill_fd_newtmp(main, tmp_i, i, j) || main->cmd[j]->h_doc == NULL)
		return (0);
	--(*i);
	return (1);
}

int	ft_fill_fd_in(t_main *main, int *i, int j)
{
	int		k;
	char	*path;
	int		tmp_i;

	tmp_i = *i;
	if (main->cmd[j]->tmp[++*i] == SP)
		++*i;
	k = *i;
	while (main->cmd[j]->tmp[*i] && main->cmd[j]->tmp[*i] != SP
		&& main->cmd[j]->tmp[*i] != IN && main->cmd[j]->tmp[*i] != OUT)
		++(*i);
	path = ft_substr(main->cmd[j]->tmp, k, *i - k);
	if (!ft_fd_close(main, j))
		return (0);
	main->cmd[j]->fd_in = open(path, O_RDONLY, 0644);
	if (main->cmd[j]->fd_in < 0)
		ft_printerr_fd(path);
	if (path)
		free(path);
	if (!ft_fill_fd_newtmp(main, tmp_i, i, j) || main->cmd[j]->fd_in < 0)
		return (0);
	--(*i);
	return (1);
}

int	ft_fill_fd_out(t_main *main, int *i, int j)
{
	int		k;
	char	*path;
	int		tmp_i;

	tmp_i = *i;
	if (main->cmd[j]->tmp[++*i] == SP)
		++*i;
	k = *i;
	while (main->cmd[j]->tmp[*i] && main->cmd[j]->tmp[*i] != SP
		&& main->cmd[j]->tmp[*i] != IN && main->cmd[j]->tmp[*i] != OUT)
		++(*i);
	path = ft_substr(main->cmd[j]->tmp, k, *i - k);
	if (main->cmd[j]->fd_out != -1)
		if (close(main->cmd[j]->fd_out) == -1)
			return (0);
	main->cmd[j]->fd_out = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (main->cmd[j]->fd_out < 0)
		ft_printerr_fd(path);
	if (path)
		free(path);
	if (!ft_fill_fd_newtmp(main, tmp_i, i, j) || main->cmd[j]->fd_out < 0)
		return (0);
	--(*i);
	return (1);
}
