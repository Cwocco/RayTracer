/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 13:10:17 by rpinoit           #+#    #+#             */
/*   Updated: 2018/01/29 11:53:45 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "vector_utilities.h"
#include "intersection.h"
#include "math_utilities.h"

double           vector_dot(t_point a, t_point b)
{
	    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_color		process_light(t_light *lst_light, t_object *lst_obj, t_object *obj_ptr, t_point inter)
{
	t_color c;
	//	t_color shadow;
	t_ray	light_ray;
	t_tmp	tmp;
	t_color ambient;
	t_intersection tmp_inter;

	tmp_inter.t = 0xffffff;
	ambient = (t_color){0.2, 0.2, 0.2, 1};
	//	shadow = (t_color){139, 139, 139, 1};
	c = (t_color){ambient.r * (obj_ptr->color.r / 255.0),
		ambient.g * (obj_ptr->color.g / 255.0),
		ambient.b * (obj_ptr->color.b / 255.0), 1};
	while (lst_light != NULL)
	{
		light_ray.pos = lst_light->pos;
		light_ray.dir = vector_sub(inter, light_ray.pos);
		normalize_vector(&light_ray.dir);
		intersection(light_ray, lst_obj, &tmp_inter);
		if (vec_dist(inter, light_ray.pos) < vec_dist(inter, tmp_inter.pos))
		{
			tmp.c = get_light_color(obj_ptr, inter, lst_light);
			c.r += tmp.c.r;
			c.g += tmp.c.g;
			c.b += tmp.c.b;
		}
		lst_light = lst_light->next;
	}
	return (c);
}

t_color		get_light_color(t_object *object, t_point inter, t_light *light)
{
	t_ray	light_vector;
	t_color	c;
	double	angle;

	light_vector.pos = vector_sub(inter, light->pos);
	normalize_vector(&light_vector.pos);
	object->normal_vector.pos = vector_sub(object->pos, inter);
//	if (object->type == cone)
//		object->normal_vector.pos.z *= -1;
//	if (object->type == cylinder)
//		object->normal_vector.pos.z = 0;
	normalize_vector(&object->normal_vector.pos);
	angle = vector_dot(light_vector.pos, object->normal_vector.pos);
	if (angle <= 0)
		c = (t_color){0, 0, 0, 1};
	else
	{
		c.r = (255.0 / 255.0) * (255.0 / 255.0) * angle;
		c.g = (255.0 / 255.0) * (255.0 / 255.0) * angle;
		c.b = (255.0 / 255.0) * (255.0 / 255.0) * angle;
	}
	return (c);
}

t_point       calc_vector(t_point a, t_point b)
{
	t_point pos;

	pos.x = b.x - a.x;
	pos.y = b.y - a.y;
	pos.z = b.z - a.z;
	return (pos);
}
/*
   double           vect_norm(t_vector *a)
   {
   return (SQRT(a->x * a->x + a->y * a->y + a->z * a->z));
   } */
