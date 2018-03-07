/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m4_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/10 21:32:14 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m4.h"

inline t_m4		ft_m4_rotx(double rad)
{
	double s;
	double c;

	s = sin(rad);
	c = cos(rad);
	return (ft_m4(
		ft_m1(1, 0, 0, 0),
		ft_m1(0, c, -s, 0),
		ft_m1(0, s, c, 0),
		ft_m1(0, 0, 0, 1)));
}

inline t_m4		ft_m4_roty(double rad)
{
	double s;
	double c;

	s = sin(rad);
	c = cos(rad);
	return (ft_m4(
		ft_m1(c, 0, s, 0),
		ft_m1(0, 1, 0, 0),
		ft_m1(-s, 0, c, 0),
		ft_m1(0, 0, 0, 1)));
}

inline t_m4		ft_m4_rotz(double rad)
{
	double s;
	double c;

	s = sin(rad);
	c = cos(rad);
	return (ft_m4(
		ft_m1(c, -s, 0, 0),
		ft_m1(s, c, 0, 0),
		ft_m1(0, 0, 1, 0),
		ft_m1(0, 0, 0, 1)));
}

inline t_m4		ft_m4_rot(double rad, t_point a)
{
	double	s;
	double	c;

	normalize_vector(&a);
	s = sin(rad);
	c = cos(rad);
	return (ft_m4(
		ft_m1(c + a.x * a.x * (1 - c), a.x * a.y * (1 - c) - a.z * s,
			a.x * a.z * (1 - c) + a.y * s, 0),
		ft_m1(a.y * a.x * (1 - c) + a.z * s, c + a.y * a.y * (1 - c),
			a.y * a.z * (1 - c) - a.x * s, 0),
		ft_m1(a.z * a.x * (1 - c) - a.y * s, a.z * a.y * (1 - c) + a.x * s,
			c + a.z * a.z * (1 - c), 0),
		ft_m1(0, 0, 0, 1)));
}

inline t_point		ft_m4_apply(t_m4 m, t_point to)
{
	t_point	v;
	double	w;

	v = (t_point){
		to.x * m.m[0][0] + to.y * m.m[1][0] + to.z * m.m[2][0] + m.m[3][0],
		to.x * m.m[0][1] + to.y * m.m[1][1] + to.z * m.m[2][1] + m.m[3][1],
		to.x * m.m[0][2] + to.y * m.m[1][2] + to.z * m.m[2][2] + m.m[3][2]};
	w = m.m[0][3] * to.x + m.m[1][3] * to.y + m.m[2][3] * to.z + m.m[3][3];
	if (w != 0 && w != 1)
		return ((t_point){v.x / w, v.y / w, v.z / w});
	return (v);
}
