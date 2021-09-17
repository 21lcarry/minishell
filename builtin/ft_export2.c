#include "../includes/minishell.h"

void	ft_add_env_exp2(char *key, t_main *main, char *str)
{
	int		len;
	char	**tmp;
	int		i;

	len = ft_arrlen(main->env_exp);
	tmp = (char **)malloc(sizeof(char *) * len + 2);
	i = -1;
	while (main->env_exp[++i])
		tmp[i] = main->env_exp[i];
	tmp[i] = ft_strjoin(key, str);
	tmp[i + 1] = NULL;
	free(main->env_exp);
	main->env_exp = tmp;
}

void	ft_add_env_exp(char *key, t_main *main, char *str)
{
	int	i;
	int	len;

	if (key)
	{
		i = -1;
		while (main->env_exp[++i])
		{
			if (ft_strlen(main->env_exp[i]) > ft_strlen(key))
				len = ft_strlen(key);
			else
				len = ft_strlen(main->env_exp[i]);
			if (ft_strncmp(main->env_exp[i], key, len) == 0)
			{
				if (main->env_exp[i])
					free(main->env_exp[i]);
				main->env_exp[i] = ft_strjoin(key, str);
				return ;
			}
		}
		ft_add_env_exp2(key, main, str);
	}
}

char	*ft_get_export_str(char *str)
{
	int		i;
	char	*res;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	i = -1;
	while (str[++i])
		if (str[i] == '=')
			break ;
	if (str[i] == '=')
	{
		tmp = ft_substr(str, 0, i + 1);
		tmp2 = ft_strjoin(tmp, "\"");
		tmp3 = ft_strdup(&str[i + 1]);
		free(tmp);
		tmp = ft_strjoin(tmp2, tmp3);
		free(tmp2);
		free(tmp3);
		res = ft_strjoin(tmp, "\"");
		free(tmp);
	}
	else
		res = ft_strdup(str);
	return (res);
}

void	ft_add_by_key(t_main *main, char *cmd, int j)
{
	char	*key;
	char	*val;

	key = ft_substr(cmd, 0, j + 1);
	val = ft_strdup(&cmd[j + 1]);
	ft_add_env_exp(key, main, val);
	ft_add_env(key, main, val);
	free(key);
	free(val);
}
