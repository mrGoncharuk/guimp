/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:36:27 by mhonchar          #+#    #+#             */
/*   Updated: 2019/07/25 20:21:23 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIMP_H
# define GUIMP_H

# include <stdbool.h>
# include <unistd.h>
# include "canvas.h"
# include "button.h"
# include "SDL.h"
# include "libft.h"
# include "error_handler.h"
# define STD_WIDTH 800
# define STD_HEIGHT 600

typedef struct		s_flags
{
	bool			running;
	bool			lmb_down;
	bool			clear_canvas;
}					t_flags;

typedef struct		s_sdls
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	t_flags			flags;
	t_lbutton		buttons[TOTAL_BUTTONS];

}					t_sdls;

void				ft_sdl_init(t_sdls *win);
void				ft_sdl_clean(t_sdls *s);
void				bt_clear_canvas(t_canvas *canvas, t_flags *flags);
void				bt_event_clear_canvas(SDL_Event *e, t_lbutton *bt, t_flags *flags);
#endif
