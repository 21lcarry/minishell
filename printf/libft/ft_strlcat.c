/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 01:08:48 by lcarry            #+#    #+#             */
/*   Updated: 2020/11/01 22:05:18 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	i;
	size_t	l;
	size_t	res;

	j = ft_strlen(dst);
	l = j;
	i = 0;
	if (size == 1 || size <= l)
		return ((size_t)ft_strlen(src) + size);
	if (size > l)
	{
		while (i + 1 < size && i <= (size_t)ft_strlen(src))
		{
			dst[j] = src[i];
			++j;
			++i;
		}
	}
	dst[size - 1] = '\0';
	if (size == 0)
		res = (size_t)ft_strlen(src);
	else
		res = l + (size_t)ft_strlen(src);
	return (res);
}
