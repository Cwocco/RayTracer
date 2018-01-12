/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 17:19:56 by nboste            #+#    #+#             */
/*   Updated: 2016/10/08 17:44:49 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	t;
	size_t	d_l;
	size_t	s_l;

	i = 0;
	t = 0;
	d_l = ft_strlen(dest);
	s_l = ft_strlen(src);
	while (i < (size - 1) && dest[i])
		i++;
	if ((i == (size - 1) && dest[i] != '\0') || !size)
		return (size + s_l);
	while (src[t] && t < (size - 1))
	{
		if (i < size - 1)
			dest[i++] = src[t];
		t++;
	}
	dest[i] = '\0';
	return (d_l + s_l);
}
