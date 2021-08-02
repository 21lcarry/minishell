/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:00:43 by lcarry            #+#    #+#             */
/*   Updated: 2021/01/27 18:00:44 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_toupper_str(char *str)
{
	char	*res;
	int		i;

	i = 0;
	res = str;
	while (str[i])
	{
		res[i] = str[i];
		if (str[i] >= 97 && str[i] <= 122)
			res[i] = (str[i] - 32);
		++i;
	}
	return (res);
}

int	ft_putstr_r(char *s, int fd)
{
	if (s && fd)
		write(fd, &s[0], ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_numlen(int nb)
{
	int		len;
	long	tmp;

	tmp = nb;
	len = 0;
	if (tmp < 0)
	{
		tmp = tmp * -1;
		len++;
	}
	while (tmp > 0)
	{
		tmp = tmp / 10;
		len++;
	}
	return (len);
}

int	ft_putchar_r(char c)
{
	write(1, &c, 1);
	return (1);
}
