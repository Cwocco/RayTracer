/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 12:41:34 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/01/26 18:11:22 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "rtv1.h"

t_color     process_light(t_light *lst_light, t_object *lst_obj, t_object *obj_ptr, t_point inter);

t_color     get_light_color(t_object *object, t_point inter, t_light *light);

t_point       calc_vector(t_point a, t_point b);

#endif
