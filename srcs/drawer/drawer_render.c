/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:34:08 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 22:16:43 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"

void	drawer_render(t_drawer *drawer)
{
	SDL_UpdateTexture(drawer->texture, NULL, drawer->pixels,
		sizeof(t_pixel) * TEX_W);
	SDL_RenderClear(drawer->renderer);
	SDL_RenderCopy(drawer->renderer, drawer->texture, NULL, NULL);
	SDL_RenderPresent(drawer->renderer);
}
