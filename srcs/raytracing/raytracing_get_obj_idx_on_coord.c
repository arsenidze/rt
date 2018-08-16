/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_get_obj_idx_on_coord.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:48:53 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/15 22:00:00 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"
#include "raytracing_private.h"
#include "scene.h"
#include "canvas.h"
#include "intersection.h"

int			raytracing_get_obj_idx_on_coord(const t_scene *scene, int i, int j,
			const t_canvas *canvas)
{
	t_ray			ray;
	t_intersection	isect;
	unsigned int	idx;
	
	ray.o = scene->camera.pos;	
	ray.d = get_ray_dir(scene->camera, i, j, canvas);
	if (!find_closest_intersection(scene, ray, &isect))
		return (0);
	idx = 0;
	while (idx < scene->objects.size)
	{
		if (isect.hit_object == &scene->objects.data[idx])
		{
			return (idx);
		}
		idx++;
	}
	return (0);
}
