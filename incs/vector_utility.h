/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utility.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:28:33 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/01/24 18:28:35 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_UTILITY_H
# define VECTOR_UTILITY_H

#include "rtv1.h"

t_point vector_sub(t_point p1, t_point p2);

void	normalize_vector(t_point *p);

// double	get_norm(t_point p);

double	vect_len(t_point p);

double 	get_angle(t_point a, t_point b);

double  vec_dist(t_point p1, t_point p2);

#endif
