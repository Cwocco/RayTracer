/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:46:33 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/16 16:22:21 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_push_in_tab(char *tab, int len, int n, int sign)
{
	while (len > -1)
	{
		tab[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	if (sign == 1)
		tab[0] = '-';
	return (tab);
}

char		*ft_itoa(int n)
{
	char	*tab;
	int		len;
	int		tmp_n;
	int		sign;

	len = 0;
	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	tmp_n = n;
	while (tmp_n /= 10)
		len++;
	len = len + sign;
	if (!(tab = (char*)malloc(sizeof(*tab) * (len + 2))))
		return (NULL);
	tab[len + 1] = '\0';
	return (ft_push_in_tab(tab, len, n, sign));
}
