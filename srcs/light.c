/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 13:10:17 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/06 11:15:27 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			check_distance_between_light_and_intersection(t_point light_pos,
		t_point inter_pos)
{
	double distance;

	if (light_pos.x == 0 && light_pos.y == 0 && light_pos.z == 0)
	{
		distance = vector_len(vector_sub(light_pos, inter_pos));
		distance = distance < 0 ? -distance : distance;
		if (distance < 10.000001)
		{
			printf("distance = %f\n", distance);
			return (1);
		}
	}
	return (0);
}

int			no_object_obstructing_light(const t_env *env, t_light *light, t_intersection *inter,
		t_object *lst_obj)
{
	t_intersection	new_inter;
	t_ray			light_ray;
	double			light_distance;

//	if (check_distance_between_light_and_intersection(light->pos, inter->pos))
//			return (0);
	new_inter.t = MAX_RAY_LENGTH;
	light_ray.pos = inter->pos;
	light_ray.dir = vector_sub(light->pos, inter->pos);
	light_distance = vector_len(light_ray.dir);
	normalize_vector(&light_ray.dir);
	intersection(env, light_ray, lst_obj, &new_inter);
	if (new_inter.t < light_distance)
		return (0);
	return (1);
}

t_color		process_light(const t_env *env, t_light *lst_light, t_object *lst_obj,
		t_intersection *inter, t_ray r)
{
	t_color c;
	double	cos_teta;

	set_ambient_light(&c, inter->obj);
	get_texture(&c, inter, &r);
	get_texture(&inter->obj.mater.diffuse, inter, &r);
	get_texture(&inter->obj.mater.specular, inter, &r);
//	inter->normal = get_normal(inter, env->scene.objs);
	while (lst_light)
	{
		if (no_object_obstructing_light(env, lst_light, inter, lst_obj))
		{
			inter->light_vector = vector_sub(lst_light->pos, inter->pos);
			normalize_vector(&inter->light_vector);
			cos_teta = dot_product(inter->normal, inter->light_vector);
			if (cos_teta >= 0 && cos_teta <= 1)
							add_diffuse_light(&c, inter->obj, lst_light, cos_teta);
			add_specular_light(&c, r.pos, inter);		
		}
		lst_light = lst_light->next;
	}
	return (c);
}
