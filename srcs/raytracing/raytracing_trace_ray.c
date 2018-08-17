/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_trace_ray.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:03:09 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/15 22:10:13 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"
#include "raytracing_private.h"
#include "scene.h"
#include "canvas.h"
#include "ray.h"
#include "vect3d.h"

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
