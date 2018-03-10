/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:47:09 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/10 13:45:22 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "error.h"
#include "parser.h"

#define LHT_ON1 "./ressources/light_on_1.xpm"
#define LHT_ON2 "./ressources/light_on_2.xpm"
#define LHT_OFF1 "./ressources/light_off_1.xpm"
#define LHT_OFF2 "./ressources/light_off_2.xpm"
#define SHD_ON1 "/ressources/shadow_on_1.xpm"
#define SHD_ON2 "/ressources/shadow_on_2.xpm"
#define SHD_OFF1 "/ressources/shadow_off_1.xpm"
#define SHD_OFF2 "/ressources/shadow_off_2.xpm"

static void			import_interface2(t_env *e, int fd, int w, int h)
{
	if (!(e->img_light_off_2 = mlx_xpm_file_to_image(e->mlx, LHT_OFF2, &w, &h)))
		ft_exit(LHT_OFF2" not finded or corrupted. Exiting.\n");
	close(fd);
	if ((fd = open(SHD_ON1, O_RDONLY)) == -1)
		ft_exit(SHD_ON1" not finded or you haven't the rights. Exiting.\n");
	if (!(e->img_shadow_on1 = mlx_xpm_file_to_image(e->mlx, SHD_ON1, &w, &h)))
		ft_exit(SHD_ON1" not finded or corrupted. Exiting.\n");
	mlx_put_image_to_window(e->mlx, e->win, e->img_shadow_on1, WIN_W + 166, 33);
	close(fd);
	if ((fd = open(SHD_ON2, O_RDONLY)) == -1)
		ft_exit(SHD_ON2" not finded or you haven't the rights. Exiting.\n");
	if (!(e->img_shadow_on_2 = mlx_xpm_file_to_image(e->mlx, SHD_ON2, &w, &h)))
		ft_exit(SHD_ON2" not finded or corrupted. Exiting.\n");
	close(fd);
	if ((fd = open(SHD_OFF1, O_RDONLY)) == -1)
		ft_exit(SHD_OFF1" not finded or you haven't the rights. Exiting.\n");
	if (!(e->img_shadow_off1 = mlx_xpm_file_to_image(e->mlx, SHD_OFF1, &w, &h)))
		ft_exit(SHD_OFF1" not finded or corrupted. Exiting.\n");
	close(fd);
	if ((fd = open(SHD_OFF2, O_RDONLY)) == -1)
		ft_exit(SHD_OFF2" not finded or you haven't the rights. Exiting.\n");
	if (!(e->img_shadow_off2 = mlx_xpm_file_to_image(e->mlx, SHD_OFF2, &w, &h)))
		ft_exit(SHD_OFF2" not finded or corrupted. Exiting.\n");
	close(fd);
}

static void			import_interface(t_env *e)
{
	int w;
	int h;
	int fd;

	h = 100;
	w = 100;
	if ((fd = open(LHT_ON1, O_RDONLY)) == -1)
		ft_exit(LHT_ON1" not finded or you haven't the rights. Exiting.\n");
	if (!(e->img_light_on_1 = mlx_xpm_file_to_image(e->mlx, LHT_ON1, &w, &h)))
		ft_exit(LHT_ON1" not finded or corrupted. Exiting.\n");
	mlx_put_image_to_window(e->mlx, e->win, e->img_light_on_1, WIN_W + 33, 33);
	close(fd);
	if ((fd = open(LHT_ON2, O_RDONLY)) == -1)
		ft_exit(LHT_ON2" not finded or you haven't the rights. Exiting.\n");
	if (!(e->img_light_on_2 = mlx_xpm_file_to_image(e->mlx, LHT_ON2, &w, &h)))
		ft_exit(LHT_ON2" not finded or corrupted. Exiting.\n");
	close(fd);
	if ((fd = open(LHT_OFF1, O_RDONLY)) == -1)
		ft_exit(LHT_OFF1" not finded or you haven't the rights. Exiting.\n");
	if (!(e->img_light_off_1 = mlx_xpm_file_to_image(e->mlx, LHT_OFF1, &w, &h)))
		ft_exit(LHT_OFF1" not finded or corrupted. Exiting.\n");
	close(fd);
	if ((fd = open(LHT_OFF2, O_RDONLY)) == -1)
		ft_exit(LHT_OFF2" not finded or you haven't the rights. Exiting.\n");
	import_interface2(e, fd, w, h);
}

static void			init_win(t_env *env, char *name)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->win_w + 300, env->win_h, name);
	env->img = mlx_new_image(env->mlx, env->win_w, env->win_h);
	env->data = mlx_get_data_addr(env->img, &env->bpp, &env->sline,
		&env->endian);
	mlx_string_put(env->mlx, env->win, WIN_W / 2, WIN_H / 2, 0xff0000,
		"Loading..");
	import_interface(env);
}

int					main(int argc, char **argv)
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
