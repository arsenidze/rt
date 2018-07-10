/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:32:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/06 14:20:26 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWER_H
# define DRAWER_H

# include "rtv1_defines.h"
# include "SDL.h"

# define DRAWER_SUCCESS 0
# define DRAWER_FAILURE 1

# define TEX_W WIN_W
# define TEX_H WIN_H
# define SET_PIXEL(pixels, x, y, c) {pixels[(y) * TEX_W + (x)] = (c);}

typedef Uint32	t_pixel;

typedef struct	s_drawer
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	t_pixel			*pixels;
	int				pitch;
}				t_drawer;

t_drawer		*drawer_new(void);
void			drawer_delete(t_drawer *drawer);
void			drawer_render(t_drawer *drawer);

#endif
