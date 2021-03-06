/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_on_canvas_with_stereoscopy.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 18:32:56 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 14:22:48 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "scene.h"
#include "canvas.h"
#include "color.h"

static void	combine_pixels(t_pixel *first_pixels, t_pixel *snd_pixels,
			t_uint w, t_uint h)
{
	t_uint	i;
	t_uint	j;
	t_color	*colors1;
	t_color	*colors2;

	colors1 = (t_color *)first_pixels;
	colors2 = (t_color *)snd_pixels;
	j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			colors1[j * w + i].rgba[GREEN] = colors2[j * w + i].rgba[GREEN];
			colors1[j * w + i].rgba[BLUE] = colors2[j * w + i].rgba[BLUE];
			i++;
		}
		j++;
	}
}

void		render_on_canvas_with_stereoscopy(const t_scene *scene,
			t_canvas *canvas, const t_options *optns)
{
	t_pixel		*tmp_pixels;
	t_camera	*camera;
	t_vect3d	offset;

	camera = &((t_scene *)scene)->camera;
	offset = vect3d_mult_on_scalar(camera->basis.y, STEREOSCOPY_OFFSET);
	camera->pos -= offset;
	render_on_canvas(scene, canvas, optns);
	camera->pos += offset;
	tmp_pixels = canvas->pixels;
	canvas->pixels = malloc(sizeof(t_pixel) * canvas->w * canvas->h);
	camera->pos += offset;
	render_on_canvas(scene, canvas, optns);
	camera->pos -= offset;
	combine_pixels(tmp_pixels, canvas->pixels, canvas->w, canvas->h);
	free(canvas->pixels);
	canvas->pixels = tmp_pixels;
}
