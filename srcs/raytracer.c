/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:47:44 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/02/14 15:08:20 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		raytracer_process(t_env *env)
{
	t_2ipair	win_pos;
	t_ray		r;
	t_color		c;

	win_pos.x = 0;
	while (win_pos.x < env->rend.size.x)
	{
		win_pos.y = 0;
		while (win_pos.y < env->rend.size.y)
		{
			r = get_prim_ray(win_pos, env);
//				(t_ray){env->scene.cam.pos,(t_point){
//						win_pos.x - (env->rend.size.x / 2),
//						win_pos.y - (env->rend.size.y / 2),
//						0},
//					MAX_RAY_DEPTH
//				};
			c = raytrace(r, env);
			drawer_putpixel(env, win_pos, c);
			win_pos.y++;
		}
		win_pos.x++;
	}
}

t_ray		get_prim_ray(t_2ipair p, t_env *env)
{
	t_camera	*cam;
	t_ray		r;

	cam = &env->scene.cam;
	r.dir.x = cam->d * cam->uvn.n.x
		- (cam->near.x / 2.0) * cam->uvn.u.x
		+ (cam->near.y / 2.0) * cam->uvn.v.x
		+ (((double)p.x + 0.5) * cam->step.x) * cam->uvn.u.x
		- (((double)p.y + 0.5) * cam->step.y) * cam->uvn.v.x;
	r.dir.y = cam->d * cam->uvn.n.y
		- (cam->near.x / 2.0) * cam->uvn.u.y
		+ (cam->near.y / 2.0) * cam->uvn.v.y
		+ (((double)p.x + 0.5) * cam->step.x) * cam->uvn.u.y
		- (((double)p.y + 0.5) * cam->step.y) * cam->uvn.v.y;
	r.dir.z = cam->d * cam->uvn.n.z
		- (cam->near.x / 2.0) * cam->uvn.u.z
		+ (cam->near.y / 2.0) * cam->uvn.v.z
		+ (((double)p.x + 0.5) * cam->step.x) * cam->uvn.u.z
		- (((double)p.y + 0.5) * cam->step.y) * cam->uvn.v.z;
	normalize_vector(&r.dir);
	r.pos = cam->pos;
	r.depth = MAX_RAY_DEPTH;
	return (r);
}

t_color		raytrace(t_ray r, t_env *env)
{
	t_intersection	inter;
//	t_point			reflect;
	t_color			c;

	c = (t_color){ .r = 0.0, .g = 0.0, .b = 0.0, .a = 1};
	inter.t = MAX_RAY_LENGTH;
	if (intersection(r, env->scene.objs, &inter))
	{
	//	get_reflected_ray(&r.reflect);
	//	get_inter_pos(&inter.pos, &r.reflect);
		inter.pos = vector_add(r.pos, vector_multiply(r.dir, inter.t)); //+ reflect * EPSILON;
		get_normal(&inter);
		c = process_light(env->scene.lgts, env->scene.objs, &inter, r);
		get_final_color(&c);
	}
	return (c);
}
