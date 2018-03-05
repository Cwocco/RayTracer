/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:46:34 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/03 11:23:13 by jpicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_uint32	t_colortouint32(t_color c)
{
	t_uint32	u;

	u = c.a;
	u <<= 8;
	u += c.r;
	u <<= 8;
	u += c.g;
	u <<= 8;
	u += c.b;
	return (u);
}

void			drawer_init(t_env *env)
{
	if (!(env->rend.rend_sdl = SDL_CreateRenderer(env->win.win_sdl,
					-1,
					SDL_RENDERER_ACCELERATED)))
		ft_exit("SDL REND INIT FAILED");
	if (!(env->rend.texture_sdl = SDL_CreateTexture(env->rend.rend_sdl,
					SDL_PIXELFORMAT_ARGB8888,
					SDL_TEXTUREACCESS_STREAMING,
					env->win.size.x,
					env->win.size.y)))
		ft_exit("SDL TEXTURE INIT FAILED");
	if (!(env->rend.pixels = (t_uint32 *)
				malloc(sizeof(t_uint32) * env->win.size.x * env->win.size.y)))
		ft_exit("RENDERER ARRAY INIT FAILED");
	env->rend.size.x = env->win.size.x;
	env->rend.size.y = env->win.size.y;
}

void			drawer_process(t_env *env)
{
	SDL_UpdateTexture(env->rend.texture_sdl, NULL,
			env->rend.pixels, env->rend.size.x * sizeof(t_uint32));
	SDL_RenderCopy(env->rend.rend_sdl, env->rend.texture_sdl, NULL, NULL);
	SDL_RenderPresent(env->rend.rend_sdl);
	ft_memset(
			env->rend.pixels,
			0,
			sizeof(t_uint32) * env->rend.size.x * env->rend.size.y);
}

void			drawer_destroy(t_env *env)
{
	free(env->rend.pixels);
	SDL_DestroyRenderer(env->rend.rend_sdl);
	SDL_DestroyTexture(env->rend.texture_sdl);
}

void			drawer_putpixel(t_env *env, t_2ipair p, t_color c)
{
	t_rend	*r;

	r = &env->rend;
	if (p.x >= 0 && p.x < r->size.x && p.y >= 0 && p.y < r->size.y)
		r->pixels[p.x + r->size.x * p.y] = t_colortouint32(c);
}
