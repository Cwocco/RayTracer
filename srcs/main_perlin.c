/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_perlin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:37:50 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/01 14:10:53 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perlin.h"

static P[B + B + 2]
static t_point G3[B + B + 2];
static int start = 1;

static void init_perlin(void)
{
	int i;
	int j;
	int k;

	i = -1;
	while (++i < B)
	{
		P[i] = i;
		G3[i].x = (double)((random() % (B + B)) - B) / B;
		G3[i].y = (double)((random() % (B + B)) - B) / B;
		G3[i].z = (double)((random() % (B + B)) - B) / B;
		normalize_vector(&G3[i]);
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
		G3[B + i].x = G3[i].x;
		G3[B + i][j].y = G3[i][j].y;
		G3[B + i][j].z = G3[i][j].z;
	}
	start = 0;
}

double noise3(t_point vec)
{
	t_pnoise n;
	register i;
	register j;

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
	set_a(&n, 1, g_g3);
	set_c(&n, g_g3);
	set_a(&n, 2, g_g3);
	set_d(&n, g_g3);
	return (LERP(n.sz, n.c, n.d));
}
