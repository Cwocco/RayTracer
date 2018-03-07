/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 08:48:09 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/03 11:24:09 by jpicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "m4.h"

void    rotate_vec(t_point *v, t_point rot)
{
    t_m4 m;

    m = ft_m4_rotx(ft_degtorad(rot.x));
    m = ft_m4_mul(m, ft_m4_roty(ft_degtorad(rot.z)));
    m = ft_m4_mul(m, ft_m4_rotz(ft_degtorad(rot.y)));
    *v = ft_m4_apply(m, *v);
}

void    vec_unrotate(t_point *v, t_point rot)
{
    t_m4 m;

    m = ft_m4_rotx(-ft_degtorad(rot.x));
    m = ft_m4_mul(m, ft_m4_roty(-ft_degtorad(rot.z)));
    m = ft_m4_mul(m, ft_m4_rotz(-ft_degtorad(rot.y)));
    *v = ft_m4_apply(m, *v);
}
