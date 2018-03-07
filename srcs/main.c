/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:47:09 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/05 11:09:30 by jpicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int argc, char **argv)
{
	t_env	env;

	env.win_w = WIN_W;
	env.win_h = WIN_H;
	env.argc = argc;
	env.argv = argv;
	env.obj_rot.x = 0;
	env.obj_rot.y = 0;
	env.obj_rot.z = 0;
	env.cam_rot = (t_point){0, 0, 0};
	reader(&env);
	rt_sdlinit(&env, argv[1]);
	rt_sdlloop(&env);
	return (0);
}
