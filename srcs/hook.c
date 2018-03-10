/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:06:14 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/10 14:20:06 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		rot_cam_keyhook(const int key, t_env *env)
{
	t_point *rot;

	rot = &env->scene.cam.rot;
	if (key == KEY_D)
		rot->y = rot->y == 350 ? 0 : rot->y + 10;
	else if (key == KEY_A)
		rot->y = rot->y == 350 ? 0 : rot->y - 10;
	else if (key == KEY_W)
		rot->x = rot->x == 350 ? 0 : rot->x + 10;
	else if (key == KEY_S)
		rot->x = rot->x == 350 ? 0 : rot->x - 10;
	else if (key == KEY_1)
		rot->z = rot->z == 350 ? 0 : rot->z + 10;
	else if (key == KEY_2)
		rot->z = rot->z == 350 ? 0 : rot->z - 10;
	return (1);
}

int		pos_cam_keyhook(int key, t_env *env)
{
	if (key == KEY_I)
		env->scene.cam.pos.z += 10;
	else if (key == KEY_K)
		env->scene.cam.pos.z -= 10;
	else if (key == KEY_L)
		env->scene.cam.pos.x += 10;
	else if (key == KEY_J)
		env->scene.cam.pos.x -= 10;
	else if (key == KEY_9)
		env->scene.cam.pos.y += 10;
	else if (key == KEY_8)
		env->scene.cam.pos.y -= 10;
	return (1);
}

int		key_press(int key, t_env *env)
{
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(EXIT_SUCCESS);
	}
	else if (key == KEY_A || key == KEY_D || key == KEY_W || key == KEY_S \
			|| key == KEY_1 || key == KEY_2)
		env->mark = rot_cam_keyhook(key, env);
	else if (key == KEY_I || key == KEY_K || key == KEY_L || key == KEY_J
			|| key == KEY_9 \
			|| key == KEY_8)
		env->mark = pos_cam_keyhook(key, env);
	else if (key == KEY_M)
	{
		if (env->ambilight == 0)
			env->ambilight = 1;
		else
			env->ambilight = 0;
		env->mark = 1;
	}
	return (0);
}

int		mouse_motion(unsigned int x, unsigned int y, t_env *e)
{
	if (x < (unsigned int)e->win_w && y < (unsigned int)e->win_h)
	{
		e->active_icon = 0;
		if (x >= 1033 && x <= 1133 && y >= 33 && y <= 133)
			e->active_icon = 1;
		else if (x >= 1166 && x <= 1266 && y >= 33 && y <= 133)
			e->active_icon = 3;
	}
	return (0);
}
