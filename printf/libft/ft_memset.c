/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:41:24 by lcarry            #+#    #+#             */
/*   Updated: 2020/10/29 19:14:06 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char	temp;
	unsigned char	*arr;
	int				i;

	temp = c;
	arr = destination;
	i = 0;
	while (n > 0)
	{
		arr[i] = temp;
		i++;
		n--;
	}
	return (arr);
}
