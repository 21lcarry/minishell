/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:04:14 by lcarry            #+#    #+#             */
/*   Updated: 2020/11/05 21:04:56 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elem;
	t_list	*tmp;

	if (!(del))
		return ;
	elem = *lst;
	while (elem)
	{
		tmp = elem->next;
		del(elem->content);
		elem->next = NULL;
		free(elem);
		elem = tmp;
	}
	*lst = NULL;
}
