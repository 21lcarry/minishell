/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:58:24 by lcarry            #+#    #+#             */
/*   Updated: 2021/01/27 17:58:26 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_write_char(int chr, t_struct format)
{
	if (format.minus == 1)
		format.length += ft_putchar_r(chr);
	format.length += ft_write_while(format.width - 1, ' ');
	if (format.minus == 0)
		format.length += ft_putchar_r(chr);
	return (format.length);
}
