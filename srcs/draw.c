/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:09:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/07 00:00:22 by jpicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void put_pixel(t_env *env, t_point *pos, t_color c)
{
	int pts;

	(void)c;
	pts = ((int)pos->x * 4) + ((int)pos->y * env->sline);
	env->data[pts] = (char)c.b;
	env->data[++pts] = (char)c.g;
	env->data[++pts] = (char)c.r;
}

void    import_interface(t_env *e)
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
	mlx_put_image_to_window(e->mlx, e->win, e->IMG_light_on_1, 1033, 33);
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
	mlx_put_image_to_window(e->mlx, e->win, e->IMG_shadow_on_1, 1166, 33);
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

void	mlx_draw_rt(t_env *env)
{
	int			i;
	t_thenv		thenv[NBTHREAD];
	pthread_t	ths[NBTHREAD];

	ft_bzero(thenv, sizeof(t_thenv) * NBTHREAD);
	ft_bzero(ths, sizeof(pthread_t) * NBTHREAD);
	mlx_clear_window(env->mlx, env->win);
	i = -1;
	while (++i < NBTHREAD)
	{
		thenv[i].env = env;
		thenv[i].from_y = ((env->win_h / NBTHREAD) * i) - 1;
		thenv[i].to_y = (env->win_h / NBTHREAD) * (i + 1);
		pthread_create(ths + i, NULL, (void *(*)(void *))raytracer_process,
			thenv + i);
	}
	while (i--)
		pthread_join(ths[i], NULL);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	env->mark = 0;
}
