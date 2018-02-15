/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 08:48:09 by rpinoit           #+#    #+#             */
/*   Updated: 2018/02/15 14:04:54 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void rotate_x(t_point *vec, double angle)
{
	double	tmp_y;
	double	tmp_z;

	tmp_y = vec->y;
	tmp_z = vec->z;
	vec->y = ((tmp_y * cos(angle)) - (tmp_z * sin(angle)));
	vec->z = ((tmp_y * sin(angle)) + (tmp_z * cos(angle)));
}

//Profondeur-> Formule Z
static void rotate_y(t_point *vec, double angle)
{
	double	tmp_x;
	double	tmp_z;

	tmp_x = vec->x;
	tmp_z = vec->z;
	vec->z = ((tmp_z * cos(angle)) - (tmp_x * sin(angle)));
	vec->x = ((tmp_z * sin(angle)) + (tmp_x * cos(angle)));
}

//Hauteur-> formule Y
static void rotate_z(t_point *vec, double angle)
{
	double  tmp_x;
	double  tmp_y;

	tmp_x = vec->x;
	tmp_y = vec->y;
	vec->x = ((tmp_x * cos(angle)) - (tmp_y * sin(angle)));
	vec->y = ((tmp_x * sin(angle)) + (tmp_y * cos(angle)));
}

void vec_unrotate(t_point *vec, t_point rotate)
{
	rotate_x(vec, -ft_degtorad(rotate.x));
	rotate_y(vec, -ft_degtorad(rotate.y));
	rotate_z(vec, -ft_degtorad(rotate.z));
}

void rotate_vec(t_point *vec, t_point rotate)
{
	rotate_x(vec, ft_degtorad(rotate.x));
	rotate_y(vec, ft_degtorad(rotate.y));
	rotate_z(vec, ft_degtorad(rotate.z));
}
