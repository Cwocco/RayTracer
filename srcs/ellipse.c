/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:32:48 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/08 17:57:56 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_point	ellipse_normal(t_intersection *inter)
{
	t_point	normal;

	normal = vector_sub(inter->pos, inter->obj.pos);
	normal.x = 0;
	normalize_vector(&normal);
	return (normal);
}
