/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:32:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/08 22:14:45 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWER_H
# define DRAWER_H

# include "SDL.h"
# include "canvas.h"

# define DRAWER_SUCCESS 0
# define DRAWER_FAILURE 1

typedef struct	s_drawer
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	t_canvas		canvas;
}				t_drawer;

short			drawer_init(t_drawer *drawer, unsigned int win_w,
				unsigned int win_h, const char *win_name);
void			drawer_deinit(t_drawer *drawer);
void			drawer_render_on_window(const t_drawer *drawer);

#endif
