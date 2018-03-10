/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:47:44 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/10 13:54:30 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "perlin.h"
#include "anti_alias.h"
#include "light.h"
#include "raytracer.h"
#include "obj_normal.h"
#include "vector_utilities.h"
#include "intersection.h"
#include "pixel.h"
#include "vector_rotate.h"

void		*raytracer_process(t_thenv *thenv)
{
	t_point		win_pos;
	t_ray		r;
	t_color		c;

	win_pos.x = 0;
	while (win_pos.x < thenv->env->win_w)
	{
		win_pos.y = thenv->from_y;
		while (++win_pos.y < thenv->to_y)
		{
			if (ANTI == 1)
				c = anti_aliasing_rt(win_pos, thenv->env);
			else
			{
				r = get_prim_ray(win_pos, thenv->env);
				c = raytrace(r, thenv->env);
			}
			if (SEPIA == 1)
				sepia(&c);
			else if (FIFTYSHADES == 1)
				fifty_shades_of_grey(&c);
			else if (DALTO == 1)
				daltonism(&c);
			put_pixel(thenv->env, &win_pos, c);
		}
		win_pos.x++;
	}
	pthread_exit(NULL);
}

t_ray		get_prim_ray(const t_point p, const t_env *env)
{
	t_camera const	*cam;
	t_ray			r;

	cam = &env->scene.cam;
	r.dir.x = p.x - (env->win_w / 2);
	r.dir.y = p.y - (env->win_h / 2);
	r.dir.z = cam->d;
	normalize_vector(&r.dir);
	r.pos = cam->pos;
	vec_rotate(&r.dir, env->cam_rot);
	normalize_vector(&r.dir);
	r.depth = MAX_RAY_DEPTH;
	return (r);
}

t_color		raytrace(const t_ray r, t_env *env)
{
	t_intersection	inter;
	t_color			c;

	c = (t_color){ .r = 0.0, .g = 0.0, .b = 0.0, .a = 1};
	inter.t = MAX_RAY_LENGTH;
	if (intersection(env, r, env->scene.objs, &inter))
	{
		inter.pos = vector_add(r.pos, vector_multiply(r.dir, inter.t));
		inter.normal = get_normal(&inter);
		if (TEXTURE == 3)
			bump_mapping(&inter, &r);
		c = process_light(env, &inter, r);
		get_final_color(&c);
	}
	return (c);
}
