/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:32:48 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/10 13:49:44 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ellipse.h"
#include "math_utilities.h"
#include "vector_utilities.h"

t_point	ellipse_normal(t_intersection *inter)
{
	t_point	normal;

	normal = vector_sub(inter->pos, inter->obj.pos);
	normal.x = 0;
	normalize_vector(&normal);
	return (normal);
}

void	inter_ellipse(t_ray r, t_object *obj, double *t)
{
	t_point dir;
	t_point pos;
	t_point poly;
	t_point test;

	dir = (t_point){r.dir.x, r.dir.y, r.dir.z};
	test = (t_point){ .x = 40, .y = 25, .z = 25};
	pos = vector_sub(r.pos, obj->pos);
	poly.x = (get_sqr(dir.x) / get_sqr(test.x))
		+ (get_sqr(dir.y) / get_sqr(test.y))
		+ (get_sqr(dir.z) / get_sqr(test.z));
	poly.y = 2.0 * (((dir.x * pos.x) / get_sqr(test.x))
			+ ((dir.y * pos.y) / get_sqr(test.y))
			+ ((dir.z * pos.z) / get_sqr(test.z)));
	poly.z = (get_sqr(pos.x) / get_sqr(test.x))
		+ (get_sqr(pos.y) / get_sqr(test.y))
		+ (get_sqr(pos.z) / get_sqr(test.z)) - 10;
	return (solve_equation(poly, t));
}
