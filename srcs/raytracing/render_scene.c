/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:15:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/18 14:23:51 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
//Temp solution
#include "rtv1_defines.h"
//
#include "drawer.h"
#include "scene.h"
#include "userinput.h"
#include "raytracing.h"
#include "vect3d.h"
#include "mmath.h"

/*
**	0.86602540378 - 1 / (2 * tan(30deg))
**	30deg = half of FOV
*/
#define DIST_TO_PP (WIN_W * 0.86602540378)

static t_vect3d	get_ray_dir(t_camera *camera, double x, double y)
{
	t_vect3d	ray_dir;
	double		dir_factor;
	double		up_factor;
	double		right_factor;

	dir_factor = DIST_TO_PP;
	up_factor = -(y - WIN_H / 2);
	right_factor = (x - WIN_W / 2);
	ray_dir = vect3d_mult_on_scalar(camera->dir, dir_factor)
			+ vect3d_mult_on_scalar(camera->up, up_factor)
			+ vect3d_mult_on_scalar(camera->right, right_factor);
	ray_dir = vect3d_norm(ray_dir);
	return (ray_dir);
}

#define VECT3D_TO_COLOR(v) COLOR_RGBA(255*v[X], 255*v[Y], 255*v[Z], 0)

static void		fill_square_of_pixels(t_canvas canvas, t_square square,
				t_vect3d color)
{
	int		i;
	int		j;
	int		col;

	col = VECT3D_TO_COLOR(color).value;
	j = 0;
	while (j < square.size)
	{
		i = 0;
		while (i < square.size)
		{
			SET_PIXEL(canvas, square.left + i, square.top + j, col);
			i++;
		}
		j++;
	}
}

#include <stdio.h>
static t_vect3d	handle_antialiasing(const t_scene *scene, int i, int j)
{
	int			s1;
	int			s2;
	//double		delta;
	t_vect3d	color;
	t_vect3d	ray_dir;

	//delta = 1.0 / (NSAMPLES + 1);
	color = vect3d(0, 0, 0);
	s1 = 0;
	while (s1 < NSAMPLES)
	{
		s2 = 0;
		while (s2 < NSAMPLES)
		{
			double tmp1 = i + (s2 + 1) / (double)(NSAMPLES + 1);
			double tmp2 = j + (s1 + 1) / (double)(NSAMPLES + 1);
			ray_dir = get_ray_dir(scene->camera,
					tmp1,
					tmp2);
			color += trace_ray(scene, scene->camera->pos, ray_dir, 0);
			s2++;
		}
		s1++;
	}
	color = vect3d_div_on_scalar(color, NSAMPLES * NSAMPLES);
	return (color);
}
#include <stdio.h>
void			render_scene(const t_scene *scene, t_canvas canvas,
				const t_userinput *userinput)
{
//	printf("can_w: %u can_h: %u\n", canvas.w, canvas.h);
	unsigned int	j;
	unsigned int	i;
	t_vect3d		ray_dir;
	t_vect3d		color;

	j = 0;
	while (j < canvas.h)
	{
		i = 0;
		while (i < canvas.w)
		{
			if (userinput->is_antialiasing)
				color = handle_antialiasing(scene,
											i + canvas.pos_x, j + canvas.pos_y);
			else
			{
				ray_dir = get_ray_dir(scene->camera,
									i + canvas.pos_x, j + canvas.pos_y);
				//vect3d_print(ray_dir);
				color = trace_ray(scene, scene->camera->pos, ray_dir, 0);
			}
			if (userinput->step_in_pixels > 1)
			{
				fill_square_of_pixels(canvas,
					(t_square){.top = j, .left = i,
						.size = userinput->step_in_pixels}, color);
			}
			else
				SET_PIXEL(canvas, i, j, VECT3D_TO_COLOR(color).value);
			i += userinput->step_in_pixels;
		}
		j += userinput->step_in_pixels;
	}
}
