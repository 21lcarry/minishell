/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:04:14 by lcarry            #+#    #+#             */
/*   Updated: 2020/10/29 23:21:15 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t num, size_t size)
{
	size_t	fsize;
	void	*loc;

	fsize = num * size;
	loc = malloc(fsize);
	if (loc)
		ft_memset(loc, 0, fsize);
	return (loc);
}
