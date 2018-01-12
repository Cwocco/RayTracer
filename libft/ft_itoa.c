/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 21:49:01 by nboste            #+#    #+#             */
/*   Updated: 2016/10/12 21:23:40 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_str_size(int n)
{
	size_t			i;
	size_t			neg;
	unsigned int	nb;

	i = 0;
	neg = n < 0 ? 1 : 0;
	nb = n < 0 ? n * -1 : n;
	while (nb)
	{
		i++;
		nb = nb / 10;
	}
	return (i + neg);
}

static char		*ft_zero_str(void)
{
	char	*s;

	if (!(s = (char *)malloc(2)))
		return (NULL);
	s[0] = '0';
	s[1] = '\0';
	return (s);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				neg;
	unsigned int	nb;

	if (n == 0)
		return (ft_zero_str());
	i = ft_get_str_size(n);
	if (!(str = (char *)ft_strnew(sizeof(char) * (i))))
		return (NULL);
	i = 0;
	neg = n < 0 ? 1 : 0;
	nb = n < 0 ? n * -1 : n;
	if (neg)
		str[i++] = '-';
	while (nb)
	{
		str[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (neg)
		ft_strrev(str + 1, 0);
	else
		ft_strrev(str, 0);
	return (str);
}
