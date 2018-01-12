/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utility.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 20:17:46 by nboste            #+#    #+#             */
/*   Updated: 2018/01/11 08:56:46 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_UTILITY_H
# define VECTOR_UTILITY_H

#include "rtv1.h"

void	normalize_vector(t_point *p);

double	get_norm(t_point p);

float 	get_angle(t_point a, t_point b);

double	calc_dist(t_point a, t_point b);

#endif
