/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:46:53 by ada-cunh          #+#    #+#             */
/*   Updated: 2018/01/26 12:46:54 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void	event_process(t_event *event)
{
	SDL_Event	ev;

	event->mouse.lclick = 0;
	event->mouse.rclick = 0;
	event->mouse.wup = 0;
	event->mouse.wdown = 0;
	while (SDL_PollEvent(&ev))
	{
		if (ev.type == SDL_QUIT)
			event->exit = 1;
		else if (ev.type == SDL_MOUSEMOTION || ev.type == SDL_MOUSEWHEEL
				|| ev.type == SDL_MOUSEBUTTONDOWN)
			event_handle_mouse(&ev, event);
		if (ev.type == SDL_WINDOWEVENT
				&& ev.window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
			event->focus = 1;
		else if (ev.type == SDL_WINDOWEVENT
				&& ev.window.event == SDL_WINDOWEVENT_FOCUS_LOST)
			event->focus = 0;
	}
	if (event->focus)
		event->keys = SDL_GetKeyboardState(NULL);
	if (event->keys[SDL_SCANCODE_ESCAPE])
		event->exit = 1;
}

void	event_reset(t_event *event)
{
	event->exit = 0;
	event->focus = 1;
	event->draw = 0;
}

void	event_handle_mouse(SDL_Event *ev, t_event *event)
{
	if (ev->type == SDL_MOUSEMOTION)
	{
		event->mouse.move = 1;
		event->mouse.pos.x = ev->motion.x;
		event->mouse.pos.y = ev->motion.y;
	}
	else if (ev->type == SDL_MOUSEWHEEL)
	{
		if (ev->wheel.y == 1)
		{
			event->mouse.wup = 1;
		}
		else if (ev->wheel.y == -1)
		{
			event->mouse.wdown = 1;
		}
	}
	else
	{
		event->mouse.lclick = 1;
		event->mouse.pos.x = ev->button.x;
		event->mouse.pos.y = ev->button.y;
	}
}

int		handle_event(t_bool *e)
{
	if (*e)
	{
		*e = 0;
		return (1);
	}
	return (0);
}
