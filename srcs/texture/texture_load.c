/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:21:44 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/01 14:46:25 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "SDL.h"
#include "SDL_image.h"
#include <stdlib.h>
#include "libft.h"

short	texture_load(t_texture *tex, const char *tex_name)
{
	SDL_Surface	*surface;

	surface = IMG_Load(tex_name);
	if (!surface)
		return (TEXTURE_FAILURE);
	tex->w = surface->w;
	tex->h = surface->h;
	tex->bpp = surface->format->BytesPerPixel;
	if (!(tex->pixels = malloc(surface->h * surface->pitch)))
	{
		SDL_FreeSurface(surface);
		return (TEXTURE_FAILURE);
	}
	SDL_LockSurface(surface);
	ft_memcpy(tex->pixels, surface->pixels, surface->h * surface->pitch);
	SDL_UnlockSurface(surface);
	SDL_FreeSurface(surface);
	return (TEXTURE_SUCCESS);
}
