/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:32:17 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/02/05 08:49:26 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "SDL.h"
# include "libft.h"
# include "types.h"
# include "event.h"

# define W_WIDTH 1000
# define W_HEIGHT 1000

# define MAX_RAY_DEPTH 4
# define MAX_RAY_LENGTH 0xffffff

typedef unsigned char	t_bool;
typedef unsigned int	t_uint32;

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

# include "camera.h"
# include "light.h"
# include "raytracer.h"
# include "drawer.h"
# include "math_utilities.h"
# include "error.h"
# include "obj_normal.h"
# include "event.h"
# include "parser.h"
# include "vector_utilities.h"
# include "intersection.h"
# include "pixel.h"
# include "vector_rotate.h"

#endif
