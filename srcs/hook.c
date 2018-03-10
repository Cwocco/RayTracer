/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:06:14 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/10 15:20:31 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		rot_obj_keyhook(const int key, t_env *env)
{
	if (key == KEY_LEFT)
		env->obj_rot.y = env->obj_rot.y == 350 ? 0 : env->obj_rot.y + 10;
	else if (key == KEY_RIGHT)
		env->obj_rot.y = env->obj_rot.y == -350 ? 0 : env->obj_rot.y - 10;
	else if (key == KEY_UP)
		env->obj_rot.x = env->obj_rot.x == 350 ? 0 : env->obj_rot.x + 10;
	else if (key == KEY_DOWN)
		env->obj_rot.x = env->obj_rot.x == -350 ? 0 : env->obj_rot.x - 10;
	else if (key == KEY_PLUS)
		env->obj_rot.z = env->obj_rot.z == 350 ? 0 : env->obj_rot.z + 10;
	else if (key == KEY_MINUS)
		env->obj_rot.z = env->obj_rot.z == -350 ? 0 : env->obj_rot.z - 10;
	return (1);
}

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
	else if ((key > 122 && key < 127) || key == 24 || key == 27)
		env->mark = rot_obj_keyhook(key, env);
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
	if (x < WIN_W + 300 && y < WIN_H)
	{
		e->active_icon = 0;
		if (x >= WIN_W + 33 && x <= WIN_W + 133 && y >= 33 && y <= 133)
			e->active_icon = 1;
		else if (x >= WIN_W + 166 && x <= WIN_W + 266 && y >= 33 && y <= 133)
			e->active_icon = 3;
	}
	return (0);
}
