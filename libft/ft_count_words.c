/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:00:41 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/16 12:53:43 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		get_count;

	i = 0;
	count = 0;
	get_count = 0;
	while (s[i] != '\0')
	{
		if (get_count == 1 && s[i] == c)
			get_count = 0;
		if (get_count == 0 && s[i] != c)
		{
			get_count = 1;
			count++;
		}
		i++;
	}
	return (count);
}
