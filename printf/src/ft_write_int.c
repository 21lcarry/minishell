/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:58:56 by lcarry            #+#    #+#             */
/*   Updated: 2021/01/27 17:58:58 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_write_int2(char *tmp_str, int tmp_i, t_struct format)
{
	int	tmp;

	tmp = 0;
	if (tmp_i < 0 && format.precision >= 0)
		ft_putchar_r('-');
	if (format.precision >= 0 && tmp_i < 0)
		tmp += ft_write_while(((format.precision) - (ft_numlen(tmp_i) - 1)),
				'0');
	else if (tmp_i == 0)
		tmp += ft_write_while(((format.precision - 1) - (ft_numlen(tmp_i))),
				'0');
	else
		tmp += ft_write_while(((format.precision - 1) - (ft_numlen(tmp_i) - 1)),
				'0');
	tmp += ft_putstr_r(tmp_str, 1);
	return (tmp);
}

static int	ft_write_int3(char *tmp_str, int tmp_i, t_struct format)
{
	int	j;

	j = 0;
	if (format.minus == 1)
		j += ft_write_int2(tmp_str, tmp_i, format);
	if (format.precision >= 0 && (size_t)format.precision < ft_strlen(tmp_str))
		format.precision = ft_strlen(tmp_str);
	if (format.precision >= 0)
	{
		format.width -= format.precision;
		j += ft_write_while(format.width, ' ');
	}
	else if (format.zero == 1 && format.minus != 1)
		j += ft_write_while((format.width - ft_strlen(tmp_str)), '0');
	else
		j += ft_write_while((format.width - ft_strlen(tmp_str)), ' ');
	if (format.minus == 0)
		j += ft_write_int2(tmp_str, tmp_i, format);
	return (j);
}

static int	ft_write_int4(int tmp_i, char **tmp_str, t_struct *format)
{
	if (format->zero == 1 && format->precision < 0)
		ft_putchar_fd('-', 1);
	if (tmp_i != -2147483648)
		tmp_i *= -1;
	else
		*tmp_str = ft_strdup("2147483648");
	format->zero = 1;
	--format->width;
	++format->length;
	return (tmp_i);
}

int	ft_write_int(int num, t_struct format)
{
	int		tmp_i;
	char	*tmp_str;

	tmp_i = num;
	tmp_str = NULL;
	if (format.precision == 0 && num == 0)
	{
		format.length += ft_write_while(format.width, ' ');
		return (format.length);
	}
	if (tmp_i < 0 && (format.precision >= 0 || format.zero == 1))
		num = ft_write_int4(tmp_i, &tmp_str, &format);
	if (!tmp_str)
		tmp_str = ft_itoa(num);
	if (tmp_str == NULL)
		return (-1);
	format.length += ft_write_int3(tmp_str, tmp_i, format);
	free(tmp_str);
	return (format.length);
}
