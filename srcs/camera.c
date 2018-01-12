/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:31:56 by nboste            #+#    #+#             */
/*   Updated: 2018/01/06 16:15:08 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	init_camera(t_env *env, t_point pos, t_uvn uvn)
{
	t_camera	*cam;

	cam = &env->scene.cam;
	cam->pos = pos;
	cam->uvn.u = uvn.u;
	cam->uvn.v = uvn.v;
	cam->uvn.n = uvn.n;
	cam->ratio = env->win.size.x / env->win.size.y;
	cam->fov = ft_degtorad(42);
	cam->d = 1.0 / tan(cam->fov / 2);
	cam->near.y = 2 * tan(cam->fov / 2) * cam->d;
	cam->near.x = cam->near.y * cam->ratio;
	cam->step.x = cam->near.x / (double)env->win.size.x;
	cam->step.y = cam->near.y / (double)env->win.size.y;
}
