/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_strip_if_not_fit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 14:57:55 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 15:13:43 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

short	canvas_strip_if_not_fit(t_canvas *canvas, t_canvas_rect *rect)
{
	short	is_stripped;

	is_stripped = 0;
	if ((t_uint)(rect->left + rect->w) > canvas->w)
	{
		rect->w = canvas->w - rect->left;
		is_stripped = 1;
	}
	if ((t_uint)(rect->top + rect->h) > canvas->h)
	{
		rect->h = canvas->h - rect->top;
		is_stripped = 1;
	}
	return (is_stripped);
}
