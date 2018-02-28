/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:27:04 by rpinoit           #+#    #+#             */
/*   Updated: 2018/02/28 18:09:16 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_H
# define PIXEL_H

# include "rtv1.h"

void	get_final_color(t_color *c);

void	sepia(t_color *prim_color);

void	fifty_shades_of_grey(t_color *prim_color);

double	get_val(double val, double min, double max);

void	daltonism(t_color *prim_color);

#endif
