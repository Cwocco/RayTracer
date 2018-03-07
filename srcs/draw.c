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
	pts = ((int)pos->x * 4) + ((int)pos->y * env->thenv[0]->sline);
	env->thenv[0]->data[pts] = c.b;
	env->thenv[0]->data[++pts] = c.g;
	env->thenv[0]->data[++pts] = c.r;
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

void    mlx_draw_rt(t_env *env)
{
    int         w;
    int         h;

    w = 100;
    h = 100;
    env->img = mlx_new_image(env->mlx, env->win_w, env->win_h);
    env->data = mlx_get_data_addr(env->img, &env->bpp, &env->sline,
            &env->endian);
    env->i_th = -1;
    while (++env->i_th < NBTHREAD)
    {
        if (env->init == 0)
        {
            env->thenv[env->i_th] = ft_memalloc(sizeof(t_env));
            env->thenv[env->i_th]->thenv[0] = env;
            import_interface(env);
        }
        env->thenv[env->i_th]->i_th = env->i_th;
        if (pthread_create(&env->tid[env->i_th], NULL, raytracer_process, env->thenv[env->i_th]) != 0)
            ft_putstr("Erreur de thread.\n");
    }
    env->i_th = -1;
    while (++env->i_th < NBTHREAD)
        pthread_join(env->tid[env->i_th], NULL);
    env->init = 1;
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
    env->mark = 0;
}
