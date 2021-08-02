/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:59:10 by lcarry            #+#    #+#             */
/*   Updated: 2021/01/27 17:59:12 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_write_percent(t_struct format)
{
	if (format.minus == 1)
		format.length += ft_putchar_r('%');
	if (format.zero == 1 && format.minus != 1)
		format.length += ft_write_while(format.width - 1, '0');
	else if (format.zero == 0)
		format.length += ft_write_while(format.width - 1, ' ');
	else
		format.length += ft_write_while(format.width - 1, ' ');
	if (format.minus == 0)
		format.length += ft_putchar_r('%');
	return (format.length);
}
