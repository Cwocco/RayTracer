/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 13:10:17 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/10 17:53:51 by rpinoit          ###   ########.fr       */
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

static inline double	sha(t_env *env, t_light *light,
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

t_color					process_light(t_env *env, t_intersection *inter,
		t_ray r)
{
	t_object	*lst_obj;
	t_light		*lst_light;
	t_color		c;
	double		tmp[2];

	lst_light = env->scene.lgts;
	lst_obj = env->scene.objs;
	get_texture(&c, inter, &r);
	get_texture(&inter->obj.mater.diffuse, inter, &r);
	get_texture(&inter->obj.mater.specular, inter, &r);
	set_ambient_light(&c, inter->obj);
	while (env->ambilight == 0 && lst_light)
	{
		if (env->shadow == 0 || (tmp[1] = sha(env, lst_light, inter, lst_obj)))
		{
			inter->light_vector = vector_sub(lst_light->pos, inter->pos);
			normalize_vector(&inter->light_vector);
			tmp[0] = dot_product(inter->normal, inter->light_vector);
			if (tmp[0] >= 0 && tmp[0] <= 1)
				add_diffuse_light(&c, inter->obj, lst_light, tmp);
			add_specular_light(&c, r.pos, inter, tmp[1]);
		}
		lst_light = lst_light->next;
	}
	return (c);
}
