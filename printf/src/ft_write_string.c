/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:59:42 by lcarry            #+#    #+#             */
/*   Updated: 2021/01/27 17:59:45 by lcarry           ###   ########.fr       */
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

static int	ft_write_string2(char *str, t_struct format)
{
	int	j;

	j = 0;
	if (format.precision >= 0)
	{
		j += ft_write_while(format.precision - ft_strlen(str), ' ');
		j += ft_putstr_a(str, format.precision);
	}
	else
		j += ft_putstr_r(str, 1);
	return (j);
}

int	ft_write_string(char *str, t_struct format)
{
	if (str == NULL)
		str = "(null)\0";
	if (format.precision >= 0 && (size_t)format.precision > ft_strlen(str))
		format.precision = ft_strlen(str);
	if (format.minus == 1)
		format.length += ft_write_string2(str, format);
	if (format.precision >= 0)
		format.length += ft_write_while(format.width - format.precision, ' ');
	else
		format.length += ft_write_while(format.width - ft_strlen(str), ' ');
	if (format.minus == 0)
		format.length += ft_write_string2(str, format);
	return (format.length);
}
