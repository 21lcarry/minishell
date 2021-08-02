/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 20:42:58 by lcarry            #+#    #+#             */
/*   Updated: 2020/10/31 00:39:59 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*res;
	int		i;
	int		l;

	l = 0;
	while (src[l])
		l++;
	res = (char *)malloc(sizeof(char) * l + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		res[i] = src[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
