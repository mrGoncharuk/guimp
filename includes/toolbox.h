/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 19:20:35 by mhonchar          #+#    #+#             */
/*   Updated: 2019/07/26 19:26:13 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLBOX_H
# define TOOLBOX_H

# include "guimp.h"


# define TB_WIDTH 200
# define TB_HEIGHT 600

typedef struct	s_toolbox
{
	t_window	wn;
	t_flags		*flags;
	t_lbutton	buttons[];
}				t_toolbox;

#endif