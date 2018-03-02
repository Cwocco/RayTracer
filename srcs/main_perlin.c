/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_perlin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:37:50 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/02 14:34:39 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perlin.h"

static int P[B + B + 2];
static t_point g3[B + B + 2];
static int start = 1;

static void init_perlin(void)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < B)
	{
		P[i] = i;
		g3[i].x = (double)((random() % (B + B)) - B) / B;
		g3[i].y = (double)((random() % (B + B)) - B) / B;
		g3[i].z = (double)((random() % (B + B)) - B) / B;
		normalize_vector(&g3[i]);
	}
	while (--i) 
	{
		j = 0;
		k = P[i];
		P[i] = P[j = random() % B];
		P[j] = k;
	}
	i = -1;
	while (++i < B + 2)
	{
		P[B + i] = P[i];
		g3[B + i].x = g3[i].x;
		g3[B + i].y = g3[i].y;
		g3[B + i].z = g3[i].z;
	}
	start = 0;
}

double noise3(t_point vec)
{
	t_pnoise	n;
	int			i;
	int			j;

	if (start) 
		init_perlin();
	set_x(&n, vec);
	set_y(&n, vec);
	set_z(&n, vec);
	i = P[n.bx0];
	j = P[n.bx1];
	n.b00 = P[i + n.by0];
	n.b10 = P[j + n.by0];
	n.b01 = P[i + n.by1];
	n.b11 = P[j + n.by1];
	n.t = S_CURVE(n.rx0);
	n.sy = S_CURVE(n.ry0);
	n.sz = S_CURVE(n.rz0);
	set_a(&n, 1, g3);
	set_c(&n, g3);
	set_a(&n, 2, g3);
	set_d(&n, g3);
	return (LERP(n.sz, n.c, n.d));
}
