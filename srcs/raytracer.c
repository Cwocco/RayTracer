/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:47:44 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/06 17:04:22 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		raytracer_process(t_thenv *thenv)
{
	t_pixel		win_pos;
	t_ray		r;
	t_color		c;

	win_pos.x = 0;
	while (win_pos.x < thenv->env->win_w)
	{
		win_pos.y = thenv->from_y;
		while (win_pos.y < thenv->to_y)
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
			rt_sdldrawpixel(thenv->env, win_pos, c);
			win_pos.y++;
		}
		win_pos.x++;
	}
	return (0);
}

t_ray		get_prim_ray(const t_pixel p, const t_env *env)
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

//t_color sepia(t_color *new, t_color *c)

t_color		raytrace(const t_ray r, const t_env *env)
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
		if (TEXTURE == 3)
			bump_mapping(&inter, &r);
		c = process_light(env, env->scene.lgts, env->scene.objs, &inter, r);
		get_final_color(&c);
//		get_texture(&c, &inter, (t_ray*)&r);
	}
	return (c);
}
