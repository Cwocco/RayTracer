/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:32:10 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/02/16 12:52:46 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "rtv1.h"

void		raytracer_process(t_env *env);

t_ray		get_prim_ray(t_point p, t_env *env);

t_color		raytrace(t_ray r, t_env *env);

#endif
