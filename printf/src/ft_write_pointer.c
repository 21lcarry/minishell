/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:59:26 by lcarry            #+#    #+#             */
/*   Updated: 2021/01/27 17:59:27 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_putstr_a(char *str, int len)
{
	int	j;

	j = 0;
	while (str[j] && j < len)
		ft_putchar_fd(str[j++], 1);
	return (j);
}

static int	ft_write_pointer3(char *pt, t_struct format)
{
	int	j;

	j = 0;
	j += ft_putstr_r("0x", 1);
	if (format.precision >= 0)
	{
		j += ft_write_while(format.precision - ft_strlen(pt), '0');
		j += ft_putstr_a(pt, format.precision);
	}
	else
		j += ft_putstr_r(pt, 1);
	return (j);
}

static int	ft_write_pointer2(char *pt, t_struct format)
{
	int	j;

	j = 0;
	if ((size_t)format.precision < ft_strlen(pt))
		format.precision = ft_strlen(pt);
	if (format.minus == 1)
		j += ft_write_pointer3(pt, format);
	j += ft_write_while(format.width - (ft_strlen(pt) + 2), ' ');
	if (format.minus == 0)
		j += ft_write_pointer3(pt, format);
	return (j);
}

int	ft_write_pointer(unsigned long long p, t_struct format)
{
	char	*pt;

	if (format.precision == 0 && p == 0)
	{
		if (format.minus == 0)
			format.length += ft_write_while(format.width - 2, ' ');
		format.length += ft_putstr_r("0x", 1);
		if (format.minus == 1)
			format.length += ft_write_while(format.width - 2, ' ');
		return (format.length);
	}
	pt = ft_itoa_unll(p, 16);
	if (pt == NULL)
		return (-1);
	format.length += ft_write_pointer2(pt, format);
	free(pt);
	return (format.length);
}
