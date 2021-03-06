/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_phong_shading.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:25:39 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/10 17:48:44 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "vector_utilities.h"

void	set_ambient_light(t_color *c, t_object obj)
{
	t_color ambient;

	ambient = (t_color){ .r = 0.3, .g = 0.3, .b = 0.3, .a = 1};
	*c = (t_color){ .r = ambient.r * (obj.color.r / 255.0),
		.g = ambient.g * (obj.color.g / 255.0),
		.b = ambient.b * (obj.color.b / 255.0),
		.a = 1 };
}

void	add_diffuse_light(t_color *c, t_object obj, t_light *light, double f[2])
{
	t_color light_intensity;

	light_intensity = (t_color){ .r = 0.5, .g = 0.5, .b = 0.5, .a = 1};
	c->r += (f[0]
		* (obj.mater.diffuse.r / 255.0)
		* (light->color.r / 255.0)
		* (obj.color.r / 255.0)
		* light_intensity.r) * f[1];
	c->g += (f[0]
		* (obj.mater.diffuse.g / 255.0)
		* (light->color.g / 255.0)
		* (obj.color.g / 255.0)
		* light_intensity.g) * f[1];
	c->b += (f[0]
		* (obj.mater.diffuse.b / 255.0)
		* (light->color.b / 255.0)
		* (obj.color.b / 255.0)
		* light_intensity.b) * f[1];
}

void	add_specular_light(t_color *c, t_point r_pos, t_intersection *inter,
		double f)
{
	t_point	refra;
	t_point	vision;
	double	cos_omega;
	t_point	tmp;
	double	i;

	i = 0.8;
	tmp = vec_mul(inter->normal,
		2.0 * dot_product(inter->normal, inter->light_vector));
	refra = vector_sub(tmp, inter->light_vector);
	normalize_vector(&refra);
	vision = vector_sub(r_pos, inter->pos);
	normalize_vector(&vision);
	cos_omega = pow(fmax(0, dot_product(refra, vision)), 300.0);
	if (cos_omega >= 0)
	{
		c->r += (cos_omega * (inter->obj.mater.specular.r / 255.0 * i)) * f;
		c->g += (cos_omega * (inter->obj.mater.specular.g / 255.0 * i)) * f;
		c->b += (cos_omega * (inter->obj.mater.specular.b / 255.0 * i)) * f;
	}
}
