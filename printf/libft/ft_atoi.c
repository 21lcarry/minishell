/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 23:59:41 by lcarry            #+#    #+#             */
/*   Updated: 2020/11/01 20:06:17 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	tmp;
	long int	i;
	int			minus;

	tmp = 0;
	i = 0;
	minus = 1;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == 43)
		minus = 1;
	if (str[i] == 45)
		minus = -1 + ((i++) * 0);
	while (str[i] != '\0' && (str[i] > 47 && str[i] < 58))
	{
		tmp = tmp * 10;
		tmp += str[i] - 48;
		i++;
		if (tmp > 2147483647 && minus != -1)
			return (-1);
		else if (tmp > 2147483648 && minus == -1)
			return (-1);
	}
	return (tmp * minus);
}
