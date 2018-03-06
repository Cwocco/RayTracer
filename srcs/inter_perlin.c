/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_perlin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:04:59 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/06 17:33:02 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perlin.h"

void	bump_mapping(t_intersection *inter, const t_ray *r)
{
	t_point	noise_coef;
	double	bump_coef; // Parser add needed
	t_point	vec;
	t_point *n;

	bump_coef = 0.5;
	n = &inter->normal;
	vec = vector_add(r->pos, vector_multiply(r->dir, inter->t));
	noise_coef.x = noise3((t_point){0.1 * vec.x, 0.1 * vec.y, 0.1 * vec.z});
	noise_coef.y = noise3((t_point){0.1 * vec.y, 0.1 * vec.z, 0.1 * vec.x});
	noise_coef.z = noise3((t_point){0.1 * vec.z, 0.1 * vec.x, 0.1 * vec.y});
	n->x = (1.0 - bump_coef) * n->x + bump_coef * noise_coef.x;
	n->y = (1.0 - bump_coef) * n->y + bump_coef * noise_coef.y;
	n->z = (1.0 - bump_coef) * n->z + bump_coef * noise_coef.z;
	normalize_vector(n);
}

// Outputs data change needed to try somethings cf tuto
void	inter_perlin(t_ray *r, t_intersection *inter, t_color *c)
{
	double	noise_coef;
	int		lvl;
	t_point	pos;
	t_point	vec;

	noise_coef = 0;
	lvl = 1;
	pos = vector_add(r->pos, vector_multiply(r->dir, inter->t));
//	vec.x = pos.x * 0.9;
//	vec.y = pos.y * 0.9;
//	vec.z = pos.z * 0.9;
	vec.x = pos.x * 0.5;
	vec.y = pos.y * 0.5;
	vec.z = pos.z * 0.5;
	while (++lvl < 10)
		noise_coef += (1.0 / lvl) * fabs(noise3(vec));
//	noise_coef = 0.9 * sin((pos.x + pos.y) * 0.05 + noise_coef) + 0.1;
	noise_coef = 0.8 * sin((pos.x + pos.y) * 0.05 + noise_coef) + 0.9;
	c->r *= noise_coef;
	c->g *= noise_coef;
	c->b *= noise_coef;
//	c->r = c->r > 255.0 ? 255.0 : c->r;
//	c->g = c->g > 255.0 ? 255.0 : c->g;
//	c->b = c->b > 255.0 ? 255.0 : c->b;
//	c->r = c->r < 0.0 ? 0.0 : c->r;
//	c->g = c->g < 0.0 ? 0.0 : c->g;
//	c->b = c->b < 0.0 ? 0.0 : c->b;
}

// Check outputs value cf tuto
void	marble_perlin(t_ray *r, t_intersection *inter, t_color *c)
{
	double	noise_coef;
	int		lvl;
	t_point	pos;
	t_point	vec; 

	noise_coef = 0;
	lvl = 1;
	pos = vector_add(r->pos, vector_multiply(r->dir, inter->t));
	while (++lvl < 10)
	{
		vec.x = pos.x * 0.05 * lvl;
		vec.y = pos.y * 0.05 * lvl;
		vec.z = pos.z * 0.05* lvl;
		noise_coef +=  (1.0 / lvl)  * fabs(noise3(vec));
	}
	noise_coef = 0.5 * sin((pos.x + pos.y) * 0.05 + noise_coef) + 0.5;
//	noise_coef = 0.9 * sin((pos.x + pos.y) * 0.05 + noise_coef);
	c->r = c->r * noise_coef + (1.0 - noise_coef);
	c->g = c->g * noise_coef + (1.0 - noise_coef);
	c->b = c->b * noise_coef + (1.0 - noise_coef);
//	c->r = c->r > 255.0 ? 255.0 : c->r;
//	c->g = c->g > 255.0 ? 255.0 : c->g;
//	c->b = c->b > 255.0 ? 255.0 : c->b;
//	c->r = c->r < 0.0 ? 0.0 : c->r;
//	c->g = c->g < 0.0 ? 0.0 : c->g;
//	c->b = c->b < 0.0 ? 0.0 : c->b;
}

void	get_texture(t_color *c, t_intersection *inter, t_ray *r)
{
	if (TEXTURE == 0)
		return ;
	else if (TEXTURE == 1)
		inter_perlin(r, inter, c);
	else if (TEXTURE == 2)
		marble_perlin(r, inter, c);
}
