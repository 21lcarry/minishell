/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 00:11:42 by lcarry            #+#    #+#             */
/*   Updated: 2020/10/30 00:29:03 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *arr, int c, size_t n)
{
	unsigned char	*array;
	unsigned char	ch;
	size_t			i;

	array = arr;
	ch = c;
	i = 0;
	while (i < n)
	{
		if (array[i] == ch)
			return (&array[i]);
		i++;
	}
	return (0);
}
