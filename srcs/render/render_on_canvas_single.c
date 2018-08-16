/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_on_canvas_single.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 23:15:47 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/15 22:15:17 by amelihov         ###   ########.fr       */
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

static t_canvas_rect	make_rect_that_fit(const t_canvas *canvas, int i,
						int j, const t_options *optns)
{
	t_canvas_rect	rect;

	rect.top = j;
	rect.left = i;
	if ((t_uint)(i + optns->pixels_step_w) <= canvas->w)
		rect.w = optns->pixels_step_w;
	else
		rect.w = canvas->w - i;
	if ((t_uint)(j + optns->pixels_step_h) <= canvas->h)
		rect.h = optns->pixels_step_h;
	else
		rect.h = canvas->h - j;
	return (rect);
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
			if (optns->pixels_step_w > 1)
			{
//				rect = (t_canvas_rect){j, i, optns->pixels_step_w,
//					optns->pixels_step_h};
//				rect = canvas_strip_if_not_fit(&canvas, rect);
//				canvas_fill_rect(&canvas, rect, c);	
				canvas_fill_rect(canvas,
					make_rect_that_fit(canvas, i, j, optns), c);	
			}
			else
				CANVAS_SET_PIXEL((*canvas), i, j, c);
			i += optns->pixels_step_w;
		}
		j += optns->pixels_step_h;
	}
}
