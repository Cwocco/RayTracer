/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:30:43 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/10 18:27:23 by jpicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "error.h"
#include "parser.h"

void	init_cam(t_env *env, char **d)
{
	t_camera	*cam;

	if (check_data_array(d, 11) == 1)
		ft_exit("Invalid camera data.");
	cam = &env->scene.cam;
	cam->fov = ft_atoi(d[7]);
	check_value(cam->fov, 1, 90);
	cam->d = (env->win_w / 2 / (fabs(tan(ft_degtorad(cam->fov) / 2))));
	cam->pos = (t_point){ft_atod(d[1]), ft_atod(d[2]), ft_atod(d[3])};
	cam->rot = (t_point){ft_atod(d[4]), ft_atod(d[5]), ft_atod(d[6])};
	check_value(cam->rot.x, -360, 360);
	check_value(cam->rot.y, -360, 360);
	check_value(cam->rot.z, -360, 360);
	cam->ratio = env->win_h / env->win_w;
	env->anti = ft_atoi(d[8]);
	env->sepia = ft_atoi(d[9]);
	env->fifty = ft_atoi(d[10]);
	env->dalto = ft_atoi(d[11]);
	check_value(env->anti, 0, 1);
	check_value(env->sepia, 0, 1);
	check_value(env->fifty, 0, 1);
	check_value(env->dalto, 0, 1);
}

void	init_light(t_env *env, char **light_data)
{
	t_light *light;

	light = env->scene.lgts;
	if (check_data_array(light_data, 7) == 1)
		ft_exit("Invalid light data.");
	if (!light)
	{
		if (!(light = (t_light*)malloc(sizeof(t_light))))
			ft_exit("Failed to malloc.");
		light->next = NULL;
		fill_light_struct(light, light_data);
		env->scene.lgts = light;
	}
	else
	{
		while (light->next != NULL)
			light = light->next;
		if (!(light->next = (t_light*)malloc(sizeof(t_light))))
			ft_exit("Failed to malloc.");
		light->next->next = NULL;
		fill_light_struct(light->next, light_data);
	}
}

void	get_cam_data(t_env *env, t_list *lst)
{
	char **camera_data;

	camera_data = NULL;
	if (lst->next)
	{
		lst = lst->next;
		camera_data = (char**)lst->content;
	}
	else
		ft_exit("Empty #CAM data.");
	if (ft_strcmp(camera_data[0], "camera:") == 0)
	{
		if (lst->next)
		{
			if (ft_strcmp(((char**)lst->next->content)[0], "#") == 0)
				init_cam(env, camera_data);
			else
				ft_exit("No # at the end of #CAM.");
		}
		else
			ft_exit("Invalid file.");
	}
	else
		ft_exit("Invalid #CAM data.");
}

void	get_obj_data(t_env *env, t_list *lst)
{
	char **obj_data;

	lst->next == NULL ? ft_exit("Empty #OBJ data.") : (lst = lst->next);
	while (lst)
	{
		if (!(obj_data = (char**)lst->content))
			ft_exit("Empty line.");
		else if (ft_strcmp(obj_data[0], "sphere:") == 0)
			init_object(env, lst, sphere);
		else if (ft_strcmp(obj_data[0], "plan:") == 0)
			init_object(env, lst, plan);
		else if (ft_strcmp(obj_data[0], "cone:") == 0)
			init_object(env, lst, cone);
		else if (ft_strcmp(obj_data[0], "cylinder:") == 0)
			init_object(env, lst, cylinder);
		else if (ft_strcmp(obj_data[0], "#") == 0)
			if (ft_strcmp(((char**)lst->next->content)[0], "#LIGHT") == 0)
				return ;
			else
				ft_exit("Clear end of #OBJ!.");
		else
			ft_exit("Invalid #OBJ data.");
		lst = lst->next;
	}
}

void	get_light_data(t_env *env, t_list *lst)
{
	char **light_data;

	if (lst->next)
		lst = lst->next;
	else
		return ;
	while (lst)
	{
		light_data = (char**)lst->content;
		if (ft_strcmp(light_data[0], "light:") == 0)
			init_light(env, light_data);
		else if (ft_strcmp(light_data[0], "#") == 0)
		{
			if (lst->next)
				ft_exit("Clear end of file!");
			else
				return ;
		}
		else
			ft_exit("Invalid #LIGHT datas or no #.");
		lst = lst->next;
	}
}
