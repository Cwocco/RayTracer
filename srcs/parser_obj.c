/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:00:22 by rpinoit           #+#    #+#             */
/*   Updated: 2018/01/12 11:11:08 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parser.h"

void	check_color(int	r, int g, int b, int a)
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

void	init_object(t_env *env, t_list *lst, t_object_type type)
{
	t_object *object;

	object = env->scene.objs;
	if (type == sphere)
		if (check_data_array((char**)lst->content, 8) == 1)
			ft_exit("Invalid object sphere data.");
	if (type == plan)
		if (check_data_array((char**)lst->content, 10) == 1)
			ft_exit("Invalid object plan data.");
	if (type == cylinder || type == cone)
		if (check_data_array((char**)lst->content, 11) == 1)
	            ft_exit("Invalid object cylinder or cone data.");
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
	{
		object->radius = ft_atod(d[4]);
		check_color(ft_atoi(d[5]), ft_atoi(d[6]), ft_atoi(d[7]), ft_atoi(d[8]));
		object->color = (t_color){(t_uchar)ft_atoi(d[5]), (t_uchar)ft_atoi(d[6]),
		(t_uchar)ft_atoi(d[7]), (t_uchar)ft_atoi(d[8])};
	}
	if (type == plan)
	{
		object->normal = (t_point){ft_atod(d[4]), ft_atod(d[5]), ft_atod(d[6])};
		check_color(ft_atoi(d[7]), ft_atoi(d[8]), ft_atoi(d[9]), ft_atoi(d[10]));
		object->color = (t_color){(t_uchar)ft_atoi(d[7]), (t_uchar)ft_atoi(d[8]),
			        (t_uchar)ft_atoi(d[9]), (t_uchar)ft_atoi(d[10])};
	}
	if (type == cylinder || type == cone)
	{
		object->radius = ft_atod(d[4]);
		object->axis = (t_point){ft_atod(d[5]), ft_atod(d[6]), ft_atod(d[7])};
		check_color(ft_atoi(d[8]), ft_atoi(d[9]), ft_atoi(d[10]), ft_atoi(d[11]));
		object->color = (t_color){(t_uchar)ft_atoi(d[8]), (t_uchar)ft_atoi(d[9]), 
			(t_uchar)ft_atoi(d[10]), (t_uchar)ft_atoi(d[11])};
	}
}

void	fill_light_struct(t_light *light, char **d)
{
	light->pos = (t_point){ft_atod(d[1]), ft_atod(d[2]), ft_atod(d[3])};
//	light->vect = (t_point){ft_atod(d[4]), ft_atod(d[5]), ft_atod(d[6])};
	check_color(ft_atoi(d[7]), ft_atoi(d[8]), ft_atoi(d[9]), ft_atoi(d[10]));
//	light->specular = (t_color){(t_uchar)ft_atoi(d[7]), (t_uchar)ft_atoi(d[8]),
//		                    (t_uchar)ft_atoi(d[9]), (t_uchar)ft_atoi(d[10])};
	check_color(ft_atoi(d[11]), ft_atoi(d[12]), ft_atoi(d[13]), ft_atoi(d[14]));
//	light->ambient = (t_color){(t_uchar)ft_atoi(d[11]), (t_uchar)ft_atoi(d[12]),
//		                    (t_uchar)ft_atoi(d[13]), (t_uchar)ft_atoi(d[14])};
	check_color(ft_atoi(d[15]), ft_atoi(d[16]), ft_atoi(d[17]), ft_atoi(d[18]));
//	light->diffuse = (t_color){(t_uchar)ft_atoi(d[15]), (t_uchar)ft_atoi(d[16]),
//		                    (t_uchar)ft_atoi(d[17]), (t_uchar)ft_atoi(d[18])};
}
