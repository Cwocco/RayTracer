/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:38:36 by nboste            #+#    #+#             */
/*   Updated: 2017/05/29 17:00:24 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define FT_PI 3.1415926

typedef struct			s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}						t_list;

typedef unsigned char	t_bool;

typedef unsigned int	t_uint32;

typedef struct			s_2ipair
{
	int	x;
	int	y;
}						t_2ipair;

typedef struct			s_2dpair
{
	double	x;
	double	y;
}						t_2dpair;

typedef struct			s_3itriplet
{
	int		a;
	int		b;
	int		c;
}						t_3itriplet;

typedef struct			s_3dtriplet
{
	double	a;
	double	b;
	double	c;
}						t_3dtriplet;

typedef struct			s_3dvertex
{
	double	x;
	double	y;
	double	z;
}						t_3dvertex;

#endif
