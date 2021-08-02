/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 23:30:24 by lcarry            #+#    #+#             */
/*   Updated: 2020/11/06 18:07:51 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	l;
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	l = ft_strlen((char *)s);
	if (l < start)
		len = 0;
	else if ((l - start) < len)
		len = l - start;
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		res[i] = s[start];
		++i;
		++start;
	}
	res[i] = '\0';
	return (res);
}
