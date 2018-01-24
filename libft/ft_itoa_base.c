/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:29:47 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/05 12:57:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static char	*ft_push_in_tab_base(int len, long tmp_value, int base)
{
	char	*tab;

	if (!(tab = (char*)malloc(sizeof(*tab) * (len + 2))))
		return (NULL);
	while (len > -1)
	{
		tab[len] = tmp_value % base < 10 ?
			tmp_value % base + '0' : tmp_value % base - 10 + 'A';
		tmp_value = tmp_value / (long)base;
		len--;
	}
	return (tab);
}

char		*ft_itoa_base(int value, int base)
{
	int		len;
	long	tmp_value;
	long	tmp_value2;
	int		sign;
	char	*tab;

	len = 0;
	sign = 0;
	tmp_value = (long)value;
	if (base <= 1 || base > 16)
		return (0);
	if (value < 0)
	{
		sign = 1;
		tmp_value = -tmp_value;
	}
	tmp_value2 = tmp_value;
	while (tmp_value /= (long)base)
		len++;
	len = len + sign;
	tab = ft_push_in_tab_base(len, tmp_value2, base);
	tab[len + 1] = '\0';
	if (sign == 1)
		tab[0] = '-';
	return (tab);
}
