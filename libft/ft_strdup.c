/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:26:06 by nboste            #+#    #+#             */
/*   Updated: 2016/10/08 11:23:47 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	size_t	i;
	char	*n;

	len = ft_strlen(str);
	i = 0;
	if (!(n = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len--)
		n[i++] = *str++;
	n[i] = '\0';
	return (n);
}
