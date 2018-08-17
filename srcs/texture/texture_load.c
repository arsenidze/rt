/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:21:44 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 22:48:03 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "SDL.h"
#include "SDL_image.h"
#include <stdlib.h>
#include "libft.h"

short	texture_load(t_texture *tex, const char *tex_name)
{
	SDL_Surface	*surfrace;

	surfrace = IMG_Load(tex_name);
	if (!surfrace)
		return (TEXTURE_FAILURE);
	tex->w = surfrace->w;
	tex->h = surfrace->h;
	tex->bpp = surfrace->format->BytesPerPixel;
	if (!(tex->pixels = malloc(surfrace->h * surfrace->pitch)))
	{
		SDL_FreeSurface(surfrace);
		return (TEXTURE_FAILURE);
	}
	SDL_LockSurface(surfrace);
	ft_memcpy(tex->pixels, surfrace->pixels, surfrace->h * surfrace->pitch);
	SDL_UnlockSurface(surfrace);
	SDL_FreeSurface(surfrace);
	return (TEXTURE_SUCCESS);
}
