/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:31:34 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/01/31 17:37:11 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "rtv1.h"

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
