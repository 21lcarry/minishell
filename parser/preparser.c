#include "../includes/minishell.h"

int	ft_check_dquote(char *line, int *i)
{
	int	count;

	count = 1;
	++(*i);
	while (line[*i] && line[*i] != '"')
		++(*i);
	if (line[*i] && line[*i] == '"')
		++count;
	if (count % 2 != 0)
		return (0);
	if (line[*i])
		++(*i);
	return (1);
}

int	ft_check_quote(char *line, int *i)
{
	int	count;

	count = 1;
	++(*i);
	while (line[*i] && line[*i] != '\'')
		++(*i);
	if (line[*i] && line[*i] == '\'')
		++count;
	if (count % 2 != 0)
		return (0);
	if (line[*i])
		++(*i);
	return (1);
}

static void	ft_skip_quote(char *line, int *i)
{
	if (line[*i] == '\'')
		while (line[++*i] != '\'')
			;
	if (line[*i] == '"')
		while (line[++*i] != '"')
			;
}

int	ft_check_other(t_main *main)
{
	int	i;

	i = 0;
	while (main->line[i])
	{
		while (main->line[i] && (main->line[i] != '>' && main->line[i] != '<'
				&& main->line[i] != '\'' && main->line[i] != '"'))
			++i;
		if (main->line[i] && ((main->line[i] == '>' && main->line[i + 1]
					== '>') || (main->line[i] == '<'
					&& main->line[i + 1] == '<')))
			++i;
		if (main->line[i] && (main->line[i] == '>' || main->line[i] == '<'))
		{
			while (main->line[i] && ft_isspace(main->line[++i]))
				;
			if (!main->line[i] || (main->line[i] && (main->line[i] == '>'
						|| main->line[i] == '<' || main->line[i] == '|')))
				return (i);
		}
		ft_skip_quote(main->line, &i);
		if (main->line[i])
			++i;
	}
	return (ft_count_pipes(main));
}

int	ft_preparser(t_main *main)
{
	int	i;

	i = 0;
	while (main->line[i])
	{
		if (main->line[i] == '\'')
			if (!ft_check_quote(main->line, &i))
				return (i);
		if (main->line[i] == '"')
			if (!ft_check_dquote(main->line, &i))
				return (i);
		if (main->line[i] == '|')
			if (!ft_check_pipe(main->line, &i))
				return (i);
		if (main->line[i] && main->line[i] != '\'' && main->line[i] != '"')
			++i;
	}
	return (ft_check_other(main));
}
