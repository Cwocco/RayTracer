/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:26:06 by rpinoit           #+#    #+#             */
/*   Updated: 2018/02/15 13:59:39 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_sphere_normal(t_intersection *inter)
{
	inter->normal = vector_sub(inter->pos, inter->obj.pos);
	normalize_vector(&inter->normal);
}

void	get_plane_normal(t_intersection *inter)
{
	inter->normal = inter->obj.normal;
	normalize_vector(&inter->normal);
}

void	get_cylinder_normal(t_intersection *inter)
{
	t_point rotate;
	t_point	normal;

	rotate = (t_point){90, -30, 90};
	normal = vector_sub(inter->pos, inter->obj.pos);
	rotate_vec(&normal, rotate);
	normal.z = 0;
	vec_unrotate(&normal, rotate);
	inter->normal = normal;
	normalize_vector(&inter->normal);
}

void	get_cone_normal(t_intersection *inter)
{
	t_point rotate;
	t_point	normal;

	rotate = (t_point){0, 0, 0};
	normal = vector_sub(inter->pos, inter->obj.pos);
	rotate_vec(&normal, rotate);
	normal.z *= -1;
	vec_unrotate(&normal, rotate);
	inter->normal = normal;
	normalize_vector(&inter->normal);
}


void	get_normal(t_intersection *inter)
{
	t_object_type	type;

	type = inter->obj.type;
	if (type == sphere)
		get_sphere_normal(inter);
	else if (type == plan)
		get_plane_normal(inter);
	else if (type == cylinder)
		get_cylinder_normal(inter);
	else if (type == cone)
		get_cone_normal(inter);
}
