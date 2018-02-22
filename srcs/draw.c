/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:09:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/02/16 14:01:53 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void put_pixel(t_env *env, t_point *pos, t_color c)
{
	int pts;

	(void)c;
	pts = ((int)pos->x * 4) + ((int)pos->y * env->sline);
	env->data[pts] = c.b;
	env->data[++pts] = c.g;
	env->data[++pts] = c.r;
}

void	mlx_draw_rt(t_env *env)
{
	env->img = mlx_new_image(env->mlx, env->win_w, env->win_h);
	env->data = mlx_get_data_addr(env->img, &env->bpp, &env->sline,
			&env->endian);
	raytracer_process(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
}
