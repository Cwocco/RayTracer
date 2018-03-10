/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipse.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:39:10 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/10 09:17:49 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELLIPSE_H
# define ELLIPSE_H

# include "rtv1.h"

void		inter_ellipse(t_ray r, t_object *obj, double *t);

t_point		ellipse_normal(t_intersection *inter);

#endif
