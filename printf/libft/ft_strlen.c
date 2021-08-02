/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 22:01:07 by lcarry            #+#    #+#             */
/*   Updated: 2020/11/06 18:03:54 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;
	char	tmp;

	tmp = *str;
	count = 0;
	while (tmp != '\0')
	{
		count++;
		tmp = *(str + count);
	}
	return (count);
}
