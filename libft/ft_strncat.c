/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:28:56 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/16 18:33:23 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len;
	size_t i;

	dest_len = ft_strlen(dest);
	i = 0;
	if (dest == 0)
		return (NULL);
	while (src[i] != '\0' && n > i)
	{
		((char*)dest)[dest_len + i] = src[i];
		i++;
	}
	((char*)dest)[dest_len + i] = '\0';
	return (char*)(dest);
}
