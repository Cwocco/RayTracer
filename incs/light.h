/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 12:41:34 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/10 17:47:55 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "rtv1.h"

void		set_ambient_light(t_color *c, t_object obj);

void		add_diffuse_light(t_color *c, t_object obj, t_light *light,
						double f[2]);

void		add_specular_light(t_color *c, t_point r_pos,
						t_intersection *inter, double coef);

t_color		process_light(t_env *env, t_intersection *inter, t_ray r);

#endif
