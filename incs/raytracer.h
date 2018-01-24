/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:32:10 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/01/24 18:32:10 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

#include "rtv1.h"

void		raytracer_process(t_env *env);

t_ray		get_prim_ray(t_2ipair p, t_env *env);

t_color		raytrace(t_ray r, t_env *env);

t_color     process_light(t_env *env, t_point inter, t_color c, t_object *obj_ptr);

t_bool		check_object_between(t_point light_pos, t_point inter, t_object *obj);

#endif
