/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:32:28 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/02/22 18:14:54 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TYPES_H
# define TYPES_H

# include "rtv1.h"

typedef unsigned char	t_uchar;

typedef struct			s_color
{
	double		r;
	double		g;
	double		b;
	double		a;
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
	cone,
	hyperboloid
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
	t_point		rot;
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
	t_point			axis;

	//CONE
	//double		radius;
	t_ray			normal_vector;
	t_point			rot;      
    struct s_object *next;
}                       t_object;

typedef struct			s_intersection
{
	t_object	obj;
	t_point		pos;
	t_point		normal;
	t_point		light_vector;
	double		t;
}						t_intersection;

typedef struct          s_tmp
{
    t_light		*light;
    t_object	*obj;
    t_point		light_pos;
    t_ray		shadow_ray;
    t_intersection final_inter;
	t_color		c;
//   double		d1;
//   double		d2;
    double		angle;
}                       t_tmp;

#endif
