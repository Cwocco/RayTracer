/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 13:10:17 by rpinoit           #+#    #+#             */
/*   Updated: 2018/01/29 19:06:54 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "vector_utilities.h"
#include "intersection.h"
#include "math_utilities.h"
#include "obj_normal.h"

double           get_cos(t_point a, t_point b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double			vector_norm(t_point a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

int				no_object_obstructing_light(t_light *light, t_intersection *inter, t_object *lst_obj)
{
	t_intersection	new_inter;
	t_ray			light_ray;
	double			light_distance;

	new_inter.t = MAX_RAY_LENGTH;
	light_ray.pos = inter->pos;
	light_ray.dir = vector_sub(light->pos, inter->pos);
	light_distance = vector_norm(light_ray.dir);
	intersection(light_ray, lst_obj, &new_inter);
	if (new_inter.t <= light_distance)
		return (0);
	return (1);
}

void		add_diffuse_light(t_color *c, t_object *obj, t_light *light, double cos)
{
	c->r += cos * (obj->mater.diffuse.r / 255.0) * (light->color.r / 255.0);
	c->g += cos * (obj->mater.diffuse.g / 255.0) * (light->color.g / 255.0);
	c->b += cos * (obj->mater.diffuse.b / 255.0) * (light->color.b / 255.0);
}

t_color		process_light(t_light *lst_light, t_object *lst_obj, t_intersection *inter)
{
	t_color c;
	t_color ambient;
	t_point	normal;
	t_point	light_vector;
	double	cos_angle;

	// c = ambient_light();
	ambient = (t_color){0.1, 0.1, 0.1, 1};
	c = (t_color){ambient.r * (inter->obj->color.r / 255.0),
		ambient.g * (inter->obj->color.g / 255.0),
		ambient.b * (inter->obj->color.b / 255.0), 1};
	normal = (t_point){0, 0, 0};
	normal = get_normal(normal, inter);
	normalize_vector(&normal);
	while (lst_light)
	{
		if (no_object_obstructing_light(lst_light, inter, lst_obj))
		{
			light_vector = vector_sub(lst_light->pos, inter->pos);
			normalize_vector(&light_vector);
			cos_angle = get_cos(normal, light_vector);
			if (cos_angle > 0)
				add_diffuse_light(&c, inter->obj, lst_light, cos_angle);
		}
		lst_light = lst_light->next;
	}
	return (c);
}
