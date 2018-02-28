/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:03:22 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/02/28 12:15:14 by ada-cunh         ###   ########.fr       */
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
	double c;

	new_c.r = prim_color->r;
	new_c.g = prim_color->g;
	new_c.b = prim_color->b;
	c = (prim_color->r + prim_color->g + prim_color->b) / 765.0;
	new_c.r = 243.6 * c;
    new_c.g = 145.6 * c;
    new_c.b = 44.8 * c;	
	prim_color->r = new_c.r;
	prim_color->g = new_c.g;
	prim_color->b = new_c.b;
}
