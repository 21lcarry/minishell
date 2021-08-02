/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:00:35 by lcarry            #+#    #+#             */
/*   Updated: 2021/01/27 18:00:36 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_format_valid(const char chr)
{
	if (chr == 'd' || chr == 'i' || chr == 'u' || chr == 'c'
		|| chr == 's' || chr == 'p' || chr == 'x' || chr == 'X' || chr == '%')
		return (1);
	if (chr == '-' || chr == ' ' || chr == '0' || chr == '.' || chr == '*')
		return (2);
	if (ft_isdigit(chr))
		return (3);
	return (0);
}

int	ft_format_precision(const char *str, t_struct *format, va_list ap)
{
	int	i;

	i = 1;
	format->precision = 0;
	if (str[i] == '*')
	{
		format->precision = va_arg(ap, int);
		++i;
	}
	else
		while (ft_isdigit(str[i]))
			format->precision = (format->precision * 10) + (str[i++] - '0');
	return (i);
}

t_struct	ft_format_width(va_list ap, t_struct format)
{
	format.width = va_arg(ap, int);
	if (format.width < 0)
	{
		format.minus = 1;
		if (format.width == -2147483648)
			format.width = 2147483647;
		else
			format.width *= -1;
	}
	return (format);
}

int	ft_format_width_dig(const char *str, t_struct *format)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
		format->width = (format->width * 10) + (str[i++] - '0');
	--i;
	return (i);
}

int	ft_parse_format(const char *str, int i, t_struct *format,
va_list ap)
{
	++i;
	while (str[i])
	{
		if (!(ft_format_valid(str[i])))
			break ;
		if (str[i] == '0' && format->width == 0)
			format->zero = 1;
		if (str[i] == '-')
			format->minus = 1;
		if (str[i] == '.')
			i += ft_format_precision(&str[i], format, ap);
		if (str[i] == '*' && str[i - 1] != '.')
			*format = ft_format_width(ap, *format);
		if (ft_isdigit(str[i]))
			i += ft_format_width_dig(&str[i], format);
		if (ft_format_valid(str[i]) == 1)
		{
			format->type = str[i];
			break ;
		}
		++i;
	}
	return (i);
}
