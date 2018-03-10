/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:47:44 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/10 19:28:42 by rpinoit          ###   ########.fr       */
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

	win_pos.x = -1;
	while (++win_pos.x < thenv->env->win_w)
	{
		win_pos.y = thenv->from_y;
		while (++win_pos.y < thenv->to_y)
		{
			if (thenv->env->anti == 1)
				c = anti_aliasing_rt(win_pos, thenv->env);
			else
			{
				r = get_prim_ray(win_pos, thenv->env);
				c = raytrace(r, thenv->env);
			}
			raytracer_process_option(thenv, &c);
			put_pixel(thenv->env, &win_pos, c);
		}
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
	r.refra_depth = MAX_RAY_DEPTH;
	r.refle_depth = 1;
	return (r);
}

static void	recurse_refraction(t_env *env, t_intersection *i, t_ray *r,
		t_color *c)
{
	t_color ref_c;
	t_ray	re;
	t_point v;
	double	tmp[3];

	v = vector_sub(i->pos, r->pos);
	normalize_vector(&v);
	tmp[0] = -dot_product(i->normal, v);
	tmp[1] = 1 * 1 * (1.0 - tmp[0] * tmp[0]);
	tmp[2] = sqrt(1.0 - tmp[1]);
	re.pos = i->pos;
	re.dir = vec_add(vec_mul(v, 1), vec_mul(i->normal, (1 * tmp[0] - tmp[2])));
	normalize_vector(&re.dir);
	re.refra_depth -= 1;
	ref_c = raytrace(re, env);
	c->r *= (1 - i->obj.refraction);
	c->g *= (1 - i->obj.refraction);
	c->b *= (1 - i->obj.refraction);
	if (ref_c.r != 0.0 && ref_c.g != 0.0 && ref_c.b != 0.0)
	{
		c->r += i->obj.refraction * ref_c.r;
		c->g += i->obj.refraction * ref_c.g;
		c->b += i->obj.refraction * ref_c.b;
	}
}

static void	recurse_reflection(t_env *env, t_intersection *inter, t_ray *r,
		t_color *c)
{
	t_color	ref_c;
	t_ray	reflected;
	t_point	vision;

	vision = vector_sub(r->pos, inter->pos);
	reflected.pos = inter->pos;
	reflected.dir = vector_sub(vec_mul(inter->normal,
				2.0 * dot_product(inter->normal, vision)), vision);
	normalize_vector(&reflected.dir);
	reflected.refle_depth -= 1;
	ref_c = raytrace(reflected, env);
	c->r *= (1 - inter->obj.reflection);
	c->g *= (1 - inter->obj.reflection);
	c->b *= (1 - inter->obj.reflection);
	if (ref_c.r != 0.0 && ref_c.r != 0.0 && ref_c.r != 0.0)
	{
		c->r += inter->obj.reflection * ref_c.r;
		c->g += inter->obj.reflection * ref_c.g;
		c->b += inter->obj.reflection * ref_c.b;
	}
}

t_color		raytrace(t_ray r, t_env *env)
{
	t_intersection	inter;
	t_color			c;

	c = (t_color){ .r = 0.0, .g = 0.0, .b = 0.0, .a = 1};
	inter.t = MAX_RAY_LENGTH;
	if (intersection(env, r, env->scene.objs, &inter))
	{
		inter.pos = vec_add(r.pos, vec_mul(r.dir, inter.t));
		inter.normal = get_normal(&inter);
		if (inter.obj.texture == 3)
			bump_mapping(&inter, &r);
		c = process_light(env, &inter, r);
		get_final_color(&c);
		if (inter.obj.reflection > 0 && r.refra_depth > 0)
			recurse_reflection(env, &inter, &r, &c);
		if (inter.obj.refraction > 0 && r.refle_depth > 0)
			recurse_refraction(env, &inter, &r, &c);
	}
	return (c);
}
