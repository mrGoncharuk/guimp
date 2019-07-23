/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:51:23 by mhonchar          #+#    #+#             */
/*   Updated: 2019/07/23 16:52:56 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void		ft_sdl_clean(t_sdls *s)
{
    SDL_DestroyWindow(s->win);
    SDL_Quit();
}