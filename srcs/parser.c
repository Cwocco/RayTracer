/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:43:47 by rpinoit           #+#    #+#             */
/*   Updated: 2018/02/26 14:55:11 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		check_data_array(char **d, int size)
{
	int i;
	int check_s;

	i = 1;
	if ((check_s = ft_tablen(d)) != size + 1)
		ft_exit("Wrong number of data.");
	while (i <= size)
	{
		check_s = ft_strlen(d[i]);
		if ((check_s > 0 && ft_strdigit(d[i])) ||
			(d[i][0] == '-' && check_s > 1 && ft_strdigit(d[i] + 1)))
			i++;
		else
			return (1);
	}
	return (0);
}

void	check_param(char *name, int ac)
{
	if (ac != 2)
		ft_exit("Usage : ./rtv1 <scene_file>");
	if ((name = ft_strrchr(name, (int)'.')))
	{
		if (ft_strcmp(name, ".rt") == 0)
			return ;
		else
			ft_exit("Invalid format file. DOT RT FILE ?");
	}
	else
		ft_exit("Invalid format file. DOT RT FILE ?");
}

void	get_data(t_env *env, t_list *lst)
{
	t_list	*tmp;
	char	**line;
	int		mark;

	tmp = lst;
	mark = 0;
	(void)env;
	while (lst)
	{
		line = (char**)lst->content;
		if (ft_strcmp(line[0], "#CAM") == 0 && mark == 0)
		{
			get_cam_data(env, lst);
			mark++;
		}
		else if (ft_strcmp(line[0], "#OBJ") == 0 && mark == 1)
		{
			get_obj_data(env, lst);
			mark++;
		}
		else if (ft_strcmp(line[0], "#LIGHT") == 0 && mark == 2)
		{
			get_light_data(env, lst);
			mark++;
		}
		lst = lst->next;
	}
	if (mark != 3)
		ft_exit("Invalid file: #CAM -> #OBJ -> #LIGHT.");
	ft_lstdel(&tmp, ft_deltab);
}

void	reader(t_env *env)
{
	int		fd;
	char	*line;
	char	**split;
	t_list	*lst;

	line = NULL;
	env->scene.objs = NULL;
	check_param(env->argv[1], env->argc);
	if ((fd = open(env->argv[1], O_RDONLY)) <= 0)
		ft_exit("Failed to open file.");
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		ft_strdel(&line);
		if (lst)
		{
			ft_lstadd(&lst, ft_lstnew(NULL, sizeof(char**)));
			if (!lst)
				ft_exit("Failed to malloc");
			lst->content = (void*)split;
		}
		else
		{
			if (!(lst = ft_lstnew(NULL, sizeof(char **))))
				ft_exit("Failed to malloc");
		}
		lst->content = (void*)split;
	}
	ft_lstrev(&lst);
	get_data(env, lst);
	if (close(fd) == -1)
		ft_exit("Failed to close file.");
}
