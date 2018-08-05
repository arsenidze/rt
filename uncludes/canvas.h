/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:09:30 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/05 21:11:57 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "SDL.h"

# define CANVAS_SET_PIXEL(can, x, y, c) {can.pixels[(y) * can.w + (x)] = (c);}
# define CANVAS_GET_PIXEL(can, x, y) can.pixels[(y) * can.w + (x)]

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

#endif
