#include "libft.h"

size_t	ft_arrlen(char **arr)
{
	size_t	i;

	i = 0;
	if (!*arr)
		return (0);
	while (arr[i])
		++i;
	return (i);
}
