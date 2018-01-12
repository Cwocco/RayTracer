/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 19:56:30 by nboste            #+#    #+#             */
/*   Updated: 2016/10/08 11:18:39 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*b;
	size_t	i;

	i = 0;
	if (!(b = (char *)malloc(size)))
		return (NULL);
	while (i < size)
		b[i++] = 0;
	return ((void *)b);
}
