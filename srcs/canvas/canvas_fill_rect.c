/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_fill_rect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:17:18 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 22:44:57 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

void	canvas_fill_rect(const t_canvas *canvas, t_canvas_rect rect,
		int color)
{
	t_uint	i;
	t_uint	j;

	j = 0;
	while (j < rect.h)
	{
		i = 0;
		while (i < rect.w)
		{
			CANVAS_SET_PIXEL((*canvas), rect.left + i, rect.top + j, color);
			i++;
		}
		j++;
	}
}
