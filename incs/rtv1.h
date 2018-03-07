/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:32:17 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/06 17:30:16 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "types.h"
# include "event.h"
# include "mlx.h"
# include <pthread.h>
# include <math.h>
# include <stdio.h>
# include <stdint.h>

# define WIN_W 1000
# define WIN_H 1000

# define KEY_ESCAPE 53
# define KEY_LEFT 123
# define KEY_DOWN 126
# define KEY_RIGHT 124
# define KEY_UP 125
# define KEY_MINUS 27
# define KEY_PLUS 24
# define KEY_A 0
# define KEY_D 2
# define KEY_W 13
# define KEY_S 1
# define KEY_1 18
# define KEY_2 19
# define KEY_I 34
# define KEY_J 38
# define KEY_L 37
# define KEY_K 40
# define KEY_8 28
# define KEY_9 25

# define NBTHREAD 8

# define MAX_RAY_DEPTH 4
# define MAX_RAY_LENGTH 0xffffff

# define SEPIA 0
# define FIFTYSHADES 0
# define DALTO 0
# define TEXTURE 0
# define ANTI 0

typedef unsigned char	t_bool;
typedef unsigned int	t_uint32;

typedef struct			s_win
{
	t_2ipair	size;
	char		*name;
	t_bool		focus;
}						t_win;

typedef struct			s_rend
{
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
	void            *mlx;
	void            *win;
	void            *img;
	char            *data;
	int             bpp;
	int             sline;
	int             endian;
	int				win_w;
	int				win_h;
	int				mark;
	t_scene		scene;
//	t_event		event;
//	t_win		win;
//	t_rend		rend;
	int			argc;
	char		**argv;
	t_point		obj_rot;
	t_point		cam_rot;
}						t_env;

typedef struct			s_thenv
{
	t_env				*env;
	int					from_y;
	int					to_y;
}						t_thenv;

void put_pixel(t_env *env, t_point *pos, t_color c);

void    mlx_draw_rt(t_env *env);

int     expose_hook(t_env *env);

int     key_hook(int key, t_env *env);

void					init(t_env *env);

void					process(t_env *env);

void					destroy(t_env *env);

# include "perlin.h"
# include "anti_alias.h"
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
