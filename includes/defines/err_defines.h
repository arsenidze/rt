/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_defines.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:12:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/21 19:56:47 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_DEFINES_H
# define ERR_DEFINES_H

# define DRAWER_NEW_MEM					"Not enough memory to init drawer"
# define DRAWER_NEW_SDL_INIT			(char *)SDL_GetError()
# define DRAWER_NEW_SDL_CREATE_WINDOW 	(char *)SDL_GetError()
# define DRAWER_NEW_SDL_CREATE_RENDERER	(char *)SDL_GetError()
# define DRAWER_NEW_SDL_CREATE_TEXTURE 	(char *)SDL_GetError()

#endif
