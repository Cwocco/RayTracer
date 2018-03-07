/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft/math/m4.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 10:28:45 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/10 11:58:52 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M4_H
# define M4_H

# include "rtv1.h"

typedef struct	s_m1_fields
{
	double		m0;
	double		m1;
	double		m2;
	double		m3;
}				t_m1_fields;

typedef union	u_m1
{
	t_m1_fields	f;
	double		m[4];
}				t_m1;

typedef struct	s_m4_fields
{
	t_m1		m0;
	t_m1		m1;
	t_m1		m2;
	t_m1		m3;
}				t_m4_fields;

typedef union	u_m4
{
	t_m4_fields	f;
	double		m[4][4];
}				t_m4;

extern t_m1		ft_m1(double m0, double m1, double m2, double m3);
extern t_m4		ft_m4(t_m1 m0, t_m1 m1, t_m1 m2, t_m1 m3);
extern t_m4		ft_m4_identity(void);
extern t_m4		ft_m4_transx(double s);
extern t_m4		ft_m4_transy(double s);
extern t_m4		ft_m4_transz(double s);
extern t_m4		ft_m4_trans(t_point off);
extern t_m4		ft_m4_scale(t_point scale);
extern t_m4		ft_m4_rotx(double rad);
extern t_m4		ft_m4_roty(double rad);
extern t_m4		ft_m4_rotz(double rad);
extern t_m4		ft_m4_rot(double rad, t_point a);
extern t_m4		ft_m4_mul(t_m4 a, t_m4 b);
extern t_point	ft_m4_apply(t_m4 m, t_point to);

#endif
