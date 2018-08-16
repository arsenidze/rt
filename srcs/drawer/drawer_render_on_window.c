/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_render_on_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 18:43:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/15 18:44:00 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"

void	drawer_render_on_window(const t_drawer *drawer)
{
	SDL_UpdateTexture(drawer->texture, NULL, drawer->canvas.pixels,
		sizeof(t_pixel) * drawer->canvas.w);
	SDL_RenderClear(drawer->renderer);
	SDL_RenderCopy(drawer->renderer, drawer->texture, NULL, NULL);
	SDL_RenderPresent(drawer->renderer);
}
