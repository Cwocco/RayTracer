/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 11:49:05 by nboste            #+#    #+#             */
/*   Updated: 2016/12/23 08:25:40 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem;
	t_list	*next_elem;

	elem = *alst;
	while (elem)
	{
		next_elem = elem->next;
		del(elem->content, elem->content_size);
		free(elem);
		elem = next_elem;
	}
	*alst = NULL;
}

void	ft_free(void *v, size_t s)
{
	s++;
	free(v);
}
