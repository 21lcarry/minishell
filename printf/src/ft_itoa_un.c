/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_un.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 01:32:10 by lcarry            #+#    #+#             */
/*   Updated: 2021/01/27 01:32:11 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_nblen(unsigned int nb)
{
	int	len;

	len = 1;
	if (nb)
		++len;
	while (nb)
	{
		++len;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa_un(unsigned int nb)
{
	char			*str;
	unsigned int	i;

	i = ft_nblen(nb);
	str = (char *)ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	while (i)
	{
		str[--i] = 48 + (nb % 10);
		nb = nb / 10;
	}
	return (str);
}
