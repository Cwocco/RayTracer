/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:21:06 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/16 10:25:12 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t dest_len;
	size_t i;

	dest_len = ft_strlen(dest);
	i = 0;
	if (dest == 0)
		return (NULL);
	while (src[i] != '\0')
	{
		((char*)dest)[dest_len + i] = src[i];
		i++;
	}
	((char*)dest)[dest_len + i] = '\0';
	return (char*)(dest);
}
