/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:36:52 by mhonchar          #+#    #+#             */
/*   Updated: 2019/07/21 20:01:10 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "guimp.h"

void	ml_event();
void	ml_update();
void	ml_render();


int		sdl_mainloop(t_sdls *win)
{
	SDL_Event	event;

	while (win->running)
	{
		while(SDL_PollEvent(&event))
            if((SDL_QUIT == event.type) || (SDL_KEYDOWN == event.type && SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
                win->running = false;
	}
	return (0);
}

int		main(void)
{
	t_sdls		win;

	sdl_st_init(&win);
	sdl_mainloop(&win);
    return (0);
}