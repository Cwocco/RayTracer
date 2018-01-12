/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 14:18:21 by nboste            #+#    #+#             */
/*   Updated: 2016/10/09 14:41:44 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*curr;
	t_list	*prev;
	t_list	*new;

	new = NULL;
	if (lst && f)
	{
		curr = f(lst);
		lst = lst->next;
		new = curr;
		if (new)
		{
			while (lst)
			{
				prev = curr;
				curr = f(lst);
				if (!curr)
					return (NULL);
				prev->next = curr;
				lst = lst->next;
			}
			curr->next = 0;
		}
	}
	return (new);
}
