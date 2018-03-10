/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:26:06 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/10 13:55:01 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ellipse.h"
#include "vector_utilities.h"
#include "vector_rotate.h"

t_point			sphere_normal(t_intersection *inter)
{
	t_point		normal;

	normal = vector_sub(inter->pos, inter->obj.pos);
	normalize_vector(&normal);
	return (normal);
}

t_point			cylinder_normal(t_intersection *inter)
{
	t_point		normal;

	normal = vector_sub(inter->pos, inter->obj.pos);
	vec_rotate(&normal, inter->obj.rot);
	normal.y = 0;
	vec_unrotate(&normal, inter->obj.rot);
	normalize_vector(&normal);
	return (normal);
}

t_point			cone_normal(t_intersection *inter)
{
	t_point		normal;

	normal = vector_sub(inter->pos, inter->obj.pos);
	vec_rotate(&normal, inter->obj.rot);
	normal.y *= -1;
	vec_unrotate(&normal, inter->obj.rot);
	normalize_vector(&normal);
	return (normal);
}

t_point			plane_normal(t_intersection *inter)
{
	t_point		normal;

	normal = (t_point){inter->obj.normal.x,
				inter->obj.normal.y, inter->obj.normal.z};
	normalize_vector(&normal);
	return (normal);
}

t_point			get_normal(t_intersection *inter)
{
	t_object_type type;

	type = inter->obj.type;
	if (type == sphere)
		return (sphere_normal(inter));
	else if (type == cylinder)
		return (cylinder_normal(inter));
	else if (type == cone)
		return (cone_normal(inter));
	else if (type == plan)
		return (plane_normal(inter));
	else if (type == ellipse)
		return (ellipse_normal(inter));
	return ((t_point){0, 0, 0});
}
