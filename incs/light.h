/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 12:41:34 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/01/11 14:18:08 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "rtv1.h"

t_color		lights(t_point inter, t_env *env, t_object *obj);

t_ray		calc_vector(t_point a, t_point b);

void		set_color();

#endif
