/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:16:47 by mhonchar          #+#    #+#             */
/*   Updated: 2019/07/21 19:58:46 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void		sdl_st_init(t_sdls *win)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		err_sdl(ERR_INIT);
	win->win = SDL_CreateWindow("GUImp", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		STD_WIDTH, STD_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	if (win->win == NULL)
		err_sdl(ERR_WIN_CREATE);
	win->renderer = SDL_CreateRenderer(win->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (win->renderer == NULL)
		err_sdl(ERR_RENDERER_CREATE);
	win->running = true;
}