/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:00:07 by lcarry            #+#    #+#             */
/*   Updated: 2020/11/01 20:02:21 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int ch, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	unsigned char	c;
	size_t			i;

	src = (unsigned char *)source;
	dest = destination;
	c = ch;
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == c)
			return (&dest[i + 1]);
		++i;
	}
	return (0);
}
