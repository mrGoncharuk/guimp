/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:59:46 by mhonchar          #+#    #+#             */
/*   Updated: 2019/07/23 20:23:48 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

t_canvas	*ft_create_canvas(SDL_Renderer *r, const int w, const int h)
{
	t_canvas	*canvas;

	if (w == 0 || h == 0)
		return (NULL);
	canvas = (t_canvas *)malloc(sizeof(t_canvas));
	canvas->w = w;
	canvas->h = h;
	if ((canvas->pixels = (Uint32 *)malloc(w * h * sizeof(Uint32))) == NULL)
	{
		free(canvas);
		return (NULL);
	}
	canvas->field = SDL_CreateTexture(r, SDL_PIXELFORMAT_ARGB8888,
					SDL_TEXTUREACCESS_STATIC, w, h);
	if (canvas->field == NULL)
	{
		free(canvas->pixels);
		free(canvas);
		return (NULL);
	}
	ft_memset(canvas->pixels, 255, w * h * sizeof(Uint32));
	canvas->draw_color = 0;
	return (canvas);
}

void		ft_destroy_canvas(t_canvas *canvas)
{
	if (!canvas)
		return ;
	if (canvas->pixels)
		free(canvas->pixels);
	SDL_DestroyTexture(canvas->field);
	free(canvas);
}
