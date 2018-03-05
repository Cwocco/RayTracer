/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_alias.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:22:50 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/05 10:58:21 by jpicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color     anti_alias_color(t_color c[17])
{
	t_color color;

	color.r = (c[0].r + c[1].r + c[2].r + c[3].r + c[4].r + c[5].r + c[6].r + c[7].r + c[8].r + c[9].r + c[10].r + c[11].r + c[12].r + c[13].r + c[14].r + c[15].r + c[16].r) / 16.0;
	color.g = (c[0].g + c[1].g + c[2].g + c[3].g + c[4].g + c[5].g + c[6].g + c[7].g + c[8].g + c[9].g + c[10].g + c[11].g + c[12].g + c[13].g + c[14].g + c[15].g + c[16].g) / 16.0;
	color.b = (c[0].b + c[1].b + c[2].b + c[3].b + c[4].b + c[5].b + c[6].b + c[7].b + c[8].b + c[9].b + c[10].b + c[11].b + c[12].b + c[13].b + c[14].b + c[15].b + c[16].b) / 16.0;

	return (color);
}

t_color     anti_aliasing_rt(t_point win_pos, t_env *env)
{
	t_color c[17];
	t_point pix;
	t_ray   r;
	t_point tmp;

	tmp = win_pos;
	pix.x = 0;
	while (pix.x < 4)
	{
		pix.y = 0;
		while (pix.y < 4)
		{
			tmp.x = win_pos.x + pix.x * 0.25;
			tmp.y = win_pos.y + pix.y * 0.25;
			r = get_prim_ray(tmp, env);
			c[(int)pix.x + (int)pix.y * 4] = raytrace(r, env);
			pix.y++;
		}
		pix.x++;
	}
	return (anti_alias_color(c));
}
