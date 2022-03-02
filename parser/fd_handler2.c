#include "../includes/minishell.h"

int	ft_fill_fd_dout(t_main *main, int *i, int j)
{
	int		k;
	char	*path;
	int		tmp_i;

	tmp_i = *i;
	*i = *i + 2;
	if (main->cmd[j]->tmp[*i] == SP)
		++(*i);
	k = *i;
	while (main->cmd[j]->tmp[*i] && main->cmd[j]->tmp[*i] != SP
		&& main->cmd[j]->tmp[*i] != IN && main->cmd[j]->tmp[*i] != OUT)
		++(*i);
	path = ft_substr(main->cmd[j]->tmp, k, *i - k);
	if (main->cmd[j]->fd_out != -1)
		if (close(main->cmd[j]->fd_out) == -1)
			return (0);
	main->cmd[j]->fd_out = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (main->cmd[j]->fd_out < 0)
		ft_printerr_fd(path);
	if (path)
		free(path);
	if (!ft_fill_fd_newtmp(main, tmp_i, i, j) || main->cmd[j]->fd_out < 0)
		return (0);
	--(*i);
	return (1);
}
