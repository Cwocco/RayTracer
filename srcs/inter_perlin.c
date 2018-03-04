/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_perlin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:04:59 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/04 16:00:18 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perlin.h"

// Outputs data change needed to try somethings cf tuto
void inter_perlin(t_ray *r, t_intersection *inter, t_color *c)
{
	double	noise_coef;
	int		lvl;
	t_point	pos;
	t_point	vec;

	noise_coef = 0;
	lvl = 1;
	pos = vector_add(r->pos, vector_multiply(r->dir, inter->t));
	vec.x = pos.x * 0.5;
	vec.y = pos.y * 0.5;
	vec.z = pos.z * 0.5;
	while (++lvl < 10)
		noise_coef += (1.0 / lvl) * fabs(noise3(vec));
//	noise_coef = 0.8 * sin((pos.x + pos.y) * 0.05 + noise_coef) + 0.9;
	noise_coef = 2.0 * sin((pos.x + pos.y) * 0.05 + noise_coef) + 0.9;
	c->r += inter->obj.color.r * noise_coef;
	c->g += inter->obj.color.g * noise_coef;
	c->b += inter->obj.color.b * noise_coef;
}

// Check outputs value cf tuto
void marble_perlin(t_ray *r, t_intersection *inter, t_color *c)
{
	double	noise_coef;
	int		lvl;
	t_point	pos;
	t_point	vec;

	noise_coef = 0;
	lvl =1;
	pos = vector_add(r->pos, vector_multiply(r->dir, inter->t));
	vec.x = pos.x * 5;
	vec.y = pos.y * 5;
	vec.z = pos.z * 5;
	while (++lvl < 10)
		noise_coef +=  (1.0 / lvl)  * fabs(noise3(vec));
	noise_coef = 0.5 * sin((pos.x + pos.y) * 0.05 + noise_coef) + 0.5;
	c->r += inter->obj.color.r * noise_coef + (1.0 - noise_coef);
    c->g += inter->obj.color.g * noise_coef + (1.0 - noise_coef);
    c->b += inter->obj.color.b * noise_coef + (1.0 - noise_coef);
}

void get_texture(t_color *c, t_intersection *inter, t_ray *r)
{
	if (TEXTURE == 1)
		inter_perlin(r, inter, c);
	else if (TEXTURE == 2)
		marble_perlin(r, inter, c);
	else if (TEXTURE == 0)
		return ;
}
