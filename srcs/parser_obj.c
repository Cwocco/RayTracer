/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:00:22 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/10 18:17:33 by jpicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "error.h"
#include "parser.h"

void	check_color(double r, double g, double b, double a)
{
	if (r > 255 || r < 0)
		ft_exit("Bad color r.");
	if (g > 255 || g < 0)
		ft_exit("Bad color g.");
	if (b > 255 || b < 0)
		ft_exit("Bad color b.");
	if (a > 1 || a < 0)
		ft_exit("Bad color a.");
}

void	check_object(t_list *lst, t_object_type type)
{
	if (type == sphere)
		if (check_data_array((char**)lst->content, 23) == 1)
			ft_exit("Invalid object sphere data.");
	if (type == plan)
		if (check_data_array((char**)lst->content, 25) == 1)
			ft_exit("Invalid object plan data.");
	if (type == cylinder || type == cone)
		if (check_data_array((char**)lst->content, 26) == 1)
			ft_exit("Invalid object cylinder or cone data.");
	if (type == ellipse)
		if (check_data_array((char**)lst->content, 22) == 1)
			ft_exit("Invalid object ellipse data.");
}

void	init_object(t_env *env, t_list *lst, t_object_type type)
{
	t_object *object;

	object = env->scene.objs;
	check_object(lst, type);
	if (!object)
	{
		if (!(object = (t_object*)malloc(sizeof(t_object))))
			ft_exit("Failed to malloc.");
		object->next = NULL;
		fill_object_struct(object, (char**)lst->content, type);
		env->scene.objs = object;
	}
	else
	{
		while (object->next != NULL)
			object = object->next;
		if (!(object->next = (t_object*)malloc(sizeof(t_object))))
			ft_exit("Failed to malloc.");
		object->next->next = NULL;
		fill_object_struct(object->next, (char**)lst->content, type);
	}
}

void	fill_object_struct(t_object *object, char **d, t_object_type type)
{
	object->type = type;
	object->pos = (t_point){ft_atod(d[1]), ft_atod(d[2]), ft_atod(d[3])};
	if (type == sphere)
		fill_sphere_struct(object, d);
	if (type == plan)
		fill_plan_struct(object, d);
	if (type == cylinder)
		fill_cylinder_struct(object, d);
	if (type == cone)
		fill_cone_struct(object, d);
	if (type == cone)
		fill_cone_struct(object, d);
}

void	fill_light_struct(t_light *light, char **d)
{
	light->pos = (t_point){ft_atod(d[1]), ft_atod(d[2]), ft_atod(d[3])};
	check_color(ft_atod(d[4]), ft_atod(d[5]), ft_atod(d[6]), ft_atod(d[7]));
	light->color = (t_color){ft_atod(d[4]), ft_atod(d[5]), ft_atod(d[6]),
		ft_atod(d[7])};
}
