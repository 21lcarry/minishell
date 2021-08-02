/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:36:14 by lcarry            #+#    #+#             */
/*   Updated: 2021/01/26 21:36:15 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_struct	ft_structinit(void)
{
	t_struct	format;

	format.minus = 0;
	format.zero = 0;
	format.width = 0;
	format.precision = -1;
	format.type = 0;
	format.length = 0;
	return (format);
}

int	ft_processor(t_struct format, va_list ap)
{
	if (format.type == 'd' || format.type == 'i')
		format.length = ft_write_int(va_arg(ap, int), format);
	else if (format.type == 'u')
		format.length = ft_write_unint(va_arg(ap, unsigned int), format);
	else if (format.type == 'c')
		format.length = ft_write_char(va_arg(ap, int), format);
	else if (format.type == 's')
		format.length = ft_write_string(va_arg(ap, char *), format);
	else if (format.type == 'p')
		format.length = ft_write_pointer(va_arg(ap, unsigned long long),
				format);
	else if (format.type == 'x' || format.type == 'X')
		format.length = ft_write_hex(va_arg(ap, unsigned int), format);
	else if (format.type == '%')
		format.length = ft_write_percent(format);
	return (format.length);
}

int	ft_parse(const char *str, va_list ap)
{
	t_struct	format;
	int			result;
	int			i;

	result = 0;
	i = 0;
	while (str[i])
	{
		format = ft_structinit();
		if (str[i] == '%' && str[i + 1])
		{
			i = ft_parse_format(str, i, &format, ap);
			result += ft_processor(format, ap);
			if (result == -1)
				return (result);
		}
		else if (str[i] != '%')
			result += ft_putchar_r(str[i]);
		++i;
	}
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			result;
	char		*str;

	str = ft_strdup((char *)format);
	if (str == NULL)
		return (-1);
	result = 0;
	va_start(ap, format);
	result += ft_parse(str, ap);
	free(str);
	va_end(ap);
	return (result);
}
