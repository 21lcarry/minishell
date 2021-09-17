#include "../includes/minishell.h"

void	ft_lex_dquote2(t_main *main, int i, int j)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	*free_tmp;

	tmp = ft_substr(main->line, 0, j);
	tmp2 = ft_substr(main->line, j + 1, i - j - 1);
	tmp3 = ft_strdup(&main->line[i + 1]);
	free_tmp = tmp;
	tmp = ft_strjoin(tmp, tmp2);
	free(free_tmp);
	free(tmp2);
	free_tmp = main->line;
	main->line = ft_strjoin(tmp, tmp3);
	free(free_tmp);
	free(tmp);
	free(tmp3);
}

int	ft_lexer(t_main *main)
{
	int	i;

	i = 0;
	while (main->line[i])
	{
		if (main->line[i] == '\'')
			if (!ft_lex_quote(main, &i))
				return (0);
		if (main->line[i] == '$' && !ft_isspace(main->line[i + 1])
			&& main->line[i + 1] != '|' && main->line[i + 1])
			if (!ft_lex_var(main, &i))
				return (0);
		if (main->line[i] == '$' && (ft_isspace(main->line[i + 1])
				|| main->line[i + 1] == '|' || !(main->line[i + 1])))
			++i;
		if (main->line[i] == '"')
			if (!ft_lex_dquote(main, &i))
				return (0);
		if (main->line[i] == '|')
			main->line[i++] = PIP;
		if (ft_isspace(main->line[i]))
			ft_lex_space(main, &i);
		i += ft_lexer_part(main, i);
	}
	return (1);
}

void	ft_lex_space(t_main *main, int *i)
{
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*free_p;

	j = *i;
	while (main->line[++*i] && ft_isspace(main->line[*i]))
		;
	if (main->line[*i] == '\0')
	{
		free_p = main->line;
		main->line = ft_substr(main->line, 0, j);
		free(free_p);
		return ;
	}
	else
		main->line[j] = SP;
	tmp = ft_substr(main->line, 0, j + 1);
	tmp2 = ft_strdup(&main->line[*i]);
	free_p = main->line;
	main->line = ft_strjoin(tmp, tmp2);
	free(free_p);
	*i = ft_strlen(tmp) - 1;
	free(tmp);
	free(tmp2);
}

char	*ft_lex_find_var(t_main *main, int j, int i)
{
	int		len;
	char	*key;
	int		k;
	char	*res;

	res = ft_strdup("=");
	len = i - j;
	key = (char *)malloc((len + 1) * sizeof(char));
	k = 0;
	while (++j < i)
		key[k++] = main->line[j];
	key[k++] = '=';
	key[k] = '\0';
	k = -1;
	while (main->env[++k])
	{
		if (ft_strncmp(key, main->env[k], ft_strlen(key)) == 0)
		{
			if (res)
				free(res);
			res = ft_strdup(&main->env[k][ft_strlen(key)]);
		}
	}
	free(key);
	return (res);
}

int	ft_lex_dquote(t_main *main, int *i)
{
	int	j;

	j = *i;
	while (main->line[*i] && main->line[++(*i)] != '"')
	{
		if (main->line[*i] == '$' && !ft_isspace(main->line[*i + 1])
			&& main->line[*i + 1] != '|' && main->line[*i + 1] != '$'
			&& main->line[*i + 1] != '"')
		{
			ft_lex_var(main, i);
			--*i;
		}
		while (main->line[*i] == '$' && main->line[*i + 1] == '$')
			ft_lex_var(main, i);
	}
	ft_lex_dquote2(main, *i, j);
	--(*i);
	if (main->line == NULL)
		return (0);
	return (1);
}
