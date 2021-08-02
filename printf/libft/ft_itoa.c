/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:44:59 by lcarry            #+#    #+#             */
/*   Updated: 2020/11/11 18:46:13 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(int nb)
{
	int	len;

	len = 1;
	if (nb < 0)
		++len;
	nb /= 10;
	while (nb)
	{
		nb /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char	*str;
	int		i;

	i = ft_nblen(nb);
	str = (char *)ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (nb >= 0)
	{
		while (i)
		{
			str[--i] = 48 + (nb % 10);
			nb = nb / 10;
		}
	}
	else
	{
		while (nb)
		{
			str[--i] = 48 - (nb % 10);
			nb = nb / 10;
		}
		str[i - 1] = '-';
	}
	return (str);
}
