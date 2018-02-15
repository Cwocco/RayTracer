/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:30:57 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/02/13 12:50:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	vector_norm(t_point a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

double	dot_product(t_point a, t_point b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_point	vector_multiply(t_point vec, double factor)
{
	t_point ret;

	ret.x = vec.x * factor;
	ret.y = vec.y * factor;
	ret.z = vec.z * factor;
	return (ret);
}

void	normalize_vector(t_point *p)
{
	double	len;

	len = sqrt((p->x * p->x) + (p->y * p->y) + (p->z * p->z));
	if (len > 0)
	{
		p->x = p->x / len;
		p->y = p->y / len;
		p->z = p->z / len;
	}
}

t_point	vector_sub(t_point p1, t_point p2)
{
	t_point	p;

	p.x = p1.x - p2.x;
	p.y = p1.y - p2.y;
	p.z = p1.z - p2.z;
	return (p);
}

t_point vector_add(t_point p1, t_point p2)
{
	t_point p;

	p.x = p1.x + p2.x;
	p.y = p1.y + p2.y;
	p.z = p1.z + p2.z;
	return (p);
}
