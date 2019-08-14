/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wn_toolbox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 19:11:48 by mhonchar          #+#    #+#             */
/*   Updated: 2019/08/14 15:01:29 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "toolbox.h"

void		wn_create_toolbox(t_toolbox *tb)
{
	wn_create(&(tb->wn));
	wn_init(&(tb->wn), "ToolBox",  (SDL_Point) {TB_WIDTH, TB_HEIGHT}, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	wn_create_renderer(&(tb->wn));
}