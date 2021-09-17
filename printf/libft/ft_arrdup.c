#include "libft.h"
#include <stdlib.h>

char	**ft_arrdup(char **arr)
{
	int		i;
	int		len;
	char	**res;

	len = (int)ft_arrlen(arr);
	res = (char **)malloc((len + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = ft_strdup(arr[i]);
	res[i] = NULL;
	return (res);
}
