#include "../includes/minishell.h"

int	ft_check_pipe(char *line, int *i)
{
	int	j;

	if (*i == 0 || *i == (int)ft_strlen(line) - 1 || line[++(*i)] == '|')
		return (0);
	j = 0;
	while (line[j] && ft_isspace(line[j]))
		if (line[++j] == '|')
			return (0);
	j = *i;
	while (line[j] && ft_isspace(line[j]))
		if (line[++j] == '|')
			return (0);
	if (line[j] == '\0')
		return (0);
	return (1);
}

static int	ft_other_replace(t_main *main)
{
	int	i;

	i = 0;
	while (main->line[i])
	{
		if (main->line[i] == '\'')
			while (main->line[++i] != '\'')
				;
		if (main->line[i] == '"')
			while (main->line[++i] != '"')
				;
		if (main->line[i] == '>')
			main->line[i] = OUT;
		if (main->line[i] == '<')
			main->line[i] = IN;
		if (main->line[i])
			++i;
	}
	return (-1);
}

int	ft_count_pipes(t_main *main)
{
	int	i;

	main->num_p = 0;
	i = 0;
	while (main->line[i])
	{
		if (main->line[i] == '\'')
			while (main->line[++i] != '\'')
				;
		if (main->line[i] == '"')
			while (main->line[++i] != '"')
				;
		if (main->line[i] == '|')
			++main->num_p;
		if (main->line[i])
			++i;
	}
	return (ft_other_replace(main));
}
