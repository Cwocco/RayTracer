/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:30:57 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/01/26 10:30:57 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_utilities.h"
#include <math.h>

// Commented by ada-cunh: On garde le vecteur 1:1 pour avoir la direction
void	normalize_vector(t_point *p)
{
	double  len;

	len = sqrt((p->x * p->x) + (p->y * p->y) + (p->z * p->z));
	if (len > 0)
	{
		p->x = p->x / len;
		p->y = p->y / len;
		p->z = p->z / len;
	}
}

// Commented by ada-cunh: Norm
double vect_len(t_point p)
{
	double len;

	len = sqrt((p.x * p.x) + (p.y * p.y) + (p.z * p.z));
	return (len);
}

// Commented by ada-cunh: Calcul vect p1-p2
t_point	vector_sub(t_point p1, t_point p2)
{
	t_point	p;

	p.x = p1.x - p2.x;
	p.y = p1.y - p2.y;
	p.z = p1.z - p2.z;
	return (p);
}

double	vec_dist(t_point p1, t_point p2)
{
	return (sqrt((p2.x - p1.x) * (p2.x - p1.x) +
				 (p2.y - p1.y) * (p2.y - p1.y) +
				 (p2.z - p1.z) * (p2.z - p1.z)));
}

/*
double	get_norm(t_point p)
{
	return (sqrt((p.x * p.x) + (p.y * p.y) + (p.z * p.z)));
}
*/
double	get_angle(t_point a, t_point b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
