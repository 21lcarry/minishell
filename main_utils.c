#include "includes/minishell.h"

void	ft_close(int fd)
{
	if (fd > 0)
		close(fd);
}

void	ft_arr_free(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return ;
	i = -1;
	while (s[++i] != '\0')
		write(fd, &s[i], 1);
}

static int	ft_free_cmd2(t_main *main, int i)
{
	int	err;

	err = 0;
	if (main->cmd[i]->fd_in != -1)
		err = close(main->cmd[i]->fd_in);
	main->cmd[i]->fd_in = -1;
	if (main->cmd[i]->fd_out != -1)
		err = close(main->cmd[i]->fd_out);
	main->cmd[i]->fd_out = -1;
	if (main->cmd[i]->file)
	{
		unlink(main->cmd[i]->file);
		free(main->cmd[i]->file);
	}
	return (err);
}

int	ft_free_cmd(t_main *main)
{
	int	i;
	int	err;
	int	j;

	i = -1;
	err = 0;
	while (main->cmd[++i])
	{
		j = -1;
		if (main->cmd[i]->tmp != NULL)
			free(main->cmd[i]->tmp);
		if (main->cmd[i]->error == 0)
			while (main->cmd[i]->command[++j] != NULL)
				free(main->cmd[i]->command[j]);
		if (main->cmd[i]->command && main->cmd[i]->fd_in == -1
			&& main->cmd[i]->fd_out == -1)
			free(main->cmd[i]->command);
		err = ft_free_cmd2(main, i);
		free(main->cmd[i]);
	}
	free(main->cmd);
	return (err);
}
