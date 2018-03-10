/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_perlin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:37:50 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/10 13:49:25 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "perlin.h"
#include "vector_utilities.h"

static int		g_p[B + B + 2];
static t_point	g_g3[B + B + 2];
static int		g_start = 1;

static int		ntm_norme(int i)
{
	int k;
	int j;

	while (--i)
	{
		k = g_p[i];
		j = random() % B;
		g_p[i] = g_p[j];
		g_p[j] = k;
	}
	return (i);
}

static void		init_perlin(void)
{
	int		i;

	i = -1;
	while (++i < B)
	{
		g_p[i] = i;
		g_g3[i].x = (double)((random() % (B + B)) - B) / B;
		g_g3[i].y = (double)((random() % (B + B)) - B) / B;
		g_g3[i].z = (double)((random() % (B + B)) - B) / B;
		normalize_vector(&g_g3[i]);
	}
	i = ntm_norme(i);
	while (++i < B + 2)
	{
		g_p[B + i] = g_p[i];
		g_g3[B + i].x = g_g3[i].x;
		g_g3[B + i].y = g_g3[i].y;
		g_g3[B + i].z = g_g3[i].z;
	}
	g_start = 0;
}

double			noise3(t_point vec)
{
	t_pnoise	n;
	int			i;
	int			j;

	if (g_start)
		init_perlin();
	set_x(&n, vec);
	set_y(&n, vec);
	set_z(&n, vec);
	i = g_p[n.bx0];
	j = g_p[n.bx1];
	n.b00 = g_p[i + n.by0];
	n.b10 = g_p[j + n.by0];
	n.b01 = g_p[i + n.by1];
	n.b11 = g_p[j + n.by1];
	n.t = S_CURVE(n.rx0);
	n.sy = S_CURVE(n.ry0);
	n.sz = S_CURVE(n.rz0);
	set_a(&n, 1, g_g3);
	set_c(&n, g_g3);
	set_a(&n, 2, g_g3);
	set_d(&n, g_g3);
	return (LERP(n.sz, n.c, n.d));
}
