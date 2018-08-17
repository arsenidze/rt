/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:50:50 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 22:45:32 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"
#include "err.h"
#include "libft.h"
#include <stdlib.h>

void			drawer_deinit(t_drawer *drawer)
{
	if (!drawer->canvas.pixels)
		free(drawer->canvas.pixels);
	if (!drawer->texture)
		SDL_DestroyTexture(drawer->texture);
	if (!drawer->renderer)
		SDL_DestroyRenderer(drawer->renderer);
	if (!drawer->window)
		SDL_DestroyWindow(drawer->window);
	SDL_Quit();
}

static short	drawer_err_exit(t_drawer *drawer, char *err)
{
	drawer_deinit(drawer);
	try_set_err(err);
	return (DRAWER_FAILURE);
}

short			drawer_init(t_drawer *drawer, unsigned int win_w,
				unsigned int win_h, const char *win_name)
{
	ft_memset(drawer, 0, sizeof(t_drawer));
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (drawer_err_exit(drawer, DRAWER_NEW_SDL_INIT));
	if (!(drawer->window = SDL_CreateWindow(win_name,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, win_w, win_h, 0)))
		return (drawer_err_exit(drawer, DRAWER_NEW_SDL_CREATE_WINDOW));
	if (!(drawer->renderer = SDL_CreateRenderer(drawer->window, -1,
		SDL_RENDERER_ACCELERATED)))
		return (drawer_err_exit(drawer, DRAWER_NEW_SDL_CREATE_RENDERER));
	if (!(drawer->texture = SDL_CreateTexture(drawer->renderer,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, win_w, win_h)))
		return (drawer_err_exit(drawer, DRAWER_NEW_SDL_CREATE_TEXTURE));
	SDL_SetRenderDrawColor(drawer->renderer, 0, 0, 0, 255);
	if (!(drawer->canvas.pixels = malloc(sizeof(t_pixel) * win_w * win_h)))
		return (drawer_err_exit(drawer, DRAWER_NEW_MEM));
	ft_memset(drawer->canvas.pixels, 0, sizeof(t_pixel) * win_w * win_h);
	drawer->canvas.w = win_w;
	drawer->canvas.h = win_h;
	drawer->canvas.pos_x = 0;
	drawer->canvas.pos_y = 0;
	drawer->canvas.win_w = win_w;
	drawer->canvas.win_h = win_h;
	return (DRAWER_SUCCESS);
}
