#include "../includes/minishell.h"

int	ft_lex_quote(t_main *main, int *i)
{
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	*free_tmp;

	j = *i;
	while (main->line[*i] && main->line[++(*i)] != '\'')
		;
	tmp = ft_substr(main->line, 0, j);
	tmp2 = ft_substr(main->line, j + 1, *i - j - 1);
	tmp3 = ft_strdup(&main->line[*i + 1]);
	free_tmp = tmp;
	tmp = ft_strjoin(tmp, tmp2);
	free(free_tmp);
	free(tmp2);
	free_tmp = main->line;
	main->line = ft_strjoin(tmp, tmp3);
	free(free_tmp);
	free(tmp);
	free(tmp3);
	--(*i);
	if (main->line == NULL)
		return (0);
	return (1);
}

void	ft_lex_var2(t_main *main, char *var, int *i, int j)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_substr(main->line, 0, j);
	tmp3 = ft_strjoin(tmp, var);
	if (main->line[*i - 1] == '$' && !ft_isalpha(main->line[*i])
		&& main->line[*i] != '_' && main->line[*i] != '$' && main->line[*i])
	{
		tmp2 = ft_strdup(&main->line[*i - 1]);
		*i = ft_strlen(tmp3) + 1;
	}
	else
	{
		tmp2 = ft_strdup(&main->line[*i]);
		*i = ft_strlen(tmp3);
	}
	free(tmp);
	free(var);
	tmp = main->line;
	main->line = ft_strjoin(tmp3, tmp2);
	free(tmp);
	free(tmp2);
	free(tmp3);
}

int	ft_lex_var(t_main *main, int *i)
{
	char	*var;
	int		j;

	j = *i;
	while (main->line[++(*i)] && (ft_isalnum(main->line[*i])
			|| main->line[*i] == '_') && !ft_isdigit(main->line[j]))
		;
	if (main->line[*i] == '?' && main->line[*i - 1] == '$')
	{
		var = ft_itoa(g_status);
		++*i;
	}
	else
		var = ft_lex_find_var(main, j, *i);
	if (var == NULL)
		return (0);
	if (var && var[0] == '=')
		var[0] = '\0';
	if (ft_isdigit(main->line[*i]))
		++(*i);
	ft_lex_var2(main, var, i, j);
	if (main->line == NULL)
		return (0);
	return (1);
}

int	ft_lexer_part(t_main *main, int i)
{
	if (main->line[i] && main->line[i] != '\'' && main->line[i] != '$'
		&& main->line[i] != '"')
		return (1);
	else
		return (0);
}
