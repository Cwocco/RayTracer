/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utilities.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:26:21 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/01/31 17:37:13 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILITIES_H
# define MATH_UTILITIES_H

# include "rtv1.h"

void	solve_equation(t_point poly, double *t);

double	get_delta(double a, double b, double c);

#endif
