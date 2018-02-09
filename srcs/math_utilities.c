/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:32:34 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/02/02 15:24:10 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	solve_equation(t_point poly, double *t)
{
	double delta;
	double x1;
	double x2;

	delta = get_delta(poly.x, poly.y, poly.z);
	if (delta < 0)
		return ;
	x1 = (-poly.y + sqrt(delta)) / (2.0 * poly.x);
	x2 = (-poly.y - sqrt(delta)) / (2.0 * poly.x);
	if (x1 < x2 && x1 > 0.000001)
		*t = x1;
	else if (x2 > 0.000001)
		*t = x2;
}

double	get_delta(double a, double b, double c)
{
	return (b * b - 4.0 * a * c);
}
