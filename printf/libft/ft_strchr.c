/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:12:58 by lcarry            #+#    #+#             */
/*   Updated: 2020/10/28 15:56:55 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	size_t	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == symbol)
			return ((char *)&string[i]);
		i++;
	}
	if (string[i] == symbol)
		return ((char *)&string[i]);
	return (0);
}
