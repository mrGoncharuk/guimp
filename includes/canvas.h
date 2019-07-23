/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:22:57 by mhonchar          #+#    #+#             */
/*   Updated: 2019/07/23 20:23:19 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "SDL.h"
# include "libft.h"

typedef struct		s_vector2
{
	int				x;
	int				y;
}					t_vector2;

typedef struct		s_mousepos
{
	t_vector2		lmb_down;
	t_vector2		motion;
	t_vector2		temp;
}					t_mousepos;

typedef struct  	s_canvas
{
    int				w;
	int				h;
	Uint32			draw_color;
	Uint32			*pixels;
	SDL_Texture		*field;
}					t_canvas;

t_canvas	*ft_create_canvas(SDL_Renderer *r, const int w, const int h);
void		ft_destroy_canvas(t_canvas *canvas);
void		ft_draw_line(t_canvas *canv, t_vector2 p0, t_vector2 p1);


#endif