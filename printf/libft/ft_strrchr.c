/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:01:30 by lcarry            #+#    #+#             */
/*   Updated: 2020/11/01 22:18:23 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	l;

	l = ft_strlen(str);
	while (l + 1 > 0)
	{
		if (str[l] == ch)
			return ((char *)&str[l]);
		--l;
	}
	return (0);
}
