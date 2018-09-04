/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_trace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:27:12 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/02 20:29:29 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"
#include "raytracing_private.h"
#include "scene.h"
#include "canvas.h"
#include "ray.h"
#include "vect3d.h"
	#include <math.h>
t_vect3d	raytracing_trace(const t_scene *scene, int i, int j,
			const t_canvas *canvas)
{
	t_ray		ray;
	t_vect3d	color;

	ray.o = scene->camera.pos;
	ray.d = get_ray_dir(scene->camera, i, j, canvas);
	color = trace_ray(scene, ray, 0);
	return (color);
}
