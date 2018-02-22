/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:47:44 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/02/21 13:18:56 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

#define ANTI 0

void		raytracer_process(t_env *env)
{
	t_point		win_pos;
	t_ray		r;
	t_color		c;

	win_pos.x = 0;
	while (win_pos.x < env->win_w)
	{
		win_pos.y = 0;
		while (win_pos.y < env->win_h)
		{
			if (ANTI == 1)
				c = anti_aliasing_rt(win_pos, env);
			else
			{
				r = get_prim_ray(win_pos, env);
				c = raytrace(r, env);
			}
			put_pixel(env, &win_pos, c);
			win_pos.y++;
		}
		win_pos.x++;
	}
}

t_ray		get_prim_ray(t_point p, t_env *env)
{
	t_camera	*cam;
	t_ray		r;

	cam = &env->scene.cam;
	r.dir.x = p.x - (env->win_w / 2);
	r.dir.y = p.y - (env->win_h / 2);
	r.dir.z = cam->d;
	normalize_vector(&r.dir);
	r.pos = cam->pos;
	rotate_vec(&r.dir, env->cam_rot);
	normalize_vector(&r.dir);
	r.depth = MAX_RAY_DEPTH;
	return (r);
}

t_color		raytrace(t_ray r, t_env *env)
{
	t_intersection	inter;
	t_color			c;

	c = (t_color){ .r = 0.0, .g = 0.0, .b = 0.0, .a = 1};
	inter.t = MAX_RAY_LENGTH;
	if (intersection(env, r, env->scene.objs, &inter))
	{
		inter.pos = vector_add(r.pos, vector_multiply(r.dir, inter.t)); //+ reflect * EPSILON;
		inter.normal = get_normal(&inter);
		c = process_light(env, env->scene.lgts, env->scene.objs, &inter, r);
		get_final_color(&c);
	}
	return (c);
}
