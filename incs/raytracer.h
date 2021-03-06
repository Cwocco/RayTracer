/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:32:10 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/10 19:25:17 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "rtv1.h"

void		raytracer_process_option(t_thenv *thenv, t_color *c);

void		*raytracer_process(t_thenv *thenv);

t_ray		get_prim_ray(const t_point p, const t_env *env);

t_color		raytrace(const t_ray r, t_env *env);

#endif
