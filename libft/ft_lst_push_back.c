/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 10:07:45 by nboste            #+#    #+#             */
/*   Updated: 2017/01/16 03:12:01 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lst_push_back(t_list **begin_list, void *data, size_t size)
{
	t_list *elem;
	t_list *tmp;

	elem = ft_lstnew(data, size);
	tmp = *begin_list;
	if (!(*begin_list))
		*begin_list = elem;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		(tmp)->next = elem;
	}
}
