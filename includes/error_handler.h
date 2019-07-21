/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:22:10 by mhonchar          #+#    #+#             */
/*   Updated: 2019/07/21 19:39:41 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

enum	e_err_sdl {ERR_INIT, ERR_WIN_CREATE, ERR_RENDERER_CREATE};


int		err_sdl(int err_code);

#endif