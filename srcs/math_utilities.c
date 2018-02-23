/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:32:34 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/02/23 16:51:33 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double get_sqr(double val)
{
	return ((val) * (val));
}

void	solve_equation(t_point poly, double *t)
{
	double delta;
	double x1;
	double x2;

	delta = get_delta(poly.x, poly.y, poly.z);
	if (delta < 0.000000)
		return ;
	x1 = (-poly.y + sqrt(delta)) / (2.0 * poly.x);
	x2 = (-poly.y - sqrt(delta)) / (2.0 * poly.x);
	if (x1 < x2 && x1 > 0.000001)
		*t = x1;
	else if (x2 > 0.000001 && (x1 > x2 || x1 <= 0.000001))
		*t = x2;
	else if (x1 < 0.000001 && x2 < 0.000001)
		*t = MAX_RAY_LENGTH;
}

double	get_delta(double a, double b, double c)
{
	return (b * b - 4.0 * a * c);
}
