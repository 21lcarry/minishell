#include "../includes/minishell.h"

char	*ft_strtrim2(char const *s1, char const *set)
{
	size_t		size_s;
	char		*res;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size_s = ft_strlen(s1);
	while (size_s && ft_strchr(set, s1[size_s]))
		size_s--;
	res = ft_substr((char *)s1, 0, size_s + 1);
	return (res);
}

void	ft_parseerr(t_main *main, int j)
{
	main->cmd[j]->error = 1;
	g_status = 1;
	ft_putendl_fd(strerror(errno), STDERR);
}
