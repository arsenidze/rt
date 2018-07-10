/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:15:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 23:18:04 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"
#include "scene.h"
#include "userinput.h"
#include "raytracing.h"
#include "vect3d.h"

/*
**	0.86602540378 - 1 / (2 * tan(30deg))
**	30deg = half of FOV
*/
#define DIST_TO_PP (TEX_W * 0.86602540378)

static t_vect3d	get_ray_dir(t_camera *camera, int x, int y)
{
	t_vect3d	ray_dir;
	double		dir_factor;
	double		up_factor;
	double		left_factor;

	dir_factor = DIST_TO_PP;
	up_factor = -(y - TEX_H / 2);
	left_factor = (x - TEX_W / 2);
	ray_dir = vect3d_mult_on_scalar(camera->dir, dir_factor)
			+ vect3d_mult_on_scalar(camera->up, up_factor)
			+ vect3d_mult_on_scalar(camera->left, left_factor);
	ray_dir = vect3d_norm(ray_dir);
	return (ray_dir);
}

static void		fill_square_of_pixels(t_pixel *pixels, t_square square,
				t_color color)
{
	int		i;
	int		j;

	j = 0;
	while (j < square.size)
	{
		i = 0;
		while (i < square.size)
		{
			SET_PIXEL(pixels, square.left + i, square.top + j, color.value);
			i++;
		}
		j++;
	}
}

void			render_scene(t_pixel *pixels, t_scene *scene,
				t_userinput *userinput)
{
	int			j;
	int			i;
	t_vect3d	ray_dir;
	t_color		color;

	j = 0;
	while (j < TEX_H)
	{
		i = 0;
		while (i < TEX_W)
		{
			ray_dir = get_ray_dir(scene->camera, i, j);
			color = trace_ray(scene, ray_dir);
			if (userinput->step_in_pixels > 1)
				fill_square_of_pixels(pixels,
					(t_square){.top = j, .left = i,
								.size = userinput->step_in_pixels},
					color);
			else
				SET_PIXEL(pixels, i, j, color.value);
			i += userinput->step_in_pixels;
		}
		j += userinput->step_in_pixels;
	}
}
