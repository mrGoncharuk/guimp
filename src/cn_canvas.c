/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cn_canvas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:59:46 by mhonchar          #+#    #+#             */
/*   Updated: 2019/08/19 20:09:50 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

static int	cn_create(t_canvas *cn, SDL_Renderer *r, const int w, const int h)
{
	if (w == 0 || h == 0)
		return (-1);
	cn->w = w;
	cn->h = h;
	if ((cn->pixels = (Uint32 *)malloc(w * h * sizeof(Uint32))) == NULL)
		return (-1);
	cn->field = SDL_CreateTexture(r, SDL_PIXELFORMAT_ARGB8888,
					SDL_TEXTUREACCESS_STATIC, w, h);
	if (cn->field == NULL)
	{
		free(cn->pixels);
		return (-1);
	}
	ft_memset(cn->pixels, 255, w * h * sizeof(Uint32));
	cn->draw_color = 0;
	return (0);
}

void		cn_create_canvas(t_canvas *cn)
{
	wn_init(&(cn->wn), "GUImp",(SDL_Rect) {SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,CN_WIDTH, CN_HEIGHT},
		SDL_WINDOW_SHOWN |SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	if (cn_create(cn, cn->wn.renderer, CN_WIDTH, CN_HEIGHT) < 0)
		err_sdl(ERR_WIN_CREATE);
}

// void		cn_set_mp(SDL_Point point)
// {
// 	static SDL_Point	new_point;
// 	static SDL_Point	old_point;

// 	old_point = new_point;
// 	new_point = point;
// 	return (new_point);
// }

void		cn_destroy_canvas(t_canvas *canvas)
{
	if (!canvas)
		return ;
	if (canvas->pixels)
		free(canvas->pixels);
	SDL_DestroyTexture(canvas->field);
	wn_destroy(&(canvas->wn));
}


