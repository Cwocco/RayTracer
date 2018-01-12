/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 07:49:46 by nboste            #+#    #+#             */
/*   Updated: 2017/10/30 15:01:51 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "libft.h"
# include "SDL.h"

typedef struct		s_mouse
{
	t_bool		move;
	t_bool		lclick;
	t_bool		rclick;
	t_2ipair	pos;
	t_bool		wup;
	t_bool		wdown;
}					t_mouse;

typedef struct		s_event
{
	const Uint8		*keys;
	t_mouse			mouse;
	t_bool			focus;
	t_bool			exit;
	t_bool			draw;
}					t_event;

void				event_process(t_event *event);

void				event_reset(t_event *event);

void				event_handle_mouse(SDL_Event *ev, t_event *event);

int					handle_event(t_bool *e);

#endif
