
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:44:47 by nboste            #+#    #+#             */
/*   Updated: 2018/01/11 14:12:54 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "ft_types.h"

typedef unsigned char	t_uchar;

typedef struct			s_color
{
	t_uchar		r;
	t_uchar		g;
	t_uchar		b;
	t_uchar		a;
}						t_color;

typedef struct			s_point
{
	double		x;
	double		y;
	double		z;
}						t_point;

typedef t_point			t_norm;

typedef enum			e_object_type
{
	sphere,
	plan,
	cylinder,
	cone
}						t_object_type;

/* typedef struct			s_object
{
	t_object_type	type;
	t_point			pos;
	t_light			test;

	// SPHERE
	double			radius;
	t_color			color;

	// PLAN
	t_point			normal;

	// CYLINDER
	//double		radius;
	t_point			axis;

	//CONE
	double			alpha;
	//t_point		axis;

	struct s_object	*next;
}						t_object; */

typedef struct			s_ray
{
	t_point		pos;
	t_point		dir;
	t_uint32	depth;
}						t_ray;

typedef struct			s_uvn
{
	t_point		u; // right
	t_point		v; // up
	t_point		n; // target
}						t_uvn;

typedef struct			s_camera
{
	t_point		pos;
	double		ratio;
	double		fov;
	double		d;
	t_2dpair	near;
	t_2dpair	step;
	t_uvn		uvn;
}						t_camera;

typedef struct			s_material
{
//	float			shine;
//  float			shinestrength;
//  float			transmission;
//  float			reflection;
    t_color			specular;
    t_color			ambient;
    t_color			diffuse;
}						t_material;


typedef struct			s_light
{
	t_point			pos;
//  t_point			vect;
    t_color			color;
	struct s_light	*next;
}						t_light;

typedef struct          s_object
{
    t_object_type   type;
    t_point         pos;
//    t_light         test;
	t_material			mater;

    // SPHERE
    double          radius;
    t_color         color;

    // PLAN
    t_point         normal;

    // CYLINDER
    //double        radius;
    t_point         axis;

	//CONE
	//double		alpha;
	//t_point		axis;
      
    struct s_object *next;
}                       t_object;

typedef struct          s_degueulasse
{
    t_light		*l;
    t_object	*o;
    t_point		l_pos;
    t_ray		s_ray;
    t_point		final_inter;
//   double		d1;
//   double		d2;
    float		angle;

}                       t_degueulasse;

#endif
