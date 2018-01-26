/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:32:34 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/01/26 10:33:34 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utilities.h"
#include "vector_utilities.h"

double	get_delta(double a, double b, double c)
{
	return (b * b - 4 * a * c);
}

double	dot_product(t_point p1, t_point p2)
{
	double n1;
	double n2;

	normalize_vector(&p1);
	normalize_vector(&p2);
	n1 = vect_len(p1);
	n2 = vect_len(p2);
	return (p1.x * p2.x + p1.y * p2.y + p1.z * p2.z);
}

// Commented by ada-cunh: Calcule produit vectoriel
t_point	cross_product(t_point a, t_point b)
{
	t_point n;

	n.x = (a.y * b.z) - (a.z * b.y);
	n.y = (a.z * b.x) - (a.x * b.z);
	n.z = (a.x * b.y) - (a.y * b.x);
	return (n);
}
