/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_normal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:25:18 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/08 18:16:34 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_NORMAL_H
# define OBJ_NORMAL_H

# include "rtv1.h"

t_point		sphere_normal(t_intersection *inter);
t_point		cylinder_normal(t_intersection *inter);
t_point		cone_normal(t_intersection *inter);
t_point		plane_normal(t_intersection *inter);
t_point		get_normal(t_intersection *inter);

#endif
