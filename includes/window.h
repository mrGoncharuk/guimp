/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:39:32 by mhonchar          #+#    #+#             */
/*   Updated: 2019/07/26 19:15:29 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <stdbool.h>
# include "SDL.h"

typedef struct		s_window
{
	SDL_Window		*m_win;
	SDL_Renderer	*m_rendrer;
	int				*m_id;
	int				m_w;
	int				m_h;
	bool			m_mouse_focus;
	bool			m_keyboard_focus;
	bool			m_full_screen;
	bool			m_minimized;
	bool			m_shown;
}					t_window;

void			wn_create(t_window *wn);
bool			wn_init(t_window *wn, const char *title, SDL_Point size, Uint32 flags);
SDL_Renderer	*wn_create_renderer(t_window *wn);
void			wn_handle_event(t_window *wn, SDL_Event *e);

#endif