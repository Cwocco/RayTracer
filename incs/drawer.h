/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:31:13 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/01/24 18:31:13 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DRAWER_H
# define DRAWER_H

# include "rtv1.h"

void	drawer_init(t_env *env);

void	drawer_process(t_env *env);

void	drawer_destroy(t_env *env);

void	drawer_putpixel(t_env *env, t_2ipair p, t_color c);

#endif
