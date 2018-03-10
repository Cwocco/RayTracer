/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_perlin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:17:59 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/10 11:17:15 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perlin.h"

void	set_x(t_pnoise *n, t_point vec)
{
	n->t = vec.x + N;
	n->bx0 = ((int)n->t) & BM;
	n->bx1 = (n->bx0 + 1) & BM;
	n->rx0 = n->t - (int)n->t;
	n->rx1 = n->rx0 - 1.0;
}

void	set_y(t_pnoise *n, t_point vec)
{
	n->t = vec.y + N;
	n->by0 = ((int)n->t) & BM;
	n->by1 = (n->by0 + 1) & BM;
	n->ry0 = n->t - (int)n->t;
	n->ry1 = n->ry0 - 1.0;
}

void	set_z(t_pnoise *n, t_point vec)
{
	n->t = vec.z + N;
	n->bz0 = ((int)n->t) & BM;
	n->bz1 = (n->bz0 + 1) & BM;
	n->rz0 = n->t - (int)n->t;
	n->rz1 = n->rz0 - 1.0;
}
