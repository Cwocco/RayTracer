/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 21:50:40 by nboste            #+#    #+#             */
/*   Updated: 2016/10/08 11:27:04 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str, int idx)
{
	int		size;
	char	tmp;

	size = ft_strlen(str);
	if (idx < size / 2)
	{
		tmp = str[idx];
		str[idx] = str[size - idx - 1];
		str[size - idx - 1] = tmp;
		ft_strrev(str, idx + 1);
	}
}
