/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:46:35 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/14 17:09:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (size != 0)
	{
		while (dst[i] != '\0' && i < size)
			i++;
		j = i;
		while (src[i - j] != '\0' && (i < size - 1))
		{
			dst[i] = src[i - j];
			i++;
		}
		if (i < size)
			dst[i] = '\0';
	}
	return (j + ft_strlen(src));
}
