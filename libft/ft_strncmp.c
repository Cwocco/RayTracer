/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:00:36 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/16 18:36:01 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	i = 0;
	tmp_s1 = (unsigned char*)s1;
	tmp_s2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (tmp_s1[i] == tmp_s2[i] && tmp_s1[i] != '\0' && tmp_s2[i] != '\0' \
			&& (i < (n - 1)))
		i++;
	return (tmp_s1[i] - tmp_s2[i]);
}
