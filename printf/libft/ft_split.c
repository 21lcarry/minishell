/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:20:27 by lcarry            #+#    #+#             */
/*   Updated: 2020/11/16 19:08:53 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_numelem(char const *s, char c)
{
	size_t	i;
	int		j;

	i = 1;
	j = 0;
	if (s[0] != c && s[0])
		++j;
	if (ft_strlen(s))
	{
		while (s[i])
		{
			if (s[i] != c && s[i - 1] == c)
				++j;
			++i;
		}
	}
	return (j);
}

static size_t	ft_start(const char *s, char c, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (s[k] == c && s[k])
		++k;
	if (s[0] == c && s[0])
		--j;
	if (j < i && s[0] != c && s[0])
		++k;
	while (j < i)
	{
		if (s[k] != c && s[k - 1] == c)
			++j;
		if (j == i)
			--k;
		++k;
	}
	return (k);
}

static char	*ft_takeword(const char *s, char c, int i)
{
	char	*tmp;
	int		j;
	int		len;
	size_t	k;

	k = ft_start(s, c, i);
	len = 0;
	while (s[k + len] != c && s[k + len])
		++len;
	tmp = (char *)ft_calloc(len + 1, sizeof(char));
	if (tmp == NULL)
		return (NULL);
	j = 0;
	while (j < len)
	{
		tmp[j] = s[k + j];
		++j;
	}
	return (tmp);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		elem;
	int		i;

	if (!s)
		return (NULL);
	elem = ft_numelem(s, c);
	arr = (char **)ft_calloc(elem + 1, sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < elem)
	{
		arr[i] = ft_takeword(s, c, i);
		if (arr[i] == NULL)
		{
			while (--i >= 0)
				free(arr[i]);
			free(arr);
			return (NULL);
		}
		++i;
	}
	arr[i] = NULL;
	return (arr);
}
