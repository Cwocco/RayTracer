/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:09:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/05 10:07:58 by jpicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void put_pixel(t_env *env, t_point *pos, t_color c)
{
	int pts;

	(void)c;
	pts = ((int)pos->x * 4) + ((int)pos->y * env->thenv[0]->sline);
	env->thenv[0]->data[pts] = c.b;
	env->thenv[0]->data[++pts] = c.g;
	env->thenv[0]->data[++pts] = c.r;
}

void	mlx_draw_rt(t_env *env)
{
	env->img = mlx_new_image(env->mlx, env->win_w, env->win_h);
	env->data = mlx_get_data_addr(env->img, &env->bpp, &env->sline,
			&env->endian);
	env->i_th = -1;
	while (++env->i_th < NBTHREAD)
	{
		if (env->init == 0)
		{
			env->thenv[env->i_th] = ft_memalloc(sizeof(t_env));
			env->thenv[env->i_th]->thenv[0] = env;
		}
		env->thenv[env->i_th]->i_th = env->i_th;
		if (pthread_create(&env->tid[env->i_th], NULL, raytracer_process, env->thenv[env->i_th]) != 0)
			ft_putstr("Erreur de thread.\n");
	}
	env->i_th = -1;
	while (++env->i_th < NBTHREAD)
		pthread_join(env->tid[env->i_th], NULL);
	env->init = 1;
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
	env->mark = 0;
}
