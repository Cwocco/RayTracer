/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 10:53:10 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/10 15:21:06 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void			process_dynamic(t_env *env)
{
	usleep(140000);
	if (env->active_icon == 1)
	{
		if (env->ambilight == 0)
			mlx_put_image_to_window(env->mlx, env->win,
					env->img_light_on_1, WIN_W + 33, 33);
		else
			mlx_put_image_to_window(env->mlx, env->win,
					env->img_light_off_1, WIN_W + 33, 33);
		env->active_icon = 2;
	}
	else if (env->active_icon == 2)
	{
		if (env->ambilight == 0)
			mlx_put_image_to_window(env->mlx, env->win,
					env->img_light_on_2, WIN_W + 33, 33);
		else
			mlx_put_image_to_window(env->mlx, env->win,
					env->img_light_off_2, WIN_W + 33, 33);
		env->active_icon = 1;
	}
	else if (env->active_icon == 3)
	{
		if (env->shadow == 1)
			mlx_put_image_to_window(env->mlx, env->win,
					env->img_shadow_on_1, WIN_W + 166, 33);
		else
			mlx_put_image_to_window(env->mlx, env->win,
					env->img_shadow_off_1, WIN_W + 166, 33);
		env->active_icon = 4;
	}
	else if (env->active_icon == 4)
	{
		if (env->shadow == 1)
			mlx_put_image_to_window(env->mlx, env->win,
					env->img_shadow_on_2, WIN_W + 166, 33);
		else
			mlx_put_image_to_window(env->mlx, env->win,
					env->img_shadow_off_2, WIN_W + 166, 33);
		env->active_icon = 3;
	}
}

int				button_event(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	if (button == M_LFT)
	{
		if (e->active_icon == 1 || e->active_icon == 2)
		{
			if (e->ambilight == 0)
				e->ambilight = 1;
			else
				e->ambilight = 0;
			e->mark = 1;
		}
		else if (e->active_icon == 3 || e->active_icon == 4)
		{
			if (e->shadow == 0)
				e->shadow = 1;
			else
				e->shadow = 0;
			e->mark = 1;
		}
	}
	return (0);
}

int				red_cross(void)
{
	exit(EXIT_SUCCESS);
}

int				loop_hook(t_env *env)
{
	if (env->active_icon > 0)
		process_dynamic(env);
	if (env->mark == 1)
	{
		env->mark = 0;
		mlx_draw_rt(env);
	}
	return (0);
}
