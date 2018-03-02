/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param_perlin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:42:50 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/02 11:03:28 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perlin.h"

void set_a(t_pnoise *n, int i, t_point g3[B + B + 2])
{
	if (i == 1)
	{
		n->q = g3[n->b00 + n->bz0];
		n->u = AT3(n->rx0, n->ry0, n->rz0);
		n->q = g3[n->b10 + n->bz0];
		n->v = AT3(n->rx1, n->ry0, n->rz0);
		n->a = LERP(n->t, n->u, n->v);
	}
	else if (i == 2)
	{
		n->q = g3[n->b00 + n->bz1] ; 
		n->u = AT3(n->rx0, n->ry0, n->rz1);
		n->q = g3[n->b10 + n->bz1] ; 
		n->v = AT3(n->rx1, n->ry0, n->rz1);
		n->a = LERP(n->t, n->u, n->v);
	}
}

void set_c(t_pnoise *n, t_point g3[B + B + 2])
{
	n->q = g3[n->b01 + n->bz0];
	n->u = AT3(n->rx0, n->ry1, n->rz0);
	n->q = g3[n->b11 + n->bz0];
	n->v = AT3(n->rx1, n->ry1, n->rz0);
	n->b = LERP(n->t, n->u, n->v);
	n->c = LERP(n->sy, n->a, n->b);
}

void set_d(t_pnoise *n, t_point g3[B + B + 2])
{
	n->q = g3[n->b01 + n->bz1];
	n->u = AT3(n->rx0, n->ry1, n->rz1);
	n->q = g3[n->b11 + n->bz1]; 
	n->v = AT3(n->rx1, n->ry1, n->rz1);
	n->b = LERP(n->t, n->u, n->v);
	n->d = LERP(n->sy, n->a, n->b);
}
