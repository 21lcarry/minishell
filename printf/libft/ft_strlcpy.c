/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:48:39 by lcarry            #+#    #+#             */
/*   Updated: 2020/11/06 17:42:06 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;

	if (!dst || !src)
		return (0);
	j = ft_strlen(src);
	i = 0;
	while (i + 1 < size && i <= j)
	{
		dst[i] = src[i];
		++i;
	}
	dst[size - 1] = '\0';
	return (j);
}
