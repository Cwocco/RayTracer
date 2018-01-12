/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 20:45:38 by nboste            #+#    #+#             */
/*   Updated: 2016/11/13 22:11:38 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!(new = (char *)malloc(len + 1)) || !s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s[(size_t)start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
