/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:03:57 by nboste            #+#    #+#             */
/*   Updated: 2018/01/12 12:03:32 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "drawer.h"
#include <math.h>
#include "vector_utility.h"
#include "intersection.h"
#include "error.h"
#include "light.h"

void	raytracer_process(t_env *env)
{
	t_2ipair	i;
	t_ray		r;
	t_color		c;

	i.x = 0;
	while (i.x < env->rend.size.x)
	{
		i.y = 0;
		while (i.y < env->rend.size.y)
		{
			r = get_prim_ray(i, env);
			c = raytrace(r, env);
			drawer_putpixel(env, i, c);
			i.y++;
		}
		i.x++;
	}
}

t_ray	get_prim_ray(t_2ipair p, t_env *env)
{
	t_camera	*cam;
	t_ray		r;

	cam = &env->scene.cam;
	r.dir.x = cam->d * cam->uvn.n.x - (cam->near.x / 2) * cam->uvn.u.x + (cam->near.y / 2) * cam->uvn.v.x + (((double)p.x + 0.5) * cam->step.x) * cam->uvn.u.x - (((double)p.y + 0.5) * cam->step.y) * cam->uvn.v.x;
	r.dir.y = cam->d * cam->uvn.n.y - (cam->near.x / 2) * cam->uvn.u.y + (cam->near.y / 2) * cam->uvn.v.y + (((double)p.x + 0.5) * cam->step.x) * cam->uvn.u.y - (((double)p.y + 0.5) * cam->step.y) * cam->uvn.v.y;
	r.dir.z = cam->d * cam->uvn.n.z - (cam->near.x / 2) * cam->uvn.u.z + (cam->near.y / 2) * cam->uvn.v.z + (((double)p.x + 0.5) * cam->step.x) * cam->uvn.u.z - (((double)p.y + 0.5) * cam->step.y) * cam->uvn.v.z;
	normalize_vector(&r.dir);
	r.pos = cam->pos;
	r.depth = MAX_RAY_DEPTH;
	return (r);
}

static double	vec_dist(t_point p1, t_point p2)
{
	return (sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y) + (p2.z - p1.z) * (p2.z - p1.z)));
}

t_color			raytrace(t_ray r, t_env *env)
{
	t_object	*obj;
	t_point		inter;
	double		dist;
	t_color		c;

	c = (t_color){0, 0, 0, 1};
	dist = 0xfffff;
	obj = env->scene.objs;
	while (obj != NULL)
	{
		if (intersection(r, obj, &inter))
		{
			if (vec_dist(inter, r.pos) < dist)
			{
				dist = vec_dist(inter, r.pos);
				c = lights(inter, env, obj);
			}
		}
		obj = obj->next;
	}
	return c;
}
