/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 21:40:50 by nboste            #+#    #+#             */
/*   Updated: 2018/01/12 10:30:09 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "drawer.h"
#include "error.h"
#include "camera.h"
#include "raytracer.h"
#include "parser.h"

static void	print_fps(void)
{
	static int	time;
	static int	fps;
	t_uint32	t;

	fps++;
	if (!time)
		time = SDL_GetTicks();
	if ((t = SDL_GetTicks()) >= (t_uint32)time + 1000)
	{
		ft_putstr("fps : ");
		ft_putnbr(fps);
		ft_putchar('\n');
		fps = 0;
		time = t;
	}
}

void		init(t_env *env)
{
	env->win.name = "RTv1";
	env->win.size.x = W_WIDTH;
	env->win.size.y = W_HEIGHT;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		ft_exit("SDL INIT FAILED");
	if (!(env->win.win_sdl = SDL_CreateWindow(env->win.name,
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					env->win.size.x,
					env->win.size.y,
					SDL_WINDOW_SHOWN)))
		ft_exit("SDL WINDOW INIT FAILED");
	drawer_init(env);
	reader(env);
}

void		process(t_env *env)
{
	event_reset(&env->event);
	env->event.draw = 1;
	while (!env->event.exit)
	{
		print_fps();
		if (env->event.draw)
		{
			raytracer_process(env);
			drawer_process(env);
			env->event.draw = 0;
		}
		event_process(&env->event);
	}
}

void		destroy(t_env *env)
{
	drawer_destroy(env);
	SDL_DestroyWindow(env->win.win_sdl);
	SDL_Quit();
}
