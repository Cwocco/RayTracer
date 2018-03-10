/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_damier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:37:44 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/10 14:49:42 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "perlin.h"

#define DAM_SIZE 7

void	set_damier(t_point *p, t_color *c)
{
	t_3ipair	pos;
	t_color		c1;
	t_color		c2;

	c1 = (t_color){0.0, 0.0, 0.0, 1};
	c2 = (t_color){255.0, 255.0, 255.0, 1};
	pos = (t_3ipair){round(p->x / (double)DAM_SIZE),
				round(p->y / (double)DAM_SIZE),
				round(p->z / (double)DAM_SIZE)};
	if (pos.x % 2 == 0)
	{
		if (((pos.y % 2 == 0) && (pos.z % 2 == 0)) ||
			(((pos.y % 2 != 0) && (pos.z % 2 != 0))))
			*c = c2;
		else
			*c = c1;
	}
	else
	{
		if ((((pos.y % 2 == 0) && (pos.z % 2 == 0))) ||
			(((pos.y % 2 != 0) && (pos.z % 2 != 0))))
			*c = c1;
		else
			*c = c2;
	}
}
