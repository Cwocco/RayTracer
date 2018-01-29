/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:31:49 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/01/26 18:19:21 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "rtv1.h"
#include "vector_utilities.h"

static t_point norm_sphere(t_point *pos, t_object *o)
{
	t_point norm;

	norm = vector_sub(*pos, o->pos);
	normalize_vector(&norm);
	return (norm);
}

static t_point norm_cone(t_point *pos, t_object *o)
{
	t_point norm;

	norm = vector_sub(*pos, o->pos);
	norm.y *= -1;
	normalize_vector(&norm);
	return (norm);
}

static t_point norm_cylinder(t_point *pos, t_object *o)
{
	t_point norm;

	norm = vector_sub(*pos, o->pos);
	norm.y = 0;
	normalize_vector(&norm);
	return (norm);
}

/*
static t_point norm_plan(t_point *pos, t_object *o)
{
	t_point norm;

	norm = vector_sub(*pos, obj->pos);
	
}
*/

t_point get_normal(t_point *pos, t_object *o)
{
	if (o->type == sphere)
		return (norm_sphere(pos, o));
//	else if (obj->type == plan)
	//	return (norm_plan(pos, obj));
	else if (o->type == cylinder)
		return (norm_cylinder(pos, o));
	else if (o->type == cone)
		return (norm_cone(pos, o));
	return ((t_point){0, 0, 0});
}
