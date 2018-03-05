/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_normal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:25:18 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/03 11:18:43 by jpicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_NORMAL_H
# define OBJ_NORMAL_H

# include "rtv1.h"

/*
void		get_sphere_normal(t_intersection *inter);

void		get_plane_normal(t_intersection *inter);

void		get_cylinder_normal(t_intersection *inter);

void		get_cone_normal(t_intersection *inter);

void		get_normal(t_intersection *inter);
*/

t_point   sphere_normal(t_intersection *inter);
t_point cylinder_normal(t_intersection *inter);
t_point   cone_normal(t_intersection *inter);
t_point   plane_normal(t_intersection *inter);
t_point          get_normal(t_intersection *inter);
#endif
