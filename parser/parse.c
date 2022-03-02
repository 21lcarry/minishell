#include "../includes/minishell.h"

int	ft_parser(t_main *main)
{
	int	i;
	int	j;

	ft_init_cmd(main);
	i = ft_strlen(main->line) - 1;
	j = main->num_p;
	while (i > 0)
	{
		if (main->line[i] == PIP)
			if (!ft_parse_cmd(main, i, &j))
				ft_parseerr(main, j);
		--i;
	}
	if (!ft_parse_cmd(main, i, &j))
		ft_parseerr(main, j);
	return (1);
}

int	ft_parse_cmd(t_main *main, int i, int *j)
{
	char	*trim;

	trim = ft_strdup("0");
	trim[0] = SP;
	if (i > 0)
		main->cmd[*j]->tmp = ft_strtrim2(&main->line[i + 1], trim);
	else
		main->cmd[*j]->tmp = ft_strtrim2(&main->line[i], trim);
	if (i > 0)
		main->line[i] = '\0';
	free(trim);
	if (!ft_fill_cmd(main, *j))
		return (0);
	--*j;
	return (1);
}

void	ft_hdoc_handler(t_main *main)
{
	int		i;
	char	*name;
	char	*tmp;
	int		fd;

	i = -1;
	name = ft_strdup(".hdoc_");
	while (main->cmd[++i])
	{
		if (main->cmd[i]->h_doc)
		{
			tmp = ft_itoa(i);
			main->cmd[i]->file = ft_strjoin(name, tmp);
			free(tmp);
			fd = open(main->cmd[i]->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			write(fd, main->cmd[i]->h_doc, ft_strlen(main->cmd[i]->h_doc));
			close(fd);
			main->cmd[i]->fd_in = open(main->cmd[i]->file, O_RDONLY, 0644);
			free(main->cmd[i]->h_doc);
			main->cmd[i]->h_doc = NULL;
		}
	}
	free(name);
}

int	ft_fill_cmd(t_main *main, int j)
{
	int	i;

	i = 0;
	while (main->cmd[j]->tmp[i])
	{
		if (main->cmd[j]->tmp[i] == IN || main->cmd[j]->tmp[i] == OUT)
			if (!ft_fill_fd(main, &i, j))
				return (0);
		if (main->cmd[j]->tmp[i] && main->cmd[j]->tmp[i] != IN
			&& main->cmd[j]->tmp[i] != OUT)
			++i;
	}
	ft_hdoc_handler(main);
	ft_fill_command(main, j);
	return (1);
}

void	ft_fill_command(t_main *main, int j)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (main->cmd[j]->tmp[i++])
		if (main->cmd[j]->tmp[i] == SP)
			++k;
	i = ft_strlen(main->cmd[j]->tmp);
	main->cmd[j]->command = (char **)malloc((k + 2) * sizeof(char *));
	main->cmd[j]->command[k + 1] = NULL;
	while (main->cmd[j]->tmp[--i])
	{
		if (main->cmd[j]->tmp[i] == SP)
		{
			main->cmd[j]->command[k--] = ft_strdup(&main->cmd[j]->tmp[i + 1]);
			main->cmd[j]->tmp[i] = '\0';
		}
	}
	main->cmd[j]->command[k] = ft_strdup(&main->cmd[j]->tmp[i + 1]);
}
