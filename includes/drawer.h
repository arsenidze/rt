/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:32:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/14 15:48:46 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWER_H
# define DRAWER_H

//# include "rtv1_defines.h"
# include "SDL.h"

# define DRAWER_SUCCESS 0
# define DRAWER_FAILURE 1

//# define TEX_W WIN_W
//# define TEX_H WIN_H
# define SET_PIXEL(canvas, x, y, c) {canvas.pixels[(y) * canvas.w + (x)] = (c);}
# define GET_PIXEL(canvas, x, y) canvas.pixels[(y) * canvas.w + (x)]

typedef Uint32	t_pixel;
typedef Uint32	t_uint;

typedef struct	s_canvas
{
	t_pixel	*pixels;
	t_uint	w;
	t_uint	h;	
	t_uint	pos_x;
	t_uint	pos_y;
}				t_canvas;

typedef struct	s_drawer
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	t_canvas		canvas;
	//t_pixel			*pixels;
	//int				pitch;
}				t_drawer;

t_drawer		*drawer_new(unsigned int win_w, unsigned int win_h,
				const char *win_name);
void			drawer_delete(t_drawer *drawer);
void			drawer_render(t_drawer *drawer);

#endif
