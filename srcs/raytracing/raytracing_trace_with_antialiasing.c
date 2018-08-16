/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_trace_with_antialiasing.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:01:26 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/15 22:10:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"
#include "raytracing_private.h"
#include "scene.h"
#include "canvas.h"
#include "ray.h"
#include "vect3d.h"

t_vect3d	raytracing_trace_with_antialiasing(const t_scene *scene,
			int i, int j, const t_canvas *canvas)
{
	t_ray		ray;
	t_vect3d	color;
	int			s1;
	int			s2;

	ray.o = scene->camera.pos;
	color = vect3d(0, 0, 0);
	s1 = 0;
	while (s1 < NSAMPLES)
	{
		s2 = 0;
		while (s2 < NSAMPLES)
		{
			ray.d = get_ray_dir(scene->camera,
					i + (s2 + 1) / (double)(NSAMPLES + 1),
					j + (s1 + 1) / (double)(NSAMPLES + 1),
					canvas);
			color += trace_ray(scene, ray, 0);
			s2++;
		}
		s1++;
	}
	color = vect3d_div_on_scalar(color, NSAMPLES * NSAMPLES);
	return (color);
}
