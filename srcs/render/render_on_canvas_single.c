/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_on_canvas_single.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 23:15:47 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 15:12:51 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "render_private.h"
#include "scene.h"
#include "canvas.h"
#include "options.h"
#include "color.h"
#include "raytracing.h"
#include "filter.h"

static void		fill_pixels_on_canvas(t_canvas *canvas, int coord[2],
				const t_options *optns, int color)
{
	t_canvas_rect	rect;

	if (optns->pixels_step_w == 1 && optns->pixels_step_h == 1)
	{
		CANVAS_SET_PIXEL((*canvas), coord[0], coord[1], color);
		return ;
	}
	rect = (t_canvas_rect){.top = coord[1], .left = coord[0],
		.w = optns->pixels_step_w, .h = optns->pixels_step_h};
	canvas_strip_if_not_fit(canvas, &rect);
	canvas_fill_rect(canvas, rect, color);
}

#define VECT3D_TO_COLOR(v) COLOR_RGBA(255*v[X], 255*v[Y], 255*v[Z], 0)

void			render_on_canvas_single(const t_scene *scene, t_canvas *canvas,
				const t_options *optns)
{
	unsigned int	j;
	unsigned int	i;
	t_ray			ray;
	t_vect3d		color;
	int				c;

	ray.o = scene->camera.pos;
	j = 0;
	while (j < canvas->h)
	{
		i = 0;
		while (i < canvas->w)
		{
			if (optns->is_antialiasing)
				color = raytracing_trace_with_antialiasing(scene, i, j, canvas);
			else
				color = raytracing_trace(scene, i, j, canvas);
			if (options_is_filters_on(optns))
				color = filter_apply_filters(color, optns);
			c = VECT3D_TO_COLOR(color).value;
			fill_pixels_on_canvas(canvas, (int[2]){i, j}, optns, c);
			i += optns->pixels_step_w;
		}
		j += optns->pixels_step_h;
	}
}
