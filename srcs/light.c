/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 13:10:17 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/10 17:22:07 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "light.h"
#include "math_utilities.h"
#include "vector_utilities.h"
#include "intersection.h"
#include "perlin.h"
#include "vector_utilities.h"

/*
**No object obstructing light
*/

static inline double	check_obstruct(t_env *env, t_light *light,
					t_intersection *inter, t_object *lst_obj)
{
	t_intersection	new_inter;
	t_ray			light_ray;
	double			light_distance;

	new_inter.t = MAX_RAY_LENGTH;
	light_ray.pos = inter->pos;
	light_ray.dir = vector_sub(light->pos, inter->pos);
	light_distance = vector_len(light_ray.dir);
	normalize_vector(&light_ray.dir);
	intersection(env, light_ray, lst_obj, &new_inter);
	if (new_inter.t < light_distance)
		return (new_inter.obj.refraction > 0 ? new_inter.obj.refraction : 0);
	return (1);
}

t_color				process_light(t_env *env, t_intersection *inter, t_ray r)
{
	t_object	*lst_obj;
	t_light		*lst_light;
	t_color		c;
	double		coef;
	double		cos_teta;

	lst_light = env->scene.lgts;
	lst_obj = env->scene.objs;
	get_texture(&c, inter, &r);
	get_texture(&inter->obj.mater.diffuse, inter, &r);
	get_texture(&inter->obj.mater.specular, inter, &r);
	set_ambient_light(&c, inter->obj);
	while (env->ambilight == 0 && lst_light)
	{
		if (env->shadow == 0 || (coef = check_obstruct(env, lst_light, inter, lst_obj)) > 0)
		{
			inter->light_vector = vector_sub(lst_light->pos, inter->pos);
			normalize_vector(&inter->light_vector);
			cos_teta = dot_product(inter->normal, inter->light_vector);
			if (cos_teta >= 0 && cos_teta <= 1)
				add_diffuse_light(&c, inter->obj, lst_light, cos_teta, coef);
			add_specular_light(&c, r.pos, inter, coef);
		}
		lst_light = lst_light->next;
	}
	return (c);
}
