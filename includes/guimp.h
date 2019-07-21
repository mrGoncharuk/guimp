/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:36:27 by mhonchar          #+#    #+#             */
/*   Updated: 2019/07/21 19:57:44 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIMP_H
# define GUIMP_H

# include <stdbool.h>
# include "../frameworks/SDL2.framework/Headers/SDL.h"
# include "libft.h"
# include "error_handler.h"
# define STD_WIDTH 800
# define STD_HEIGHT 600

typedef struct  	s_canvas
{
    unsigned int	w;
	unsigned int	h;
	SDL_Surface		*field;
}					t_canvas;

typedef struct		s_sdls
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	bool			running;

}					t_sdls;

void				sdl_st_init(t_sdls *win);

#endif