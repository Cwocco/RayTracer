/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:43:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/08 18:04:57 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *str)
{
	double	res;
	double	factor;
	int		sign;

	res = 0.0;
	sign = 1.0;
	factor = 1.0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		sign = (*str++ == '-') ? -1 : 1;
	while (ft_isdigit(*str))
		res = res * 10.0 + (double)(*str++ - '0');
	if (*str == '.')
		while (ft_isdigit(*++str) && (factor /= 10))
			res += factor * (double)(*str - '0');
	if (*str == 'e' || *str == 'E')
		return (res * sign * ft_pow(10.0, (double)ft_atoi(++str)));
	return (res * sign);
}
