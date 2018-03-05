/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:06:14 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/05 10:42:08 by jpicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		rot_obj_keyhook(const int key, t_env *env)
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

static int		rot_cam_keyhook(const int key, t_env *env)
{
	if (key == KEY_D)
		env->cam_rot.y = env->cam_rot.y == 350 ? 0 : env->cam_rot.y + 10;
	else if (key == KEY_A)
		env->cam_rot.y = env->cam_rot.y == -350 ? 0 : env->cam_rot.y - 10;
	else if (key == KEY_W)
		env->cam_rot.x = env->cam_rot.x == 350 ? 0 : env->cam_rot.x + 10;
	else if (key == KEY_S)
		env->cam_rot.x = env->cam_rot.x == -350 ? 0 : env->cam_rot.x - 10;
	else if (key == KEY_1)
		env->cam_rot.z = env->cam_rot.z == 350 ? 0 : env->cam_rot.z + 10;
	else if (key == KEY_2)
		env->cam_rot.z = env->cam_rot.z == -350 ? 0 : env->cam_rot.z - 10;
	return (1);
}

static int		pos_cam_keyhook(int key, t_env *env)
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

int		key_hook(int key, t_env *env)
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
	else if (key == KEY_I || key == KEY_K || key == KEY_L || key == KEY_J || key == KEY_9 \
			|| key == KEY_8)
		env->mark = pos_cam_keyhook(key, env);
	if (env->mark == 1)
		mlx_draw_rt(env);
	return (0);
}
