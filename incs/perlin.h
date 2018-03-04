/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:49:03 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/04 15:47:51 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERLIN_H
# define PERLIN_H

# include "rtv1.h"

# define B 0x100
# define BM 0xff

# define N 0x1000
# define NP 12 / * 2^N */
# define NM 0xfff

# define S_CURVE(t) ( t * t * (3.0 - 2.0 * t) )
# define LERP(t, a, b) ( a + t * (b - a) )
# define AT3(rx, ry, rz) ( rx * n->q.x + ry * n->q.y + rz * n->q.z )

typedef struct	s_pnoise
{
	int		bx0;
	int		bx1;
	int		by0;
	int		by1;
	int		bz0;
	int		bz1;
	int		b00;
	int		b10;
	int		b01;
	int		b11;
	double	rx0;
	double	rx1;
	double	ry0;
	double	ry1;
	double	rz0;
	double	rz1;
	t_point	q;
	double	sy;
	double	sz;
	double	a;
	double	b;
	double	c;
	double	d;
	double	t;
	double	u;
	double	v;
}				t_pnoise;

void	set_x(t_pnoise *n, t_point vec);
void	set_y(t_pnoise *n, t_point vec);
void	set_z(t_pnoise *n, t_point vec);

void	set_a(t_pnoise *n, int i, t_point g3[B + B + 2]);
void	set_c(t_pnoise *n, t_point g3[B + B + 2]);
void	set_d(t_pnoise *n, t_point g3[B + B + 2]);

double	noise3(t_point vec);

void	inter_perlin(t_ray *ray, t_intersection *inter, t_color *c);
void	marble_perlin(t_ray *ray, t_intersection *inter, t_color *c);
void	get_texture(t_color *c, t_intersection *inter, t_ray *r);

#endif
