/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:35:36 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/16 15:24:06 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	i_tab;
	char	**tab;

	i = 0;
	i_tab = 0;
	if (s == NULL || !(tab = (char**)malloc(sizeof(*tab) * \
					(ft_count_words(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] != '\0' && (s[i + len] != c))
				len++;
			tab[i_tab++] = ft_strsub(s, i, len);
			i = i + len;
		}
	}
	tab[i_tab] = NULL;
	return (tab);
}
