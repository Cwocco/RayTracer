/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 18:47:39 by nboste            #+#    #+#             */
/*   Updated: 2016/11/09 02:55:10 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && *s1 && *s2 && n)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0 || *s1 == *s2)
		return (0);
	return (((unsigned char)*s1 - (unsigned char)*s2));
}
