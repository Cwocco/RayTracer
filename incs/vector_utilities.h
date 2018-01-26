/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utilities.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:26:47 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/01/26 10:26:57 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_UTILITIES_H
# define VECTOR_UTILITIES_H

#include "rtv1.h"

t_point vector_sub(t_point p1, t_point p2);

void	normalize_vector(t_point *p);

// double	get_norm(t_point p);

double	vect_len(t_point p);

double 	get_angle(t_point a, t_point b);

double  vec_dist(t_point p1, t_point p2);

#endif
