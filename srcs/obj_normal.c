/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:26:06 by rpinoit           #+#    #+#             */
/*   Updated: 2018/01/29 16:08:51 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_normal.h"
#include "vector_utilities.h"

void	get_sphere_normal(t_point *normal, t_intersection *inter)
{
	*normal = vector_sub(inter->pos, inter->obj->pos);
}

void	get_plane_normal(t_point *normal, t_intersection *inter)
{
	*normal = inter->obj->normal;
}

void	get_cylinder_normal(t_point *normal, t_intersection *inter)
{
	(void)inter;
	*normal = (t_point){0, 0, 0};
}

void	get_cone_normal(t_point *normal, t_intersection *inter)
{
	(void)inter;
	*normal = (t_point){0, 0, 0};
}

t_point		get_normal(t_point normal, t_intersection *inter)
{
	t_object	*obj;

	obj = inter->obj;
	if (obj->type == sphere)
		get_sphere_normal(&normal, inter);
	else if (obj->type == plan)
		get_plane_normal(&normal, inter);
	else if (obj->type == cylinder)
		get_cylinder_normal(&normal, inter);
	else if (obj->type == cone)
		get_cone_normal(&normal, inter);
	return (normal);
}
