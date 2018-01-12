/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 12:39:42 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/01/12 12:15:21 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "vector_utility.h"
#include "intersection.h"

t_color     lights(t_point inter, t_env *env, t_object *obj)
{
	t_degueulasse tmp;
	t_ray r;
	t_color c;

	tmp.l = env->scene.lgts;
	c = obj->color;
	while (tmp.l != NULL)
	{
		tmp.l->color = (t_color){255, 255, 255, 1};
		tmp.l_pos = tmp.l->pos;
		tmp.o = env->scene.objs;
		tmp.s_ray = calc_vector(tmp.l_pos, inter);
		normalize_vector(&tmp.s_ray.pos);
		r = calc_vector(obj->pos, inter);
		normalize_vector(&r.pos);
		//      env->scene.prim_r = get_shadow_ray(inter, env->scene.prim_r.dir);
		//      normalize_vector(&env->scene.prim_r.dir);
		tmp.angle = get_angle(tmp.s_ray.pos, r.pos);
		while (tmp.o != NULL)
		{
			set_color(tmp.o);
			if (intersection(tmp.s_ray, tmp.o, &tmp.final_inter))
			{
				if (tmp.angle <= 0)
					c = ((t_color){0, 0, 0, 1});
				//if (tmp.angle > 0)			
				else if (calc_dist(tmp.final_inter, inter) > calc_dist(inter, tmp.l_pos))
				{
					c.r =  (tmp.o->mater.diffuse.r * tmp.l->color.r) * (tmp.angle) / 255;
					c.g = (tmp.o->mater.diffuse.g * tmp.l->color.g) * (tmp.angle) / 255;
					c.b = (tmp.o->mater.diffuse.b * tmp.l->color.b) * (tmp.angle) / 255;
				}
			}
			tmp.o = tmp.o->next;
		}
		tmp.l = tmp.l->next;
	}
	return (c);
}

t_ray       calc_vector(t_point a, t_point b)
{
	t_ray ab;

	ab.pos.x = b.x - a.x;
	ab.pos.y = b.y - a.y;
	ab.pos.z = b.z - a.z;
	return (ab);
}

void        set_color(t_object *o)
{
	o->color = (t_color){0, 150, 200, 0};
	o->mater.specular = (t_color){255, 255, 255, 1};
	o->mater.ambient = (t_color){255, 255, 255, 1};
	o->mater.diffuse = (t_color){0, 0, 255, 1};
}
