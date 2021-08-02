/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:42:27 by lcarry            #+#    #+#             */
/*   Updated: 2020/11/05 21:25:02 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, void *source, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	dest = destination;
	src = source;
	i = n;
	if (!dest && !src)
		return (dest);
	if (src < dest)
		while (i-- > 0)
			dest[i] = src[i];
	else
	{
		i = 0;
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}
