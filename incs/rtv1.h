/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:32:17 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/10 15:19:17 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "types.h"
# include "mlx.h"
# include <pthread.h>
# include <math.h>
# include <stdint.h>

# define WIN_W 1000
# define WIN_H 1000

# define M_LFT 1

# define KEY_ESCAPE 53
# define KEY_LEFT 123
# define KEY_DOWN 126
# define KEY_RIGHT 124
# define KEY_UP 125
# define KEY_MINUS 27
# define KEY_PLUS 24
# define KEY_A 0
# define KEY_D 2
# define KEY_M 46
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

# define NBTHREAD 16

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
	t_2ipair			size;
	char				*name;
	t_bool				focus;
}						t_win;

typedef struct			s_rend
{
	t_uint32			*pixels;
	t_2ipair			size;
}						t_rend;

typedef struct			s_scene
{
	t_ray				prim_r;
	t_object			*objs;
	t_light				*lgts;
	t_camera			cam;
}						t_scene;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					active_icon;
	void				*img_light_on_1;
	void				*img_light_on_2;
	void				*img_light_off_1;
	void				*img_light_off_2;
	void				*img_shadow_on_1;
	void				*img_shadow_on_2;
	void				*img_shadow_off_1;
	void				*img_shadow_off_2;
	int					bpp;
	int					sline;
	int					endian;
	int					win_w;
	int					win_h;
	int					mark;
	int					ambilight;
	int					shadow;
	t_scene				scene;
	int					argc;
	char				**argv;
	t_point				obj_rot;
	t_point				cam_rot;
}						t_env;

typedef struct			s_thenv
{
	t_env				*env;
	int					from_y;
	int					to_y;
}						t_thenv;

void					put_pixel(t_env *env, t_point *pos, t_color c);

void					mlx_draw_rt(t_env *env);

int						expose_hook(t_env *env);

void					init(t_env *env);

void					process(t_env *env);

void					destroy(t_env *env);

int						red_cross(void);

int						loop_hook(t_env *env);

int						mouse_motion(unsigned int x, unsigned y, t_env *e);

int						key_press(int key, t_env *env);

int						button_event(int button, int x, int y, t_env *e);

void					process_dynamic(t_env *env);

int						rot_obj_keyhook(const int key, t_env *env);

#endif
