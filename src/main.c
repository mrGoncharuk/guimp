/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:36:52 by mhonchar          #+#    #+#             */
/*   Updated: 2019/07/23 20:30:12 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "guimp.h"

void	ml_event(t_flags *f, t_mousepos *mp)
{
	SDL_Event	event;

	while(SDL_PollEvent(&event))
	{
		if((SDL_QUIT == event.type) || (SDL_KEYDOWN == event.type && SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
			f->running = false;
		if (event.type == SDL_MOUSEBUTTONUP)
			if (event.button.button == SDL_BUTTON_LEFT)
                f->lmb_down = false;
		if (event.type == SDL_MOUSEBUTTONDOWN)
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				SDL_GetMouseState(&(mp->lmb_down.x), &(mp->lmb_down.y));
				mp->motion = mp->lmb_down;
				mp->temp = mp->lmb_down;
				f->lmb_down = true;
			}
		if (event.type == SDL_MOUSEMOTION)
			if (f->lmb_down)
			{
				mp->motion.x = event.motion.x;
                mp->motion.y = event.motion.y;
			}
	}
}
void	ml_update(t_canvas *canv, t_mousepos *mp)
{
	SDL_UpdateTexture(canv->field, NULL, canv->pixels, canv->w * sizeof(Uint32));
	ft_draw_line(canv, mp->temp, mp->motion);
	mp->temp = mp->motion;
}

void	ml_render(t_sdls *win, t_canvas *canv)
{
	SDL_RenderClear(win->renderer);
	SDL_RenderCopy(win->renderer, canv->field, NULL, NULL);
	SDL_RenderPresent(win->renderer);
}



int		sdl_mainloop(t_sdls *win)
{
	t_canvas	*canv;
	t_mousepos	mp;

	canv = ft_create_canvas(win->renderer, STD_WIDTH, STD_HEIGHT);
	while (win->flags.running)
	{
		ml_event(&(win->flags), &mp);
		ml_update(canv, &mp);
		ml_render(win, canv);
	}
	return (0);
}

int		main(void)
{
	t_sdls		win;

	ft_sdl_init(&win);
	sdl_mainloop(&win);
	ft_sdl_clean(&win);
    return (0);
}