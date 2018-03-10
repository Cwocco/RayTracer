/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:09:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/10 19:25:47 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "light.h"
#include "raytracer.h"
#include "perlin.h"
#include "anti_alias.h"
#include "light.h"
#include "obj_normal.h"
#include "vector_utilities.h"
#include "intersection.h"
#include "pixel.h"
#include "vector_rotate.h"

void	raytracer_process_option(t_thenv *thenv, t_color *c)
{
	if (thenv->env->sepia == 1)
		sepia(c);
	else if (thenv->env->fifty == 1)
		fifty_shades_of_grey(c);
	else if (thenv->env->dalto == 1)
		daltonism(c);
}

void	put_pixel(t_env *env, t_point *pos, t_color c)
{
	int pts;

	(void)c;
	pts = ((int)pos->x * 4) + ((int)pos->y * env->sline);
	env->data[pts] = (char)c.b;
	env->data[++pts] = (char)c.g;
	env->data[++pts] = (char)c.r;
}

void	mlx_draw_rt(t_env *env)
{
	int			i;
	t_thenv		thenv[NBTHREAD];
	pthread_t	ths[NBTHREAD];

	ft_bzero(thenv, sizeof(t_thenv) * NBTHREAD);
	ft_bzero(ths, sizeof(pthread_t) * NBTHREAD);
	i = -1;
	while (++i < NBTHREAD)
	{
		thenv[i].env = env;
		thenv[i].from_y = ((env->win_h / NBTHREAD) * i) - 1;
		thenv[i].to_y = (env->win_h / NBTHREAD) * (i + 1) + 1;
		pthread_create(ths + i, NULL, (void *(*)(void *))raytracer_process,
				thenv + i);
	}
	while (i--)
		pthread_join(ths[i], NULL);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	env->mark = 0;
}
