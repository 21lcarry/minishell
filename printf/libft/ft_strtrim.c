/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:52:32 by lcarry            #+#    #+#             */
/*   Updated: 2020/11/06 18:07:21 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_ft(const char *s1, const char *set, size_t *start, size_t *end)
{
	while (ft_strchr(set, s1[*start]))
		++start;
	while (ft_strchr(set, s1[*end - 1]) && start < end - 2)
		--end;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*res;

	ft_ft(s1, set, &start, &end);
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	start = 0;
	if (start < end - 1)
	{
		res = ft_substr(s1, start, end - start);
		if (res == NULL)
			return (NULL);
		res[end] = '\0';
	}
	else
	{
		res = (char *)ft_calloc(1, sizeof(char));
		if (res == NULL)
			return (NULL);
		res[0] = '\0';
	}
	return (res);
}
