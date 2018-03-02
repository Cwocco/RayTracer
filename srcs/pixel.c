/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:03:22 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/02 17:58:21 by ada-cunh         ###   ########.fr       */
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
	t_color	new_c;
	double	c;

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

void		fifty_shades_of_grey(t_color *prim_color)
{
	t_color	new_c;
	double	c;

	new_c.r = prim_color->r;
	new_c.g = prim_color->g;
	new_c.b = prim_color->b;
	c = (prim_color->r * 76.5 * 2
		+ prim_color->g * 76.5 * 2
		+ prim_color->b * 28.05 * 2) / 765.0;
	new_c.r = get_val(c, 0.0, 255.0);
	new_c.g = get_val(c, 0.0, 255.0);
	new_c.b = get_val(c, 0.0, 255.0);
	prim_color->r = new_c.r;
	prim_color->g = new_c.g;
	prim_color->b = new_c.b;
}

//ntmgithub
void		daltonism(t_color *prim_color)
{
	t_color new_c;
	double	tmp_g;

	new_c.r = prim_color->r;
	new_c.g = prim_color->g;
	new_c.b = prim_color->b;
	if (new_c.g > new_c.r && new_c.g > new_c.b)
	{
		tmp_g = new_c.g;
		new_c.g = new_c.b >= new_c.r ? new_c.r : new_c.b;
		new_c.b = tmp_g;
		new_c.r = tmp_g;
	}
	else if (new_c.g == new_c.r || new_c.g == new_c.b)
		new_c.g = 0;
	prim_color->r = new_c.r;
	prim_color->g = new_c.g;
	prim_color->b = new_c.b;
}

double		get_val(double val, double min, double max)
{
	if (val < min)
		val = min;
	if (val > max)
		val = max;
	return (val);
}
