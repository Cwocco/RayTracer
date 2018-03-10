/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:32:28 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/10 15:44:46 by rpinoit          ###   ########.fr       */
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

typedef struct			s_uvn
{
	t_point u;
	t_point v;
	t_point n;
}						t_uvn;

typedef enum			e_object_type
{
	sphere,
	plan,
	cylinder,
	cone,
	ellipse
}						t_object_type;

typedef struct			s_ray
{
	t_point		pos;
	t_point		dir;
	int			refle_depth;
	int			refra_depth;
}						t_ray;

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
	t_color			specular;
	t_color			ambient;
	t_color			diffuse;
}						t_material;

typedef struct			s_light
{
	t_point			pos;
	t_color			color;
	struct s_light	*next;
}						t_light;

typedef struct			s_object
{
	t_object_type	type;
	t_point			pos;
	t_material		mater;

	double			radius;
	t_color			color;

	t_point			normal;
	t_point			axis;

	t_ray			normal_vector;
	t_point			rot;
	double			reflection;
	double			refraction;
	struct s_object *next;
}						t_object;

typedef struct			s_intersection
{
	t_object	obj;
	t_point		pos;
	t_point		normal;
	t_point		light_vector;
	double		t;
}						t_intersection;

#endif
