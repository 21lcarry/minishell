/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 01:31:50 by lcarry            #+#    #+#             */
/*   Updated: 2021/01/27 01:31:51 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_nblen_base(unsigned int nb, int base)
{
	int	len;

	len = 1;
	nb /= base;
	if (nb)
		++len;
	while (nb)
	{
		++len;
		nb /= base;
	}
	return (len);
}

char	*ft_itoa_base(unsigned int nb, int base)
{
	unsigned int	i;
	char			*str;

	i = ft_nblen_base(nb, base);
	str = (char *)ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	while (i-- > 0)
	{
		if (nb % base > 9)
			str[i] = (nb % base) + ('a' - 10);
		else
			str[i] = (nb % base) + ('0');
		nb = nb / base;
	}
	return (str);
}
