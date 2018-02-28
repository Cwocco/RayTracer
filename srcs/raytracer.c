/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:47:44 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/02/28 12:47:05 by ada-cunh         ###   ########.fr       */
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
			if (SEPIA == 1)
				sepia(&c);
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

//t_color sepia(t_color *new, t_color *c)

t_color		raytrace(t_ray r, t_env *env)
{
	t_intersection	inter;
	t_color			c;
/*	t_object *tamer;
	
    tamer = (t_object*)malloc(sizeof(t_object));
    tamer->next = NULL;
    tamer->type = hyperboloid;
	tamer->pos.x = 0;
	tamer->pos.y = 0;
	tamer->pos.z = 2000;
    tamer->pos = (t_point){ .x = 0, .y = 0, .z = 200};
//  tamer->mater.specular = (t_color){ .r = 255, .g = 255, .b = 255, .a = 1};
    tamer->mater.ambient = (t_color){ .r = 255, .g = 0, .b = 0, .a = 1};
//	tamer->mater.diffuse = (t_color){ .r = 255, .g = 255, .b = 255, .a = 1};
    env->scene.objs = tamer;
*/
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
