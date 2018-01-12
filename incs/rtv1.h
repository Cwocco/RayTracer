/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:43:07 by nboste            #+#    #+#             */
/*   Updated: 2018/01/11 11:34:20 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "SDL.h"
# include "libft.h"
# include "event.h"
# include "types.h"

# define W_WIDTH 900
# define W_HEIGHT 900

# define MAX_RAY_DEPTH 4


typedef struct			s_win
{
	SDL_Window	*win_sdl;
	t_2ipair	size;
	char		*name;
	t_bool		focus;
}						t_win;

typedef struct			s_rend
{
	SDL_Renderer	*rend_sdl;
	SDL_Texture		*texture_sdl;
	t_uint32		*pixels;
	t_2ipair		size;
}						t_rend;

typedef struct			s_scene
{
	t_ray		prim_r;
	t_object	*objs;
	t_light		*lgts;
	t_camera	cam;
}						t_scene;

typedef struct			s_env
{
	t_scene		scene;
	t_event		event;
	t_win		win;
	t_rend		rend;
	int			argc;
	char		**argv;
}						t_env;

void					init(t_env *env);

void					process(t_env *env);

void					destroy(t_env *env);

#endif
