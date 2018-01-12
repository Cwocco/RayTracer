/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:04:25 by nboste            #+#    #+#             */
/*   Updated: 2017/10/30 15:48:59 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

#include "rtv1.h"

void		raytracer_process(t_env *env);

t_ray		get_prim_ray(t_2ipair p, t_env *env);

t_color		raytrace(t_ray r, t_env *env);

#endif
