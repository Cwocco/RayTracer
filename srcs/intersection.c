/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 20:38:35 by nboste            #+#    #+#             */
/*   Updated: 2018/01/12 13:43:49 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "vector_utility.h"

static double	get_delta(double a, double b, double c)
{
	return (b * b - 4 * a * c);
}

static double dotProduct(t_point p1, t_point p2)
{
	double n1;
	double n2;

	normalize_vector(&p1);
	normalize_vector(&p2);
	n1 = get_norm(p1);
	n2 = get_norm(p2);
	return (p1.x * p2.x + p1.y * p2.y + p1.z * p2.z);
}

static t_bool   inter_cylinder(t_ray r, t_object *obj, t_point *inter)
{
	t_point pos;
	t_point dir;
	t_point poly;
	double  delta;

	dir = r.dir;
	pos = r.pos;
	poly.x = (dir.x * dir.x + dir.y * dir.y);
	poly.y = 2 * dir.x * (pos.x - obj->pos.x) + 2 * dir.y * (pos.y - obj->pos.y);
	poly.z = pow(pos.x - obj->pos.x, 2) + pow(pos.y - obj->pos.y, 2) - pow(obj->radius, 2);
	delta = get_delta(poly.x, poly.y, poly.z);
	if (delta < 0)
		return (0);
	else
	{
		inter->x = (-poly.y + sqrt(delta)) / (2 * poly.x);
		inter->y = (-poly.y - sqrt(delta)) / (2 * poly.x);
		if (inter->x < inter->y)
		{
			inter->y = r.pos.y + r.dir.y * inter->x;
			inter->z = r.pos.z + r.dir.z * inter->x;
			inter->x = r.pos.x + r.dir.x * inter->x;
		}
		else
		{
			inter->x = r.pos.x + r.dir.x * inter->y;
			inter->z = r.pos.z + r.dir.z * inter->y;
			inter->y = r.pos.y + r.dir.y * inter->y;
		}
		return (1);
	}
}

static t_bool          inter_cone(t_ray r, t_object *obj, t_point *inter)
{
	t_point pos;
	t_point dir;
	t_point poly;
	double  delta;

	dir = r.dir;
	pos = r.pos;
	poly.x = (dir.x * dir.x) + (dir.y * dir.y) - (dir.z * dir.z);
	poly.y = 2 * ((dir.x * (pos.x - obj->pos.x)) + (dir.y * (pos.y - obj->pos.y)) - (dir.z * (pos.z - obj->pos.z)));
	poly.z = pow(pos.x - obj->pos.x, 2) + pow(pos.y - obj->pos.y, 2) - pow(pos.z - obj->pos.z, 2);
	delta = get_delta(poly.x, poly.y, poly.z);
	if (delta < 0)
		return (0);
	else
	{
		inter->x = (-poly.y + sqrt(delta)) / (2 * poly.x);
		inter->y = (-poly.y - sqrt(delta)) / (2 * poly.x);
		if (inter->x < inter->y)
		{
			inter->y = r.pos.y + r.dir.y * inter->x;
			inter->z = r.pos.z + r.dir.z * inter->x;
			inter->x = r.pos.x + r.dir.x * inter->x;
		}
		else
		{
			inter->x = r.pos.x + r.dir.x * inter->y;
			inter->z = r.pos.z + r.dir.z * inter->y;
			inter->y = r.pos.y + r.dir.y * inter->y;
		}
		return (1);
	}
}

static t_bool	inter_sphere(t_ray r, t_object *obj, t_point *inter)
{
	t_point		dir;
	t_point		pos;
	t_point		opos;
	t_point		poly;
	double		delta;

	dir = r.dir;
	pos = r.pos;
	opos = obj->pos;
	poly.x = (dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
	poly.y = 2 * (dir.x * (pos.x - opos.x) + dir.y * (pos.y - opos.y) + dir.z * (pos.z - opos.z));
	poly.z = (pow(pos.x + opos.x, 2) + pow(pos.y - opos.y, 2) + pow(pos.z - opos.z, 2) - (obj->radius * obj->radius));
	delta = get_delta(poly.x, poly.y, poly.z);
	if (delta < 0)
		return (0);
	else
	{
		inter->x = (-poly.y + sqrt(delta)) / (2 * poly.x);
		inter->y = (-poly.y - sqrt(delta)) / (2 * poly.x);
		if (inter->x < inter->y)
		{
			inter->y = r.pos.y + r.dir.y * inter->x;
			inter->z = r.pos.z + r.dir.z * inter->x;
			inter->x = r.pos.x + r.dir.x * inter->x;
		}
		else
		{
			inter->x = r.pos.x + r.dir.x * inter->y;
			inter->z = r.pos.z + r.dir.z * inter->y;
			inter->y = r.pos.y + r.dir.y * inter->y;
		}
		return (1);
	}
}

static t_bool	inter_plan(t_ray r, t_object *obj, t_point *inter)
{
	t_point		l;
	t_point		n;
	t_point		p0;
	t_point		l0;
	double		denom;

	l = r.dir;
	n = obj->normal;
	p0 = obj->pos;
	l0 = r.pos;
	denom = dotProduct(n, l);
	if (denom > 1e-9)
	{
		inter->x = r.pos.x + denom * r.dir.x;
		inter->y = r.pos.y + denom * r.dir.y;
		inter->z = r.pos.z + denom * r.dir.z;
		return 1;
	}
	return 0;
}

t_bool			intersection(t_ray r, t_object *obj, t_point *inter)
{
	if (obj->type == sphere)
		return (inter_sphere(r, obj, inter));
	else if (obj->type == plan)
		return (inter_plan(r, obj, inter));
	else if (obj->type == cylinder)
		return (inter_cylinder(r, obj, inter));
	else if (obj->type == cone)
		return (inter_cone(r, obj, inter));
	else
		return (0);
}
