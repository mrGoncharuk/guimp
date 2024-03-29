/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:22:55 by mhonchar          #+#    #+#             */
/*   Updated: 2019/08/19 19:50:50 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	ft_event(t_sdls *app)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if((SDL_QUIT == event.type) || (SDL_KEYDOWN == event.type && SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
			app->flags.running = false;
		if (event.window.windowID == app->canvas.wn.id)
			cn_event_handle(&(app->canvas), &event, &(app->flags));
		//wn_handle_event(&(app->toolbox.wn), &event);
	}
	
}
void	ft_update(t_sdls *app)
{
	cn_update(&(app->canvas));
}
void	ft_render(t_sdls *app)
{
	cn_render(&(app->canvas));
}

void	ft_mainloop(t_sdls *app)
{
	while(app->flags.running)
	{
		ft_event(app);
		ft_update(app);
		ft_render(app);
	}
}