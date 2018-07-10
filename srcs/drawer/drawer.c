/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:50:50 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 22:13:43 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"
#include "errors.h"
#include "libft.h"
#include <stdlib.h>

void			drawer_delete(t_drawer *drawer)
{
	if (!drawer)
		return ;
	if (!drawer->pixels)
		free(drawer->pixels);
	if (!drawer->texture)
		SDL_DestroyTexture(drawer->texture);
	if (!drawer->renderer)
		SDL_DestroyRenderer(drawer->renderer);
	if (!drawer->window)
		SDL_DestroyWindow(drawer->window);
	free(drawer);
	SDL_Quit();
}

static void		*drawer_err_exit(t_drawer *drawer, char *err)
{
	drawer_delete(drawer);
	try_set_err(err);
	return (NULL);
}

t_drawer		*drawer_new(void)
{
	t_drawer	*drawer;

	if (!(drawer = malloc(sizeof(t_drawer))))
		return (drawer_err_exit(drawer, DRAWER_NEW_MEM));
	ft_memset(drawer, 0, sizeof(t_drawer));
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (drawer_err_exit(drawer, DRAWER_NEW_SDL_INIT));
	if (!(drawer->window = SDL_CreateWindow(PROGNAME,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H, 0)))
		return (drawer_err_exit(drawer, DRAWER_NEW_SDL_CREATE_WINDOW));
	if (!(drawer->renderer = SDL_CreateRenderer(drawer->window, -1,
		SDL_RENDERER_ACCELERATED)))
		return (drawer_err_exit(drawer, DRAWER_NEW_SDL_CREATE_RENDERER));
	if (!(drawer->texture = SDL_CreateTexture(drawer->renderer,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, TEX_W, TEX_H)))
		return (drawer_err_exit(drawer, DRAWER_NEW_SDL_CREATE_TEXTURE));
	SDL_SetRenderDrawColor(drawer->renderer, 0, 0, 0, 255);
	if (!(drawer->pixels = malloc(sizeof(t_pixel) * TEX_W * TEX_H)))
		return (drawer_err_exit(drawer, DRAWER_NEW_MEM));
	ft_memset(drawer->pixels, 0, sizeof(t_pixel) * TEX_W * TEX_H);
	return (drawer);
}
