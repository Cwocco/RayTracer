/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:31:44 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/02/16 15:28:06 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "rtv1.h"

t_bool		intersection(t_env *env,t_ray r, t_object *obj, t_intersection *inter);

#endif
