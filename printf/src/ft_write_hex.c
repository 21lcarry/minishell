/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:58:46 by lcarry            #+#    #+#             */
/*   Updated: 2021/01/27 17:58:47 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_write_hex3(char *str_hex, t_struct format)
{
	int	j;

	j = 0;
	if (format.precision >= 0)
		j += ft_write_while(((format.precision) - (ft_strlen(str_hex))), '0');
	j += ft_putstr_r(str_hex, 1);
	return (j);
}

static int	ft_write_hex2(char *str_hex, t_struct format)
{
	int	j;

	j = 0;
	if (format.minus == 1)
		j += ft_write_hex3(str_hex, format);
	if (format.precision >= 0 && (size_t)format.precision < ft_strlen(str_hex))
		format.precision = ft_strlen(str_hex);
	if (format.precision >= 0)
	{
		format.width -= format.precision;
		j += ft_write_while(format.width, ' ');
	}
	else if (format.zero == 1)
		j += ft_write_while((format.width - ft_strlen(str_hex)), '0');
	else
		j += ft_write_while((format.width - ft_strlen(str_hex)), ' ');
	if (format.minus == 0)
		j += ft_write_hex3(str_hex, format);
	return (j);
}

int	ft_write_hex(unsigned int hex, t_struct format)
{
	char	*str_hex;

	hex = hex + 4294967295 + 1;
	if (format.precision == 0 && hex == 0)
	{
		format.length += ft_write_while(format.width, ' ');
		return (format.length);
	}
	str_hex = ft_itoa_base(hex, 16);
	if (str_hex == NULL)
		return (-1);
	if (format.type == 'X' && str_hex)
		str_hex = ft_toupper_str(str_hex);
	format.length += ft_write_hex2(str_hex, format);
	free(str_hex);
	return (format.length);
}
