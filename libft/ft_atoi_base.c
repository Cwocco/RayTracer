/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:29:16 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/16 16:57:11 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *str, int str_base)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	if (str_base <= 1 || str_base > 16)
		return (0);
	ft_isspace(str);
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str <= '9' && *str >= '0' && *str - '0' < str_base)
			result = result * str_base + *str - '0';
		else if (*str >= 'A' && *str <= 'F' && *str - 'A' + 10 < str_base)
			result = result * str_base + (*str - 'A' + 10);
		else if (*str >= 'a' && *str <= 'f' && *str - 'a' + 10 < str_base)
			result = result * str_base + (*str - 'a' + 10);
		else
			return (0);
		str++;
	}
	return (result * sign);
}
