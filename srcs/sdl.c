/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:47:09 by alucas-           #+#    #+#             */
/*   Updated: 2018/03/05 11:09:30 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_sdldrawpixel(t_env *e, t_pixel pos, t_color c)
{
	if (pos.x >= 0 && pos.x < e->win_w &&
		pos.y >= 0 && pos.y < e->win_h)
	{
		SDL_SetRenderDrawColor(e->rend,
			(Uint8)(c.r - 0.001), (Uint8)(c.g - 0.001),
			(Uint8)(c.b - 0.001), (Uint8)(c.a - 0.001));
		SDL_RenderDrawPoint(e->rend, pos.x, pos.y);
	}
}

void	rt_sdldraw(t_env *e)
{
	int			i;
	t_thenv		thenv[NBTHREAD];
	pthread_t	ths[NBTHREAD];

	ft_bzero(thenv, sizeof(t_thenv) * NBTHREAD);
	ft_bzero(ths, sizeof(pthread_t) * NBTHREAD);
	SDL_RenderClear(e->rend);
	SDL_SetRenderDrawColor(e->rend, 0, 0, 0, 255);
	i = -1;
	while (++i < NBTHREAD)
	{
		thenv[i].env = e;
		thenv[i].from_y = ((e->win_h / NBTHREAD) * i) - 1;
		thenv[i].to_y = (e->win_h / NBTHREAD) * (i + 1) + 1;
		pthread_create(ths + i, NULL, (void *(*)(void *))raytracer_process,
			thenv + i);
	}
	while (i--)
		pthread_join(ths[i], NULL);
	SDL_RenderPresent(e->rend);
}

void	rt_sdlinit(t_env *e, char const *name)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		ft_exit("SDL ERROR: SDL_Init failed.");
	if ((e->win = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, e->win_w, e->win_h, 0)) == NULL)
		ft_exit("SDL ERROR: SDL_CreateWindow failed.");
	if (!(e->rend = SDL_CreateRenderer(e->win, -1, SDL_RENDERER_SOFTWARE)))
		ft_exit("SDL ERROR: SDL_CreateRenderer.");
}

void	rt_sdlexit(t_env *e)
{
	SDL_DestroyWindow(e->win);
	SDL_DestroyRenderer(e->rend);
	SDL_Quit();
	exit(EXIT_SUCCESS);
}

void	rt_sdlonkeydown(t_env *e, SDL_Event *ev)
{
	if (ev->key.keysym.sym == SDLK_ESCAPE)
		rt_sdlexit(e);
	if (ev->key.keysym.sym == SDLK_LEFT)
		e->obj_rot.y = e->obj_rot.y == 350 ? 0 : e->obj_rot.y + 10;
	else if (ev->key.keysym.sym == SDLK_RIGHT)
		e->obj_rot.y = e->obj_rot.y == -350 ? 0 : e->obj_rot.y - 10;
	else if (ev->key.keysym.sym == SDLK_UP)
		e->obj_rot.x = e->obj_rot.x == 350 ? 0 : e->obj_rot.x + 10;
	else if (ev->key.keysym.sym == SDLK_DOWN)
		e->obj_rot.x = e->obj_rot.x == -350 ? 0 : e->obj_rot.x - 10;
	else if (ev->key.keysym.sym == SDLK_KP_PLUS)
		e->obj_rot.z = e->obj_rot.z == 350 ? 0 : e->obj_rot.z + 10;
	else if (ev->key.keysym.sym == SDLK_KP_MINUS)
		e->obj_rot.z = e->obj_rot.z == -350 ? 0 : e->obj_rot.z - 10;
	else if (ev->key.keysym.sym == SDLK_d)
		e->cam_rot.y = e->cam_rot.y == 350 ? 0 : e->cam_rot.y + 10;
	else if (ev->key.keysym.sym == SDLK_a)
		e->cam_rot.y = e->cam_rot.y == -350 ? 0 : e->cam_rot.y - 10;
	else if (ev->key.keysym.sym == SDLK_w)
		e->cam_rot.x = e->cam_rot.x == 350 ? 0 : e->cam_rot.x + 10;
	else if (ev->key.keysym.sym == SDLK_s)
		e->cam_rot.x = e->cam_rot.x == -350 ? 0 : e->cam_rot.x - 10;
	else if (ev->key.keysym.sym == SDLK_1)
		e->cam_rot.z = e->cam_rot.z == 350 ? 0 : e->cam_rot.z + 10;
	else if (ev->key.keysym.sym == SDLK_2)
		e->cam_rot.z = e->cam_rot.z == -350 ? 0 : e->cam_rot.z - 10;
	else if (ev->key.keysym.sym == SDLK_i)
		e->scene.cam.pos.z += 10;
	else if (ev->key.keysym.sym == SDLK_k)
		e->scene.cam.pos.z -= 10;
	else if (ev->key.keysym.sym == SDLK_l)
		e->scene.cam.pos.x += 10;
	else if (ev->key.keysym.sym == SDLK_j)
		e->scene.cam.pos.x -= 10;
	else if (ev->key.keysym.sym == SDLK_9)
		e->scene.cam.pos.y += 10;
	else if (ev->key.keysym.sym == SDLK_8)
		e->scene.cam.pos.y -= 10;
	rt_sdldraw(e);
}

void	rt_sdlloop(t_env *e)
{
	SDL_Event ev;

	ft_bzero(&ev, sizeof(SDL_Event));
	rt_sdldraw(e);
	while (1)
	{
		if (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT)
				rt_sdlexit(e);
			else if (ev.type == SDL_KEYDOWN)
				rt_sdlonkeydown(e, &ev);
		}
	}
}


