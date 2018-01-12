/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 22:23:27 by nboste            #+#    #+#             */
/*   Updated: 2016/10/08 11:21:50 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	unsigned int	val;

	if (nb < 0)
	{
		ft_putchar('-');
		val = nb * -1;
	}
	else
	{
		val = nb;
	}
	if (val > 9)
	{
		ft_putnbr(val / 10);
		ft_putchar(val % 10 + '0');
	}
	else
	{
		ft_putchar(val + '0');
	}
}
