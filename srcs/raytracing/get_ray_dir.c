/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:30:14 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/15 22:06:39 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing_private.h"
#include "vect3d.h"
#include "camera.h"
#include "canvas.h"

t_vect3d	get_ray_dir(t_camera camera, double x, double y,
			const t_canvas *canvas)
{
	t_vect3d	ray_dir;
	double		dir_factor;
	double		up_factor;
	double		right_factor;

	dir_factor = (double)canvas->w / (2 * TAN30);
	up_factor = -((double)y + canvas->pos_y - canvas->win_h / 2);
	right_factor = (double)x + canvas->pos_x - canvas->win_w / 2;
	ray_dir = vect3d_mult_on_scalar(camera.basis.x, dir_factor)
			+ vect3d_mult_on_scalar(camera.basis.y, right_factor)
			+ vect3d_mult_on_scalar(camera.basis.z, up_factor);
	ray_dir = vect3d_norm(ray_dir);
	return (ray_dir);
}
