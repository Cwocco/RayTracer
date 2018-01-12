/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 20:19:21 by nboste            #+#    #+#             */
/*   Updated: 2016/11/13 22:10:04 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*new;
	size_t	i;

	if (!s || !f)
		return (NULL);
	new = ft_strdup(s);
	i = 0;
	while (new && new[i])
	{
		new[i] = f(new[i]);
		i++;
	}
	return (new);
}
