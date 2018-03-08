/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:47:09 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/07 00:14:13 by jpicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void    import_interface(t_env *e)
{
	int     w;
	int     h;
	int     fd;

	h = 100;
	w = 100;
	if ((fd = open("./ressources/light_on_1.xpm", O_RDONLY)) == -1)
		ft_exit("./ressources/light_on_1.xpm not finded or you haven't the rights. Exiting.\n");
	if (!(e->IMG_light_on_1 = mlx_xpm_file_to_image(e->mlx, "./ressources/light_on_1.xpm", &w, &h)))
		ft_exit("./ressources/light_on_1_xpm not finded or corrupted. Exiting.\n");
	mlx_put_image_to_window(e->mlx, e->win, e->IMG_light_on_1, WIN_W + 33, 33);
	close(fd);
	if ((fd = open("./ressources/light_on_2.xpm", O_RDONLY)) == -1)
		ft_exit("./ressources/light_on_2.xpm not finded or you haven't the rights. Exiting.\n");
	if (!(e->IMG_light_on_2 = mlx_xpm_file_to_image(e->mlx, "./ressources/light_on_2.xpm", &w, &h)))
		ft_exit("./ressources/light_on_2_xpm not finded or corrupted. Exiting.\n");
	close(fd);
	if ((fd = open("./ressources/light_off_1.xpm", O_RDONLY)) == -1)
		ft_exit("./ressources/light_off_1.xpm not finded or you haven't the rights. Exiting.\n");
	if (!(e->IMG_light_off_1 = mlx_xpm_file_to_image(e->mlx, "./ressources/light_off_1.xpm", &w, &h)))
		ft_exit("./ressources/light_off_1_xpm not finded or corrupted. Exiting.\n");
	close(fd);
	if ((fd = open("./ressources/light_off_2.xpm", O_RDONLY)) == -1)
		ft_exit("./ressources/light_off_2.xpm not finded or you haven't the rights. Exiting.\n");
	if (!(e->IMG_light_off_2 = mlx_xpm_file_to_image(e->mlx, "./ressources/light_off_2.xpm", &w, &h)))
		ft_exit("./ressources/light_off_2_xpm not finded or corrupted. Exiting.\n");
	close(fd);
	if ((fd = open("./ressources/shadow_on_1.xpm", O_RDONLY)) == -1)
		ft_exit("./ressources/shadowt_on_1.xpm not finded or you haven't the rights. Exiting.\n");
	if (!(e->IMG_shadow_on_1 = mlx_xpm_file_to_image(e->mlx, "./ressources/shadow_on_1.xpm", &w, &h)))
		ft_exit("./ressources/shadow_on_1_xpm not finded or corrupted. Exiting.\n");
	mlx_put_image_to_window(e->mlx, e->win, e->IMG_shadow_on_1, WIN_W + 166, 33);
	close(fd);
	if ((fd = open("./ressources/shadow_on_2.xpm", O_RDONLY)) == -1)
		ft_exit("./ressources/shadow_on_2.xpm not finded or you haven't the rights. Exiting.\n");
	if (!(e->IMG_shadow_on_2 = mlx_xpm_file_to_image(e->mlx, "./ressources/shadow_on_2.xpm", &w, &h)))
		ft_exit("./ressources/shadow_on_2_xpm not finded or corrupted. Exiting.\n");
	close(fd);
	if ((fd = open("./ressources/shadow_off_1.xpm", O_RDONLY)) == -1)
		ft_exit("./ressources/shadow_off_1.xpm not finded or you haven't the rights. Exiting.\n");
	if (!(e->IMG_shadow_off_1 = mlx_xpm_file_to_image(e->mlx, "./ressources/shadow_off_1.xpm", &w, &h)))
		ft_exit("./ressources/shadow_off_1_xpm not finded or corrupted. Exiting.\n");
	close(fd);
	if ((fd = open("./ressources/shadow_off_2.xpm", O_RDONLY)) == -1)
		ft_exit("./ressources/shadow_off_2.xpm not finded or you haven't the rights. Exiting.\n");
	if (!(e->IMG_shadow_off_2 = mlx_xpm_file_to_image(e->mlx, "./ressources/shadow_off_2.xpm", &w, &h)))
		ft_exit("./ressources/shadow_off_2_xpm not finded or corrupted. Exiting.\n");
	close(fd);
}

static void init_win(t_env *env, char *name)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->win_w + 300, env->win_h, name);
	env->img = mlx_new_image(env->mlx, env->win_w, env->win_h);
	env->data = mlx_get_data_addr(env->img, &env->bpp, &env->sline,
		&env->endian);
	mlx_string_put(env->mlx, env->win, WIN_W /2, WIN_H /2, 0xff0000, "Loading..");
	import_interface(env);
}



int		main(int argc, char **argv)
{
	t_env	env;

	env.win_w = WIN_W;
	env.win_h = WIN_H;
	env.mark = 0;
	env.argc = argc;
	env.argv = argv;
	env.obj_rot.x = 0;
	env.obj_rot.y = 0;
	env.obj_rot.z = 0;
//	env.obj_rot = (t_point){90, 0, 90};
	env.cam_rot = (t_point){0, 0, 0};
	reader(&env);
	init_win(&env, argv[1]);
	env.mark = 1;
    env.active_icon = 0;
    env.ambilight = 0;
    env.shadow = 1;
	mlx_draw_rt(&env);
    mlx_hook(env.win, 6, 1L << 0, mouse_motion, &env);
    mlx_hook(env.win, 17, 1L << 17, red_cross, &env);
    mlx_hook(env.win, 2, 1L << 0, key_press, &env);
    mlx_hook(env.win, 4, 1L << 2, button_event, &env);
    mlx_loop_hook(env.mlx, loop_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
