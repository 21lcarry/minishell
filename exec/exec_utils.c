#include "../includes/minishell.h"

int	ft_preparser_error(char c)
{
	char	tmp[3];

	ft_putstr_fd("-minishell: preparser: syntax error near unexpected token `",
		STDERR);
	tmp[0] = c;
	tmp[1] = '\'';
	tmp[2] = '\0';
	ft_putendl_fd(tmp, STDERR);
	return (1);
}

int	ft_lexer_error(void)
{
	ft_putstr_fd("-minishell: lexer: ", STDERR);
	ft_putendl_fd(strerror(errno), STDERR);
	return (2);
}

void	ft_shell_lvl(t_main *main)
{
	int		tmp;
	char	*lvl;
	char	*lvl_tmp;

	lvl = getenv("SHLVL");
	tmp = ft_atoi(lvl);
	++tmp;
	lvl_tmp = ft_itoa(tmp);
	ft_add_env("SHLVL=", main, lvl_tmp);
	ft_add_env_exp("SHLVL=", main, lvl_tmp);
	free(lvl_tmp);
}

char	*ft_getenv(char *key, t_main *main)
{
	int		i;
	int		len;
	char	*res;

	i = -1;
	res = NULL;
	while (main->env[++i])
	{
		if (ft_strlen(main->env[i]) > ft_strlen(key))
			len = ft_strlen(key);
		else
			len = ft_strlen(main->env[i]);
		if (ft_strncmp(main->env[i], key, len) == 0)
			res = ft_strdup(&main->env[i][len + 1]);
	}
	return (res);
}
