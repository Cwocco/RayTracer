/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 08:48:09 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/03 11:24:09 by jpicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	vec_rotate_x(t_point *v, double ang)
{
	double tmp_y;
	double tmp_x;

	tmp_y = v->y;
	tmp_x = v->z;
	v->y = tmp_y * cos(ang) - tmp_x * sin(ang);
	v->z = tmp_y * sin(ang) + tmp_x * cos(ang);
}

static void	vec_rotate_y(t_point *v, double ang)
{
	double tmp_x;
	double tmp_z;

	tmp_x = v->x;
	tmp_z = v->z;
	v->z = tmp_z * cos(ang) - tmp_x * sin(ang);
	v->x = tmp_z * sin(ang) + tmp_x * cos(ang);
}

static void	vec_rotate_z(t_point *v, double ang)
{
	double tmp_x;
	double tmp_y;

	tmp_x = v->x;
	tmp_y = v->y;
	v->x = tmp_x * cos(ang) - tmp_y * sin(ang);
	v->y = tmp_x * sin(ang) + tmp_y * cos(ang);
}

void		vec_rotate(t_point *v, t_point rot)
{
	vec_rotate_y(v, ft_degtorad(rot.y));
	vec_rotate_x(v, ft_degtorad(rot.x));
	vec_rotate_z(v, ft_degtorad(rot.z));
}

void		vec_unrotate(t_point *v, t_point rot)
{
	vec_rotate_y(v, -ft_degtorad(rot.y));
	vec_rotate_x(v, -ft_degtorad(rot.x));
	vec_rotate_z(v, -ft_degtorad(rot.z));
}
