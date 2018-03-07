/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:51:28 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/07 00:09:12 by jpicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>
/*
void	inter_cylinder(t_ray r, t_object *obj, double *t)
{
	t_point pos;
	t_point dir;
	t_point poly;

	dir = (t_point){r.dir.x, r.dir.y, r.dir.z};
	pos = vector_sub(r.pos, obj->pos);
	rotate_vec(&pos, obj->rot);
	vec_rotate(&dir, obj->rot);
	poly.x = dir.x * dir.x + dir.z * dir.z;
	poly.y = 2.0 * (dir.x * pos.x + dir.z * pos.z);
	poly.z = pos.x * pos.x + pos.z * pos.z - obj->radius * obj->radius;
	return (solve_equation(poly, t));
}
*/
void	inter_cylinder(t_ray r, t_object *obj, double *t)
{
	t_point pos;
	t_point dir;
	t_point poly;

	dir = (t_point){r.dir.x, r.dir.y, r.dir.z};
	pos = vector_sub(r.pos, obj->pos);
	vec_rotate(&pos, obj->rot);
	vec_rotate(&dir, obj->rot);
	poly.x = dir.x * dir.x + dir.z * dir.z;
	poly.y = 2.0 * (pos.x * dir.x + pos.z * dir.z);
	poly.z = pos.x * pos.x + pos.z * pos.z - 10;
	return (solve_equation(poly, t));
}

void	inter_cone(t_ray r, t_object *obj, double *t)
{
    t_point pos;
    t_point dir;
    t_point poly;
//    double  radius;

    dir = (t_point){r.dir.x, r.dir.y, r.dir.z};
    pos = vector_sub(r.pos, obj->pos);
//  printf("pos.x = %f\n", pos.x);
//  printf("pos.y = %f\n", pos.y);
//  printf("pos.z = %f\n", pos.z);
	vec_rotate(&pos, obj->rot);
	vec_rotate(&dir, obj->rot);
//  printf("pos.x = %f\n", pos.x);
//  printf("pos.y = %f\n", pos.y);
//  printf("pos.z = %f\n", pos.z);
//    radius = sin(ft_degtorad(obj->radius)) * sin(ft_degtorad(obj->radius));
    poly.x = dir.x * dir.x - dir.y * dir.y + dir.z * dir.z; 
	poly.y = 2.0 * (pos.x * dir.x - pos.y * dir.y + pos.z * dir.z);
	poly.z = pos.x * pos.x - pos.y * pos.y + pos.z * pos.z;
    return (solve_equation(poly, t));
}

void	inter_sphere(t_ray r, t_object *obj, double *t)
{
	t_point		dir;
	t_point		pos;
	t_point		poly;

	dir = r.dir;
	pos = vector_sub(r.pos, obj->pos);
	poly.x = dir.x * dir.x + dir.y * dir.y + dir.z * dir.z;
	poly.y = dir.x * pos.x + dir.y * pos.y + dir.z * pos.z;
	poly.y *= 2.0;
	poly.z = pos.x * pos.x + pos.y * pos.y + pos.z * pos.z;
	poly.z -= obj->radius * obj->radius;
	return (solve_equation(poly, t));
}

void	inter_plane(t_ray r, t_object *obj, double *t)
{
	double	n;
	double	d;
	t_point	dir;
	t_point	pos;
	t_point normal;

	dir = r.dir;
	pos = vector_sub(r.pos, obj->pos);
	normal = obj->normal;
	n = normal.x * pos.x + normal.y * pos.y + normal.z * pos.z;
	d = normal.x * dir.x + normal.y * dir.y + normal.z * dir.z;
	*t = -n / d > 0.000001 ? -n / d : MAX_RAY_LENGTH;
}
/*
void inter_hyper(t_ray r, t_object *obj, double *t)
{
	t_point dir;
	t_point pos;
	t_point poly;
	t_point test;

	dir = (t_point){r.dir.x, r.dir.y, r.dir.z};
	test = (t_point){ .x = 400, .y = 250, .z = 250};
//	printf("tagrossmer\n");
//	obj->pos.x = 0;
//	obj->pos.y = 0;
//	obj->pos.z = 200;
	pos = vector_sub(r.pos, obj->pos);
	poly.x = (get_sqr(dir.x) / get_sqr(test.x))
		+ (get_sqr(dir.y) / get_sqr(test.y))
		+ (get_sqr(dir.z) / get_sqr(test.z));
	poly.y = 2.0 * (((dir.x * pos.x) / get_sqr(test.x))
					+ ((dir.y * pos.y) / get_sqr(test.y))
					+ ((dir.z * pos.z) / get_sqr(test.z)));
	poly.z = (get_sqr(pos.x) / get_sqr(test.x))
		+ (get_sqr(pos.y) / get_sqr(test.y))
		+ (get_sqr(pos.z) / get_sqr(test.z)) - 1;
//	poly.x = pos.z * pos.z - pos.x * pos.x - pos.y * pos.y;
//	poly.y = 2.0 * (dir.z * pos.z - dir.x * pos.x - dir.y * pos.y);
//	poly.z = dir.z * dir.z + 10 - dir.x * dir.x - dir.y * dir.y;
	return (solve_equation(poly, t));
}
*/
t_bool	intersection(const t_env *env, t_ray r, t_object *obj, t_intersection *inter)
{
	double t;
	t_bool ret;
/*	t_object *tamer;

	tamer = (t_object*)malloc(sizeof(t_object));
	tamer->next = NULL;
	tamer->type = hyperboloid;
	tamer->pos = (t_point){ .x = 0, .y = 0, .z = 200};
	tamer->mater.specular = (t_color){ .r = 255, .g = 255, .b = 255, .a = 1};
	tamer->mater.ambient = (t_color){ .r = 255, .g = 0, .b = 0, .a = 1};
	tamer->mater.diffuse = (t_color){ .r = 255, .g = 255, .b = 255, .a = 1};
	obj = tamer;
*/
	t = MAX_RAY_LENGTH;
	ret = 0;
	while (obj != NULL)
	{
		obj->rot = env->obj_rot;
		if (obj->type == sphere)
			inter_sphere(r, obj, &t);
		else if (obj->type == plan)
			inter_plane(r, obj, &t);
		else if (obj->type == cylinder)
			inter_cylinder(r, obj, &t);
		else if (obj->type == cone)
			inter_cone(r, obj, &t);
//		else if (obj->type == hyperboloid)
//			inter_hyper(r, obj, &t);
		if (t < inter->t /*&& t > 0.000001*/)
		{
			inter->obj = *obj;
			inter->t = t;
			ret = 1;
		}
		obj = obj->next;
	}
	return (ret);
}
