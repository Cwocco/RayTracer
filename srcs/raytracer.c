/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:47:44 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/10 16:01:54 by rpinoit          ###   ########.fr       */
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
	r.refra_depth = MAX_RAY_DEPTH;
	r.refle_depth = MAX_RAY_DEPTH;
	return (r);
}

void	recurse_refraction(t_env *env, t_intersection *inter, t_ray *r,
		t_color *c)
{
	t_color ref_c;
	t_ray	refracted;
	t_point vision;
	double	n;
	double	cos1;
	double	cos2;

	n = 1.0 / 1.0;
	vision = vector_sub(inter->pos, r->pos);
	normalize_vector(&vision);
	cos1 = -dot_product(inter->normal, vision);
	cos2 = sqrt(1.0 - (n * n - n * n * (1 - cos1 * cos1)));
	refracted.pos = inter->pos;
	refracted.dir = vector_add(vector_multiply(vision, n),
			vector_multiply(inter->normal, (n * cos1 - cos2)));
	normalize_vector(&refracted.dir);
	refracted.refle_depth -= 1;
	ref_c = raytrace(refracted, env);
	c->r *= (1 - inter->obj.refraction);
	c->g *= (1 - inter->obj.refraction);
	c->b *= (1 - inter->obj.refraction);
	if (ref_c.r != 0.0 && ref_c.g != 0.0 && ref_c.b != 0.0)
	{
		c->r += inter->obj.refraction * ref_c.r;
		c->g += inter->obj.refraction * ref_c.g;
		c->b += inter->obj.refraction * ref_c.b;
	}
}

void	recurse_reflection(t_env *env, t_intersection *inter, t_ray *r,
		t_color *c)
{
	t_color	ref_c;
	t_ray	reflected;
	t_point	vision;

	vision = vector_sub(r->pos, inter->pos);
	normalize_vector(&vision);
	reflected.pos = inter->pos;
	reflected.dir = vector_sub(vector_multiply(inter->normal,
				2.0 * dot_product(inter->normal, vision)), vision);
	normalize_vector(&reflected.dir);
	reflected.refle_depth -= 1;
	ref_c = raytrace(reflected, env);
	c->r *= (1 - inter->obj.reflection);
	c->g *= (1 - inter->obj.reflection);
	c->b *= (1 - inter->obj.reflection);
	if (ref_c.r != 0.0 && ref_c.g != 0.0 && ref_c.b != 0.0)
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
		inter.pos = vector_add(r.pos, vector_multiply(r.dir, inter.t));
		inter.normal = get_normal(&inter);
		if (TEXTURE == 3)
			bump_mapping(&inter, &r);
		c = process_light(env, &inter, r);
		get_final_color(&c);
		if (inter.obj.reflection && r.refra_depth)
			recurse_reflection(env, &inter, &r, &c);
		if (inter.obj.refraction && r.refle_depth)
			recurse_refraction(env, &inter, &r, &c);
	}
	return (c);
}
