/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:00:01 by lcarry            #+#    #+#             */
/*   Updated: 2021/01/27 18:00:03 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_write_unint3(char *tmp_str, t_struct format)
{
	int	j;

	j = 0;
	if (format.precision >= 0)
		j += ft_write_while(((format.precision) - (ft_strlen(tmp_str))), '0');
	j += ft_putstr_r(tmp_str, 1);
	return (j);
}

static int	ft_write_unint2(char *tmp_str, t_struct format)
{
	int	j;

	j = 0;
	if (format.minus == 1)
		j += ft_write_unint3(tmp_str, format);
	if (format.precision >= 0 && (size_t)format.precision < ft_strlen(tmp_str))
		format.precision = ft_strlen(tmp_str);
	if (format.precision >= 0)
	{
		format.width -= format.precision;
		j += ft_write_while(format.width, ' ');
	}
	else if (format.zero == 1)
		j += ft_write_while((format.width - ft_strlen(tmp_str)), '0');
	else
		j += ft_write_while((format.width - ft_strlen(tmp_str)), ' ');
	if (format.minus == 0)
		j += ft_write_unint3(tmp_str, format);
	return (j);
}

int	ft_write_unint(unsigned int unum, t_struct format)
{
	char	*tmp_str;

	tmp_str = NULL;
	unum = unum + 4294967295 + 1;
	if (format.precision == 0 && unum == 0)
	{
		format.length += ft_write_while(format.width, ' ');
		return (format.length);
	}
	tmp_str = ft_itoa_un(unum);
	if (tmp_str == NULL)
		return (-1);
	format.length += ft_write_unint2(tmp_str, format);
	free(tmp_str);
	return (format.length);
}
