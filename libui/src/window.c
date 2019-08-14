/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:39:11 by mhonchar          #+#    #+#             */
/*   Updated: 2019/08/14 15:05:04 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void		wn_create(t_window *wn)
{
	wn->m_win = NULL;
	wn->m_mouse_focus = false;
	wn->m_keyboard_focus = false;
	wn->m_full_screen = false;
	wn->m_minimized = false;
	wn->m_w = 0;
	wn->m_h = 0;
}

bool		wn_init(t_window *wn, const char *title, SDL_Point size, Uint32 flags)
{
	if (!flags)
		flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
	wn->m_win = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size.x, size.y, flags);
	if (wn->m_win != NULL)
	{
		wn->m_mouse_focus = true;
		wn->m_keyboard_focus = true;
		wn->m_w = size.x;
		wn->m_h = size.y;
	}
	return (wn->m_win != NULL);
}

SDL_Renderer	*wn_create_renderer(t_window *wn)
{
	return (SDL_CreateRenderer(wn->m_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
}

void			wn_handle_event(t_window *wn, SDL_Event *e)
{
	bool	update_caption;

	if (e->type == SDL_WINDOWEVENT)
	{
		update_caption = false;
		if (e->window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
		{
			wn->m_w = e->window.data1;
			wn->m_h = e->window.data2;
		}
		else if (e->window.event == SDL_WINDOWEVENT_EXPOSED)
			SDL_RenderPresent(wn->m_rendrer);
		else if (e->window.event == SDL_WINDOWEVENT_ENTER)
		{
			wn->m_mouse_focus = true;
			update_caption = true;
		}
		else if (e->window.event == SDL_WINDOWEVENT_LEAVE)
		{
			wn->m_mouse_focus = false;
			update_caption = true;
		}
		else if (e->window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
		{
			wn->m_mouse_focus = true;
			update_caption = true;
		}
		else if (e->window.event == SDL_WINDOWEVENT_FOCUS_LOST)
		{
			wn->m_mouse_focus = false;
			update_caption = true;
		}
		else if (e->window.event == SDL_WINDOWEVENT_MINIMIZED)
			wn->m_minimized = true;
		else if (e->window.event == SDL_WINDOWEVENT_MAXIMIZED)
			wn->m_minimized = false;
		else if (e->window.event == SDL_WINDOWEVENT_RESTORED)
			wn->m_minimized = false;
	}
}
