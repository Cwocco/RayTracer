/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 18:49:23 by nboste            #+#    #+#             */
/*   Updated: 2016/10/08 11:01:01 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned int	tmp;
	int				neg;

	neg = 1;
	tmp = 0;
	while ((*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
				|| *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		tmp = tmp * 10 + *str - '0';
		str++;
	}
	return ((int)(tmp * neg));
}
