/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:32:01 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/03/03 11:19:14 by jpicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "rtv1.h"

void	reader(t_env *env);

int		check_data_array(char **d, int size);

void    init_object(t_env *env, t_list *lst, t_object_type type);

void    fill_object_struct(t_object *object, char **d, t_object_type type);

void    fill_light_struct(t_light *light, char **d);

void    get_cam_data(t_env *env, t_list *lst);

void    get_obj_data(t_env *env, t_list *lst);

void    get_light_data(t_env *env, t_list *lst);

int     ft_strdigit(const char *s);

void    ft_deltab(void *content, size_t content_size);

double	ft_atod(char *s);

int     ft_tablen(char **str);

void	ft_lstrev(t_list **alst);

void	ft_print_words_tables(char **tab); // delete pls

#endif
