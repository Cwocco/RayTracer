/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utilities.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:26:21 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/03 11:18:41 by jpicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILITIES_H
# define MATH_UTILITIES_H

# include "rtv1.h"

double	get_sqr(double val);

void	solve_equation(t_point poly, double *t);

double	get_delta(double a, double b, double c);

#endif
