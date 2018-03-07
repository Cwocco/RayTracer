/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:06:14 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/07 20:10:04 by alucas-          ###   ########.fr       */
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
		env->scene.cam.pos.z += 30;
	else if (key == KEY_K)
		env->scene.cam.pos.z -= 30;
	else if (key == KEY_L)
		env->scene.cam.pos.x += 30;
	else if (key == KEY_J)
		env->scene.cam.pos.x -= 30;
	else if (key == KEY_9)
		env->scene.cam.pos.y += 30;
	else if (key == KEY_8)
		env->scene.cam.pos.y -= 30;
	return (1);
}

int     key_press(int key, t_env *env)
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

int     mouse_motion(unsigned int x, unsigned int y, t_env *e)
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

int     button_event(int button, int x, int y, t_env *e)
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

static void process_dynamic(t_env *env)
{
    usleep(140000);
    if (env->active_icon == 1)
    {
        if (env->ambilight == 0)
            mlx_put_image_to_window(env->mlx, env->win, env->IMG_light_on_1, WIN_W + 33, 33);
        else
            mlx_put_image_to_window(env->mlx, env->win, env->IMG_light_off_1, WIN_W + 33, 33);
        env->active_icon = 2;
    }
    else if (env->active_icon == 2)
    {
        if (env->ambilight == 0)
            mlx_put_image_to_window(env->mlx, env->win, env->IMG_light_on_2, WIN_W + 33, 33);
        else
            mlx_put_image_to_window(env->mlx, env->win, env->IMG_light_off_2, WIN_W + 33, 33);
        env->active_icon = 1;
    }
    else if (env->active_icon == 3)
    {
        if (env->shadow == 1)
            mlx_put_image_to_window(env->mlx, env->win, env->IMG_shadow_on_1, WIN_W + 166, 33);
        else
            mlx_put_image_to_window(env->mlx, env->win, env->IMG_shadow_off_1, WIN_W + 166, 33);
        env->active_icon = 4;
    }
    else if (env->active_icon == 4)
    {
        if (env->shadow == 1)
            mlx_put_image_to_window(env->mlx, env->win, env->IMG_shadow_on_2, WIN_W + 166, 33);
        else
            mlx_put_image_to_window(env->mlx, env->win, env->IMG_shadow_off_2, WIN_W + 166, 33);
        env->active_icon = 3;
    }
}

int     red_cross(void)
{
    exit(EXIT_SUCCESS);
}

int     loop_hook(t_env *env)
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
