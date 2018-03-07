/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_alias.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:24:51 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/03 11:18:20 by jpicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANTI_ALIAS
# define ANTI_ALIAS

#include "rtv1.h"

t_color     anti_aliasing_rt(t_pixel win_pos, t_env *env);

#endif
