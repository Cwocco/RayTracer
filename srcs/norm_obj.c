/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:31:49 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/01/24 15:59:32 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "rtv1.h"

static t_point norm_sphere(t_point *pos, t_object *o)
{
	t_point norm;

	norm = vector_sub(*pos, obj->pos);
	normalize_vector(&norm);
	return (norm);
}

t_point get_normal(t_point *pos, t_object *o)
{
	if (obj->type == sphere)
		return (norm_sphere(pos, obj));
/*
	else if (obj->type == plan)
		return ();
	else if (obj->type == cylinder)
		return ();
	else if (obj->type == cone)
		return ();
*/
	return ((t_point){0, 0, 0});
}
