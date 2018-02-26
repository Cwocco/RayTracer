/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:24:30 by rpinoit           #+#    #+#             */
/*   Updated: 2018/02/26 14:18:43 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		get_final_color(t_color *c)
{
	c->r = fmin(c->r, 1.0) * 255.0;
	c->g = fmin(c->g, 1.0) * 255.0;
	c->b = fmin(c->b, 1.0) * 255.0;
}

void		sepia(t_color *prim_color)
{
	t_color new_c;

//	new_c = (t_color){0, 0, 0, 1};
	new_c.r = prim_color->r;
	new_c.g = prim_color->g;
	new_c.b = prim_color->b;
	new_c.r += 174.0 / 255;
    new_c.g += 137.0 / 255;
    new_c.b += 100.0 / 255;
	new_c.r /= 2;
	new_c.g /= 2;
	new_c.b /= 2;
	prim_color->r = new_c.r;
	prim_color->g = new_c.g;
	prim_color->b = new_c.b;
}
